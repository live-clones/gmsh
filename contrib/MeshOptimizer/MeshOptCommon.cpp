// MeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

#include <iostream>
#include <fstream>
#include <list>
#include <string.h>
#include "MElement.h"
#include "MeshOptCommon.h"

#ifdef HAVE_NCURSES

#include "ncurses.h"
void catchPause()
{
  timeout(0);
  if(getch() == ' ') { mvpause(); }
};

void mvinit()
{
  initscr();
  start_color();
  noecho();
  curs_set(FALSE);
  timeout(0);
  init_pair(0, COLOR_WHITE, COLOR_BLACK);
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_BLACK, COLOR_YELLOW);
  init_pair(3, COLOR_RED, COLOR_WHITE);
  init_pair(4, COLOR_GREEN, COLOR_WHITE);
  init_pair(5, COLOR_BLUE, COLOR_WHITE);
  init_pair(6, COLOR_RED, COLOR_BLACK);
  init_pair(7, COLOR_GREEN, COLOR_BLACK);
  init_pair(8, COLOR_BLUE, COLOR_BLACK);
}
void mvterminate() { endwin(); }

void mvgetScreenSize(int &nbRow, int &nbCol) { getmaxyx(stdscr, nbRow, nbCol); }

void mvbold(bool on)
{
  if(on)
    attron(A_BOLD);
  else
    attroff(A_BOLD);
}

void mvcolor(int colorScheme, bool on)
{
  if(on)
    attron(COLOR_PAIR(colorScheme));
  else
    attroff(COLOR_PAIR(colorScheme));
}

void mvpause()
{
  attron(COLOR_PAIR(1));
  attron(A_BOLD);
  mvprintCenter(-1, " PAUSED (PRESS SPACE TO CONTINUE) ");
  attroff(COLOR_PAIR(1));
  attroff(A_BOLD);
  timeout(-1);
  while(getch() != ' ') {}
  mvfillRow(-1);
}

void mvprintCenter(int row, const char *fmt, ...)
{
  catchPause();
  char str[1000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);
  int nbRow, nbCol;
  getmaxyx(stdscr, nbRow, nbCol);
  if(row < 0) row = nbRow + row;
  mvprintw(row, (nbCol - strlen(str)) / 2, str, args);
  refresh();
}

void mvprintLeft(int row, const char *fmt, ...)
{
  catchPause();
  char str[1000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);
  int nbRow, nbCol;
  getmaxyx(stdscr, nbRow, nbCol);
  if(row < 0) row = nbRow + row;
  mvprintw(row, 0, str, args);
  refresh();
}

void mvprintRight(int row, const char *fmt, ...)
{
  catchPause();
  char str[1000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);
  int nbRow, nbCol;
  getmaxyx(stdscr, nbRow, nbCol);
  if(row < 0) row = nbRow + row;
  mvprintw(row, nbCol - strlen(str), str, args);
  refresh();
}

void mvprintXY(int row, int col, const char *fmt, ...)
{
  catchPause();
  char str[1000];
  va_list args;
  va_start(args, fmt);
  vsnprintf(str, sizeof(str), fmt, args);
  va_end(args);
  int nbRow, nbCol;
  getmaxyx(stdscr, nbRow, nbCol);
  if(row < 0) row = nbRow + row;
  if(col < 0) col = nbCol + col;
  mvprintw(row, col, str, args);
  refresh();
}

void mvprintList(int row, int maxSize, std::list<char *> listStr,
                 int colorScheme)
{
  int nbRow, nbCol;
  getmaxyx(stdscr, nbRow, nbCol);
  if(row < 0) row = nbRow + row;
  int i = 0;
  for(std::list<char *>::iterator it = listStr.begin(); it != listStr.end();
      it++) {
    if(i >= abs(maxSize)) break;
    if(colorScheme == 1) {
      if(*it == listStr.back())
        attron(COLOR_PAIR(2));
      else
        attron(COLOR_PAIR(1));
    }
    if(colorScheme == 2) {
      if(i % 2 == 0) attron(COLOR_PAIR(1));
    }
    mvprintLeft(row + maxSize / abs(maxSize) * i, *it);
    if(colorScheme == 1) {
      if(*it == listStr.back())
        attroff(COLOR_PAIR(2));
      else
        attroff(COLOR_PAIR(1));
    }
    if(colorScheme == 2) {
      if(i % 2 == 0) attroff(COLOR_PAIR(1));
    }
    i++;
  }
  while(i < abs(maxSize)) { mvfillRow(row + maxSize / abs(maxSize) * i++); }
}

void mvfillRow(int row, char fillWith)
{
  int nbRow, nbCol;
  getmaxyx(stdscr, nbRow, nbCol);
  if(row < 0) row = nbRow + row;
  char toFill[1] = {fillWith};
  for(int k = 0; k < nbCol; k++) mvprintXY(row, k, toFill);
}

#else

void catchPause()
{
  Msg::Error(
    "Gmsh should be configured with ncurses to use enhanced interface");
}
void mvinit()
{
  Msg::Error(
    "Gmsh should be configured with ncurses to use enhanced interface");
}
void mvterminate()
{
  Msg::Error(
    "Gmsh should be configured with ncurses to use enhanced interface");
}
void mvgetScreenSize(int &nbRow, int &nbCol)
{
  Msg::Error(
    "Gmsh should be configured with ncurses to use enhanced interface");
}
void mvbold(bool on)
{
  Msg::Error(
    "Gmsh should be configured with ncurses to use enhanced interface");
}
void mvcolor(int colorScheme, bool on)
{
  Msg::Error(
    "Gmsh should be configured with ncurses to use enhanced interface");
}
void mvpause()
{
  Msg::Error(
    "Gmsh should be configured with ncurses to use enhanced interface");
}
void mvprintCenter(int row, const char *fmt, ...)
{
  Msg::Error(
    "Gmsh should be configured with ncurses to use enhanced interface");
}
void mvprintLeft(int row, const char *fmt, ...)
{
  Msg::Error(
    "Gmsh should be configured with ncurses to use enhanced interface");
}
void mvprintRight(int row, const char *fmt, ...)
{
  Msg::Error(
    "Gmsh should be configured with ncurses to use enhanced interface");
}
void mvprintXY(int row, int col, const char *fmt, ...)
{
  Msg::Error(
    "Gmsh should be configured with ncurses to use enhanced interface");
}
void mvprintList(int row, int maxSize, std::list<char *> listStr,
                 int colorScheme)
{
  Msg::Error(
    "Gmsh should be configured with ncurses to use enhanced interface");
}
void mvfillRow(int row, char fillWith)
{
  Msg::Error(
    "Gmsh should be configured with ncurses to use enhanced interface");
}

#endif

redirectMessage::redirectMessage(std::string logFileName, bool console)
{
  std::ofstream logFile;
  _logFileName = logFileName;
  _console = console;
  if(logFileName.compare("") != 0) {
    logFile.open(_logFileName.c_str());
    logFile.close();
  }
}

void redirectMessage::operator()(std::string level, std::string message)
{
  std::ofstream logFile;
  if(_logFileName.compare("") != 0) {
    logFile.open(_logFileName.c_str(), std::ios::app);
    logFile << level << "    : " << message << std::endl;
    logFile.close();
  }
  if(_console) {
    fprintf(stdout, "%s    : %s\n", level.c_str(), message.c_str());
    fflush(stdout);
  }
}

namespace {

  // Test intersection between sphere and segment
  bool testSegSphereIntersect(SPoint3 A, SPoint3 B, const SPoint3 &P,
                              const double rr)
  {
    // Test if separating plane between sphere and segment vertices
    // For each vertex, separation if vertex is outside sphere and P on opposite
    // side to other seg. vertex w.r.t plane of normal (vertex-P) through vertex
    const SVector3 PA(P, A), PB(P, B);
    const double aa = dot(PA, PA), ab = dot(PA, PB);
    if((aa > rr) & (ab > aa)) return false;
    const double bb = dot(PB, PB);
    if((bb > rr) & (ab > bb)) return false;

    // Test if separating plane between sphere and line
    // For A, separation if projection Q of P on (AB) lies outside the sphere
    const SVector3 AB(A, B);
    const double d = ab - aa, e = dot(AB, AB);
    const SVector3 PQ = PA * e - d * AB;
    if(dot(PQ, PQ) > rr * e * e) return false;

    // Return true (intersection) if no separation at all
    return true;
  }

  // Test intersection between sphere and triangle
  // Inspired by Christer Ericson,
  // http://realtimecollisiondetection.net/blog/?p=103
  bool testTriSphereIntersect(SPoint3 A, SPoint3 B, SPoint3 C, const SPoint3 &P,
                              const double rr)
  {
    // Test if separating plane between sphere and triangle plane
    const SVector3 PA(P, A), AB(A, B), AC(A, C);
    const SVector3 V = crossprod(AB, AC); // Normal to triangle plane
    const double d =
      dot(PA, V); // Dist. from P to triangle plane times norm of V
    const double e = dot(V, V); // Norm of V
    if(d * d > rr * e)
      return false; // Test if separating plane between sphere and triangle
                    // plane

    // Test if separating plane between sphere and triangle vertices
    const SVector3 PB(P, B), PC(P, B);
    const double aa = dot(PA, PA), ab = dot(PA, PB), ac = dot(PA, PC);
    const double bb = dot(PB, PB), bc = dot(PB, PC), cc = dot(PC, PC);
    if((aa > rr) & (ab > aa) & (ac > aa))
      return false; // For each triangle vertex, separation if vertex is outside
                    // sphere
    if((bb > rr) & (ab > bb) & (bc > bb))
      return false; // and P on opposite side to other two triangle vertices
                    // w.r.t
    if((cc > rr) & (ac > cc) & (bc > cc))
      return false; // plane of normal (vertex-P) through vertex

    // Test if separating plane between sphere and triangle edges
    const SVector3 BC(B, C);
    const double d1 = ab - aa, d2 = bc - bb, d3 = ac - cc;
    const double e1 = dot(AB, AB), e2 = dot(BC, BC), e3 = dot(AC, AC);
    const SVector3 PQ1 = PA * e1 - d1 * AB; // Q1 projection of P on line (AB)
    const SVector3 PQ2 = PB * e2 - d2 * BC; // Q2 projection of P on line (BC)
    const SVector3 PQ3 = PC * e3 + d3 * AC; // Q3 projection of P on line (AC)
    const SVector3 PQC = PC * e1 - PQ1;
    const SVector3 PQA = PA * e2 - PQ2;
    const SVector3 PQB = PB * e3 - PQ3;
    if((dot(PQ1, PQ1) > rr * e1 * e1) & (dot(PQ1, PQC) > 0))
      return false; // For A, separation if Q lies outside the sphere and if P
                    // and C
    if((dot(PQ2, PQ2) > rr * e2 * e2) & (dot(PQ2, PQA) > 0))
      return false; // are on opposite sides of plane through AB with normal PQ
    if((dot(PQ3, PQ3) > rr * e3 * e3) & (dot(PQ3, PQB) > 0))
      return false; // Same for other two vertices

    // Return true (intersection) if no separation at all
    return true;
  }

} // namespace

// Test of intersection element with circle/sphere
bool MeshOptPatchDef::testElInDist(const SPoint3 &P, double limDist,
                                   MElement *el) const
{
  const double limDistSq = limDist * limDist;

  if(el->getDim() == 2) { // 2D?
    for(int iEd = 0; iEd < el->getNumEdges();
        iEd++) { // Loop over edges of element
      std::vector<MVertex *> edgeVert;
      el->getEdgeVertices(iEd, edgeVert);
      const SPoint3 A = edgeVert[0]->point();
      const SPoint3 B = edgeVert[1]->point();
      if(testSegSphereIntersect(A, B, P, limDistSq)) return true;
    }
  }
  else { // 3D
    for(int iFace = 0; iFace < el->getNumFaces();
        iFace++) { // Loop over faces of element
      std::vector<MVertex *> faceVert;
      el->getFaceVertices(iFace, faceVert);
      const SPoint3 A = faceVert[0]->point();
      const SPoint3 B = faceVert[1]->point();
      const SPoint3 C = faceVert[2]->point();
      if(faceVert.size() == 3) {
        if(testTriSphereIntersect(A, B, C, P, limDistSq)) return true;
      }
      else {
        const SPoint3 D = faceVert[3]->point();
        if(testTriSphereIntersect(A, B, C, P, limDistSq) ||
           testTriSphereIntersect(A, C, D, P, limDistSq))
          return true;
      }
    }
  }

  return false;
}
