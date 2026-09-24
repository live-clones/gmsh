// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "PViewDataGModel.h"
#include "MVertex.h"
#include "Context.h"

#if defined(HAVE_MED)

#include <med.h>

#if (MED_MAJOR_NUM >= 3)
// To avoid too many ifdefs below we use defines for the bits of the
// API that did not change too much between MED2 and MED3. If we
// remove MED2 support at some point, please remove these defines and
// replace the symbols accordingly.
#define med_geometrie_element med_geometry_type
#define med_entite_maillage med_entity_type
#define med_type_champ med_field_type
#define MED_TAILLE_NOM MED_NAME_SIZE
#define MED_TAILLE_PNOM MED_SNAME_SIZE
#define MED_LECTURE MED_ACC_RDONLY
#define MED_LECTURE_AJOUT MED_ACC_RDEXT
#define MED_NOEUD MED_NODE
#define MED_MAILLE MED_CELL
#define MED_NOEUD_MAILLE MED_NODE_ELEMENT
#define MED_NOPFL MED_NO_PROFILE
#define MEDouvrir MEDfileOpen
#define MEDfermer MEDfileClose
#define MEDnChamp MEDfieldnComponent
#define MEDnValProfil MEDprofileSizeByName
#endif

extern int med2mshElementType(med_geometrie_element med);
extern int med2mshNodeIndex(med_geometrie_element med, int k);

// a MED file, closed on every way out
class medFile {
public:
  med_idt fid;
  medFile(med_idt f) : fid(f) {}
  ~medFile()
  {
    if(fid >= 0) MEDfermer(fid);
  }
  bool close()
  {
    bool ok = (MEDfermer(fid) >= 0);
    fid = -1;
    return ok;
  }
};

std::vector<std::string> medGetFieldNames(const std::string &fileName)
{
  std::vector<std::string> fieldNames;

#if (MED_MAJOR_NUM >= 3)
  med_idt fid = MEDfileOpen(fileName.c_str(), MED_ACC_RDONLY);
#else
  med_idt fid = MEDouvrir((char *)fileName.c_str(), MED_LECTURE);
#endif
  if(fid < 0) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return fieldNames;
  }
  medFile file(fid);

#if (MED_MAJOR_NUM >= 3)
  med_int numFields = MEDnField(fid);
#else
  med_int numFields = MEDnChamp(fid, 0);
#endif

  for(int index = 0; index < numFields; index++) {
    med_int numComp = MEDnChamp(fid, index + 1);
    if(numComp <= 0) {
      Msg::Error("Could not get number of components for MED field");
      return fieldNames;
    }

    char name[MED_TAILLE_NOM + 1], meshName[MED_TAILLE_NOM + 1];
    char dtUnit[MED_TAILLE_PNOM + 1];
    std::vector<char> compName(numComp * MED_TAILLE_PNOM + 1);
    std::vector<char> compUnit(numComp * MED_TAILLE_PNOM + 1);
    med_int numSteps = 0;
    med_type_champ type;
#if (MED_MAJOR_NUM >= 3)
    med_bool localMesh;
    if(MEDfieldInfo(fid, index + 1, name, meshName, &localMesh, &type,
                    &compName[0], &compUnit[0], dtUnit, &numSteps) < 0) {
#else
    if(MEDchampInfo(fid, index + 1, name, &type, &compName[0], &compUnit[0],
                    numComp) < 0) {
#endif
      Msg::Error("Could not get MED field info");
      return fieldNames;
    }
    fieldNames.push_back(name);
  }

  if(!file.close()) Msg::Error("Unable to close file '%s'", fileName.c_str());
  return fieldNames;
}

bool PViewDataGModel::readMED(const std::string &fileName, int fileIndex)
{
  med_idt fid = MEDouvrir((char *)fileName.c_str(), MED_LECTURE);
  if(fid < 0) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }
  medFile file(fid);

  med_int numComp = MEDnChamp(fid, fileIndex + 1);
  if(numComp <= 0) {
    Msg::Error("Could not get number of components for MED field");
    return false;
  }

  char name[MED_TAILLE_NOM + 1], meshName[MED_TAILLE_NOM + 1];
  char dtUnit[MED_TAILLE_PNOM + 1];
  std::vector<char> compName(numComp * MED_TAILLE_PNOM + 1);
  std::vector<char> compUnit(numComp * MED_TAILLE_PNOM + 1);
  med_int numSteps = 0;
  med_type_champ type;
#if (MED_MAJOR_NUM >= 3)
  med_bool localMesh;
  if(MEDfieldInfo(fid, fileIndex + 1, name, meshName, &localMesh, &type,
                  &compName[0], &compUnit[0], dtUnit, &numSteps) < 0) {
#else
  if(MEDchampInfo(fid, fileIndex + 1, name, &type, &compName[0], &compUnit[0],
                  numComp) < 0) {
#endif
    Msg::Error("Could not get MED field info");
    return false;
  }

  Msg::Info("Reading %d-component field '%s'", (int)numComp, name);
  setName(name);
  setFileName(fileName);
  setFileIndex(fileIndex);

  int numCompMsh = (numComp <= 1) ? 1 :
                   (numComp <= 3) ? 3 :
                   (numComp <= 9) ? 9 :
                                    numComp;

  if(numCompMsh > 9)
    Msg::Info(
      "More than 9 components in field: you will probably want to force "
      "the field type to scalar, vector or tensor in the options");

  // Warning! The ordering of the elements in the last two lists is
  // important: it should match the ordering of the MSH element types
  // (when elements are saved without tags, this governs the order
  // with which we implicitly index them in GModel::readMED)
  const med_entite_maillage entType[] = {MED_NOEUD, MED_MAILLE,
                                         MED_NOEUD_MAILLE};
#if (MED_MAJOR_NUM >= 3)
  const med_geometrie_element eleType[] = {
    MED_NONE,   MED_SEG2,   MED_TRIA3, MED_QUAD4,  MED_TETRA4,  MED_HEXA8,
    MED_PENTA6, MED_PYRA5,  MED_SEG3,  MED_TRIA6,  MED_QUAD9,   MED_TETRA10,
    MED_HEXA27, MED_POINT1, MED_QUAD8, MED_HEXA20, MED_PENTA15, MED_PYRA13};
  const int nodesPerEle[] = {0, 2, 3,  4,  4, 8, 6,  5,  3,
                             6, 9, 10, 27, 1, 8, 20, 15, 13};
#else
  const med_geometrie_element eleType[] = {
    MED_NONE,   MED_SEG2,   MED_TRIA3,   MED_QUAD4, MED_TETRA4,  MED_HEXA8,
    MED_PENTA6, MED_PYRA5,  MED_SEG3,    MED_TRIA6, MED_TETRA10, MED_POINT1,
    MED_QUAD8,  MED_HEXA20, MED_PENTA15, MED_PYRA13};
  const int nodesPerEle[] = {0, 2, 3,  4, 4, 8,  6,  5,
                             3, 6, 10, 1, 8, 20, 15, 13};
#endif

  std::vector<std::pair<int, int>> pairs;
  for(std::size_t i = 0; i < sizeof(entType) / sizeof(entType[0]); i++) {
    for(std::size_t j = 0; j < sizeof(eleType) / sizeof(eleType[0]); j++) {
      if((!i && !j) || j) {
#if (MED_MAJOR_NUM >= 3)
        med_int n = numSteps;
#else
        med_int n = MEDnPasdetemps(fid, name, entType[i], eleType[j]);
#endif
        if(n > 0) {
          pairs.push_back(std::make_pair(i, j));
          numSteps = std::max(numSteps, n);
        }
        if(!i && !j) break; // MED_NOEUD does not care about eleType
      }
    }
  }

  if(numSteps < 1 || pairs.empty()) {
    Msg::Error("Nothing to import from MED file");
    return false;
  }

  for(int step = 0; step < numSteps; step++) {
    // the step of the view it goes in: the same, as the file completes the
    // steps read from others on the same mesh (e.g. a domain decomposition);
    // or, if that step is on another mesh, the step numbered in the file (a
    // file per mesh), or the next one
    int target = step;

    // FIXME: in MED3 we might want to loop over all profiles instead
    // of relying of the default one

    // FIXME: MED3 allows to store multi-step meshes; we should
    // interface this with our own gmodel-per-step structure

    for(std::size_t pair = 0; pair < pairs.size(); pair++) {
      // get step info
      med_entite_maillage ent = entType[pairs[pair].first];
      med_geometrie_element ele = eleType[pairs[pair].second];
      med_int numdt, numit, ngauss;
      med_float dt;
#if (MED_MAJOR_NUM >= 3)
      if(MEDfieldComputingStepInfo(fid, name, step + 1, &numdt, &numit, &dt) <
         0) {
#else
      char dtunit[MED_TAILLE_PNOM + 1];
      med_booleen local;
      med_int numMeshes;
      if(MEDpasdetempsInfo(fid, name, ent, ele, step + 1, &ngauss, &numdt,
                           &numit, dtunit, &dt, meshName, &local,
                           &numMeshes) < 0) {
#endif
        Msg::Error("Could not read step info");
        return false;
      }
      // create step data
      if(!pair) {
        // (the mesh of the file was read in the current model, whose name
        // another model might have)
        GModel *m = GModel::current();
        if(m->getName() != meshName) m = GModel::findByName(meshName);
        if(!m) {
          Msg::Error("Could not find mesh '%s'", meshName);
          return false;
        }
        if(hasTimeStep(step) && _steps[step]->getModel() != m)
          target = (numdt >= 1 && !hasTimeStep(numdt - 1)) ?
                     (int)numdt - 1 :
                     getNumTimeSteps();
        if(!_getStep(target, m, numCompMsh)) return false;
        _steps[target]->setFileName(fileName);
        _steps[target]->setFileIndex(fileIndex);
        _steps[target]->setTime(dt);
      }

      char locName[MED_TAILLE_NOM + 1], profileName[MED_TAILLE_NOM + 1];

      // get number of values in the field (numVal takes the number of
      // Gauss points or the number of nodes per element into account,
      // but not the number of components)
#if (MED_MAJOR_NUM >= 3)
      med_int profileSize;
      med_int numVal = MEDfieldnValueWithProfile(
        fid, name, numdt, numit, ent, ele, 1, MED_COMPACT_STMODE, profileName,
        &profileSize, locName, &ngauss);
      numVal *= ngauss;
#else
      med_int numVal =
        MEDnVal(fid, name, ent, ele, numdt, numit, meshName, MED_COMPACT);
#endif
      if(numVal <= 0) continue;

      _type = (ent == MED_NOEUD)  ? NodeData :
              (ent == MED_MAILLE) ? ElementData :
                                    ElementNodeData;
      int mult = 1;
      if(ent == MED_NOEUD_MAILLE) { mult = nodesPerEle[pairs[pair].second]; }
      else if(ngauss != 1) {
        mult = ngauss;
        _type = GaussPointData;
      }
      _steps[target]->resizeData(numVal / mult);

      // read field data
      std::vector<double> val(numVal * numComp);
#if (MED_MAJOR_NUM >= 3)
      if(MEDfieldValueWithProfileRd(fid, name, numdt, numit, ent, ele,
                                    MED_COMPACT_STMODE, profileName,
                                    MED_FULL_INTERLACE, MED_ALL_CONSTITUENT,
                                    (unsigned char *)&val[0]) < 0) {
#else
      if(MEDchampLire(fid, meshName, name, (unsigned char *)&val[0],
                      MED_FULL_INTERLACE, MED_ALL, locName, profileName,
                      MED_COMPACT, ent, ele, numdt, numit) < 0) {
#endif
        Msg::Error("Could not read field values");
        return false;
      }

      Msg::Debug(
        "MED: eletyp=%d entity=%d (0:cell, 3:node, 4:elenode) ngauss=%d "
        "localizationName=%s profileName=%s -- stepDataType=%d",
        ele, ent, ngauss, locName, profileName, _type);

      // read Gauss point data
      if(_type == GaussPointData) {
        std::vector<double> &p(
          _steps[target]->getGaussPoints(med2mshElementType(ele)));
        if(std::string(locName) == MED_GAUSS_ELNO) {
          // special case: the gauss points are the vertices of the
          // element; in this case no explicit localization has to be
          // created in MED
          p.assign(ngauss * 3, 1.e22);
        }
        else {
          int dim = ele / 100;
          std::vector<med_float> refcoo((ele % 100) * dim);
          std::vector<med_float> gscoo(ngauss * dim);
          std::vector<med_float> wg(ngauss);
#if (MED_MAJOR_NUM >= 3)
          if(MEDlocalizationRd(fid, locName, MED_FULL_INTERLACE, refcoo.data(),
                               gscoo.data(), wg.data()) < 0) {
#else
          if(MEDgaussLire(fid, refcoo.data(), gscoo.data(), wg.data(),
                          MED_FULL_INTERLACE, locName) < 0) {
#endif
            Msg::Error("Could not read Gauss points");
            return false;
          }
          // FIXME: we should check that refcoo corresponds to our
          // internal reference element
          p.clear(); // (the same points, if read again from another file)
          for(int i = 0; i < (int)gscoo.size(); i++) {
            p.push_back(gscoo[i]);
            if(i % dim == dim - 1)
              for(int j = 0; j < 3 - dim; j++) p.push_back(0.);
          }
        }
      }

      // compute profile (indices in full array of entities of given type)
      std::vector<med_int> profile;
      if(std::string(profileName) != MED_NOPFL) {
        med_int n = MEDnValProfil(fid, profileName);
        if(n > 0) {
          Msg::Debug("MED has full profile");
          profile.resize(n);
#if (MED_MAJOR_NUM >= 3)
          if(MEDprofileRd(fid, profileName, &profile[0]) < 0) {
#else
          if(MEDprofilLire(fid, &profile[0], profileName) < 0) {
#endif
            Msg::Error("Could not read profile");
            return false;
          }
        }
      }
      if(profile.empty()) {
        Msg::Debug("MED profile is empty -- using continuous sequence");
        profile.resize(numVal / mult);
        for(std::size_t i = 0; i < profile.size(); i++) profile[i] = i + 1;
      }
      if(profile.size() * mult > (std::size_t)numVal) {
        Msg::Error("MED profile '%s' has more entities than field '%s' has "
                   "values",
                   profileName, name);
        return false;
      }

      // get size of full array and tags (if any) of entities
      bool nodal = (ent == MED_NOEUD);
#if (MED_MAJOR_NUM >= 3)
      med_bool changeOfCoord;
      med_bool geoTransform;
      med_int numEnt = MEDmeshnEntity(
        fid, meshName, MED_NO_DT, MED_NO_IT, nodal ? MED_NODE : MED_CELL,
        nodal ? MED_NO_GEOTYPE : ele, nodal ? MED_COORDINATE : MED_CONNECTIVITY,
        nodal ? MED_NO_CMODE : MED_NODAL, &changeOfCoord, &geoTransform);
#else
      med_int numEnt =
        MEDnEntMaa(fid, meshName, nodal ? MED_COOR : MED_CONN,
                   nodal ? MED_NOEUD : MED_MAILLE, nodal ? MED_NONE : ele,
                   nodal ? (med_connectivite)0 : MED_NOD);
#endif
      std::vector<med_int> tags(std::max(numEnt, (med_int)0));
#if (MED_MAJOR_NUM >= 3)
      if(tags.empty() ||
         MEDmeshEntityNumberRd(fid, meshName, MED_NO_DT, MED_NO_IT,
                               nodal ? MED_NODE : MED_CELL,
                               nodal ? MED_NO_GEOTYPE : ele, &tags[0]) < 0)
#else
      if(tags.empty() ||
         MEDnumLire(fid, meshName, &tags[0], numEnt,
                    nodal ? MED_NOEUD : MED_MAILLE, nodal ? MED_NONE : ele) < 0)
#endif
        tags.clear();

      // if we don't have tags, compute the starting index (i.e., how many
      // elements of different type are in the mesh before these ones)
      std::size_t startIndex = 0;
      if(tags.empty()) {
        std::size_t maxv, maxe;
        _steps[target]->getModel()->getCheckPointedMaxNumbers(maxv, maxe);
        if(nodal) { startIndex += maxv; }
        else {
          for(int i = 1; i < pairs[pair].second; i++) {
#if (MED_MAJOR_NUM >= 3)
            med_int n = MEDmeshnEntity(
              fid, meshName, MED_NO_DT, MED_NO_IT, MED_CELL, eleType[i],
              MED_CONNECTIVITY, MED_NODAL, &changeOfCoord, &geoTransform);
#else
            med_int n = MEDnEntMaa(fid, meshName, MED_CONN, MED_MAILLE,
                                   eleType[i], MED_NOD);
#endif
            if(n > 0) startIndex += n;
          }
          startIndex += maxe;
        }
        Msg::Debug("MED has no tags -- assuming starting index %zu",
                   startIndex);
      }

      // compute entity numbers using profile, then fill step data
      for(std::size_t i = 0; i < profile.size(); i++) {
        std::size_t num;
        if(tags.empty()) { num = startIndex + profile[i]; }
        else {
          if(profile[i] == 0 || profile[i] > (int)tags.size()) {
            Msg::Error("Wrong index in profile");
            return false;
          }
          num = tags[profile[i] - 1];
        }

        double *d = _steps[target]->getData(num, true, mult);
        for(int j = 0; j < mult; j++) {
          // reorder nodes if we have ElementNode data
          int j2 = (ent == MED_NOEUD_MAILLE) ? med2mshNodeIndex(ele, j) : j;
          for(int k = 0; k < numComp; k++)
            d[numCompMsh * j + k] = val[numComp * mult * i + numComp * j2 + k];
        }
      }
    }
  }

  finalize();

  if(!file.close()) {
    Msg::Error("Unable to close file '%s'", fileName.c_str());
    return false;
  }
  return true;
}

bool PViewDataGModel::writeMED(const std::string &fileName, bool saveMesh)
{
  if(_steps.empty()) return true;

  if(hasMultipleMeshes()) {
    Msg::Error("Export not done for multi-mesh views");
    return false;
  }

  if(_type != NodeData) {
    Msg::Error("Can only export node-based datasets for now");
    return false;
  }

  // (the first steps may have no data)
  int first = getFirstNonEmptyTimeStep();
  GModel *model = _steps[first]->getModel();

  // save the mesh (its nodes then have their index in the file)
  if(saveMesh && !model->writeMED(fileName, true)) return false;

  std::string meshName(model->getName());
  std::string fieldName(getName());

#if (MED_MAJOR_NUM >= 4) || ((MED_MAJOR_NUM >= 3) && (MED_MINOR_NUM >= 3))
  // MEDfileVersionOpen actually appeared in MED 3.2.1
  med_int major = MED_MAJOR_NUM, minor = MED_MINOR_NUM,
          release = MED_RELEASE_NUM;
  if(CTX::instance()->mesh.medFileMinorVersion >= 0) {
    minor = (int)CTX::instance()->mesh.medFileMinorVersion;
    Msg::Info("Forcing MED file version to %d.%d", major, minor);
  }
  // (read-write: each step updates the field)
  med_idt fid = MEDfileVersionOpen((char *)fileName.c_str(), MED_ACC_RDWR,
                                   major, minor, release);
#else
  med_idt fid = MEDouvrir((char *)fileName.c_str(), MED_LECTURE_AJOUT);
#endif

  if(fid < 0) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }
  medFile file(fid);

  // compute profile: the nodes with data, in the file
  std::string profileName = "nodeProfile_" + fieldName;
  profileName.resize(std::min(profileName.size(), (std::size_t)MED_NAME_SIZE));
  std::vector<med_int> profile, indices;
  std::size_t notInFile = 0;
  for(std::size_t i = 0; i < _steps[first]->getNumData(); i++) {
    if(_steps[first]->getData(i)) {
      MVertex *v = model->getMeshVertexByTag(i);
      if(!v) {
        Msg::Error("Unknown node %zu in data (MED)", i);
        return false;
      }
      if(v->getIndex() < 1) {
        notInFile++;
        continue;
      }
      profile.push_back(v->getIndex());
      indices.push_back(i);
    }
  }
  if(notInFile)
    Msg::Warning("Values of view '%s' at %zu nodes not saved in the MED "
                 "file are skipped",
                 fieldName.c_str(), notInFile);

  if(profile.empty()) {
    Msg::Error("Nothing to save");
    return false;
  }

#if (MED_MAJOR_NUM >= 3)
  if(MEDprofileWr(fid, profileName.c_str(), (med_int)profile.size(),
                  &profile[0]) < 0) {
#else
  if(MEDprofilEcr(fid, &profile[0], (med_int)profile.size(),
                  (char *)profileName.c_str()) < 0) {
#endif
    Msg::Error("Could not create MED profile");
    return false;
  }

  int numComp = _steps[first]->getNumComponents();
#if (MED_MAJOR_NUM >= 3)
  // the names and units of the components, MED_SNAME_SIZE characters each
  std::string compNames, compUnits;
  for(int k = 0; k < numComp; k++) {
    std::string n = "comp" + std::to_string(k);
    n.resize(MED_SNAME_SIZE, ' ');
    compNames += n;
    std::string u = "unknown";
    u.resize(MED_SNAME_SIZE, ' ');
    compUnits += u;
  }
  if(MEDfieldCr(fid, (char *)fieldName.c_str(), MED_FLOAT64, (med_int)numComp,
                compNames.c_str(), compUnits.c_str(), "unknown",
                (char *)meshName.c_str()) < 0) {
#else
  if(MEDchampCr(fid, (char *)fieldName.c_str(), MED_FLOAT64, (char *)"unknown",
                (char *)"unknown", (med_int)numComp) < 0) {
#endif
    Msg::Error("Could not create MED field");
    return false;
  }

#if (MED_MAJOR_NUM >= 3)
  med_bool changeOfCoord, geoTransform;
  med_int numNodes =
    MEDmeshnEntity(fid, (char *)meshName.c_str(), MED_NO_DT, MED_NO_IT,
                   MED_NODE, MED_NO_GEOTYPE, MED_COORDINATE, MED_NO_CMODE,
                   &changeOfCoord, &geoTransform);
#else
  med_int numNodes = MEDnEntMaa(fid, (char *)meshName.c_str(), MED_COOR,
                                MED_NOEUD, MED_NONE, (med_connectivite)0);
#endif
  if(numNodes <= 0) {
    Msg::Error("Could not get valid number of nodes in mesh");
    return false;
  }
  for(std::size_t step = 0; step < _steps.size(); step++) {
    if(!hasTimeStep(step)) continue;
    // the values of the step at the nodes of the profile (of the first step)
    std::size_t n = 0;
    for(std::size_t i = 0; i < _steps[step]->getNumData(); i++)
      if(_steps[step]->getData(i)) n++;
    bool same =
      (n == profile.size() && numComp == _steps[step]->getNumComponents());
    for(std::size_t i = 0; i < indices.size() && same; i++)
      same = (_steps[step]->getData(indices[i]) != nullptr);
    if(!same) {
      Msg::Warning("Skipping step %zu of view '%s': not on the nodes of the "
                   "first step",
                   step, getName().c_str());
      continue;
    }
    double time = _steps[step]->getTime();
    std::vector<double> val(profile.size() * numComp);
    for(std::size_t i = 0; i < profile.size(); i++)
      for(int k = 0; k < numComp; k++)
        val[i * numComp + k] = _steps[step]->getData(indices[i])[k];
#if (MED_MAJOR_NUM >= 3)
    if(MEDfieldValueWithProfileWr(
         fid, (char *)fieldName.c_str(), (med_int)(step + 1), MED_NO_IT, time,
         MED_NODE, MED_NO_GEOTYPE, MED_COMPACT_STMODE, profileName.c_str(), "",
         MED_FULL_INTERLACE, MED_ALL_CONSTITUENT, numNodes,
         (unsigned char *)&val[0]) < 0) {
#else
    if(MEDchampEcr(fid, (char *)meshName.c_str(), (char *)fieldName.c_str(),
                   (unsigned char *)&val[0], MED_FULL_INTERLACE, numNodes,
                   (char *)MED_NOGAUSS, MED_ALL, (char *)profileName.c_str(),
                   MED_COMPACT, MED_NOEUD, MED_NONE, (med_int)step,
                   (char *)"unknown", time, MED_NONOR) < 0) {
#endif
      Msg::Error("Could not write MED field");
      return false;
    }
  }

  if(!file.close()) {
    Msg::Error("Unable to close file '%s'", fileName.c_str());
    return false;
  }
  return true;
}

#else

bool PViewDataGModel::readMED(const std::string &fileName, int fileIndex)
{
  Msg::Error("Gmsh must be compiled with MED support to read '%s'",
             fileName.c_str());
  return false;
}

bool PViewDataGModel::writeMED(const std::string &fileName, bool saveMesh)
{
  Msg::Error("Gmsh must be compiled with MED support to write '%s'",
             fileName.c_str());
  return false;
}

#endif
