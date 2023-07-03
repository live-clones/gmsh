// Gmsh - Copyright (C) 1997-2023 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "meshRenumber.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "HilbertCurve.h"
#include <queue>

struct SortClass {
  const size_t *_degree;
  bool operator()(const size_t i, const size_t j)
  {
    return _degree[i] < _degree[j];
  }
};

static void RCM(std::vector<size_t> &sorted, const size_t *const row,
                const size_t *const indices)
{
  std::vector<size_t> min; // long long for padding (64bits)
  std::vector<size_t> Nmin;
  std::vector<size_t> degree;
  std::vector<size_t> newIndices;
#pragma omp parallel num_threads(Msg::GetNumThreads())
  {
    unsigned int numThreads = Msg::GetNumThreads();
    unsigned int myThreadID = Msg::GetThreadNum();
#pragma omp single
    {
      min.resize(numThreads, row[sorted.size()] - row[0]);
      Nmin.resize(numThreads, 0);
      degree.resize(sorted.size(), 0);
    }
#pragma omp for
    for(auto i = 0ULL; i < sorted.size(); ++i) {
      degree[i] = row[i + 1] - row[i];
      if(min[myThreadID] > degree[i]) {
        min[myThreadID] = degree[i];
        Nmin[myThreadID] = i;
      }
    }
#pragma omp single
    {
      for(auto i = 0U; i < numThreads; ++i) {
        if(min[0] > min[i]) {
          min[0] = min[i];
          Nmin[0] = Nmin[i];
        }
      }
    }
    SortClass sortClass;
    sortClass._degree = degree.data();

#pragma omp single
    {
      newIndices.resize(row[sorted.size()], 0);
    }
#pragma omp for
    for(auto i = 0ULL; i < sorted.size(); ++i) {
      for(auto j = row[i]; j < row[i + 1]; ++j) { newIndices[j] = indices[j]; }
      std::sort(&newIndices[row[i]], &newIndices[row[i + 1]], sortClass);
    }
  }

  sorted[Nmin[0]] = sorted.size();
  size_t nbrNodesSorted = sorted.size() - 1;

  std::queue<size_t> queue;
  for(auto i = row[Nmin[0]]; i < row[Nmin[0] + 1]; ++i) {
    queue.push(newIndices[i]);
  }

  while(nbrNodesSorted != 0) {
    if(queue.size() != 0) {
      if(sorted[queue.front()] == 0) {
        sorted[queue.front()] = nbrNodesSorted--;
        for(auto i = row[queue.front()]; i < row[queue.front() + 1]; ++i) {
          queue.push(newIndices[i]);
        }
      }
      queue.pop();
    }
    else {
      size_t min = row[sorted.size()] - row[0];
      size_t Nmin = 0;
      for(auto i = 0ULL; i < sorted.size(); ++i) {
        if(min > degree[i] && sorted[i] == 0) {
          min = degree[i];
          Nmin = i;
        }
      }
      queue.push(Nmin);
    }
  }
}

int meshRenumber_Vertices_RCMK(const std::vector<size_t> &_elements,
                               std::map<size_t, size_t> &permutations)
{
  GModel *gm = GModel ::current();
  permutations.clear();

  std::vector<size_t> elements;
  if(_elements.empty()) {
    std::vector<GEntity *> entities;
    gm->getEntities(entities);
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
        MElement *e = ge->getMeshElement(j);
        elements.push_back(e->getNum());
      }
    }
  }
  else
    elements = _elements;

  std::map<MVertex *, size_t> initial_numbering;
  size_t count = 0;
  std::vector<std::pair<size_t, size_t>> coords;
  size_t numbers[1000];
  std::map<std::size_t, MVertex *> inverse_numbering;
  for(auto n : elements) {
    MElement *e = gm->getMeshElementByTag(n);
    for(size_t i = 0; i < e->getNumVertices(); i++) {
      MVertex *v = e->getVertex(i);
      auto it = initial_numbering.find(v);
      if(it == initial_numbering.end()) {
        numbers[i] = count;
        inverse_numbering[count] = v;
        initial_numbering[v] = count++;
      }
      else
        numbers[i] = it->second;
    }
    for(size_t i = 0; i < e->getNumVertices(); i++) {
      for(size_t j = 0; j < e->getNumVertices(); j++) {
        coords.push_back(std::make_pair(numbers[i], numbers[j]));
      }
    }
  }
  std::sort(coords.begin(), coords.end());

  auto last = std::unique(coords.begin(), coords.end());
  coords.erase(last, coords.end());

  std::vector<size_t> ai, aj;
  ai.push_back(0);
  std::size_t line = coords[0].first;
  for(auto c : coords) {
    if(c.first != line) {
      ai.push_back(aj.size());
      line = c.first;
    }
    aj.push_back(c.second);
  }
  ai.push_back(aj.size());

  std::vector<size_t> sorted(count);

  RCM(sorted, &ai[0], &aj[0]);

  for(auto it : initial_numbering) {
    permutations[it.first->getNum()] = sorted[it.second];
  }

  return 0;
}

int meshRenumber_Vertices_Hilbert(const std::vector<size_t> &_elements,
                                  std::map<size_t, size_t> &permutations)
{
  GModel *gm = GModel ::current();
  permutations.clear();

  std::set<MVertex*> allv;
  if(_elements.empty()) {
    std::vector<GEntity *> entities;
    gm->getEntities(entities);
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      for(std::size_t k = 0; k < ge->getNumMeshVertices(); k++) {
        allv.insert(ge->getMeshVertex(k));
      }
    }
  }
  else {
    for(auto n : _elements) {
      MElement *e = gm->getMeshElementByTag(n);
      for(std::size_t k = 0; k < e->getNumVertices(); k++) {
        allv.insert(e->getVertex(k));
      }
    }
  }
  std::vector<MVertex*> v(allv.begin(), allv.end());
  SortHilbert(v);
  for(std::size_t i = 0; i < v.size(); i++) {
    permutations[v[i]->getNum()] = i + 1;
  }

  return 0;
}
