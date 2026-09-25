// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshMessage.h"
#include "PViewDataGModel.h"
#include "MVertex.h"
#include "Context.h"
#include "fullMatrix.h"
#include "StringUtils.h"
#include "OS.h"
#include "Numeric.h"
#include <cstring>
#include <limits>
#include <map>
#include <memory>
#include "MElement.h"

// In MSH 4.2, the records of a data section come in blocks: `numBlocks
// numEntities minTag maxTag`, then for each block `numEntitiesInBlock` (with,
// before it, `elementType numValuesPerElement` in $ElementNodeData), the tags
// of the entities of the block, and their values. Before 4.2, each record is
// the tag of an entity (an int in binary), the number of values for
// $ElementNodeData, and the values.

namespace {

  // a binary file read through a buffer of its own (of the given size, at
  // most 1 MB), so that the small records of the sections before MSH 4.2 do
  // not each cost a call to fread (done() puts the file position back after
  // the last byte used)
  class bufferedReader {
  private:
    FILE *_fp;
    std::unique_ptr<char[]> _buffer;
    std::size_t _size, _pos, _end;

  public:
    bufferedReader(FILE *fp, std::size_t size)
      : _fp(fp),
        _size(std::max<std::size_t>(1, std::min<std::size_t>(size, 1 << 20))),
        _pos(0), _end(0)
    { _buffer.reset(new char[_size]); }
    bool read(void *dst, std::size_t size)
    {
      char *d = (char *)dst;
      while(size) {
        if(_pos == _end) {
          if(size >= _size) return fread(d, 1, size, _fp) == size;
          _end = fread(_buffer.get(), 1, _size, _fp);
          _pos = 0;
          if(!_end) return false;
        }
        std::size_t n = std::min(size, _end - _pos);
        memcpy(d, &_buffer[_pos], n);
        _pos += n;
        d += n;
        size -= n;
      }
      return true;
    }
    void done()
    {
      if(_end > _pos) fseek(_fp, -(long)(_end - _pos), SEEK_CUR);
      _pos = _end = 0;
    }
  };

  // the min/max of the scalar representation of n values of numComp
  // components each
  void minMax(int numComp, double *d, std::size_t n, double &min, double &max)
  {
    if(numComp == 1) {
      for(std::size_t i = 0; i < n; i++) {
        min = std::min(min, d[i]);
        max = std::max(max, d[i]);
      }
      return;
    }
    for(std::size_t i = 0; i < n; i++) {
      double val = ComputeScalarRep(numComp, &d[numComp * i]);
      min = std::min(min, val);
      max = std::max(max, val);
    }
  }

  bool readSizeTs(FILE *fp, bool binary, bool swap, std::size_t *v,
                  std::size_t n)
  {
    if(binary) {
      if(fread(v, sizeof(std::size_t), n, fp) != n) return false;
      if(swap) SwapBytes((char *)v, sizeof(std::size_t), n);
      return true;
    }
    for(std::size_t i = 0; i < n; i++)
      if(fscanf(fp, "%zu", &v[i]) != 1) return false;
    return true;
  }

  bool readDoubles(FILE *fp, bool binary, bool swap, double *v, std::size_t n)
  {
    if(binary) {
      if(fread(v, sizeof(double), n, fp) != n) return false;
      if(swap) SwapBytes((char *)v, sizeof(double), n);
      return true;
    }
    for(std::size_t i = 0; i < n; i++)
      if(fscanf(fp, "%lf", &v[i]) != 1) return false;
    return true;
  }

  // the blocks of MSH 4.2
  bool readBlocks(stepData<double> *s, FILE *fp, bool binary, bool swap,
                  bool hasMult, double &min, double &max)
  {
    std::size_t header[4]; // numBlocks numEntities minTag maxTag
    if(!readSizeTs(fp, binary, swap, header, 4)) return false;
    std::size_t numBlocks = header[0], numEntities = header[1];
    if(numEntities) s->resizeData(header[3] + 1);
    int numComp = s->getNumComponents();
    Msg::StartProgressMeter(numEntities);
    std::vector<std::size_t> tags;
    std::vector<double> buffer;
    std::size_t numRead = 0;
    for(std::size_t b = 0; b < numBlocks; b++) {
      int mult = 1;
      if(hasMult) {
        int type[2]; // elementType numValuesPerElement
        if(binary) {
          if(fread(type, sizeof(int), 2, fp) != 2) return false;
          if(swap) SwapBytes((char *)type, sizeof(int), 2);
        }
        else if(fscanf(fp, "%d %d", &type[0], &type[1]) != 2)
          return false;
        mult = type[1];
        if(mult < 0) return false;
      }
      std::size_t n = 0;
      if(!readSizeTs(fp, binary, swap, &n, 1)) return false;
      tags.resize(n);
      if(!readSizeTs(fp, binary, swap, tags.data(), n)) return false;
      std::size_t stride = (std::size_t)numComp * mult;
      double *d = s->allocate(n * stride);
      // (by chunks of about 1 MB, read into a buffer and copied, which is
      // faster than reading into the new memory, and whose min/max are
      // computed while they are in the cache)
      std::size_t chunk = std::max<std::size_t>(1, (1 << 17) / (stride + 1));
      for(std::size_t first = 0; first < n; first += chunk) {
        std::size_t num = std::min(chunk, n - first);
        double *c = d + first * stride;
        if(binary) {
          buffer.resize(num * stride);
          if(!readDoubles(fp, true, swap, buffer.data(), num * stride))
            return false;
          std::copy(buffer.begin(), buffer.end(), c);
        }
        else if(!readDoubles(fp, false, false, c, num * stride))
          return false;
        minMax(numComp, c, num * mult, min, max);
      }
      for(std::size_t k = 0; k < n; k++)
        s->setData(tags[k], d + k * stride, mult);
      numRead += n;
      if(numEntities > 100000)
        Msg::ProgressMeter(numRead, true, "Reading data");
    }
    Msg::StopProgressMeter();
    return true;
  }

  // the records of the versions before 4.2
  bool readRecords(stepData<double> *s, FILE *fp, bool binary, bool swap,
                   bool hasMult, int numEnt, double &min, double &max)
  {
    if(numEnt < 0) return false;
    s->resizeData(numEnt);
    int numComp = s->getNumComponents();
    Msg::StartProgressMeter(numEnt);
    if(binary && !hasMult) {
      // records of the same size, read by chunks of about 1 MB
      std::size_t size = sizeof(int) + numComp * sizeof(double);
      std::size_t chunk = std::max<std::size_t>(1, (1 << 20) / size);
      std::vector<char> buffer;
      for(std::size_t first = 0; first < (std::size_t)numEnt; first += chunk) {
        std::size_t num = std::min(chunk, numEnt - first);
        buffer.resize(num * size);
        if(fread(&buffer[0], size, num, fp) != num) return false;
        double *d = s->allocate(num * numComp);
        for(std::size_t k = 0; k < num; k++) {
          int tag;
          memcpy(&tag, &buffer[k * size], sizeof(int));
          memcpy(d + k * numComp, &buffer[k * size + sizeof(int)],
                 numComp * sizeof(double));
          if(swap) {
            SwapBytes((char *)&tag, sizeof(int), 1);
            SwapBytes((char *)(d + k * numComp), sizeof(double), numComp);
          }
          if(tag < 0) return false;
          s->setData(tag, d + k * numComp);
        }
        minMax(numComp, d, num, min, max);
        if(numEnt > 100000)
          Msg::ProgressMeter(first + num, true, "Reading data");
      }
      Msg::StopProgressMeter();
      return true;
    }
    // (a buffer no larger than the smallest the section can be)
    std::unique_ptr<bufferedReader> in;
    if(binary)
      in.reset(new bufferedReader(
        fp, numEnt * (2 * sizeof(int) + numComp * sizeof(double))));
    for(int i = 0; i < numEnt; i++) {
      int head[2] = {0, 1}; // tag, number of values
      if(binary) {
        int n = hasMult ? 2 : 1;
        if(!in->read(head, n * sizeof(int))) return false;
        if(swap) SwapBytes((char *)head, sizeof(int), n);
      }
      else {
        if(fscanf(fp, "%d", &head[0]) != 1) return false;
        if(hasMult && fscanf(fp, "%d", &head[1]) != 1) return false;
      }
      if(head[0] < 0 || head[1] < 0) return false;
      std::size_t n = (std::size_t)numComp * head[1];
      double *d = s->allocate(n);
      if(binary) {
        if(!in->read(d, n * sizeof(double))) return false;
        if(swap) SwapBytes((char *)d, sizeof(double), n);
      }
      else if(!readDoubles(fp, false, false, d, n))
        return false;
      s->setData(head[0], d, head[1]);
      minMax(numComp, d, head[1], min, max);
      if(numEnt > 100000 && (!(i & 1023) || i == numEnt - 1))
        Msg::ProgressMeter(i + 1, true, "Reading data");
    }
    if(binary) in->done();
    Msg::StopProgressMeter();
    return true;
  }

} // namespace

bool PViewDataGModel::readMSH(const std::string &viewName,
                              const std::string &fileName, int fileIndex,
                              FILE *fp, bool binary, bool swap, int step,
                              double time, int partition, int numComp,
                              int numEnt,
                              const std::string &interpolationScheme,
                              double version)
{
  Msg::Debug("Reading view `%s' step %d (time %g) partition %d: %d records",
             viewName.c_str(), step, time, partition, numEnt);

  stepData<double> *s = _getStep(step, GModel::current(), numComp);
  if(!s) return false;
  s->setFileName(fileName);
  s->setFileIndex(fileIndex);
  s->setTime(time);

  // the min/max are computed here to avoid calling finalize(true) later: this
  // would be very slow for large multi-step, multi-partition datasets (since we
  // would recompute the min/max for all the previously loaded
  // steps/partitions, and thus loop over all the elements many times)
  bool hasMult = (_type == ElementNodeData || _type == GaussPointData);
  double min = VAL_INF, max = -VAL_INF;
  if(version >= 4.2) {
    if(!readBlocks(s, fp, binary, swap, hasMult, min, max)) return false;
  }
  else {
    if(!readRecords(s, fp, binary, swap, hasMult, numEnt, min, max))
      return false;
  }
  s->setMin(std::min(s->getMin(), min));
  s->setMax(std::max(s->getMax(), max));
  _min = std::min(_min, min);
  _max = std::max(_max, max);
  if(partition >= 0) s->getPartitions().insert(partition);

  finalize(false, interpolationScheme);
  return true;
}

namespace {

  // the entities of a step with data, checked against the model
  bool dataEntities(stepData<double> *s, PViewDataGModel::DataType type,
                    std::vector<std::size_t> &indices,
                    std::vector<MElement *> &elements)
  {
    GModel *m = s->getModel();
    for(std::size_t i = 0; i < s->getNumData(); i++) {
      if(!s->getData(i)) continue;
      if(type == PViewDataGModel::NodeData) {
        if(!m->getMeshVertexByTag(i)) {
          Msg::Error("Unknown node %zu in data (MSH)", i);
          return false;
        }
      }
      else {
        MElement *e = m->getMeshElementByTag(i);
        if(!e) {
          Msg::Error("Unknown element %zu in data", i);
          return false;
        }
        elements.push_back(e);
      }
      indices.push_back(i);
    }
    return true;
  }

  // the blocks of MSH 4.2: a single one, or one for each element type and
  // number of values per element ($ElementNodeData)
  bool writeBlocks(stepData<double> *s, FILE *fp, bool binary,
                   PViewDataGModel::DataType type, bool hasMult)
  {
    std::vector<std::size_t> indices;
    std::vector<MElement *> elements;
    if(!dataEntities(s, type, indices, elements)) return false;
    std::map<std::pair<int, int>, std::vector<std::size_t>> blocks;
    for(std::size_t k = 0; k < indices.size(); k++) {
      std::pair<int, int> key(0, 1);
      if(hasMult)
        key =
          std::make_pair(elements[k]->getTypeForMSH(), s->getMult(indices[k]));
      blocks[key].push_back(indices[k]);
    }
    std::size_t header[4] = {blocks.size(), indices.size(),
                             indices.empty() ? 0 : indices.front(),
                             indices.empty() ? 0 : indices.back()};
    if(binary)
      fwrite(header, sizeof(std::size_t), 4, fp);
    else
      fprintf(fp, "%zu %zu %zu %zu\n", header[0], header[1], header[2],
              header[3]);
    int numComp = s->getNumComponents();
    std::vector<double> values;
    for(auto &b : blocks) {
      int mult = b.first.second;
      std::size_t n = b.second.size(), stride = (std::size_t)numComp * mult;
      if(binary) {
        if(hasMult) {
          int t[2] = {b.first.first, mult};
          fwrite(t, sizeof(int), 2, fp);
        }
        fwrite(&n, sizeof(std::size_t), 1, fp);
        fwrite(b.second.data(), sizeof(std::size_t), n, fp);
        // (by chunks, not to double the memory used by the view)
        const std::size_t chunk = 1 << 16;
        for(std::size_t first = 0; first < n; first += chunk) {
          std::size_t last = std::min(n, first + chunk);
          values.resize((last - first) * stride);
          for(std::size_t k = first; k < last; k++)
            std::copy(s->getData(b.second[k]), s->getData(b.second[k]) + stride,
                      &values[(k - first) * stride]);
          fwrite(values.data(), sizeof(double), values.size(), fp);
        }
      }
      else {
        if(hasMult) fprintf(fp, "%d %d ", b.first.first, mult);
        fprintf(fp, "%zu\n", n);
        for(auto i : b.second) fprintf(fp, "%zu\n", i);
        for(auto i : b.second) {
          double *d = s->getData(i);
          for(std::size_t j = 0; j < stride; j++)
            fprintf(fp, j ? " %.16g" : "%.16g", d[j]);
          fprintf(fp, "\n");
        }
      }
    }
    return true;
  }

  // the records of the versions before 4.2
  bool writeRecords(stepData<double> *s, FILE *fp, double version, bool binary,
                    PViewDataGModel::DataType type, bool hasMult)
  {
    std::vector<std::size_t> indices;
    std::vector<MElement *> elements;
    if(!dataEntities(s, type, indices, elements)) return false;
    GModel *m = s->getModel();
    int numComp = s->getNumComponents();
    for(std::size_t k = 0; k < indices.size(); k++) {
      std::size_t i = indices[k];
      std::size_t tag = i;
      if(version < 3.0)
        tag = (type == PViewDataGModel::NodeData) ?
                m->getMeshVertexByTag(i)->getIndex() :
                m->getMeshElementIndex(elements[k]);
      if(tag > (std::size_t)std::numeric_limits<int>::max()) {
        Msg::Error("Tag %zu too large for MSH %g data: use MSH 4.2", tag,
                   version);
        return false;
      }
      int num = tag;
      int mult = hasMult ? s->getMult(i) : 1;
      double *d = s->getData(i);
      if(binary) {
        fwrite(&num, sizeof(int), 1, fp);
        if(hasMult) fwrite(&mult, sizeof(int), 1, fp);
        fwrite(d, sizeof(double), numComp * mult, fp);
      }
      else {
        fprintf(fp, "%d", num);
        if(hasMult) fprintf(fp, " %d", mult);
        for(int j = 0; j < numComp * mult; j++) fprintf(fp, " %.16g", d[j]);
        fprintf(fp, "\n");
      }
    }
    return true;
  }

} // namespace

bool PViewDataGModel::writeMSH(const std::string &fileName, double version,
                               bool binary, bool saveMesh, bool multipleView,
                               int partitionNum, bool saveInterpolationMatrices,
                               bool forceNodeData, bool forceElementData)
{
  if(_steps.empty()) return true;

  // (a file for each mesh, name_0000.msh, named after its first step)
  if(hasMultipleMeshes()) {
    Msg::Info("Exporting multi-mesh view in separate files");
  }

  if(forceNodeData && _type != NodeData) {
    Msg::Warning("Cannot force NodeData for this dataset: saving native data");
  }

  if(forceElementData && _type != ElementData) {
    Msg::Warning(
      "Cannot force ElementData for this dataset: saving native data");
  }

  FILE *fp = nullptr;
  GModel *model0 = _steps[0]->getModel();

  for(std::size_t step = 0; step < _steps.size(); step++) {
    int numEnt = 0, numComp = _steps[step]->getNumComponents();
    for(std::size_t i = 0; i < _steps[step]->getNumData(); i++)
      if(_steps[step]->getData(i)) numEnt++;
    if(!numEnt) continue; // skip step

    // open file, save mesh and save interpolation matrices
    if(!fp || _steps[step]->getModel() != model0) {
      if(fp) fclose(fp);
      std::string stepFileName = fileName;
      if(hasMultipleMeshes()) {
        std::vector<std::string> n = SplitFileName(fileName);
        char s[32];
        snprintf(s, sizeof(s), "_%04d", (int)step);
        stepFileName = n[0] + n[1] + s + n[2];
        model0 = _steps[step]->getModel();
      }
      if(saveMesh) {
        if(!_steps[step]->getModel()->writeMSH(stepFileName, version, binary,
                                               false, false, 1.0, 0, 0,
                                               multipleView))
          return false;
        // append data
        fp = Fopen(stepFileName.c_str(), binary ? "ab" : "a");
        if(!fp) {
          Msg::Error("Unable to open file '%s'", stepFileName.c_str());
          return false;
        }
      }
      else {
        if(multipleView) {
          fp = Fopen(stepFileName.c_str(), binary ? "ab" : "a");
          if(!fp) {
            Msg::Error("Unable to open file '%s'", stepFileName.c_str());
            return false;
          }
        }
        else {
          fp = Fopen(stepFileName.c_str(), binary ? "wb" : "w");
          if(!fp) {
            Msg::Error("Unable to open file '%s'", stepFileName.c_str());
            return false;
          }
          fprintf(fp, "$MeshFormat\n");
          fprintf(fp, "%g %d %d\n", version, binary ? 1 : 0,
                  (int)sizeof(double));
          if(binary) {
            int one = 1;
            fwrite(&one, sizeof(int), 1, fp);
            fprintf(fp, "\n");
          }
          fprintf(fp, "$EndMeshFormat\n");
        }
      }
      // save the interpolation matrix?
      if(saveInterpolationMatrices && haveInterpolationMatrices()) {
        fprintf(fp, "$InterpolationScheme\n");
        fprintf(fp, "\"INTERPOLATION_SCHEME\"\n");
        fprintf(fp, "%d\n", (int)_interpolation.size());
        for(auto it = _interpolation.begin(); it != _interpolation.end();
            it++) {
          if(it->second.size() >= 2) {
            fprintf(fp, "%d\n2\n", it->first);
            for(int mat = 0; mat < 2; mat++) {
              int m = it->second[mat]->size1(), n = it->second[mat]->size2();
              fprintf(fp, "%d %d\n", m, n);
              for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++)
                  fprintf(fp, "%.16g ", it->second[mat]->get(i, j));
                fprintf(fp, "\n");
              }
            }
          }
        }
        fprintf(fp, "$EndInterpolationScheme\n");
      }
    }

    // save the data
    bool hasMult = (_type == ElementNodeData);
    std::string section = (_type == NodeData) ? "NodeData" :
                          hasMult             ? "ElementNodeData" :
                                                "ElementData";
    fprintf(fp, "$%s\n", section.c_str());
    if(_type != NodeData && saveInterpolationMatrices &&
       haveInterpolationMatrices())
      fprintf(fp, "2\n\"%s\"\n\"INTERPOLATION_SCHEME\"\n", getName().c_str());
    else
      fprintf(fp, "1\n\"%s\"\n", getName().c_str());
    fprintf(fp, "1\n%.16g\n", _steps[step]->getTime());
    if(partitionNum > 0) {
      fprintf(fp, "4\n%zu\n%d\n%d\n%d\n", step, numComp, numEnt, partitionNum);
    }
    else if(_steps[step]->getPartitions().size() == 1) {
      int p = *_steps[step]->getPartitions().begin();
      fprintf(fp, "4\n%zu\n%d\n%d\n%d\n", step, numComp, numEnt, p);
    }
    else {
      fprintf(fp, "3\n%zu\n%d\n%d\n", step, numComp, numEnt);
    }
    bool ok = (version >= 4.2) ?
                writeBlocks(_steps[step], fp, binary, _type, hasMult) :
                writeRecords(_steps[step], fp, version, binary, _type, hasMult);
    if(!ok) {
      fclose(fp);
      return false;
    }
    if(binary) fprintf(fp, "\n");
    fprintf(fp, "$End%s\n", section.c_str());
  }

  fclose(fp);
  return true;
}
