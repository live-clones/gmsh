// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "meshRenumber.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "GmshConfig.h"
#include "HilbertCurve.h"
#include <queue>
#include <cmath>

#if defined(HAVE_METIS)
#include "metis.h"
#endif

#define DIFF(x, y) (x > y ? x - y : y - x)

template <typename T>
static T bandwidth(std::vector<T> &ai, std::vector<T> &aj, T *p = nullptr)
{
  T maxdx = 0;
  for(size_t i = 0; i < ai.size() - 1; i++) {
    for(T j = ai[i]; j < ai[i + 1]; j++) {
      T dx = p ? DIFF(p[aj[j]], p[i]) : DIFF(aj[j], (T)i);
      if(dx > maxdx) maxdx = dx;
    }
  }
  return maxdx;
}

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
  // Adapted from GmshFEM - Copyright (C) 2019-2022, A. Royer, E. Béchet,
  // C. Geuzaine, Université de Liège

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

template <typename T>
static void
createVertexToVertexGraph(GModel *gm,
                          const std::vector<std::size_t> &elementTags,
                          std::map<MVertex *, std::size_t> &initial_numbering,
                          std::map<std::size_t, MVertex *> &invert_numbering,
                          std::vector<T> &ai, std::vector<T> &aj)
{
  ai.clear();
  aj.clear();
  initial_numbering.clear();

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

  std::size_t count = 0;
  std::vector<std::pair<T, T>> coords;
  std::size_t numbers[1000];
  for(auto e : elements) {
    for(std::size_t i = 0; i < e->getNumVertices(); i++) {
      MVertex *v = e->getVertex(i);
      auto it = initial_numbering.find(v);
      if(it == initial_numbering.end()) {
        numbers[i] = count;
        invert_numbering[count] = v;
        initial_numbering[v] = count++;
      }
      else
        numbers[i] = it->second;
    }
    for(std::size_t i = 0; i < e->getNumVertices(); i++) {
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        if(i != j) coords.push_back(std::make_pair(numbers[i], numbers[j]));
      }
    }
  }
  std::sort(coords.begin(), coords.end());

  auto last = std::unique(coords.begin(), coords.end());
  coords.erase(last, coords.end());

  ai.push_back(0);
  T line = coords[0].first;
  for(auto c : coords) {
    if(c.first != line) {
      ai.push_back((T)aj.size());
      line = c.first;
    }
    aj.push_back(c.second);
  }
  ai.push_back((T)aj.size());
}

int meshRenumber_Vertices_RCMK(const std::vector<std::size_t> &elementTags,
                               std::map<std::size_t, std::size_t> &permutations)
{
  GModel *gm = GModel ::current();
  permutations.clear();

  Msg::Info("RCMK renumbering...");

  std::map<MVertex *, std::size_t> initial_numbering;
  std::map<std::size_t, MVertex *> inverse_numbering;
  std::vector<std::size_t> ai, aj;
  createVertexToVertexGraph(gm, elementTags, initial_numbering,
                            inverse_numbering, ai, aj);

  //  int before = bandwidth(ai, aj);

  std::vector<std::size_t> sorted(initial_numbering.size());

  RCM(sorted, &ai[0], &aj[0]);

  int after = bandwidth(ai, aj, &sorted[0]);

  for(auto it : initial_numbering) {
    permutations[it.first->getNum()] = sorted[it.second];
  }

  Msg::Info("Done RCMK renumbering (bandwidth is now %d)",
            after);

  return 0;
}

int meshRenumber_Vertices_Hilbert(
  const std::vector<std::size_t> &elementTags,
  std::map<std::size_t, std::size_t> &permutations)
{
  GModel *gm = GModel ::current();
  permutations.clear();

  Msg::Info("Hilbert renumbering...");

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

  SortHilbert_Without_Brio(v);

  for(std::size_t i = 0; i < v.size(); i++) {
    permutations[v[i]->getNum()] = i + 1;
  }

  Msg::Info("Done Hilbert renumbering");

  return 0;
}

int meshRenumber_Vertices_Metis(
  const std::vector<std::size_t> &elementTags,
  std::map<std::size_t, std::size_t> &permutations)
{
  permutations.clear();

#if defined(HAVE_METIS)

  Msg::Info("METIS renumbering (nested dissection)...");

  GModel *gm = GModel ::current();
  std::map<MVertex *, std::size_t> initial_numbering;
  std::map<std::size_t, MVertex *> invert_numbering;
  std::vector<idx_t> ai, aj;
  createVertexToVertexGraph(gm, elementTags, initial_numbering,
                            invert_numbering, ai, aj);

  idx_t n = (idx_t)initial_numbering.size();
  idx_t *xadj = &ai[0];
  idx_t *adjncy = &aj[0];
  idx_t *perm = new idx_t[n];
  idx_t *iperm = new idx_t[n];
  int result = METIS_NodeND(&n, xadj, adjncy, nullptr, nullptr, perm, iperm);

  if(result != METIS_OK) {
    delete[] perm;
    delete[] iperm;
    Msg::Warning("Renumbering with METIS failed");
    return -1;
  }

  for(auto it : initial_numbering) {
    permutations[it.first->getNum()] = iperm[it.second] + 1;
  }
  delete[] perm;
  delete[] iperm;

  Msg::Info("Done METIS renumbering");

#else

  Msg::Error("Gmsh must be compiled with METIS support for METIS renumbering");

#endif

  return 0;
}
