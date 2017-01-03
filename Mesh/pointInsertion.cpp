// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributed by Paul-Emile Bernard

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "pointInsertion.h"
#include "BackgroundMeshManager.h"
#include "BackgroundMesh2D.h"
#include "BackgroundMesh3D.h"
#include "GFace.h"
#include "GRegion.h"
#include "OS.h"
#include "Context.h"
#include "meshGRegion.h"
#include "pointInsertionRTreeTools.h"
#include "intersectCurveSurface.h"

//#include "google/profiler.h"

using namespace std;

bool old_algo_hexa(){
  return true;
}

template<typename T>
void print_nodal_info(string filename, map<MVertex*, T> &mapp)
{
  ofstream out(filename.c_str());

  out << "View \"\"{" << endl;
  for (typename map<MVertex*, T>::iterator it = mapp.begin();it!=mapp.end();it++){
    MVertex *v = it->first;
    out << "SP( " << v->x() << "," << v->y() << "," << v->z() << "){" << it->second << "};" << endl;;
  }
  out << "};" << endl;

  out.close();
}

bool shoot(const SPoint2 &start, const SPoint2 &dir,
           const double &h, SPoint2 &res)
{
  const int RK = 1;

  if (RK==1){
    res = start + (dir*h);
    //    cout << "(" << start[0] << "," <<start[1] << ") -> (" << res[0] << ","
    //    <<res[1] << ") " << endl;
    return true;
  }

  return false;
}

bool computeFourNeighbors (frameFieldBackgroundMesh2D *bgm,
                           MVertex *v_center, // the vertex for which we want to
                                              // generate 4 neighbors (real
                                              // vertex (xyz), not parametric!)
                           SPoint2 &midpoint,
                           bool goNonLinear, // do we compute the position in
                                             // the real surface which is
                                             // nonlinear
                           SPoint2 newP[4][NUMDIR], // look into other directions
                           SMetric3 &metricField) // the mesh metric
{
  // we assume that v is on surface gf, and backgroundMesh2D has been created based on gf

  // get BGM and GFace
  GFace *gf = dynamic_cast<GFace*>(bgm->getBackgroundGEntity());

  // get the parametric coordinates of the point on the surface
  reparamMeshVertexOnFace(v_center, gf, midpoint);

  // get RK info on midpoint (infos in two directions...)
  RK_form infos;
  bgm->compute_RK_infos(midpoint[0],midpoint[1],v_center->x(), v_center->y(),
                        v_center->z(), infos);
  metricField = infos.metricField;

  // shoot in four directions
  SPoint2 param_vec;
  double h;
  for (int i=0;i<4;i++){// in four directions
    switch (i){
    case 0:
      param_vec = infos.paramt1;
      h = infos.paramh.first;
      break;
    case 1:
      param_vec = infos.paramt2;
      h = infos.paramh.second;
      break;
    case 2:
      param_vec = infos.paramt1 * -1.;
      h = infos.paramh.first;
      break;
    case 3:
      param_vec = infos.paramt2 * -1.;
      h = infos.paramh.second;
      break;
    }
    shoot(midpoint,param_vec,h,newP[i][0]);
    //    cout << "(" << midpoint[0] << "," <<midpoint[1] << ") -> (" <<
    //    newP[i][0][0] << "," << newP[i][0][1] << ") " << endl;
  }

  // the following comes from surfaceFiller.cpp...
  const double EPS = 1.e-7;
  for (int j=0;j<2;j++){
    for (int i=0;i<4;i++){
      newP[i][0][j] += (EPS* (double)rand() / RAND_MAX);
    }
  }

  // We could stop here. Yet, if the metric varies a lot, we can solve a
  // nonlinear problem in order to find a better approximation in the real
  // surface
  if (1 && goNonLinear){
    double L = infos.localsize;
    double newPoint[4][2];
    for (int j=0;j<2;j++){
      for (int i=0;i<4;i++){
        newPoint[i][j] = newP[i][0][j];
      }
    }
    double ERR[4];
    for (int i=0;i<4;i++){                                              //
      //      if (newPoint[i][0] < rangeU.low())newPoint[i][0] = rangeU.low();
      //      if (newPoint[i][0] > rangeU.high())newPoint[i][0] = rangeU.high();
      //      if (newPoint[i][1] < rangeV.low())newPoint[i][1] = rangeV.low();
      //      if (newPoint[i][1] > rangeV.high())newPoint[i][1] = rangeV.high();
      GPoint pp = gf->point(newP[i][0]);
      double D = sqrt ((pp.x() - v_center->x())*(pp.x() - v_center->x()) +
                       (pp.y() - v_center->y())*(pp.y() - v_center->y()) +
                       (pp.z() - v_center->z())*(pp.z() - v_center->z()) );
      ERR[i] = 100*fabs(D-L)/(D+L);
      //      printf("L = %12.5E D = %12.5E ERR = %12.5E\n",L,D,100*fabs(D-L)/(D+L));
    }

    surfaceFunctorGFace ss (gf);
    SVector3 dirs[4] = {infos.t1*(-1.0),infos.t2*(-1.0),infos.t1*(1.0),infos.t2*(1.0)};
    for (int i=0;i<4;i++){
      if (ERR[i] > 12){
        double uvt[3] = {newPoint[i][0],newPoint[i][1],0.0};
        // printf("Intersecting with circle N = %g %g %g dir = %g %g %g R
        //	  = %g p = %g %g
        //	  %g\n",n.x(),n.y(),n.z(),dirs[i].x(),dirs[i].y(),dirs[i].z(),L,
        //        v_center->x(),v_center->y(),v_center->z());
        curveFunctorCircle cf (dirs[i],infos.normal,
                               SVector3(v_center->x(),v_center->y(),v_center->z()), L);
        if (intersectCurveSurface (cf,ss,uvt,infos.paramh.first*1.e-3)){
          GPoint pp = gf->point(SPoint2(uvt[0],uvt[1]));
          double D = sqrt ((pp.x() - v_center->x())*(pp.x() - v_center->x()) +
                           (pp.y() - v_center->y())*(pp.y() - v_center->y()) +
                           (pp.z() - v_center->z())*(pp.z() - v_center->z()) );
          double DP = sqrt ((newPoint[i][0]-uvt[0])*(newPoint[i][0]-uvt[0]) +
                            (newPoint[i][1]-uvt[1])*(newPoint[i][1]-uvt[1]));
          double newErr = 100*fabs(D-L)/(D+L);
          //	    if (v_center->onWhat() != gf && gf->tag() == 3){
          //	      crossField2d::normalizeAngle (uvt[2]);
          //	      printf("INTERSECT angle = %g DP %g\n",uvt[2],DP);
          //	    }
          if (newErr < 1 && DP < .1){
            //	      printf("%12.5E vs %12.5E : %12.5E %12.5E vs %12.5E %12.5E
            //	      \n",ERR[i],newErr,newPoint[i][0],newPoint[i][1],uvt[0],uvt[1]);
            newPoint[i][0] = uvt[0];
            newPoint[i][1] = uvt[1];
          }
          //	    printf("OK\n");
        }
        else{
          Msg::Debug("Cannot put a new point on Surface %d",gf->tag());
          // printf("NOT OK\n");
        }
      }
    }

    // return the four new vertices
    for (int i=0;i<4;i++){
      newP[i][0] = SPoint2(newPoint[i][0],newPoint[i][1]);
    }
  }

  return true;
}

void computeTwoNeighbors(frameFieldBackgroundMesh3D *bgm, MVertex *parent,
                         vector<MVertex*> &spawns, SVector3 dir, double h)
{
  // using approximate size, RK1...
  double x = parent->x();
  double y = parent->y();
  double z = parent->z();
  double newx,newy,newz;
  GRegion *gr = dynamic_cast<GRegion*>(bgm->getBackgroundGEntity());

  newx = x + h * dir(0);
  newy = y + h * dir(1);
  newz = z + h * dir(2);
  spawns[0] = new MVertex(newx,newy,newz,gr,0);

  newx = x - h * dir(0);
  newy = y - h * dir(1);
  newz = z - h * dir(2);
  spawns[1] = new MVertex(newx,newy,newz,gr,0);
}

void computeSixNeighbors(frameFieldBackgroundMesh3D *bgm, MVertex *parent,
                         vector<MVertex*> &spawns, STensor3 dir, double h)
{
  // using approximate size, RK1...
  double x = parent->x();
  double y = parent->y();
  double z = parent->z();
  double newx,newy,newz;
  GRegion *gr = dynamic_cast<GRegion*>(bgm->getBackgroundGEntity());

  for (int i=0;i<3;i++){
    newx = x + h * dir(0,i);
    newy = y + h * dir(1,i);
    newz = z + h * dir(2,i);
    spawns[i*2] = new MVertex(newx,newy,newz,gr,0);

    newx = x - h * dir(0,i);
    newy = y - h * dir(1,i);
    newz = z - h * dir(2,i);
    spawns[i*2+1] = new MVertex(newx,newy,newz,gr,0);
  }
}

double Filler2D::time_bgm_and_smoothing = 0.;
double Filler2D::time_insertion = 0.;

Filler2D::Filler2D(){}

Filler2D::~Filler2D()
{
  cout << "FILLER2D timing:" << endl;
  cout << "  ------- CUMULATIVE TIME2D bgm & smoothing  : "
       << time_bgm_and_smoothing << " s." << endl;
  cout << "  ------- CUMULATIVE TIME2D inserting points : "
       << time_insertion << " s." << endl;
  cout << "  ------- TOTAL 2D TIME (new)   : "
       << time_bgm_and_smoothing+time_insertion << " s." << endl;
}

void Filler2D::pointInsertion2D(GFace* gf,  vector<MVertex*> &packed,
                                vector<SMetric3> &metrics)
{
  // NB/ do not use the mesh in GFace, use the one in backgroundMesh2D!

  //  if(debug) cout << " ------------------   OLD -------------------" << endl;
  //  stringstream ssa;
  ////  ssa << "oldbgm_angles_" << gf->tag() << ".pos";
  ////  backgroundMesh::current()->print(ssa.str(),gf,1);
  //  ssa << "oldbgm_sizes_" << gf->tag() << ".pos";
  //  backgroundMesh::current()->print(ssa.str(),gf,0);
  //
  //
  //
  //
  //  if(debug) cout << " ------------------   NEW -------------------" << endl;
  //  backgroundMesh2D *bgm2 = dynamic_cast<backgroundMesh2D*>(BGMManager::get(gf));
  //  stringstream ss2;
  //  ss2 << "basebg_sizefield_" << gf->tag() << ".pos";
  //  bgm2->exportSizeField(ss2.str());
  //
  //
  //
  //  return;
  //

  BGMManager::set_use_cross_field(true);

  const bool goNonLinear = true;
  const bool debug=false;
  const bool export_stuff=true;

  if (debug) cout << "ENTERING POINTINSERTION2D" << endl;

  double a;

  // acquire background mesh
  if(debug) cout << "pointInsertion2D: recover BGM" << endl;
  a=Cpu();
  frameFieldBackgroundMesh2D *bgm =
    dynamic_cast<frameFieldBackgroundMesh2D*>(BGMManager::get(gf));
  time_bgm_and_smoothing += (Cpu() - a);

  if (!bgm){
    Msg::Error("BGM dynamic cast failed in filler2D::pointInsertion2D");
    return;
  }

  // export BGM size field
  if(export_stuff){
    cout << "pointInsertion2D: export size field " << endl;
    stringstream ss;
    ss << "bg2D_sizefield_" << gf->tag() << ".pos";
    bgm->exportSizeField(ss.str());

    cout << "pointInsertion2D : export crossfield " << endl;
    stringstream sscf;
    sscf << "bg2D_crossfield_" << gf->tag() << ".pos";
    bgm->exportCrossField(sscf.str());

    cout << "pointInsertion2D : export smoothness " << endl;
    stringstream sss;
    sss << "bg2D_smoothness_" << gf->tag() << ".pos";
    bgm->exportSmoothness(sss.str());
  }



  // point insertion algorithm:
  a=Cpu();

  // for debug check...
  int priority_counter=0;
  map<MVertex*,int> vert_priority;

  // get all the boundary vertices
  if(debug) cout << "pointInsertion2D : get bnd vertices " << endl;
  set<MVertex*> bnd_vertices = bgm->get_vertices_of_maximum_dim(1);

  // put boundary vertices in a fifo queue
  set<smoothness_point_pair, compareSurfacePointWithExclusionRegionPtr_Smoothness> fifo;
  vector<surfacePointWithExclusionRegion*> vertices;

  // initiate the rtree
  if(debug) cout << "pointInsertion2D : initiate RTree " << endl;
  RTree<surfacePointWithExclusionRegion*,double,2,double> rtree;
  SMetric3 metricField(1.0);
  SPoint2 newp[4][NUMDIR];
  set<MVertex*>::iterator it = bnd_vertices.begin() ;

  for (; it !=  bnd_vertices.end() ; ++it){
    SPoint2 midpoint;
    computeFourNeighbors(bgm,*it, midpoint, goNonLinear, newp, metricField);
    surfacePointWithExclusionRegion *sp = new surfacePointWithExclusionRegion
      (*it, newp, midpoint,metricField);

    smoothness_point_pair mp;
    mp.ptr = sp;
    mp.rank=(1.-bgm->get_smoothness(midpoint[0],midpoint[1]));
    fifo.insert(mp);

    vertices.push_back(sp);
    double _min[2],_max[2];
    sp->minmax(_min,_max);
    rtree.Insert(_min,_max,sp);
  }

  // ---------- main loop -----------------
  while(!fifo.empty()){
    if(debug) cout << " -------- fifo.size() = " << fifo.size() << endl;
    int count_nbaddedpt = 0;

    surfacePointWithExclusionRegion * parent = (*fifo.begin()).ptr;
    fifo.erase(fifo.begin());

    for (int dir=0;dir<NUMDIR;dir++){
      for (int i=0;i<4;i++){
        if (!inExclusionZone (parent->_p[i][dir], rtree, vertices) ){

          GPoint gp = gf->point(parent->_p[i][dir]);
          MFaceVertex *v = new MFaceVertex(gp.x(),gp.y(),gp.z(),gf,gp.u(),gp.v());
          SPoint2 midpoint;
          computeFourNeighbors(bgm,v, midpoint, goNonLinear, newp, metricField);
          surfacePointWithExclusionRegion *sp = new surfacePointWithExclusionRegion
            (v, newp, midpoint, metricField, parent);
          smoothness_point_pair mp;mp.ptr = sp;mp.rank=(1.-bgm->get_smoothness(gp.u(),gp.v()));

          if (debug) vert_priority[v] = priority_counter++;

          fifo.insert(mp);
          vertices.push_back(sp);
          double _min[2],_max[2];
          sp->minmax(_min,_max);
          rtree.Insert(_min,_max,sp);

          if (debug){
            cout << "  adding node (" << sp->_v->x() << "," << sp->_v->y()
                 << "," << sp->_v->z() << ")" << endl;
            cout << "    ----------------------------- sub --- fifo.size() = "
                 << fifo.size() << endl;
          }
          count_nbaddedpt++;
        }
      }
    }
    if(debug) cout << "////////// nbre of added point: " << count_nbaddedpt << endl;
  }
  time_insertion += (Cpu() - a);

  if (debug){
    stringstream ss;
    ss << "priority_" << gf->tag() << ".pos";
    print_nodal_info(ss.str().c_str(),vert_priority);
    ss.clear();
  }

  // add the vertices as additional vertices in the
  // surface mesh
  char ccc[256]; sprintf(ccc,"points%d.pos",gf->tag());
  FILE *f = Fopen(ccc,"w");
  if(f){
    fprintf(f,"View \"\"{\n");
    for (unsigned int i=0;i<vertices.size();i++){
      vertices[i]->print(f,i);
      if(vertices[i]->_v->onWhat() == gf) {
        packed.push_back(vertices[i]->_v);
        metrics.push_back(vertices[i]->_meshMetric);
        SPoint2 midpoint;
        reparamMeshVertexOnFace(vertices[i]->_v, gf, midpoint);
      }
      delete  vertices[i];
    }
    fprintf(f,"};");
    fclose(f);
  }
}

bool Filler3D::treat_region(GRegion *gr)
{
  BGMManager::set_use_cross_field(true);

  bool use_vectorial_smoothness;
  bool use_fifo;
  string algo;

  // readValue("param.dat","SMOOTHNESSALGO",algo);
  algo.assign("SCALAR");

  if (!algo.compare("SCALAR")){
    use_vectorial_smoothness = false;
    use_fifo = false;
  }
  else if (!algo.compare("FIFO")){
    use_vectorial_smoothness = false;
    use_fifo = true;
  }
  else{
    cout << "unknown SMOOTHNESSALGO !" << endl;
    throw;
  }

  const bool debug=false;
  const bool export_stuff=true;
  double a;

  cout << "ENTERING POINTINSERTION3D" << endl;

  // acquire background mesh
  cout << "pointInsertion3D: recover BGM" << endl;
  a = Cpu();
  frameFieldBackgroundMesh3D *bgm =
    dynamic_cast<frameFieldBackgroundMesh3D*>(BGMManager::get(gr));
  time_smoothing += (Cpu() - a);

  if (!bgm){
    cout << "pointInsertion3D:: BGM dynamic cast failed ! " << endl;
    throw;
  }

  // export BGM fields
  if(export_stuff){
    cout << "pointInsertion3D: export size field " << endl;
    stringstream ss;
    ss << "bg3D_sizefield_" << gr->tag() << ".pos";
    bgm->exportSizeField(ss.str());

    cout << "pointInsertion3D : export crossfield " << endl;
    stringstream sscf;
    sscf << "bg3D_crossfield_" << gr->tag() << ".pos";
    bgm->exportCrossField(sscf.str());

    cout << "pointInsertion3D : export smoothness " << endl;
    stringstream sss;
    sss << "bg3D_smoothness_" << gr->tag() << ".pos";
    bgm->exportSmoothness(sss.str());

    if (use_vectorial_smoothness){
      cout << "pointInsertion3D : export vectorial smoothness " << endl;
      stringstream ssvs;
      ssvs << "bg3D_vectorial_smoothness_" << gr->tag() << ".pos";
      bgm->exportVectorialSmoothness(ssvs.str());
    }
  }

  // ---------------- START FILLING NEW POINTS ----------------
  cout << "pointInsertion3D : inserting points in region " << gr->tag()  << endl;

  //ProfilerStart("/home/bernard/profile");
  a = Cpu();

  // ----- initialize fifo list -----

  RTree<MVertex*,double,3,double> rtree;
  listOfPoints *fifo;
  if (use_fifo)
    fifo = new listOfPointsFifo();
  else if (use_vectorial_smoothness)
    fifo = new listOfPointsVectorialSmoothness();
  else
    fifo = new listOfPointsScalarSmoothness();

  set<MVertex*> temp;
  vector<MVertex*> boundary_vertices;
  map<MVertex*,int> vert_priority;
  map<MVertex*,double> smoothness_forplot;
  MElement *element;
  MVertex *vertex;
  list<GFace*> faces = gr->faces();
  for(list<GFace*>::iterator it=faces.begin();it!=faces.end();it++){// for all faces
    GFace *gf = *it;
    // int limit = code_kesskessai(gf->tag());
    for(unsigned int i=0;i<gf->getNumMeshElements();i++){
      element = gf->getMeshElement(i);
      for(int j=0;j<element->getNumVertices();j++){// for all vertices
        vertex = element->getVertex(j);
        temp.insert(vertex);
        // limits.insert(make_pair(vertex,limit));
      }
    }
  }

  int geodim;
  for(set<MVertex*>::iterator it=temp.begin();it!=temp.end();it++){
    geodim = (*it)->onWhat()->dim();
    if ((geodim==0) || (geodim==1) || (geodim==2)) boundary_vertices.push_back(*it);
  }

  double min[3],max[3],x,y,z,h;
  for(unsigned int i=0;i<boundary_vertices.size();i++){

    x = boundary_vertices[i]->x();
    y = boundary_vertices[i]->y();
    z = boundary_vertices[i]->z();

    // "on boundary since working on boundary_vertices ...
    MVertex *closest = bgm->get_nearest_neighbor_on_boundary(boundary_vertices[i]);
    h = bgm->size(closest);// get approximate size, closest vertex, faster ?!

    fill_min_max(x,y,z,h,min,max);

    rtree.Insert(min,max,boundary_vertices[i]);

    if (!use_vectorial_smoothness){
      smoothness_vertex_pair *svp = new smoothness_vertex_pair();
      svp->v = boundary_vertices[i];
      svp->rank = bgm->get_smoothness(x,y,z);
      svp->dir = 0;
      svp->layer = 0;
      svp->size = h;
      bgm->eval_approximate_crossfield(closest, svp->cf);

      fifo->insert(svp);
      if (debug){
        smoothness_forplot[svp->v] = svp->rank;
      }
    }
    else{
      STensor3 temp;
      bgm->eval_approximate_crossfield(closest, temp);
      for (int idir=0;idir<3;idir++){
        smoothness_vertex_pair *svp = new smoothness_vertex_pair();
        svp->v = boundary_vertices[i];
        svp->rank = bgm->get_vectorial_smoothness(idir,x,y,z);
        svp->dir = idir;
        svp->layer = 0;
        svp->size = h;
        svp->cf = temp;
        for (int k=0;k<3;k++) svp->direction(k) = temp(k,idir);

        // cout << "fifo size=" << fifo->size() << " inserting   "  ;
        fifo->insert(svp);
        // cout << " ->  fifo size=" << fifo->size() << endl;
      }
    }
  }

  // TODO: si fifo était list of *PTR -> pas de copies, gain temps ?
  Wrapper3D wrapper;
  wrapper.set_bgm(bgm);
  MVertex *parent,*individual;
  new_vertices.clear();
  bool spawn_created;
  int priority_counter=0;
  STensor3 crossfield;
  int parent_layer;

  while(!fifo->empty()){

    parent =  fifo->get_first_vertex();
    //    parent_limit = fifo->get_first_limit();
    parent_layer = fifo->get_first_layer();

    //    if(parent_limit!=-1 && parent_layer>=parent_limit()){
    //      continue;
    //    }

    vector<MVertex*> spawns;
    if (!use_vectorial_smoothness){
      spawns.resize(6);
      computeSixNeighbors(bgm,parent,spawns,fifo->get_first_crossfield(),
                          fifo->get_first_size());
    }
    else{
      spawns.resize(2);
      computeTwoNeighbors(bgm,parent,spawns,fifo->get_first_direction(),
                          fifo->get_first_size());
    }
    fifo->erase_first();

    //    cout << "while, fifo->size()=" << fifo->size() << " parent=(" <<
    //    parent->x() << "," << parent->y() << "," << parent->z() << ")" <<
    //    endl;

    for(unsigned int i=0;i<spawns.size();i++){
      spawn_created = false;
      individual = spawns[i];
      x = individual->x();
      y = individual->y();
      z = individual->z();
      //      cout << " working on candidate " << "(" << individual->x() << ","
      //      << individual->y() << "," << individual->z() << ")" << endl;

      if(bgm->inDomain(x,y,z)){
        //        cout << "   spawn " << i << " in domain" << endl;

        MVertex *closest = bgm->get_nearest_neighbor(individual);
        h = bgm->size(closest);// get approximate size, closest vertex, faster ?!

        if(far_from_boundary_3D(bgm,individual,h)){
          //        cout << "   spawn " << i << " far from bnd" << endl;
          bgm->eval_approximate_crossfield(closest, crossfield);
          wrapper.set_ok(true);
          wrapper.set_individual(individual);
          wrapper.set_parent(parent);
          wrapper.set_size(&h);
          wrapper.set_crossfield(&crossfield);

          fill_min_max(x,y,z,h,min,max);

          rtree.Search(min,max,rtree_callback_3D,&wrapper);

          if(wrapper.get_ok()){
            //        cout << "   spawn " << i << " wrapper OK" << endl;

            if (!use_vectorial_smoothness){
              smoothness_vertex_pair *svp = new smoothness_vertex_pair();
              svp->v = individual;
              svp->rank=bgm->get_smoothness(individual->x(),individual->y(),individual->z());
              svp->dir = 0;
              svp->layer = parent_layer+1;
              svp->size = h;
              svp->cf = crossfield;
              fifo->insert(svp);
              if (debug){
                smoothness_forplot[svp->v] = svp->rank;
                vert_priority[individual] = priority_counter++;
              }

            }
            else{
              if (debug) vert_priority[individual] = priority_counter++;
              for (int idir=0;idir<3;idir++){
                smoothness_vertex_pair *svp = new smoothness_vertex_pair();
                svp->v = individual;
                svp->rank = bgm->get_vectorial_smoothness(idir,x,y,z);
                svp->dir = idir;
                svp->layer = parent_layer+1;
                svp->size = h;
                for (int k=0;k<3;k++) svp->direction(k) = crossfield(k,idir);
                svp->cf = crossfield;
                fifo->insert(svp);
              }
            }

            rtree.Insert(min,max,individual);
            new_vertices.push_back(individual);
            spawn_created = true;

          }
        }
      }
      if(!spawn_created){
        delete individual;
      }
    }// end loop on spawns
  }

  //ProfilerStop();

  time_insert_points += (Cpu() - a);

  // --- output ---
  if (debug){
    stringstream ss;
    ss << "priority_3D_" << gr->tag() << ".pos";
    print_nodal_info(ss.str().c_str(),vert_priority);
    ss.clear();

    stringstream sss;
    sss << "smoothness_3D_" << gr->tag() << ".pos";
    print_nodal_info(sss.str().c_str(),smoothness_forplot);
    sss.clear();
  }

  // ------- meshing using new points
  cout << "tets in gr before= " << gr->tetrahedra.size() << endl;
  cout << "nb new vertices= " << new_vertices.size() << endl;
  a=Cpu();

  int option = CTX::instance()->mesh.algo3d;
  CTX::instance()->mesh.algo3d = ALGO_3D_DELAUNAY;

  deMeshGRegion deleter;
  deleter(gr);
  std::vector<GRegion*> regions;
  regions.push_back(gr);
  meshGRegion mesher(regions); //?
  mesher(gr); //?
  MeshDelaunayVolume(regions);
  time_meshing += (Cpu() - a);

  cout << "tets in gr after= " << gr->tetrahedra.size() << endl;
  cout << "gr tag=" << gr->tag() << endl;

  CTX::instance()->mesh.algo3d = option;

  delete fifo;
  for(unsigned int i=0;i<new_vertices.size();i++) delete new_vertices[i];
  new_vertices.clear();
  rtree.RemoveAll();

  return true;
}

int Filler3D::get_nbr_new_vertices()
{
  return new_vertices.size();
}

MVertex* Filler3D::get_new_vertex(int i)
{
  return new_vertices[i];
}

Filler3D::Filler3D(){}

Filler3D::~Filler3D()
{
  cout << "FILLER3D timing:" << endl;
  cout << "  ------- CUMULATIVE TIME3D bgm & smoothing  : "
       << time_smoothing << " s." << endl;
  cout << "  ------- CUMULATIVE TIME3D inserting points : "
       << time_insert_points << " s." << endl;
  cout << "  ------- CUMULATIVE TIME3D meshing region   : "
       << time_meshing << " s." << endl;
  cout << "  ------- CUMULATIVE TOTAL 3D TIME (new)   : "
       << time_meshing+time_smoothing+time_insert_points << " s." << endl;
}

std::vector<MVertex*> Filler3D::new_vertices;

double Filler3D::time_smoothing = 0.;
double Filler3D::time_insert_points = 0.;
double Filler3D::time_meshing = 0.;
