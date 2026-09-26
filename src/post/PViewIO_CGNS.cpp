// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "PView.h"
#include "PViewDataGModel.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"

#if defined(HAVE_LIBCGNS)

namespace {

  typedef std::pair<std::string, std::string> SolFieldName;

  int readFlowSolutionNames(
    int fileIndex, int baseIndex, int nbZone,
    std::map<SolFieldName, PViewDataGModel::DataType> &fields)
  {
    int cgnsErr;

    for(int iZone = 1; iZone <= nbZone; iZone++) {
      // get number of flow solutions in zone
      int nbZoneSol;
      cgnsErr = cg_nsols(fileIndex, baseIndex, iZone, &nbZoneSol);
      if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__);

      // get names of solution fields in each zone
      for(int iZoneSol = 1; iZoneSol <= nbZoneSol; iZoneSol++) {
        // get FlowSolution info
        char rawSolName[CGNS_MAX_STR_LEN];
        CGNS_ENUMT(GridLocation_t) location;
        cgnsErr = cg_sol_info(fileIndex, baseIndex, iZone, iZoneSol, rawSolName,
                              &location);
        if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__);
        const std::string solName(rawSolName);
        PViewDataGModel::DataType type;
        if(location == CGNS_ENUMV(CellCenter))
          type = PViewDataGModel::ElementData;
        else if(location == CGNS_ENUMV(Vertex)) {
          if(nbZone > 1) {
            Msg::Warning(
              "Multi-zone node-based solutions not supported in CGNS "
              "reader, skipping '%s'",
              rawSolName);
            continue;
          }
          else
            type = PViewDataGModel::NodeData;
        }
#ifdef HAVE_LIBCGNS_CPEX0045
        else if(location == CGNS_ENUMV(ElementBased)) {
          type = PViewDataGModel::ElementNodeData;
        }
#endif
        else {
          Msg::Warning("Unsupported GridLocation in CGNS solution reader, "
                       "skipping '%s'",
                       rawSolName);
          continue;
        }

        // get number of fields in this FlowSolution
        int nbField;
        cgnsErr = cg_nfields(fileIndex, baseIndex, iZone, iZoneSol, &nbField);
        if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__);

        // get names of fields
        for(int iField = 1; iField <= nbField; iField++) {
          CGNS_ENUMT(DataType_t) dataType;
          char rawFieldName[CGNS_MAX_STR_LEN];
          cgnsErr = cg_field_info(fileIndex, baseIndex, iZone, iZoneSol, iField,
                                  &dataType, rawFieldName);
          if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__);
          const std::string fieldName(rawFieldName);
          fields[std::make_pair(solName, fieldName)] = type;
        }
      }
    }

    return 1;
  }

  bool
  readFieldData(const std::vector<std::vector<MVertex *> > &vertPerZone,
                const std::vector<std::vector<MElement *> > &eltPerZone,
                const std::string &fileName, int fileIndex, int baseIndex,
                const std::map<SolFieldName, PViewDataGModel::DataType> &fields)
  {
    for(auto it = fields.begin(); it != fields.end(); ++it) {
      // field name and type
      const SolFieldName &solFieldName = it->first;
      const PViewDataGModel::DataType &fieldType = it->second;

      // in the most recent view of the field with the same type of data, read
      // from other files (e.g. the other steps of a series)
      const std::string fullFieldName =
        solFieldName.first + "_" + solFieldName.second;
      auto accept = [&](PViewDataGModel *d) {
        return d->getType() == fieldType && !d->hasFileName(fileName);
      };
      auto read = [&](PViewDataGModel *d) {
        return d->readCGNS(solFieldName, fileName, fileIndex, baseIndex,
                           vertPerZone, eltPerZone);
      };
      if(!PViewDataGModel::readInView(fullFieldName, fileName, fieldType,
                                      accept, read)) {
        Msg::Error("Could not read data in CGNS file '%s'", fileName.c_str());
        return false;
      }
    }

    return true;
  }

} // namespace

bool PView::readCGNS(const std::vector<std::vector<MVertex *> > &vertPerZone,
                     const std::vector<std::vector<MElement *> > &eltPerZone,
                     const std::string &fileName)
{
  int cgnsErr;

  // open CGNS file, closed on every way out
  int fileIndex = 0;
  cgnsErr = cg_open(fileName.c_str(), CG_MODE_READ, &fileIndex);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__);
  struct file {
    int index;
    ~file()
    {
      if(index >= 0) cg_close(index);
    }
  } file{fileIndex};

  // read base node
  const int baseIndex = 1;
  int cellDim = 0, physDim = 0;
  char baseName[CGNS_MAX_STR_LEN];
  cgnsErr = cg_base_read(fileIndex, baseIndex, baseName, &cellDim, &physDim);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__);

  // read number of zones
  int nbZone = 0;
  cgnsErr = cg_nzones(fileIndex, baseIndex, &nbZone);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__);

  // get flow solutions names
  std::map<SolFieldName, PViewDataGModel::DataType> fields;
  if(!readFlowSolutionNames(fileIndex, baseIndex, nbZone, fields)) return false;

  // read field data
  if(!readFieldData(vertPerZone, eltPerZone, fileName, fileIndex, baseIndex,
                    fields))
    return false;

  // close file
  file.index = -1;
  cgnsErr = cg_close(fileIndex);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__);

  return true;
}

#else

bool PView::readCGNS(const std::vector<std::vector<MVertex *> > &vertPerZone,
                     const std::vector<std::vector<MElement *> > &eltPerZone,
                     const std::string &fileName)
{
  Msg::Error("Gmsh must be compiled with CGNS support to read '%s'",
             fileName.c_str());
  return false;
}

#endif
