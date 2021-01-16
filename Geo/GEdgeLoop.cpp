// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <functional>
#include "GEdgeLoop.h"
#include "GmshMessage.h"

void GEdgeSigned::print() const
{
  if(getBeginVertex() && getEndVertex())
    Msg::Info("Curve %d sign %d, begin point %d, end point %d", ge->tag(),
              _sign, getBeginVertex()->tag(), getEndVertex()->tag());
  else
    Msg::Info("Curve %d sign %d, no begin or end points", ge->tag(), _sign);
}

int countInList(std::list<GEdge *> &wire, GEdge *ge)
{
  return std::count(wire.begin(), wire.end(), ge);
}

GEdgeSigned nextOne(GEdgeSigned *thisOne, std::list<GEdge *> &wire)
{
  if(!thisOne) {
    GEdge *ge = *(wire.begin());
    wire.erase(wire.begin());
    return GEdgeSigned(1, ge);
  }

  GVertex *gv = thisOne->getEndVertex();

  std::list<GEdge *> possibleChoices;

  auto it = wire.begin();
  auto ite = wire.end();
  while(it != ite) {
    GEdge *ge = *it;
    GVertex *v1 = ge->getBeginVertex();
    GVertex *v2 = ge->getEndVertex();
    if(v1 == gv || v2 == gv) possibleChoices.push_back(ge);
    ++it;
  }
  it = possibleChoices.begin();
  ite = possibleChoices.end();
  while(it != ite) {
    GEdge *ge = *it;
    if(countInList(possibleChoices, ge) == 2) {
      wire.erase(std::remove_if(wire.begin(), wire.end(),
                                std::bind2nd(std::equal_to<GEdge *>(), ge)),
                 wire.end());
      wire.push_back(ge);
      GVertex *v1 = ge->getBeginVertex();
      GVertex *v2 = ge->getEndVertex();
      if(v1 == gv) return GEdgeSigned(1, ge);
      if(v2 == gv) return GEdgeSigned(-1, ge);
      Msg::Error("Something wrong in curve loop 1");
      thisOne->print();
    }
    ++it;
  }
  it = possibleChoices.begin();
  ite = possibleChoices.end();
  while(it != ite) {
    GEdge *ge = *it;
    if(ge != thisOne->ge) {
      wire.erase(std::remove_if(wire.begin(), wire.end(),
                                std::bind2nd(std::equal_to<GEdge *>(), ge)),
                 wire.end());
      GVertex *v1 = ge->getBeginVertex();
      GVertex *v2 = ge->getEndVertex();
      if(v1 == gv) return GEdgeSigned(1, ge);
      if(v2 == gv) return GEdgeSigned(-1, ge);
      Msg::Error("Something wrong in curve loop 2");
      thisOne->print();
    }
    ++it;
  }

  // should never end up here
  return GEdgeSigned(0, nullptr);
}

int GEdgeLoop::count(GEdge *ge) const
{
  int count = 0;
  for(auto it = begin(); it != end(); ++it) {
    if(it->ge == ge) count++;
  }
  return count;
}

void GEdgeLoop::print() const
{
  for(auto it = begin(); it != end(); ++it) { it->print(); }
}

void GEdgeLoop::getEdges(std::vector<GEdge *> &edges) const
{
  edges.clear();
  for(auto it = begin(); it != end(); ++it) { edges.push_back(it->getEdge()); }
}

void GEdgeLoop::getSigns(std::vector<int> &signs) const
{
  signs.clear();
  for(auto it = begin(); it != end(); ++it) { signs.push_back(it->getSign()); }
}

static void loopTheLoop(std::list<GEdge *> &wire, std::list<GEdgeSigned> &loop,
                        GEdge **degeneratedToInsert)
{
  GEdgeSigned *prevOne = nullptr;
  GEdgeSigned ges(0, nullptr);

  while(wire.size()) {
    if(prevOne && (*degeneratedToInsert) &&
       (*degeneratedToInsert)->getBeginVertex() == prevOne->getEndVertex()) {
      ges = GEdgeSigned(1, *degeneratedToInsert);
      *degeneratedToInsert = nullptr;
      // printf("second degenerated edge inserted\n");
    }
    else
      ges = nextOne(prevOne, wire);
    if(ges.getSign() == 0) { // oops
      Msg::Debug("no sign in wire of size=%d: aborting loop construction");
      break;
    }
    prevOne = &ges;
    // ges.print();
    loop.push_back(ges);
  }
}

GEdgeLoop::GEdgeLoop(const std::vector<GEdge *> &cwire)
{
  // Sometimes OCC puts a nasty degenerated edge in the middle of the
  // wire ...  pushing it to front fixes the problem as it concerns
  // gmsh
  std::list<GEdge *> wire;
  std::vector<GEdge *> degenerated;
  GEdge *degeneratedToInsert = nullptr;
  for(auto it = cwire.begin(); it != cwire.end(); ++it) {
    GEdge *ed = *it;
    if(ed->degenerate(0))
      degenerated.push_back(ed);
    else
      wire.push_back(ed);
  }

  if(degenerated.size() == 1) { wire.push_front(degenerated[0]); }
  else if(degenerated.size() == 2) {
    degeneratedToInsert = degenerated[1];
    wire.push_front(degenerated[0]);
  }
  else if(degenerated.size() > 2) {
    Msg::Warning(
      "More than two degenerated edges in one model face of an OCC model");
  }

  while(!wire.empty()) { loopTheLoop(wire, loop, &degeneratedToInsert); }
}
