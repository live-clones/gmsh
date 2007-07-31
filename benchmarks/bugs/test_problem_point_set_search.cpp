#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <set>
#include <algorithm>

class MVertex{
private:
  double _x, _y, _z;
public:
  MVertex(double x, double y, double z) : _x(x), _y(y), _z(z) {}
  double x() const {return _x;}
  double y() const {return _y;}
  double z() const {return _z;}
};

class MVertexLessThanLexicographic{
 public:
  static double tolerance;
  bool operator()(const MVertex *v1, const MVertex *v2) const
  {
    printf("v1 = %.16g, %.16g, %.16g +++ v2 = %.16g, %.16g, %.16g\n",
	   v1->x(), v1->y(), v1->z(), v2->x(), v2->y(), v2->z());
    if(v1->x() < v2->x() - tolerance) return true;
    if(v1->x() > v2->x() + tolerance) return false;
    if(v1->y() < v2->y() - tolerance) return true;
    if(v1->y() > v2->y() + tolerance) return false;
    if(v1->z() < v2->z() - tolerance) return true;
    return false;
  }
};

// works
//double MVertexLessThanLexicographic::tolerance = 3.5e-13;

// does not work
double MVertexLessThanLexicographic::tolerance = 2.361143790623519e-13; 

// works
//double MVertexLessThanLexicographic::tolerance = 0.;


int main()
{
  std::set<MVertex*, MVertexLessThanLexicographic> pos;
  pos.insert(new MVertex(0.201, 0.1096015510839149, 0.1096015510839149));
  pos.insert(new MVertex(0.201, 0.1178511301975126, 0.1178511301975126));
  pos.insert(new MVertex(0.201, 0.1261007093115192, 0.1261007093115192));
  pos.insert(new MVertex(0.201, 0.1343502884254441, 0.134350288425444));
  pos.insert(new MVertex(0.201, 0.1432013275392494, 0.05931593201658891));
  pos.insert(new MVertex(0.201, 0.1539799220848939, 0.06378057206071552));
  pos.insert(new MVertex(0.201, 0.155, 0));
  pos.insert(new MVertex(0.201, 0.1647585166310726, 0.06824521210506342));
  pos.insert(new MVertex(0.201, 0.1666666666663197, 0));
  pos.insert(new MVertex(0.201, 0.1755371111771445, 0.07270985214936707));
  pos.insert(new MVertex(0.201, 0.1783333333332177, 0));
  pos.insert(new MVertex(0.201, 0.19, 0));
  pos.insert(new MVertex(0.214333333333449, 0.1096015510839149, 0.1096015510839149));
  pos.insert(new MVertex(0.2143333333333334, 0.1178511301976489, 0.1178511301976489));
  pos.insert(new MVertex(0.2143333333332177, 0.126100709311601, 0.1261007093116009));
  pos.insert(new MVertex(0.2143333333331021, 0.1343502884254441, 0.134350288425444));
  pos.insert(new MVertex(0.2143333333331021, 0.1755371111771445, 0.07270985214936707));
  pos.insert(new MVertex(0.214333333333449, 0.1432013275392494, 0.05931593201658891));
  pos.insert(new MVertex(0.2143333333333334, 0.153979922085072, 0.0637805720607893));
  pos.insert(new MVertex(0.214333333333449, 0.155, 0));
  pos.insert(new MVertex(0.2143333333332177, 0.1647585166311795, 0.06824521210510767));
  pos.insert(new MVertex(0.2143333333333334, 0.1666666666665125, 0));
  pos.insert(new MVertex(0.2143333333332177, 0.1783333333333333, 0));
  pos.insert(new MVertex(0.2143333333331021, 0.19, 0));
  pos.insert(new MVertex(0.2276666666668209, 0.1178511301977852, 0.1178511301977852));
  pos.insert(new MVertex(0.2276666666666282, 0.1261007093116827, 0.1261007093116827));
  pos.insert(new MVertex(0.2276666666664354, 0.1343502884254441, 0.134350288425444));
  pos.insert(new MVertex(0.2276666666666282, 0.1647585166312863, 0.06824521210515193));
  pos.insert(new MVertex(0.2276666666664354, 0.1755371111771445, 0.07270985214936707));
  pos.insert(new MVertex(0.2276666666668209, 0.1539799220852501, 0.06378057206086306));
  pos.insert(new MVertex(0.2276666666668209, 0.1666666666667052, 0));
  pos.insert(new MVertex(0.2276666666666282, 0.178333333333449, 0));
  pos.insert(new MVertex(0.2276666666664354, 0.19, 0));
  pos.insert(new MVertex(0.2276666666670136, 0.1096015510839149, 0.1096015510839149));
  pos.insert(new MVertex(0.2276666666670136, 0.1432013275392494, 0.05931593201658891));
  pos.insert(new MVertex(0.2276666666670136, 0.155, 0));
  pos.insert(new MVertex(0.241, 0.1096015510839149, 0.1096015510839149));
  pos.insert(new MVertex(0.241, 0.1178511301979215, 0.1178511301979215));
  pos.insert(new MVertex(0.241, 0.1261007093117645, 0.1261007093117645));
  pos.insert(new MVertex(0.241, 0.1343502884254441, 0.134350288425444));
  pos.insert(new MVertex(0.241, 0.1432013275392494, 0.05931593201658891));
  pos.insert(new MVertex(0.241, 0.1539799220854282, 0.06378057206093682));
  pos.insert(new MVertex(0.241, 0.155, 0));
  pos.insert(new MVertex(0.241, 0.1647585166313932, 0.06824521210519618));
  pos.insert(new MVertex(0.241, 0.166666666666898, 0));
  pos.insert(new MVertex(0.241, 0.1755371111771445, 0.07270985214936707));
  pos.insert(new MVertex(0.241, 0.1783333333335646, 0));
  pos.insert(new MVertex(0.241, 0.19, 0));
  
  printf("set contains %d points\n", pos.size());

  MVertex tmp(0.214333333333449, 0.1096015510839149, 0.1096015510839149);
  std::set<MVertex*, MVertexLessThanLexicographic>::iterator itp = pos.find(&tmp);
  if(itp == pos.end()){
    printf("NOT FOUND!\n");
  }
  else{
    printf("found: %.16g %.16g %.16g\n", (*itp)->x(), (*itp)->y(), (*itp)->z());
  }

}
