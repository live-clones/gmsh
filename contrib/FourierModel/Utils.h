#ifndef _UTILS_H_
#define _UTILS_H_

#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>

std::vector<double> SolveCubic(double a, double b, double c);
std::vector<double> SolveCubic(double a, double b, double c, double d);
std::vector<std::vector<int> > ones(int row, int col);
void plotSceneViewer(int app, char* bffer, std::vector<int>& color,
                      std::vector<std::vector<double> > &x,
                      std::vector<std::vector<double> > &y,
                      std::vector<std::vector<double> > &z, int ROW, int COL,
                      std::vector<std::vector<int> > &mask);

#endif
