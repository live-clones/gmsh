// Gmsh - Copyright (C) 1997-2023 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "meshRenumber.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "HilbertCurve.h"
#include <queue>

// RCM routine adapted from GmshFEM - Copyright (C) 2019-2022, A. Royer,
// E. Béchet, C. Geuzaine, Université de Liège

struct SortClass {
  const std::size_t *_degree;
  bool operator()(const std::size_t i, const std::size_t j)
  {
    return _degree[i] < _degree[j];
  }
};

static void RCM(std::vector<std::size_t> &sorted, const std::size_t *const row,
                const std::size_t *const indices)
{
  std::vector<std::size_t> min; // long long for padding (64bits)
  std::vector<std::size_t> Nmin;
  std::vector<std::size_t> degree;
  std::vector<std::size_t> newIndices;
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
  std::size_t nbrNodesSorted = sorted.size() - 1;

  std::queue<std::size_t> queue;
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
      std::size_t min = row[sorted.size()] - row[0];
      std::size_t Nmin = 0;
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

int meshRenumber_Vertices_RCMK(const std::vector<std::size_t> &elementTags,
                               std::map<std::size_t, std::size_t> &permutations)
{
  GModel *gm = GModel ::current();
  permutations.clear();

  std::vector<MElement *> elements;
  if(elementTags.empty()) {
    std::vector<GEntity *> entities;
    gm->getEntities(entities);
    for(auto ge : entities) {
      for(std::size_t j = 0; j < ge->getNumMeshElements(); j++) {
        elements.push_back(ge->getMeshElement(j));
      }
    }
  }
  else {
    for(auto n : elementTags) elements.push_back(gm->getMeshElementByTag(n));
  }

  std::map<MVertex *, std::size_t> initial_numbering;
  std::size_t count = 0;
  std::vector<std::pair<std::size_t, std::size_t>> coords;
  std::size_t numbers[1000];
  std::map<std::size_t, MVertex *> inverse_numbering;
  for(auto e : elements) {
    for(std::size_t i = 0; i < e->getNumVertices(); i++) {
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
    for(std::size_t i = 0; i < e->getNumVertices(); i++) {
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        coords.push_back(std::make_pair(numbers[i], numbers[j]));
      }
    }
  }
  std::sort(coords.begin(), coords.end());

  auto last = std::unique(coords.begin(), coords.end());
  coords.erase(last, coords.end());

  std::vector<std::size_t> ai, aj;
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

  std::vector<std::size_t> sorted(count);

  RCM(sorted, &ai[0], &aj[0]);

  for(auto it : initial_numbering) {
    permutations[it.first->getNum()] = sorted[it.second];
  }

  return 0;
}

int meshRenumber_Vertices_Hilbert(
  const std::vector<std::size_t> &elementTags,
  std::map<std::size_t, std::size_t> &permutations)
{
  GModel *gm = GModel ::current();
  permutations.clear();

  std::set<MVertex *> allv;
  if(elementTags.empty()) {
    std::vector<GEntity *> entities;
    gm->getEntities(entities);
    for(auto ge : entities) {
      for(std::size_t k = 0; k < ge->getNumMeshVertices(); k++) {
        allv.insert(ge->getMeshVertex(k));
      }
    }
  }
  else {
    for(auto n : elementTags) {
      MElement *e = gm->getMeshElementByTag(n);
      for(std::size_t k = 0; k < e->getNumVertices(); k++) {
        allv.insert(e->getVertex(k));
      }
    }
  }

  std::vector<MVertex *> v(allv.begin(), allv.end());
  SortHilbert(v);
  for(std::size_t i = 0; i < v.size(); i++) {
    permutations[v[i]->getNum()] = i + 1;
  }

  return 0;
}
