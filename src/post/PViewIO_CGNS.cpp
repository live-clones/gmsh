// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "PView.h"
#include "PViewData.h"
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
      if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

      // get names of solution fields in each zone
      for(int iZoneSol = 1; iZoneSol <= nbZoneSol; iZoneSol++) {
        // get FlowSolution info
        char rawSolName[CGNS_MAX_STR_LEN];
        CGNS_ENUMT(GridLocation_t) location;
        cgnsErr = cg_sol_info(fileIndex, baseIndex, iZone, iZoneSol, rawSolName,
                              &location);
        if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
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
        else if(location == ElementBased) {
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
        if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

        // get names of fields
        for(int iField = 1; iField <= nbField; iField++) {
          CGNS_ENUMT(DataType_t) dataType;
          char rawFieldName[CGNS_MAX_STR_LEN];
          cgnsErr = cg_field_info(fileIndex, baseIndex, iZone, iZoneSol, iField,
                                  &dataType, rawFieldName);
          if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
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
    int index = -1;
    for(auto it = fields.begin(); it != fields.end(); ++it) {
      // field name and type
      const SolFieldName &solFieldName = it->first;
      const PViewDataGModel::DataType &fieldType = it->second;
      index++;

      // either get existing view data, or create new one
      const std::string fullFieldName =
        solFieldName.first + "_" + solFieldName.second;
      PView *p = PView::getViewByName(
        fullFieldName, -1, -1); // DBGTT: to be checked for multi-file
      PViewDataGModel *d;
      bool create;
      if(p != nullptr) {
        d = dynamic_cast<PViewDataGModel *>(p->getData());
        create = false;
      }
      else {
        d = new PViewDataGModel(fieldType);
        create = true;
      }

      // read view data
      if(!d->readCGNS(solFieldName, fileName, index, fileIndex, baseIndex,
                      vertPerZone, eltPerZone)) {
        Msg::Error("Could not read data in CGNS file '%s'", fileName.c_str());
        if(create) delete d;
        return false;
      }
      else {
        d->setName(fullFieldName);
        d->setFileName(fileName);
        d->setFileIndex(index);
        if(create) new PView(d);
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

  // open CGNS file and read scale
  int fileIndex = 0;
  cgnsErr = cg_open(fileName.c_str(), CG_MODE_READ, &fileIndex);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // read base node
  const int baseIndex = 1;
  int dim = 0, meshDim = 0;
  char baseName[CGNS_MAX_STR_LEN];
  cgnsErr = cg_base_read(fileIndex, baseIndex, baseName, &meshDim, &dim);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // read number of zones
  int nbZone = 0;
  cgnsErr = cg_nzones(fileIndex, baseIndex, &nbZone);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // get flow solutions names
  std::map<SolFieldName, PViewDataGModel::DataType> fields;
  int err = readFlowSolutionNames(fileIndex, baseIndex, nbZone, fields);
  if(err == 0) return 0;

  // read field data
  bool err2 = readFieldData(vertPerZone, eltPerZone, fileName, fileIndex,
                            baseIndex, fields);
  if(!err2) return false;

  // close file
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
