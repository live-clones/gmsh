// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#pragma once

#include <unordered_map>
#include <vector>
#include <algorithm>

int getAppetiteForMotion(MVertex *v);

#include <unordered_map>
#include <algorithm>

class degeneratedVertices {
  // Union-Find
  std::unordered_map<MVertex *, MVertex *> parent;
  std::unordered_map<MVertex *, int> ufRank; // rang UF (hauteur/size)

  // Meilleur représentant "par appétit" pour chaque racine
  std::unordered_map<MVertex *, MVertex *>
    best; // root -> vertex au max appétit
  std::unordered_map<MVertex *, int>
    bestAppetite; // root -> valeur d’appétit max

  degeneratedVertices() = default;

  void make_set(MVertex *x)
  {
    if(parent.count(x)) return;
    parent[x] = x;
    ufRank[x] = 0;
    best[x] = x;
    bestAppetite[x] =
      getAppetiteForMotion(x); // snapshot (voir note ci-dessous)
  }

  MVertex *findRoot(MVertex *x)
  {
    auto it = parent.find(x);
    if(it == parent.end()) make_set(x);
    if(parent[x] == x) return x;
    parent[x] = findRoot(parent[x]);
    return parent[x];
  }

public:
  degeneratedVertices(const degeneratedVertices &) = delete;
  degeneratedVertices &operator=(const degeneratedVertices &) = delete;

  static degeneratedVertices &instance()
  {
    static degeneratedVertices instance_;
    return instance_;
  }

  void initialize()
  {
    parent.clear();
    ufRank.clear();
    best.clear();
    bestAppetite.clear();
  }

  // Union avec priorité = max(appétit) sur la composante
  void add(MVertex *a, MVertex *b)
  {
    MVertex *ra = findRoot(a);
    MVertex *rb = findRoot(b);
    if(ra == rb) return;

    // Choisir le root "gagnant" : celui dont le bestAppetite est plus grand
    int appA = bestAppetite[ra];
    int appB = bestAppetite[rb];

    // on veut ra = root gagnant
    if(appA < appB) {
      std::swap(ra, rb);
      std::swap(appA, appB);
    }

    // égalité : tie-break avec ufRank
    if(appA == appB && ufRank[ra] < ufRank[rb]) std::swap(ra, rb);

    // rattacher rb -> ra
    parent[rb] = ra;
    if(appA == appB && ufRank[ra] == ufRank[rb]) ufRank[ra]++;

    // Mettre à jour le "meilleur" de la composante ra
    if(bestAppetite[rb] > bestAppetite[ra]) {
      best[ra] = best[rb];
      bestAppetite[ra] = bestAppetite[rb];
    }
    // Nettoyage optionnel : on peut effacer les entrées rb si on veut
    // best.erase(rb); bestAppetite.erase(rb); ufRank.erase(rb); // pas
    // obligatoire
  }

  // Racine UF (technique)
  MVertex *find(MVertex *x) { return findRoot(x); }

  // Représentant "prioritaire" (celui au plus grand appétit) de la famille de x
  MVertex *representative(MVertex *x)
  {
    MVertex *r = findRoot(x);
    return best[r];
  }

  // Appétit du représentant (utile si tu veux le comparer)
  int representativeAppetite(MVertex *x)
  {
    MVertex *r = findRoot(x);
    return bestAppetite[r];
  }

  // Optionnel : pré-enregistrer un ensemble de sommets (pour éviter la init
  // paresseuse)
  void seed(const std::vector<MVertex *> &vs)
  {
    for(auto *v : vs) make_set(v);
  }
};

void removeAllMeshEntitiesThatHaveSmallEdges();
