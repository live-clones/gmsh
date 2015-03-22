// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// Contributed by Tristan Carrier and Paul-Emile Bernard

#include <numeric>
#include <iterator>
#include <fstream>
#include <sstream>
#include <math.h>
#include "yamakawa.h"
#include "GModel.h"
#include "OS.h"
#include "MVertex.h"
#include "MElement.h"
#include "MHexahedron.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "MPyramid.h"
#include "MPrism.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"

void export_gregion_mesh(GRegion *gr, string filename)
{
  // FIXME: use MElement::writeMSH

  // create set of all tets
  map<MVertex*,int> vertices;
  int counterv=1;

  for (vector<MTetrahedron*>::iterator it = gr->tetrahedra.begin();
       it!=gr->tetrahedra.end(); it++){
    for (int i=0;i<(*it)->getNumVertices();i++){
      vertices.insert(make_pair((*it)->getVertex(i),counterv));
      counterv++;
    }
  }
  for (vector<MHexahedron*>::iterator it = gr->hexahedra.begin();
       it!=gr->hexahedra.end(); it++){
    for (int i=0;i<(*it)->getNumVertices();i++){
      vertices.insert(make_pair((*it)->getVertex(i),counterv));
      counterv++;
    }
  }
  for (vector<MPrism*>::iterator it = gr->prisms.begin();
       it!=gr->prisms.end(); it++){
    for (int i=0;i<(*it)->getNumVertices();i++){
      vertices.insert(make_pair((*it)->getVertex(i),counterv));
      counterv++;
    }
  }
  for (vector<MPyramid*>::iterator it = gr->pyramids.begin();
       it!=gr->pyramids.end(); it++){
    for (int i=0;i<(*it)->getNumVertices();i++){
      vertices.insert(make_pair((*it)->getVertex(i),counterv));
      counterv++;
    }
  }

  // export mesh
  ofstream out(filename.c_str());
  out << "$MeshFormat" << endl << "2.2 0 8" << endl << "$EndMeshFormat"
      << endl << "$Nodes" << endl << vertices.size() << endl;
  // write vertices
  for (map<MVertex*,int>::iterator it = vertices.begin();
       it!=vertices.end(); it++)
    out << it->second << " " << it->first->x() << " " << it->first->y()
        << " " << it->first->z() << endl;
  out << "$EndNodes" << endl << "$Elements" << endl
      << (gr->tetrahedra.size() + gr->hexahedra.size() +
          gr->prisms.size() + gr->pyramids.size()) << endl;

  // write elems
  int counter = 1;
  for (vector<MTetrahedron*>::iterator it = gr->tetrahedra.begin();
       it!=gr->tetrahedra.end();it++){
    out << counter << " 4 2 0 26";
    for (int i=0;i<(*it)->getNumVertices();i++){
      MVertex *v = (*it)->getVertex(i);
      out << " " << vertices[v];
    }
    out << endl;
    counter++;
  }
  for (vector<MHexahedron*>::iterator it = gr->hexahedra.begin();
       it!=gr->hexahedra.end();it++){
    out << counter << " 5 2 0 26";
    for (int i=0;i<(*it)->getNumVertices();i++){
      MVertex *v = (*it)->getVertex(i);
      out << " " << vertices[v];
    }
    out << endl;
    counter++;
  }
  for (vector<MPrism*>::iterator it = gr->prisms.begin();
       it!=gr->prisms.end();it++){
    out << counter << " 6 2 0 26";
    for (int i=0;i<(*it)->getNumVertices();i++){
      MVertex *v = (*it)->getVertex(i);
      out << " " << vertices[v];
    }
    out << endl;
    counter++;
  }
  for (vector<MPyramid*>::iterator it = gr->pyramids.begin();
       it!=gr->pyramids.end();it++){
    out << counter << " 7 2 0 26";
    for (int i=0;i<(*it)->getNumVertices();i++){
      MVertex *v = (*it)->getVertex(i);
      out << " " << vertices[v];
    }
    out << endl;
    counter++;
  }

  out << "$EndElements" << endl;
  out.close();
}

template <class T>
void export_the_clique_graphviz_format(cliques_compatibility_graph<T> &cl,
                                       int clique_number,string filename)
{
  ofstream out(filename.c_str());
  out << "Graph G {" << endl;
  typename multimap<int,set<T> >::reverse_iterator it_all = cl.allQ.rbegin();
  //  multimap<int,set<T> >::reverse_iterator it_allen = cl.allQ.rend();
  for (int i=0;i<clique_number;i++){
    it_all++;
  }
  //  int clique_size = it_all->second.size();
  typename set<T>::iterator ithex = it_all->second.begin();
  typename set<T>::iterator ithexen = it_all->second.end();

  //typedef tr1::unordered_multimap<hash_key, T> graph_data;
  //typedef tr1::unordered_multimap<hash_key, pair<T, graph_data > > graph;

  int counter=1;
  map<T,int> visited_hex;
  multimap<int,int> done;

  // export all hex
  typename cliques_compatibility_graph<T>::graph::const_iterator itgraph = cl.begin_graph();
  typename cliques_compatibility_graph<T>::graph_data::const_iterator itgraphdata;

  for (;itgraph!=cl.end_graph();itgraph++){

    T firsthex = itgraph->second.first;
    //    if (!post_check_validation(firsthex)) continue;

    typename map<T,int>::iterator itfind = visited_hex.find(firsthex);
    int num1=0;
    if (itfind==visited_hex.end()){
      num1=counter;
      visited_hex[firsthex] = counter++;
    }
    else
      num1 = itfind->second;

    itgraphdata = itgraph->second.second.begin();
    for(;itgraphdata!=itgraph->second.second.end();itgraphdata++){
      T secondhex = itgraphdata->second;
      //      if (!post_check_validation(secondhex)) continue;
      itfind = visited_hex.find(secondhex);
      int num2=0;
      if (itfind==visited_hex.end()){
        num2=counter;
        visited_hex[secondhex] = counter++;
      }
      else
        num2 = itfind->second;

      // search if num1 - num2 has already been written...
      bool found=false;
      pair<multimap<int,int>::iterator, multimap<int,int>::iterator> range =
        done.equal_range(num1);
      for(multimap<int,int>::iterator it = range.first;it!=range.second;it++){
        if (it->second==num2){
          found=true;
          break;
        }
      }

      if (!found){
        done.insert(make_pair(num1,num2));
        done.insert(make_pair(num2,num1));
        out << num1 << " -- " << num2 << " ;" << endl;
      }

    }


  }
  // export chosen hex with different color
  for (;ithex!=ithexen;ithex++){ // brutal post-check: random pickup of hexahedra in clique
    typename map<T,int>::iterator itfind = visited_hex.find(*ithex);
    if (itfind==visited_hex.end()){
      cout << "graph export: should not happen ! " << endl;
      throw;
      int num2=0;
      num2=counter;
      visited_hex[itfind->first] = counter++;
      out << num2 << " [shape=circle, style=filled, fillcolor=red];" << endl;
    }
    else
      out << itfind->second << " [shape=circle, style=filled, fillcolor=red];" << endl;
  }

  out << "}" << endl;
  out.close();
}

template<class T>
clique_stop_criteria<T>::clique_stop_criteria(map<T, std::set<MElement*> > &_m, int _i)
  : hex_to_tet(_m),total_number_tet(_i)
{
};

template<class T>
clique_stop_criteria<T>::~clique_stop_criteria(){};

template<class T>
void clique_stop_criteria<T>::export_corresponding_mesh
(const graph_data_no_hash &clique) const
{
  // NB: fct not often called...

  // filename
  string filename("best_clique_so_far.msh");
  string filenametets("best_clique_so_far_remaining_tets.msh");

  // create set of all tets
  set<MElement*> tets;
  set<MElement*> hexs;
  map<MVertex*,int> vertices;
  int counterv=1;
  typename map<T, std::set<MElement*> >::const_iterator it = hex_to_tet.begin();
  for (;it!=hex_to_tet.end();it++){
    std::set<MElement*>::const_iterator itt = it->second.begin();
    for (;itt!=it->second.end();itt++){
      tets.insert(*itt);
      for (int i=0;i<4;i++){
        vertices.insert(make_pair((*itt)->getVertex(i),counterv));
        counterv++;
      }
    }
  }

  // create MHexahedron, remove included tets from set "tets"
  for (typename graph_data_no_hash::const_iterator it = clique.begin();
       it!=clique.end(); it++){
    typename map<T, std::set<MElement*> >::const_iterator itfind = hex_to_tet.find(*it);
    if (itfind==hex_to_tet.end()){
      cout << "clique_stop_criteria::void export_corresponding_mesh : not found !!!" << endl;
      throw;
    }
    // remove tets
    for (set<MElement*>::const_iterator ittet = itfind->second.begin();ittet!=itfind->second.end();ittet++){
      tets.erase(*ittet);
    }
    // create MHexahedron
    Hex* hex=*it;
    MHexahedron *h = new MHexahedron(hex->getVertex(0),hex->getVertex(1),hex->getVertex(2),hex->getVertex(3),hex->getVertex(4),hex->getVertex(5),hex->getVertex(6),hex->getVertex(7));
    for (int i=0;i<8;i++){
      vertices.insert(make_pair(hex->getVertex(i),counterv));
      counterv++;
    }
    hexs.insert(h);
  }

  // export mesh FIXME: why not use MElement::writeMSH
  ofstream out(filename.c_str());
  ofstream outtets(filenametets.c_str());
  out << "$MeshFormat" << endl << "2.2 0 8" << endl << "$EndMeshFormat"
      << endl << "$Nodes" << endl << vertices.size() << endl;
  outtets << "$MeshFormat" << endl << "2.2 0 8" << endl << "$EndMeshFormat"
          << endl << "$Nodes" << endl << vertices.size() << endl;
  // write vertices
  for (map<MVertex*,int>::iterator it = vertices.begin();it!=vertices.end();it++){
    out << it->second << " " << it->first->x() << " "
        << it->first->y() << " " << it->first->z() << endl;
    outtets << it->second << " " << it->first->x() << " "
            << it->first->y() << " " << it->first->z() << endl;
  }
  out << "$EndNodes" << endl << "$Elements" << endl << (hexs.size()+tets.size()) << endl;
  outtets << "$EndNodes" << endl << "$Elements" << endl << (hexs.size()+tets.size()) << endl;
  // write hexs
  int counter=1;
  int countertets=1;
  for (set<MElement*>::iterator it = hexs.begin();it!=hexs.end();it++){
    out << counter << " 5 2 0 26";
    for (int i=0;i<(*it)->getNumVertices();i++){
      MVertex *v = (*it)->getVertex(i);
      out << " " << vertices[v];
    }
    out << endl;
    counter++;
  }
  // write tets
  for (set<MElement*>::iterator it = tets.begin();it!=tets.end();it++){
    out << counter << " 4 2 0 26";
    outtets << counter << " 4 2 0 26";
    for (int i=0;i<(*it)->getNumVertices();i++){
      MVertex *v = (*it)->getVertex(i);
      out << " " << vertices[v];
      outtets << " " << vertices[v];
    }
    out << endl;
    outtets << endl;
    counter++;
    countertets++;
  }
  out << "$EndElements" << endl;
  out.close();
  outtets << "$EndElements" << endl;
  outtets.close();
}


template<class T>
bool clique_stop_criteria<T>::stop(const graph_data_no_hash &clique)const
{
  unsigned int total = 0;

  // need to detect slivers !!!!!!!!!!!!!!!!!!!!!!!!!!

  // it seems like slivers are presents in different potential hex.
  // So, can be located by finding dupli!cates, instead of computing volumes...??????

  set<MElement*> thetets;
  //  set<MElement*> slivers;
  for (typename graph_data_no_hash::const_iterator it = clique.begin();it!=clique.end();it++){
    typename map<T, std::set<MElement*> >::const_iterator itfind = hex_to_tet.find(*it);
    if (itfind==hex_to_tet.end()){
      cout << "clique_stop_criteria::bool stop : not found !!!" << endl;
      throw;
    }
    //    total += (itfind->second.size());
    //    cout << "volumes=" << endl;
    for (set<MElement*>::const_iterator ittet = itfind->second.begin();ittet!=itfind->second.end();ittet++){
      //      set<MElement*>::iterator itfindtet = thetets.find(*ittet);
      //      if (itfindtet!=thetets.end()){
      //        cout << "Tet " << *ittet << " already done !!!" << endl;
      //        slivers.insert(*ittet);
      //      }
      thetets.insert(*ittet);
      //cout << (*ittet) << " : " << (*ittet)->getVolume()<< endl;;
    }


  }

  // to be sure, adding volume criteria...
  vector<double> volumes;
  for (set<MElement*>::iterator it = thetets.begin();it!=thetets.end();it++){
    volumes.push_back((*it)->getVolume());
  }
  int meanvolume = (std::accumulate(volumes.begin(), volumes.end(), 0))/volumes.size();
  int nb_slivers = 0;
  double threshold = 1.e-3*meanvolume;
  for (set<MElement*>::iterator it = thetets.begin();it!=thetets.end();it++){
    if ((*it)->getVolume() < threshold){
      nb_slivers++;
    }
  }

  total = thetets.size() - nb_slivers;

  //  cout << "# tet = " << total << " on " << total_number_tet << endl;
  //  cout << "#slivers = " << slivers.size() << endl;
  if (total >= total_number_tet) return true;// the maximum clique is maximum !!! only hex !!!
  return false;
}


template<class T>
cliques_compatibility_graph<T>::cliques_compatibility_graph
(graph &_g, const map<T, std::vector<double> > &_hex_ranks,
 unsigned int _max_nb_cliques, unsigned int _nb_hex_potentiels,
 clique_stop_criteria<T> *csc, ptrfunction_export fct)
  : found_the_ultimate_max_clique(false), export_clique_graph(fct), debug(false),
    max_nb_cliques(_max_nb_cliques), nb_hex_potentiels(_nb_hex_potentiels),
    max_clique_size(0), position(0), total_nodes_number(0),
    total_nb_of_cliques_searched(0), max_nb_of_stored_cliques(10),
    criteria(csc), cancel_search(false), hex_ranks(_hex_ranks), G(_g)
{
};

template<class T>
cliques_compatibility_graph<T>::~cliques_compatibility_graph()
{
};

template<class T>
void cliques_compatibility_graph<T>::find_cliques()
{
  // init
  graph_data s;
  for (typename graph::iterator it = G.begin();it!=G.end();it++){
    s.insert(make_pair(it->first, it->second.first));
  }
  find_cliques(s,0);

  if (!cancel_search){
    cout << total_nb_of_cliques_searched << " cliques have been found." << endl << flush;
  }

};

template<class T>
void cliques_compatibility_graph<T>::export_cliques()
{
  typename multimap<int, set<T> >::reverse_iterator itstore = allQ.rbegin();
  for (;itstore!=allQ.rend();itstore++){
    cout << "clique of size " << itstore->first << ": {";
    for (typename set<T>::iterator it = itstore->second.begin(); it!=itstore->second.end();it++){
      cout << *it << " ";
    }
    cout << "}" << endl;
  }
};


template<class T>
void cliques_compatibility_graph<T>::store_clique(int n)
{
  total_nb_of_cliques_searched++;

  if(total_nb_of_cliques_searched%10000==0){
    if (max_nb_cliques>0)
      cout << "found " << total_nb_of_cliques_searched << " cliques on " << max_nb_cliques << endl << flush;
    else
      cout << "found " << total_nb_of_cliques_searched << " cliques " << endl << flush;
  }

  if (debug){
    for (int i=0;i<n;i++) cout << " ";
    cout << "entering store_clique." << endl;
  }

  //  // check if the current clique already exists
  //  typename multimap<int, set<T> >::iterator itall = allQ.begin();
  //  size_t currentsize = Q.size();
  //  for (;itall!=allQ.end();itall++){
  //    if (itall->first != currentsize) continue;
  //    typename std::vector<T> common(currentsize);
  //    typename std::vector<T>::iterator itfind = std::set_intersection (itall->second.begin(),itall->second.end(), Q.begin(),Q.end(), common.begin());
  //    common.resize(itfind-common.begin());
  //    if (common.size()==currentsize){
  //      cout << "deux cliques les mêmes !!!" << endl;
  //      cout << "première: " << endl;
  //      typename std::set<T>::iterator itt = itall->second.begin();
  //      for (;itt!=itall->second.end();itt++){
  //        cout << "  " << *itt ;
  //      }
  //      cout << endl << "seconde (current): " << endl;
  //      itt = Q.begin();
  //      for (;itt!=Q.end();itt++){
  //        cout << "  " << *itt ;
  //      }
  //      throw;
  //    }
  //
  //  }
  //  // END

  bool found_best_clique_so_far=false;
  if (Q.size()>max_clique_size){
    max_clique_size=Q.size();
    cout << "found a maximum clique of size " << Q.size() << ", exporting" << endl;
    found_best_clique_so_far=true;
  }

  // this is done to possibly stop the algorithm after a given number of cliques found:
  if ((max_nb_cliques!=0) && (total_nb_of_cliques_searched>=max_nb_cliques)){
    cancel_search=true;
    cout << max_nb_cliques << " cliques have been searched, quit searching." << endl;
  }

  // check the additional criteria
  if (criteria->stop(Q)){
    cancel_search = true;
    cout << endl << " ************** criteria reached, domain is filled with hex !!! ***************" << endl << endl;
    found_the_ultimate_max_clique=true;
  }

  const bool verbose=false;
  if (verbose) cout << "MAX CLIQUE found of size " << Q.size() << " # total cliques searched:" << total_nb_of_cliques_searched << endl;

  if (debug){
    for (int i=0;i<n;i++) cout << " ";
    cout << "MAX CLIQUE found of size " << Q.size() << ": ";
  }

  // storing the current clique... or not, depending of the number of cliques to store, to reduce memory footprint.
  bool store_it = true;
  bool delete_worst=false;
  if ((max_nb_of_stored_cliques) && (allQ.size()>=max_nb_of_stored_cliques)){
    // then, compare sizes...
    int worst_clique_size = (allQ.begin())->first;
    if ((int)Q.size() <= worst_clique_size){
      store_it = false;// don't store if not good enough
    }
    else{
      delete_worst=true;
    }
  }

  if (!store_it) return;

  // actually storing current clique
  typename multimap<int, set<T> >::iterator itstore = allQ.insert(make_pair(Q.size(),set<T>()));
  for (typename graph_data_no_hash::iterator it = Q.begin();it!=Q.end();it++){
    itstore->second.insert(*it);
    if (debug){
      //for (int i=0;i<n;i++) cout << " ";
      cout << *it << " ";
    }
  }

  // finally, possibly delete worst clique, to reduce memory footprint
  if (delete_worst) allQ.erase(allQ.begin());

  if (debug){
    cout << endl;
  }


  if (found_best_clique_so_far){
    string filename("best_clique_so_far.dot");
    export_clique_graph(const_cast<cliques_compatibility_graph<T>& >(*this),0,filename);
    criteria->export_corresponding_mesh(Q);
  }

};


template<class T>
void cliques_compatibility_graph<T>::find_cliques(graph_data &s, int n)
{
  // possible end
  if (s.size()==0){
    store_clique(n);
    return;
  }
  if (s.size()==1){
    typename graph_data::iterator ittemp = s.begin();
    T u = ittemp->second;
    Q.insert(u);
    if (debug){
      for (int i=0;i<n;i++) cout << " ";
      cout << "level " << n << ", inserting (finished) " << u << endl;
    }
    store_clique(n);
    if (debug){
      for (int i=0;i<n;i++) cout << " ";
      cout << "erasing " << u << endl;
    }
    Q.erase(u);
    if (debug){
      for (int i=0;i<n;i++) cout << " ";
      cout << "and BACK" << endl;
    }
    return;
  }

  // splitting set s into white and black nodes
  graph_data white,black;
  T u;
  hash_key u_key;
  choose_u(s,u,u_key);
  split_set_BW(u,u_key,s,white,black);
  if (debug){
    for (int i=0;i<n;i++) cout << " ";
    cout << "level " << n << " u=" << u << " white={";
    for (typename graph_data::iterator it=white.begin();it!=white.end();it++){
      //for (int i=0;i<n;i++) cout << " ";
      cout << it->second << " ";
    }
    cout << "} black={";
    for (typename graph_data::iterator it=black.begin();it!=black.end();it++){
      //for (int i=0;i<n;i++) cout << " ";
      cout << it->second << " ";
    }
    cout << "}" <<endl;
  }


  // recursive loop
  while (white.size()){
    //T u = (*(s.begin()));
    Q.insert(u);
    if (debug){
      for (int i=0;i<n;i++) cout << " ";
      cout << "level " << n << ", inserting (recursive loop) " << u << endl;
    }
    if (n==0){
      unsigned int temp=white.size();
      total_nodes_number = std::max(total_nodes_number, temp);
      position++;
      cout << "treating root node " << position << "/" << total_nodes_number << endl;
    }

    find_cliques(black,n+1);
    if (cancel_search) break;

    erase_entry(white, u, u_key);
    erase_entry(s, u, u_key);
    Q.erase(u);

    black.clear();
    if (white.size()){
      typename graph_data::iterator ittemp = white.begin();
      u = ittemp->second;
      u_key = ittemp->first;
      fill_black_set(u,u_key,s,black);// building the black set only

      if (debug){
        for (int i=0;i<n;i++) cout << " ";
        cout << "level " << n <<  " u=" << u << " white={";
        for (typename graph_data::iterator it=white.begin();it!=white.end();it++){
          //for (int i=0;i<n;i++) cout << " ";
          cout << it->second << " ";
        }
        cout << "} black={";
        for (typename graph_data::iterator it=black.begin();it!=black.end();it++){
          //for (int i=0;i<n;i++) cout << " ";
          cout << it->second << " ";
        }
        cout << "}" <<endl;
      }
    }
    else{
      if (debug){
        for (int i=0;i<n;i++) cout << " ";
        cout << "no more white" << endl;
      }
    }
  }

  if (debug){
    for (int i=0;i<n;i++) cout << " ";
    cout << "BACK " << endl;
  }


}


template<class T>
void cliques_compatibility_graph<T>::erase_entry(graph_data &s, T &u, hash_key &key)
{
  pair<typename graph_data::iterator, typename graph_data::iterator> range =
    s.equal_range(key);

  typename graph_data::iterator it = range.first;
  for (;it!=range.second;it++){
    if (it->second==u){
      s.erase(it);
      return;
    }
  }
}


template<class T>
void cliques_compatibility_graph<T>::choose_u(const graph_data &s, T &u, hash_key &u_key)
{
  if (s.size()==0){
    u=T();
    u_key=0;
    return;
  }
  // choosing u
  //  typename graph_data::const_iterator it = s.begin();
  //  ranking_data m;
  //  int value;
  //  for (;it!=s.end();it++){
  //    value = function_to_maximize_for_u(*it,s);
  //    m.insert(make_pair(value,*it));
  //  }
  //  typename ranking_data::iterator itm = m.end();
  //  itm--;
  //  T u = itm->second;
  //  return u;

  typename graph_data::const_iterator it = s.begin();
  u = it->second;
  u_key = it->first;
  double value = function_to_maximize_for_u(u,u_key,s);
  double valuemax=value;
  it++;
  for (;it!=s.end();it++){
    value = function_to_maximize_for_u(it->second,it->first,s);
    if (value>valuemax){
      valuemax=value;
      u = it->second;
      u_key = it->first;
    }
  }

  //  typename map<T, std::vector<double> >::const_iterator itfind = hex_ranks.find(u);
  //  cout << "u: " << u << " # face tri: " << itfind->second[0] << " quality: " << u->get_quality() << " value max: " << valuemax << endl;

  return;
}

template<class T>
void cliques_compatibility_graph<T>::split_set_BW(const T &u, const hash_key &u_key,
                                                  const graph_data &s, graph_data &white,
                                                  graph_data &black)
{
  // splitting set s into white and black nodes
  white.insert(make_pair(u_key,u));
  typename graph_data::const_iterator it = s.begin();
  for (;it!=s.end();it++){
    if (u==(it->second)) continue;
    if (!compatibility(u,u_key, it->second, it->first))
      white.insert(make_pair(it->first, it->second));
    else
      black.insert(make_pair(it->first, it->second));
  }
}



template<class T>
void cliques_compatibility_graph<T>::fill_black_set(const T &u, const hash_key &u_key,
                                                    const graph_data &s, graph_data &black)
{
  // filling black set
  typename graph_data::const_iterator it = s.begin();
  for (;it!=s.end();it++){
    if (u==(it->second)) continue;
    if (compatibility(u,u_key, it->second,it->first))
      black.insert(make_pair(it->first, it->second));
  }
}


// the maximum score (int) will be chosen...
template<class T>
double cliques_compatibility_graph<T>::function_to_maximize_for_u(const T &u,
                                                                  const hash_key &u_key,
                                                                  const graph_data &s)
{
  typename graph_data::const_iterator it = s.begin();
  int counter=0;
  for (;it!=s.end();it++){
    if ((it->second)==u) continue;
    if (compatibility(u,u_key, it->second,it->first))
      counter++;
  }

  //typename map<T, std::vector<double> >::const_iterator itfind = hex_ranks.find(u);
  //  cout << "u: " << u << " boundary score: " << itfind->second[0]*(nb_hex_potentiels/2.) << "  counter score : " << counter << " total: " << (itfind->second[0]*(nb_hex_potentiels/2.) + counter) << endl;
  //  return (itfind->second[0]*(nb_hex_potentiels/2.) + itfind->second[1]*1000 + counter);
  //return (itfind->second[0]*(nb_hex_potentiels/2.)*1000. + itfind->second[1]*3 + counter);
  //return (itfind->second[0]*(nb_hex_potentiels/2.) + itfind->second[1]*10 + counter);

  //return (itfind->second[2]*nb_hex_potentiels*10000. + itfind->second[0]*(nb_hex_potentiels/2.) + itfind->second[1]*10 + counter);
  return counter;
}


template<class T>
bool cliques_compatibility_graph<T>::compatibility(const T &u, const hash_key &u_key,
                                                   const T &v, const hash_key &v_key)
{
  // first, find u in graph
  pair<typename graph::const_iterator, typename graph::const_iterator> range_ukey = G.equal_range(u_key);
  typename graph::const_iterator itfind_u = range_ukey.first;
  for (;itfind_u!=range_ukey.second;itfind_u++){
    if (itfind_u->second.first == u) break;
  }
  // at this point, "G[u]" = itfind_u

  // now, find v in graph_data
  pair<typename graph_data::const_iterator, typename graph_data::const_iterator> range_vkey = itfind_u->second.second.equal_range(v_key);
  bool found_it=false;
  for (typename graph_data::const_iterator itfind_v = range_vkey.first;itfind_v!=range_vkey.second;itfind_v++){
    if (itfind_v->second == v){
      found_it=true;
      break;
    }
  }
  return (found_it);
}


template<class T>
bool cliques_losses_graph<T>::compatibility(const T &u, const hash_key &u_key,
                                            const T &v, const hash_key &v_key)
{
  // first, find u in graph
  pair<typename graph::const_iterator, typename graph::const_iterator> range_ukey = G.equal_range(u_key);
  typename graph::const_iterator itfind_u = range_ukey.first;
  for (;itfind_u!=range_ukey.second;itfind_u++){
    if (itfind_u->second.first == u) break;
  }
  // at this point, "G[u]" = itfind_u

  // now, find v in graph_data
  pair<typename graph_data::const_iterator, typename graph_data::const_iterator> range_vkey = itfind_u->second.second.equal_range(v_key);
  bool found_it=false;
  for (typename graph_data::const_iterator itfind_v = range_vkey.first;itfind_v!=range_vkey.second;itfind_v++){
    if (itfind_v->second == v){
      found_it=true;
      break;
    }
  }
  return (!found_it);
}


template<class T>
cliques_losses_graph<T>::cliques_losses_graph
(graph &_g, const map<T, std::vector<double> > &_hex_ranks,
 unsigned int _max_nb_cliques, unsigned int _nb_hex_potentiels,
 clique_stop_criteria<T> *csc, ptrfunction_export fct)
  : cliques_compatibility_graph<T>(_g, _hex_ranks, _max_nb_cliques,
                                   _nb_hex_potentiels,csc,fct),G(_g)
{
};

template<class T>
cliques_losses_graph<T>::~cliques_losses_graph(){
};


bool compare_hex_ptr_by_quality (Hex *a,Hex *b)
{
  return (a->get_quality()>(b->get_quality()));
}

/*****************************************/
/****************class Hex****************/
/*****************************************/

Hex::Hex():hash(0.),a(NULL),b(NULL),c(NULL),d(NULL),e(NULL),f(NULL),g(NULL),h(NULL){}

Hex::Hex(MVertex* a2,MVertex* b2,MVertex* c2,MVertex* d2,MVertex* e2,MVertex* f2,MVertex* g2,MVertex* h2){
  a = a2;
  b = b2;
  c = c2;
  d = d2;
  e = e2;
  f = f2;
  g = g2;
  h = h2;
  set_hash();
}

void Hex::set_hash(){
  hash = (a->getNum() + b->getNum() + c->getNum() + d->getNum() + e->getNum() + f->getNum() + g->getNum() + h->getNum());
}

unsigned long long Hex::get_hash(){
  if ((hash==0.)&&(a)) set_hash();
  return hash;
}

bool Hex::hasVertex(const MVertex *v){
  for (int i=0;i<8;i++)
    if (getVertex(i)==v) return true;
  return false;
}


bool Hex::same_vertices(Hex *h){
  for (int i=0;i<8;i++)
    if (!(h->hasVertex(getVertex(i))))
      return false;
  return true;
}

Hex::~Hex(){}

double Hex::get_quality(){
  return quality;
}

void Hex::set_quality(double new_quality){
  quality = new_quality;
}

MVertex* Hex::get_a(){
  return a;
}

MVertex* Hex::get_b(){
  return b;
}

MVertex* Hex::get_c(){
  return c;
}

MVertex* Hex::get_d(){
  return d;
}

MVertex* Hex::get_e(){
  return e;
}

MVertex* Hex::get_f(){
  return f;
}

MVertex* Hex::get_g(){
  return g;
}

MVertex* Hex::get_h(){
  return h;
}

MVertex* Hex::getVertex(int n){
  MVertex *v;
  switch (n){
  case 0:
    v = get_a();
    break;
  case 1:
    v = get_b();
    break;
  case 2:
    v = get_c();
    break;
  case 3:
    v = get_d();
    break;
  case 4:
    v = get_e();
    break;
  case 5:
    v = get_f();
    break;
  case 6:
    v = get_g();
    break;
  case 7:
    v = get_h();
    break;
  default:
    cout << "Hex: unknown vertex number " << n << endl;
    throw;
  }
  return v;
}


void Hex::set_vertices(MVertex* a2,MVertex* b2,MVertex* c2,MVertex* d2,MVertex* e2,MVertex* f2,MVertex* g2,MVertex* h2){
  a = a2;
  b = b2;
  c = c2;
  d = d2;
  e = e2;
  f = f2;
  g = g2;
  h = h2;
}

bool Hex::operator<(Hex& hex){
  return quality>hex.get_quality();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////

PEEntity::PEEntity(const vector<const MVertex*> &_v):vertices(_v){
  compute_hash();
}

//PEEntity::PEEntity(unsigned long long l):hash(l){
//}

void PEEntity::compute_hash(){
  hash=0;
  for (vector<const MVertex*>::const_iterator it = vertices.begin();it!=vertices.end();it++)
    hash+=(*it)->getNum();
}

size_t PEEntity::get_hash() const{
  return hash;
}

PEEntity::~PEEntity(){}

const MVertex* PEEntity::getVertex(size_t n)const{
  if ((n>get_max_nb_vertices()) || vertices.empty()){
    cout << " PEEntity::getVertex : wrong vertex number : int n = " << n << endl;
    throw;
  }
  return vertices[n];
}

bool PEEntity::hasVertex(const MVertex *v)const{
  return (find(vertices.begin(),vertices.end(), v)!=vertices.end());
}

bool PEEntity::same_vertices(const PEEntity *t)const{
  for (vector<const MVertex*>::const_iterator it=vertices.begin();it!=vertices.end();it++){
    if (!(t->hasVertex(*it)))
      return false;
  }
  return true;
}

bool PEEntity::operator<(const PEEntity& t) const{
  return hash<t.get_hash();
}

//bool PEEntity::operator==(const PEEntity& t) const{
//  return (hash==t.get_hash());
//}

//bool PEEntity::operator==(const size_t& l) const{
//  return (hash==l);
//}


PELine::~PELine(){};

PELine::PELine(const vector<const MVertex*> &_v):PEEntity(_v){
  if (vertices.size()!=get_max_nb_vertices()){
    cout << "PELine: wrong number of vertices given !!! aborting ! " << endl;
    throw;
  }
  compute_hash();
}

size_t PELine::get_max_nb_vertices()const{return 2;};


PETriangle::~PETriangle(){};

PETriangle::PETriangle(const vector<const MVertex*> &_v):PEEntity(_v){
  if (vertices.size()!=get_max_nb_vertices()){
    cout << "PETriangle: wrong number of vertices given !!! aborting ! " << endl;
    throw;
  }
  compute_hash();
}

//PETriangle::PETriangle(const unsigned long long l):PEEntity(l){
//}

size_t PETriangle::get_max_nb_vertices()const{return 3;};


PEQuadrangle::~PEQuadrangle(){};

PEQuadrangle::PEQuadrangle(const vector<const MVertex*> &_v):PEEntity(_v){
  if (vertices.size()!=get_max_nb_vertices()){
    cout << "PEQuadrangle: wrong number of vertices given !!! aborting ! " << endl;
    throw;
  }
  compute_hash();
}

//PEQuadrangle::PEQuadrangle(const unsigned long long l):PEEntity(l){
//}

size_t PEQuadrangle::get_max_nb_vertices()const{return 4;};


/*******************************************/
/****************class Facet****************/
/*******************************************/

Facet::Facet(){}

Facet::Facet(MVertex* a2,MVertex* b2,MVertex* c2){
  a = a2;
  b = b2;
  c = c2;
  compute_hash();
}

Facet::~Facet(){}

MVertex* Facet::get_a(){
  return a;
}

MVertex* Facet::get_b(){
  return b;
}

MVertex* Facet::get_c(){
  return c;
}

void Facet::set_vertices(MVertex* a2,MVertex* b2,MVertex* c2){
  a = a2;
  b = b2;
  c = c2;
  compute_hash();
}

bool Facet::same_vertices(Facet facet){
  bool c1,c2,c3;

  c1 = (a==facet.get_a()) || (a==facet.get_b()) || (a==facet.get_c());
  c2 = (b==facet.get_a()) || (b==facet.get_b()) || (b==facet.get_c());
  c3 = (c==facet.get_a()) || (c==facet.get_b()) || (c==facet.get_c());

  return c1 && c2 && c3;
}

void Facet::compute_hash(){
  hash = a->getNum() + b->getNum() + c->getNum();
}

unsigned long long Facet::get_hash() const{
  return hash;
}

bool Facet::operator<(const Facet& facet) const{
  return hash<facet.get_hash();
}

/**********************************************/
/****************class Diagonal****************/
/**********************************************/

Diagonal::Diagonal(){}

Diagonal::Diagonal(MVertex* a2,MVertex* b2){
  a = a2;
  b = b2;
  compute_hash();
}

Diagonal::~Diagonal(){}

MVertex* Diagonal::get_a(){
  return a;
}

MVertex* Diagonal::get_b(){
  return b;
}

void Diagonal::set_vertices(MVertex* a2,MVertex* b2){
  a = a2;
  b = b2;
  compute_hash();
}

bool Diagonal::same_vertices(Diagonal diagonal){
  bool c1,c2;

  c1 = (a==diagonal.get_a()) || (a==diagonal.get_b());
  c2 = (b==diagonal.get_a()) || (b==diagonal.get_b());

  return c1 && c2;
}

void Diagonal::compute_hash(){
  hash = a->getNum() + b->getNum();
}

unsigned long long Diagonal::get_hash() const{
  return hash;
}

bool Diagonal::operator<(const Diagonal& diagonal) const{
  return hash<diagonal.get_hash();
}

/**********************************************/
/******************class Tuple*****************/
/**********************************************/

Tuple::Tuple(){}

Tuple::Tuple(MVertex* a,MVertex* b,MVertex* c,MElement* element2,GFace* gf2){
  if(a<=b && a<=c){
    v1 = a;
  }
  else if(b<=a && b<=c){
    v1 = b;
  }
  else{
    v1 = c;
  }

  if(a>=b && a>=c){
    v3 = a;
  }
  else if(b>=a && b>=c){
    v3 = b;
  }
  else{
    v3 = c;
  }

  if(a!=v1 && a!=v3){
    v2 = a;
  }
  else if(b!=v1 && b!=v3){
    v2 = b;
  }
  else{
    v2 = c;
  }

  element = element2;
  gf = gf2;
  hash = a->getNum() + b->getNum() + c->getNum();
}

Tuple::Tuple(MVertex* a,MVertex* b,MVertex* c){
  if(a<=b && a<=c){
    v1 = a;
  }
  else if(b<=a && b<=c){
    v1 = b;
  }
  else{
    v1 = c;
  }

  if(a>=b && a>=c){
    v3 = a;
  }
  else if(b>=a && b>=c){
    v3 = b;
  }
  else{
    v3 = c;
  }

  if(a!=v1 && a!=v3){
    v2 = a;
  }
  else if(b!=v1 && b!=v3){
    v2 = b;
  }
  else{
    v2 = c;
  }

  hash = a->getNum() + b->getNum() + c->getNum();
}

Tuple::~Tuple(){}

MVertex* Tuple::get_v1(){
  return v1;
}

MVertex* Tuple::get_v2(){
  return v2;
}

MVertex* Tuple::get_v3(){
  return v3;
}

MElement* Tuple::get_element() const{
  return element;
}

GFace* Tuple::get_gf() const{
  return gf;
}

bool Tuple::same_vertices(Tuple tuple){
  if(v1==tuple.get_v1() && v2==tuple.get_v2() && v3==tuple.get_v3()){
    return 1;
  }
  else{
    return 0;
  }
}

unsigned long long Tuple::get_hash() const{
  return hash;
}

bool Tuple::operator<(const Tuple& tuple) const{
  return hash<tuple.get_hash();
}

/**************************************************/
/****************class Recombinator****************/
/**************************************************/

Recombinator::Recombinator(){}

Recombinator::~Recombinator(){
  for (std::vector<Hex*>::iterator it = potential.begin();it!=potential.end();it++){
    delete *it;
  }
}

void Recombinator::execute(){

  GRegion* gr;
  GModel* model = GModel::current();
  GModel::riter it;

  for(it=model->firstRegion();it!=model->lastRegion();it++)
    {
      gr = *it;
      if(gr->getNumMeshElements()>0){
        execute(gr);
      }
    }
}

void Recombinator::execute(GRegion* gr){
  printf("................HEXAHEDRA................\n");
  build_tuples(gr);
  init_markings(gr);

  Msg::Info("Building Connectivity...");
  build_vertex_to_vertices(gr);
  build_vertex_to_elements(gr);

  potential.clear();
  Msg::Info("Hex-merging pattern nb. 1...");
  pattern1(gr);
  Msg::Info("Hex-merging pattern nb. 2...");
  pattern2(gr);
  Msg::Info("Hex-merging pattern nb. 3...");
  pattern3(gr);

  std::sort(potential.begin(),potential.end(),compare_hex_ptr_by_quality);


  //  /// SORTIE TOUS HEX POT
  //  cout << "__________________________ START POT HEX LISTING ____________________ " << endl;
  //  for (std::vector<Hex*>::iterator it = potential.begin();it!=potential.end();it++){
  //    cout << "--- pot hex : " << *it << "   " << (*it)->get_quality() << endl;
  //  }
  //  cout << "__________________________ END POT HEX LISTING ____________________ " << endl;
  //  /// END

  hash_tableA.clear();
  hash_tableB.clear();
  hash_tableC.clear();
  merge(gr);

  rearrange(gr);

  statistics(gr);


  modify_surfaces(gr);
}

void Recombinator::init_markings(GRegion* gr){
  size_t i;
  MElement* element;

  markings.clear();

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    markings.insert(std::pair<MElement*,bool>(element,false));
  }
}

void Recombinator::pattern1(GRegion* gr){
  size_t i;
  int index;
  double quality;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex *p,*q,*r,*s;
  std::vector<MVertex*> already;
  std::set<MVertex*> bin1;
  std::set<MVertex*> bin2;
  std::set<MVertex*> bin3;
  std::set<MVertex*> bin4;
  std::set<MVertex*>::iterator it1;
  std::set<MVertex*>::iterator it2;
  std::set<MVertex*>::iterator it3;
  std::set<MVertex*>::iterator it4;
  Hex *hex;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    //for(index=0;index<4;index++){
    max_scaled_jacobian(element,index);

    a = element->getVertex(index);
    b = element->getVertex((index+1)%4);
    c = element->getVertex((index+2)%4);
    d = element->getVertex((index+3)%4);

    already.clear();
    already.push_back(a);
    already.push_back(b);
    already.push_back(c);
    already.push_back(d);
    bin1.clear();
    bin2.clear();
    bin3.clear();
    find(b,d,already,bin1);
    find(b,c,already,bin2);
    find(c,d,already,bin3);

    for(it1=bin1.begin();it1!=bin1.end();it1++){
      p = *it1;
      for(it2=bin2.begin();it2!=bin2.end();it2++){
        q = *it2;
        for(it3=bin3.begin();it3!=bin3.end();it3++){
          r = *it3;
          if(p!=q && p!=r && q!=r){
            already.clear();
            already.push_back(a);
            already.push_back(b);
            already.push_back(c);
            already.push_back(d);
            already.push_back(p);
            already.push_back(q);
            already.push_back(r);
            bin4.clear();
            find(p,q,r,already,bin4);
            for(it4=bin4.begin();it4!=bin4.end();it4++){
              s = *it4;
              hex = new Hex(a,b,q,c,d,p,s,r);
              quality = min_scaled_jacobian(*hex);
              hex->set_quality(quality);
              if(valid(*hex)){
                potential.push_back(hex);
              }
              else delete hex;
            }
          }
        }
      }
    }
    //}
  }
}

void Recombinator::pattern2(GRegion* gr){
  size_t i;
  int index1,index2,index3,index4;
  double quality;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex *p,*q,*r,*s;
  std::set<MElement*> verif;
  Hex *hex;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    //for(index1=0;index1<3;index1++){
    //for(index2=index1+1;index2<4;index2++){
    diagonal(element,index1,index2);
    two_others(index1,index2,index3,index4);

    b = element->getVertex(index1);
    d = element->getVertex(index2);
    a = element->getVertex(index3);
    c = element->getVertex(index4);

    verif.clear();
    find(b,d,verif);
    if(verif.size()==6){
      s = find(a,b,d,c,verif);
      p = find(b,c,d,a,verif);
      if(s!=0 && p!=0){
        r = find(s,b,d,a,verif);
        q = find(p,b,d,c,verif);
        if(r!=0 && q!=0){
          hex = new Hex(a,s,b,c,d,r,q,p);
          quality = min_scaled_jacobian(*hex);
          hex->set_quality(quality);
          if(valid(*hex)){
            potential.push_back(hex);
          }
          else delete hex;

          hex = new Hex(a,c,d,s,b,p,q,r);
          quality = min_scaled_jacobian(*hex);
          hex->set_quality(quality);
          if(valid(*hex)){
            potential.push_back(hex);
          }
          else delete hex;
        }
      }
    }
    //}
    //}
  }
}

void Recombinator::pattern3(GRegion* gr){
  size_t i;
  int index1,index2,index3,index4;
  bool c1,c2,c3,c4,c5;
  bool c6,c7,c8,c9,c10;
  double quality;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex *p,*q,*r,*s;
  MVertex *fA,*fB,*bA,*bB;
  std::set<MElement*> verif1;
  std::set<MElement*> verif2;
  Hex *hex;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    diagonal(element,index1,index2);
    two_others(index1,index2,index3,index4);

    b = element->getVertex(index1);
    d = element->getVertex(index2);
    a = element->getVertex(index3);
    c = element->getVertex(index4);

    verif1.clear();
    verif2.clear();
    find(b,d,verif1);
    find(a,c,verif2);

    if(verif1.size()==4 && verif2.size()==4){
      fA = find(b,d,a,c,verif1);
      fB = find(b,d,c,a,verif1);
      bA = find(a,c,b,d,verif2);
      bB = find(a,c,d,b,verif2);

      if(fA!=0 && fB!=0 && bA!=0 && bB!=0 && fA!=fB && bA!=bB){
        if(scalar(fA,fB,a,b)>scalar(fA,fB,b,c) && scalar(bA,bB,a,b)>scalar(bA,bB,b,c)){
          if(distance(fA,b,c)<distance(fB,b,c)){
            p = fA;
            q = fB;
          }
          else{
            p = fB;
            q = fA;
          }

          if(distance(bA,b,c)<distance(bB,b,c)){
            r = bA;
            s = bB;
          }
          else{
            r = bB;
            s = bA;
          }

          c1 = linked(b,p);
          c2 = linked(c,p);
          c3 = linked(p,q);
          c4 = linked(a,q);
          c5 = linked(d,q);

          c6 = linked(b,r);
          c7 = linked(c,r);
          c8 = linked(r,s);
          c9 = linked(a,s);
          c10 = linked(d,s);

          if(c1 && c2 && c3 && c4 && c5 && c6 && c7 && c8 && c9 && c10){
            hex = new Hex(p,c,r,b,q,d,s,a);
            quality = min_scaled_jacobian(*hex);
            hex->set_quality(quality);
            if(valid(*hex)){
              potential.push_back(hex);
            }
            else delete hex;
          }
        }
        else if(scalar(fA,fB,a,b)<=scalar(fA,fB,b,c) && scalar(bA,bB,a,b)<=scalar(bA,bB,b,c)){
          if(distance(fA,a,b)<distance(fB,a,b)){
            p = fA;
            q = fB;
          }
          else{
            p = fB;
            q = fA;
          }

          if(distance(bA,a,b)<distance(bB,a,b)){
            r = bA;
            s = bB;
          }
          else{
            r = bB;
            s = bA;
          }

          c1 = linked(b,p);
          c2 = linked(a,p);
          c3 = linked(p,q);
          c4 = linked(c,q);
          c5 = linked(d,q);

          c6 = linked(b,r);
          c7 = linked(a,r);
          c8 = linked(r,s);
          c9 = linked(c,s);
          c10 = linked(d,s);

          if(c1 && c2 && c3 && c4 && c5 && c6 && c7 && c8 && c9 && c10){
            hex = new Hex(p,b,r,a,q,c,s,d);
            quality = min_scaled_jacobian(*hex);
            hex->set_quality(quality);
            if(valid(*hex)){
              potential.push_back(hex);
            }
            else delete hex;
          }
        }
      }
    }
  }
}

void Recombinator::merge(GRegion* gr){
  unsigned int i;
  int count;
  bool flag;
  double threshold;
  double quality;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;
  MElement* element;
  std::set<MElement*> parts;
  std::vector<MTetrahedron*> opt;
  std::set<MElement*>::iterator it;
  std::map<MElement*,bool>::iterator it2;
  Hex *hex;

  count = 1;
  quality = 0.0;

  for(i=0;i<potential.size();i++){
    hex = potential[i];

    threshold = 0.25;
    if(hex->get_quality()<threshold){
      break;
    }

    a = hex->get_a();
    b = hex->get_b();
    c = hex->get_c();
    d = hex->get_d();
    e = hex->get_e();
    f = hex->get_f();
    g = hex->get_g();
    h = hex->get_h();

    parts.clear();
    find(a,*hex,parts);
    find(b,*hex,parts);
    find(c,*hex,parts);
    find(d,*hex,parts);
    find(e,*hex,parts);
    find(f,*hex,parts);
    find(g,*hex,parts);
    find(h,*hex,parts);

    flag = 1;
    //    bool found_used_sliver=false;
    for(it=parts.begin();it!=parts.end();it++){
      element = *it;
      it2 = markings.find(element);
      //      if(it2->second==1 && sliver(element,*hex)){
      //        found_used_sliver=true;
      //      }
      if(it2->second==1 && !sliver(element,*hex)){
        flag = 0;
        break;
      }
    }
    if(!flag) continue;

    if(!valid(*hex,parts)){
      continue;
    }

    if(!conformityA(*hex)){
      continue;
    }

    if(!conformityB(*hex)){
      continue;
    }

    if(!conformityC(*hex)){
      continue;
    }

    if(!faces_statuquo(*hex)){
      continue;
    }

    //    if (found_used_sliver){
    //      cout << "      ************************************* a used sliver passed the tests !!!!! " << endl;
    //    }

    //printf("%d - %d/%d - %f\n",count,i,(int)potential.size(),hex.get_quality());
    quality = quality + hex->get_quality();
    for(it=parts.begin();it!=parts.end();it++){
      element = *it;
      it2 = markings.find(element);
      it2->second = 1;
    }
    gr->addHexahedron(new MHexahedron(a,b,c,d,e,f,g,h));
    build_hash_tableA(*hex);
    build_hash_tableB(*hex);
    build_hash_tableC(*hex);
    count++;
  }

  opt.clear();
  opt.resize(gr->tetrahedra.size());
  opt = gr->tetrahedra;
  gr->tetrahedra.clear();

  for(i=0;i<opt.size();i++){
    element = (MElement*)(opt[i]);
    it2 = markings.find(element);
    if(it2->second==0){
      gr->tetrahedra.push_back(opt[i]);
    }
  }

  printf("hexahedra average quality (0->1) : %f\n",quality/count);
}

void Recombinator::improved_merge(GRegion* gr){
  unsigned int i;
  int count;
  bool flag;
  double threshold;
  double quality;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;
  MElement* element;
  std::set<MElement*> parts;
  std::vector<MTetrahedron*> opt;
  std::set<MElement*>::iterator it;
  std::map<MElement*,bool>::iterator it2;
  std::vector<MTetrahedron*>::iterator it3;
  Hex *hex;

  count = 1;
  quality = 0.0;

  for(i=0;i<potential.size();i++){
    hex = potential[i];

    threshold = 0.25;
    if(hex->get_quality()<threshold){
      break;
    }

    a = hex->get_a();
    b = hex->get_b();
    c = hex->get_c();
    d = hex->get_d();
    e = hex->get_e();
    f = hex->get_f();
    g = hex->get_g();
    h = hex->get_h();

    parts.clear();
    find(a,*hex,parts);
    find(b,*hex,parts);
    find(c,*hex,parts);
    find(d,*hex,parts);
    find(e,*hex,parts);
    find(f,*hex,parts);
    find(g,*hex,parts);
    find(h,*hex,parts);

    flag = 1;
    for(it=parts.begin();it!=parts.end();it++){
      element = *it;
      it2 = markings.find(element);
      if(it2->second==1 && !sliver(element,*hex)){
        flag = 0;
        break;
      }
    }
    if(!flag) continue;

    if(!valid(*hex,parts)){
      continue;
    }

    if(!conformityA(*hex)){
      continue;
    }

    if(!conformityB(*hex)){
      continue;
    }

    if(!conformityC(*hex)){
      continue;
    }

    //printf("%d - %d/%d - %f\n",count,i,(int)potential->size(),hex->get_quality());
    quality = quality + hex->get_quality();
    for(it=parts.begin();it!=parts.end();it++){
      element = *it;
      it2 = markings.find(element);
      it2->second = 1;
    }
    gr->addHexahedron(new MHexahedron(a,b,c,d,e,f,g,h));
    build_hash_tableA(*hex);
    build_hash_tableB(*hex);
    build_hash_tableC(*hex);
    count++;
  }

  opt.clear();
  opt.resize(gr->tetrahedra.size());
  opt = gr->tetrahedra;
  gr->tetrahedra.clear();

  for(i=0;i<opt.size();i++){
    element = (MElement*)(opt[i]);
    it2 = markings.find(element);
    if(it2->second==0){
      gr->tetrahedra.push_back(opt[i]);
    }
  }

  printf("hexahedra average quality (0->1) : %f\n",quality/count);
}

void Recombinator::rearrange(GRegion* gr){
  size_t i;
  MElement* element;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    element->setVolumePositive();
  }
}

void Recombinator::statistics(GRegion* gr){
  size_t i;
  int all_nbr,hex_nbr;
  double all_volume,hex_volume,volume;
  MElement* element;

  all_nbr = 0;
  hex_nbr = 0;
  all_volume = 0.0;
  hex_volume = 0.0;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    volume = element->getVolume();

    if(element->getNumVertices()==8){
      hex_nbr = hex_nbr + 1;
      hex_volume = hex_volume + volume;
    }

    all_nbr = all_nbr + 1;
    all_volume = all_volume + volume;
  }

  printf("percentage of hexahedra (number) : %.2f\n",hex_nbr*100.0/all_nbr);
  printf("percentage of hexahedra (volume) : %.2f\n",hex_volume*100.0/all_volume);
}

void Recombinator::build_tuples(GRegion* gr){
  unsigned int i;
  MVertex *a,*b,*c;
  MElement* element;
  GFace* gf;
  std::list<GFace*> faces;
  std::list<GFace*>::iterator it;

  tuples.clear();
  triangles.clear();
  faces.clear();

  faces = gr->faces();

  for(it=faces.begin();it!=faces.end();it++)
    {
      gf = *it;

      for(i=0;i<gf->getNumMeshElements();i++){
        element = gf->getMeshElement(i);

        if(element->getNumVertices()==3){
          a = element->getVertex(0);
          b = element->getVertex(1);
          c = element->getVertex(2);

          tuples.insert(Tuple(a,b,c,element,gf));
        }
      }
    }
}

void Recombinator::modify_surfaces(GRegion* gr){
  unsigned int i;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;
  MElement* element;
  GFace* gf;
  std::list<GFace*> faces;
  std::vector<MElement*> opt;
  std::list<GFace*>::iterator it;
  std::set<MElement*>::iterator it2;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);

    if(element->getNumVertices()==8){
      a = element->getVertex(0);
      b = element->getVertex(1);
      c = element->getVertex(2);
      d = element->getVertex(3);
      e = element->getVertex(4);
      f = element->getVertex(5);
      g = element->getVertex(6);
      h = element->getVertex(7);

      modify_surfaces(a,b,c,d);
      modify_surfaces(e,f,g,h);
      modify_surfaces(a,e,h,d);
      modify_surfaces(b,f,g,c);
      modify_surfaces(a,e,f,b);
      modify_surfaces(d,h,g,c);
    }
  }

  faces = gr->faces();

  for(it=faces.begin();it!=faces.end();it++)
    {
      gf = *it;

      opt.clear();

      for(i=0;i<gf->getNumMeshElements();i++){
        element = gf->getMeshElement(i);

        if(element->getNumVertices()==3){
          it2 = triangles.find(element);
          if(it2==triangles.end()){
            opt.push_back(element);
          }
        }
      }

      gf->triangles.clear();

      for(i=0;i<opt.size();i++){
        gf->triangles.push_back((MTriangle*)opt[i]);
      }
    }
}

void Recombinator::modify_surfaces(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  bool flag1,flag2;
  MElement *element1,*element2;
  GFace *gf1;//,*gf2;
  Tuple tuple1,tuple2;
  std::multiset<Tuple>::iterator it1;
  std::multiset<Tuple>::iterator it2;

  gf1 = NULL;
  //gf2 = NULL;

  tuple1 = Tuple(a,b,c);
  tuple2 = Tuple(c,d,a);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1!=tuples.end()){
    if(tuple1.get_hash()!=it1->get_hash()){
      break;
    }

    if(tuple1.same_vertices(*it1)){
      flag1 = 1;
      element1 = it1->get_element();
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2!=tuples.end()){
    if(tuple2.get_hash()!=it2->get_hash()){
      break;
    }

    if(tuple2.same_vertices(*it2)){
      flag2 = 1;
      element2 = it2->get_element();
      //gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2){
    triangles.insert(element1);
    triangles.insert(element2);

    gf1->addQuadrangle(new MQuadrangle(a,b,c,d));
  }

  tuple1 = Tuple(a,b,d);
  tuple2 = Tuple(b,c,d);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1!=tuples.end()){
    if(tuple1.get_hash()!=it1->get_hash()){
      break;
    }

    if(tuple1.same_vertices(*it1)){
      flag1 = 1;
      element1 = it1->get_element();
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2!=tuples.end()){
    if(tuple2.get_hash()!=it2->get_hash()){
      break;
    }

    if(tuple2.same_vertices(*it2)){
      flag2 = 1;
      element2 = it2->get_element();
      //gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2){
    triangles.insert(element1);
    triangles.insert(element2);

    gf1->addQuadrangle(new MQuadrangle(a,b,c,d));
  }
}

bool Recombinator::sliver(MElement* element,Hex &hex){
  bool val;
  bool flag1,flag2,flag3,flag4;
  MVertex *a,*b,*c,*d;

  val = 0;
  a = element->getVertex(0);
  b = element->getVertex(1);
  c = element->getVertex(2);
  d = element->getVertex(3);

  flag1 = inclusion(a,hex.get_a(),hex.get_b(),hex.get_c(),hex.get_d());
  flag2 = inclusion(b,hex.get_a(),hex.get_b(),hex.get_c(),hex.get_d());
  flag3 = inclusion(c,hex.get_a(),hex.get_b(),hex.get_c(),hex.get_d());
  flag4 = inclusion(d,hex.get_a(),hex.get_b(),hex.get_c(),hex.get_d());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 = inclusion(a,hex.get_e(),hex.get_f(),hex.get_g(),hex.get_h());
  flag2 = inclusion(b,hex.get_e(),hex.get_f(),hex.get_g(),hex.get_h());
  flag3 = inclusion(c,hex.get_e(),hex.get_f(),hex.get_g(),hex.get_h());
  flag4 = inclusion(d,hex.get_e(),hex.get_f(),hex.get_g(),hex.get_h());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 = inclusion(a,hex.get_a(),hex.get_b(),hex.get_e(),hex.get_f());
  flag2 = inclusion(b,hex.get_a(),hex.get_b(),hex.get_e(),hex.get_f());
  flag3 = inclusion(c,hex.get_a(),hex.get_b(),hex.get_e(),hex.get_f());
  flag4 = inclusion(d,hex.get_a(),hex.get_b(),hex.get_e(),hex.get_f());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 = inclusion(a,hex.get_b(),hex.get_c(),hex.get_g(),hex.get_f());
  flag2 = inclusion(b,hex.get_b(),hex.get_c(),hex.get_g(),hex.get_f());
  flag3 = inclusion(c,hex.get_b(),hex.get_c(),hex.get_g(),hex.get_f());
  flag4 = inclusion(d,hex.get_b(),hex.get_c(),hex.get_g(),hex.get_f());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 = inclusion(a,hex.get_c(),hex.get_d(),hex.get_g(),hex.get_h());
  flag2 = inclusion(b,hex.get_c(),hex.get_d(),hex.get_g(),hex.get_h());
  flag3 = inclusion(c,hex.get_c(),hex.get_d(),hex.get_g(),hex.get_h());
  flag4 = inclusion(d,hex.get_c(),hex.get_d(),hex.get_g(),hex.get_h());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 = inclusion(a,hex.get_a(),hex.get_d(),hex.get_e(),hex.get_h());
  flag2 = inclusion(b,hex.get_a(),hex.get_d(),hex.get_e(),hex.get_h());
  flag3 = inclusion(c,hex.get_a(),hex.get_d(),hex.get_e(),hex.get_h());
  flag4 = inclusion(d,hex.get_a(),hex.get_d(),hex.get_e(),hex.get_h());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  return val;
}

double Recombinator::diagonal(MElement* element,int& index1,int& index2){
  double max;
  double l1,l2,l3,l4,l5,l6;
  MVertex *a,*b,*c,*d;

  a = element->getVertex(0);
  b = element->getVertex(1);
  c = element->getVertex(2);
  d = element->getVertex(3);

  max = 1000000.0;
  l1 = distance(a,b);
  l2 = distance(a,c);
  l3 = distance(a,d);
  l4 = distance(b,c);
  l5 = distance(c,d);
  l6 = distance(d,b);

  if(l1>=l2 && l1>=l3 && l1>=l4 && l1>=l5 && l1>=l6){
    index1 = 0;
    index2 = 1;
    max = l1;
  }
  else if(l2>=l1 && l2>=l3 && l2>=l4 && l2>=l5 && l2>=l6){
    index1 = 0;
    index2 = 2;
    max = l2;
  }
  else if(l3>=l1 && l3>=l2 && l3>=l4 && l3>=l5 && l3>=l6){
    index1 = 0;
    index2 = 3;
    max = l3;
  }
  else if(l4>=l1 && l4>=l2 && l4>=l3 && l4>=l5 && l4>=l6){
    index1 = 1;
    index2 = 2;
    max = l4;
  }
  else if(l5>=l1 && l5>=l2 && l5>=l3 && l5>=l4 && l5>=l6){
    index1 = 2;
    index2 = 3;
    max = l5;
  }
  else if(l6>=l1 && l6>=l2 && l6>=l3 && l6>=l4 && l6>=l5){
    index1 = 3;
    index2 = 1;
    max = l6;
  }

  return max;
}

double Recombinator::distance(MVertex* v1,MVertex* v2){
  double val;
  double x,y,z;

  x = v2->x() - v1->x();
  y = v2->y() - v1->y();
  z = v2->z() - v1->z();

  val = sqrt(x*x + y*y + z*z);
  return val;
}

double Recombinator::distance(MVertex* v,MVertex* v1,MVertex* v2){
  double val;
  double x,y,z;

  x = 0.5*(v2->x() + v1->x()) - v->x();
  y = 0.5*(v2->y() + v1->y()) - v->y();
  z = 0.5*(v2->z() + v1->z()) - v->z();

  val = sqrt(x*x + y*y + z*z);
  return val;
}

double Recombinator::scalar(MVertex* v1,MVertex* v2,MVertex* v3,MVertex* v4){
  double val;
  double l1,l2;
  SVector3 vec1,vec2;

  vec1 = SVector3(v2->x()-v1->x(),v2->y()-v1->y(),v2->z()-v1->z());
  vec2 = SVector3(v4->x()-v3->x(),v4->y()-v3->y(),v4->z()-v3->z());

  l1 = vec1.norm();
  l2 = vec2.norm();

  val = dot(vec1,vec2);
  return fabs(val)/(l1*l2);
}

void Recombinator::two_others(int index1,int index2,int& index3,int& index4){
  int i;

  for(i=0;i<4;i++){
    if(i!=index1 && i!=index2){
      index3 = i;
      break;
    }
  }

  for(i=0;i<4;i++){
    if(i!=index1 && i!=index2 && i!=index3){
      index4 = i;
      break;
    }
  }
}


// soit une face du cube: abcd
// en principe, on doit avoir soit les facets (abc) et (acd), soit les facets (abd) et(bcd) qui sont inclues dans un des tets qui forment l'hex.
// si c'est le cas pour toutes les 6 faces de l'hex, return true.
// ce test permet probablement de virer les hex "avec des trous" (avec 8 noeuds ok, mais un tet manquant, ce qui peut occasionner un hex à 14 faces, par exemple, si l'on compte les faces à partir des tets inclus)
bool Recombinator::valid(Hex &hex,const std::set<MElement*>& parts){
  bool ok1,ok2,ok3;
  bool ok4,ok5,ok6;
  bool flag1A,flag1B,flag1C,flag1D;
  bool flag2A,flag2B,flag2C,flag2D;
  bool flag3A,flag3B,flag3C,flag3D;
  bool flag4A,flag4B,flag4C,flag4D;
  bool flag5A,flag5B,flag5C,flag5D;
  bool flag6A,flag6B,flag6C,flag6D;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  a = hex.get_a();
  b = hex.get_b();
  c = hex.get_c();
  d = hex.get_d();
  e = hex.get_e();
  f = hex.get_f();
  g = hex.get_g();
  h = hex.get_h();

  flag1A = inclusion(a,b,c,parts);
  flag1B = inclusion(a,c,d,parts);
  flag1C = inclusion(b,c,d,parts);
  flag1D = inclusion(a,b,d,parts);
  ok1 = (flag1A && flag1B) || (flag1C && flag1D);

  flag2A = inclusion(e,f,g,parts);
  flag2B = inclusion(e,g,h,parts);
  flag2C = inclusion(f,g,h,parts);
  flag2D = inclusion(e,f,h,parts);
  ok2 = (flag2A && flag2B) || (flag2C && flag2D);

  flag3A = inclusion(a,b,f,parts);
  flag3B = inclusion(a,f,e,parts);
  flag3C = inclusion(b,e,f,parts);
  flag3D = inclusion(a,b,e,parts);
  ok3 = (flag3A && flag3B) || (flag3C && flag3D);

  flag4A = inclusion(b,c,g,parts);
  flag4B = inclusion(b,g,f,parts);
  flag4C = inclusion(c,g,f,parts);
  flag4D = inclusion(b,c,f,parts);
  ok4 = (flag4A && flag4B) || (flag4C && flag4D);

  flag5A = inclusion(c,d,g,parts);
  flag5B = inclusion(d,g,h,parts);
  flag5C = inclusion(c,g,h,parts);
  flag5D = inclusion(c,d,h,parts);
  ok5 = (flag5A && flag5B) || (flag5C && flag5D);

  flag6A = inclusion(a,d,h,parts);
  flag6B = inclusion(a,e,h,parts);
  flag6C = inclusion(d,e,h,parts);
  flag6D = inclusion(a,d,e,parts);
  ok6 = (flag6A && flag6B) || (flag6C && flag6D);

  if(ok1 && ok2 && ok3 && ok4 && ok5 && ok6){
    return 1;
  }
  else{
    return 0;
  }
}

// renvoie true si le "MQuadrangle::etaShapeMeasure" des 6 faces est plus grand que 0.000001
bool Recombinator::valid(Hex &hex){
  double k;
  double eta1,eta2,eta3;
  double eta4,eta5,eta6;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  k = 0.000001;

  a = hex.get_a();
  b = hex.get_b();
  c = hex.get_c();
  d = hex.get_d();
  e = hex.get_e();
  f = hex.get_f();
  g = hex.get_g();
  h = hex.get_h();

  eta1 = eta(a,b,c,d);
  eta2 = eta(e,f,g,h);
  eta3 = eta(a,b,f,e);
  eta4 = eta(b,c,g,f);
  eta5 = eta(d,a,e,h);
  eta6 = eta(d,c,g,h);

  if(eta1>k && eta2>k && eta3>k && eta4>k && eta5>k && eta6>k){
    return 1;
  }
  else{
    return 0;
  }
}

double Recombinator::eta(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  double val;
  MQuadrangle* quad;

  quad = new MQuadrangle(a,b,c,d);
  val = quad->etaShapeMeasure();
  delete quad;
  return val;
}

bool Recombinator::linked(MVertex* v1,MVertex* v2){
  bool flag;
  std::map<MVertex*,std::set<MVertex*> >::iterator it;
  std::set<MVertex*>::iterator it2;

  it = vertex_to_vertices.find(v1);
  flag = 0;

  for(it2=(it->second).begin();it2!=(it->second).end();it2++){
    if(*it2==v2){
      flag = 1;
      break;
    }
  }

  return flag;
}

void Recombinator::find(MVertex* v1,MVertex* v2,const std::vector<MVertex*>& already,std::set<MVertex*>& final){
  std::map<MVertex*,std::set<MVertex*> >::iterator it1;
  std::map<MVertex*,std::set<MVertex*> >::iterator it2;

  it1 = vertex_to_vertices.find(v1);
  it2 = vertex_to_vertices.find(v2);

  intersection(it1->second,it2->second,already,final);
}

void Recombinator::find(MVertex* v1,MVertex* v2,MVertex* v3,const std::vector<MVertex*>& already,std::set<MVertex*>& final){
  std::map<MVertex*,std::set<MVertex*> >::iterator it1;
  std::map<MVertex*,std::set<MVertex*> >::iterator it2;
  std::map<MVertex*,std::set<MVertex*> >::iterator it3;

  it1 = vertex_to_vertices.find(v1);
  it2 = vertex_to_vertices.find(v2);
  it3 = vertex_to_vertices.find(v3);

  intersection(it1->second,it2->second,it3->second,already,final);
}

void Recombinator::find(MVertex* v1,MVertex* v2,std::set<MElement*>& final){
  std::map<MVertex*,std::set<MElement*> >::iterator it1;
  std::map<MVertex*,std::set<MElement*> >::iterator it2;

  it1 = vertex_to_elements.find(v1);
  it2 = vertex_to_elements.find(v2);

  intersection(it1->second,it2->second,final);
}

void Recombinator::find(MVertex* vertex,Hex hex,std::set<MElement*>& final){
  bool flag1,flag2,flag3,flag4;
  MVertex *a,*b,*c,*d;
  std::map<MVertex*,std::set<MElement*> >::iterator it;
  std::set<MElement*>::iterator it2;

  it = vertex_to_elements.find(vertex);

  for(it2=(it->second).begin();it2!=(it->second).end();it2++){
    a = (*it2)->getVertex(0);
    b = (*it2)->getVertex(1);
    c = (*it2)->getVertex(2);
    d = (*it2)->getVertex(3);

    flag1 = inclusion(a,hex);
    flag2 = inclusion(b,hex);
    flag3 = inclusion(c,hex);
    flag4 = inclusion(d,hex);

    if(flag1 && flag2 && flag3 && flag4){
      final.insert(*it2);
    }
  }
}

MVertex* Recombinator::find(MVertex* v1,MVertex* v2,MVertex* v3,MVertex* already,const std::set<MElement*>& bin){
  bool flag1,flag2,flag3,flag4;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex* pointer;
  std::set<MElement*>::const_iterator it;

  pointer = 0;

  for(it=bin.begin();it!=bin.end();it++){
    element = *it;

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);

    flag1 = inclusion(v1,a,b,c,d);
    flag2 = inclusion(v2,a,b,c,d);
    flag3 = inclusion(v3,a,b,c,d);
    flag4 = inclusion(already,a,b,c,d);

    if(flag1 && flag2 && flag3 && !flag4){
      if(a!=v1 && a!=v2 && a!=v3){
        pointer = a;
      }
      else if(b!=v1 && b!=v2 && b!=v3){
        pointer = b;
      }
      else if(c!=v1 && c!=v2 && c!=v3){
        pointer = c;
      }
      else{
        pointer = d;
      }
      break;
    }
  }

  return pointer;
}

void Recombinator::intersection(const std::set<MVertex*>& bin1,const std::set<MVertex*>& bin2,
                                const std::vector<MVertex*>& already,std::set<MVertex*>& final){
  size_t i;
  bool ok;
  std::set<MVertex*> temp;
  std::set<MVertex*>::iterator it;

  std::set_intersection(bin1.begin(),bin1.end(),bin2.begin(),bin2.end(),std::inserter(temp,temp.end()));

  for(it=temp.begin();it!=temp.end();it++){
    ok = 1;

    for(i=0;i<already.size();i++){
      if((*it)==already[i]){
        ok = 0;
        break;
      }
    }

    if(ok){
      final.insert(*it);
    }
  }
}

void Recombinator::intersection(const std::set<MVertex*>& bin1,const std::set<MVertex*>& bin2,const std::set<MVertex*>& bin3,
                                const std::vector<MVertex*>& already,std::set<MVertex*>& final){
  size_t i;
  bool ok;
  std::set<MVertex*> temp;
  std::set<MVertex*> temp2;
  std::set<MVertex*>::iterator it;

  std::set_intersection(bin1.begin(),bin1.end(),bin2.begin(),bin2.end(),std::inserter(temp,temp.end()));
  std::set_intersection(temp.begin(),temp.end(),bin3.begin(),bin3.end(),std::inserter(temp2,temp2.end()));

  for(it=temp2.begin();it!=temp2.end();it++){
    ok = 1;

    for(i=0;i<already.size();i++){
      if((*it)==already[i]){
        ok = 0;
        break;
      }
    }

    if(ok){
      final.insert(*it);
    }
  }
}

void Recombinator::intersection(const std::set<MElement*>& bin1,const std::set<MElement*>& bin2,std::set<MElement*>& final){
  std::set_intersection(bin1.begin(),bin1.end(),bin2.begin(),bin2.end(),std::inserter(final,final.end()));
}

// return true if vertex belong to hex
bool Recombinator::inclusion(MVertex* vertex,Hex hex){
  bool flag;

  flag = 0;

  if(vertex==hex.get_a()) flag = 1;
  else if(vertex==hex.get_b()) flag = 1;
  else if(vertex==hex.get_c()) flag = 1;
  else if(vertex==hex.get_d()) flag = 1;
  else if(vertex==hex.get_e()) flag = 1;
  else if(vertex==hex.get_f()) flag = 1;
  else if(vertex==hex.get_g()) flag = 1;
  else if(vertex==hex.get_h()) flag = 1;

  return flag;
}

// pfffffff... renvoie true si vertex se trouve dans [a,b,c]
// en gros, return (abcd.find(vertex)!=abcd.end());
bool Recombinator::inclusion(MVertex* vertex,MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  bool flag;

  flag = 0;

  if(vertex==a) flag = 1;
  else if(vertex==b) flag = 1;
  else if(vertex==c) flag = 1;
  else if(vertex==d) flag = 1;

  return flag;
}


// return true if all three vertices v1,v2 and v3 belong to one tet
// on pourrait plutot faire: est-ce que la face (v1v2v3) fait partie d'un tet, avec l'info hashée de tet to triangle ???
bool Recombinator::inclusion(MVertex* v1,MVertex* v2,MVertex* v3,const std::set<MElement*>& bin){
  bool ok;
  bool flag1,flag2,flag3;
  MVertex *a,*b,*c,*d;
  MElement* element;
  std::set<MElement*>::const_iterator it;

  ok = 0;

  for(it=bin.begin();it!=bin.end();it++){
    element = *it;

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);

    flag1 = inclusion(v1,a,b,c,d);
    flag2 = inclusion(v2,a,b,c,d);
    flag3 = inclusion(v3,a,b,c,d);

    if(flag1 && flag2 && flag3){
      ok = 1;
      break;
    }
  }

  return ok;
}

// return true si la facet existe dans la table A
bool Recombinator::inclusion(Facet facet){
  bool flag;
  std::multiset<Facet>::iterator it;

  it = hash_tableA.find(facet);
  flag = 0;

  while(it!=hash_tableA.end()){
    if(facet.get_hash()!=it->get_hash()){
      break;
    }

    if(facet.same_vertices(*it)){
      flag = 1;
      break;
    }

    it++;
  }

  return flag;
}

bool Recombinator::inclusion(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;

  it = hash_tableB.find(diagonal);
  flag = 0;

  while(it!=hash_tableB.end()){
    if(diagonal.get_hash()!=it->get_hash()){
      break;
    }

    if(diagonal.same_vertices(*it)){
      flag = 1;
      break;
    }

    it++;
  }

  return flag;
}

bool Recombinator::duplicate(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;

  it = hash_tableC.find(diagonal);
  flag = 0;

  while(it!=hash_tableC.end()){
    if(diagonal.get_hash()!=it->get_hash()){
      break;
    }

    if(diagonal.same_vertices(*it)){
      flag = 1;
      break;
    }

    it++;
  }

  return flag;
}

// return true si un hex est "conforme A"
// est "conforme A" un hex dont les 6 faces sont "conforme A"
// est "conforme A" une face si ses 4 facets existent dans tableA, ou bien si aucune des ses facets ne se trouve dans table A
// ça veut dire: un hex est condorme A s'il est tout seul.
// Sinon, s'il est pas tout seul, s'il a des "voisins de face"... il faut que les faces en contact soient bien en contact... pas juste un triangle en commun, mais il faut un QUAD en commun !
// ne pouvait-on pas écrire ça avec des quad, du coup ???
// ça veut dire que pour les slivers, qu'ils soient ou pas dans l'hex, dans tous les cas, les hex sont compatibles !
bool Recombinator::conformityA(Hex &hex){
  bool c1,c2,c3,c4,c5,c6;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  a = hex.get_a();
  b = hex.get_b();
  c = hex.get_c();
  d = hex.get_d();
  e = hex.get_e();
  f = hex.get_f();
  g = hex.get_g();
  h = hex.get_h();

  c1 = conformityA(a,b,c,d);
  c2 = conformityA(e,f,g,h);
  c3 = conformityA(a,b,f,e);
  c4 = conformityA(b,c,g,f);
  c5 = conformityA(d,c,g,h);
  c6 = conformityA(d,a,e,h);

  return c1 && c2 && c3 && c4 && c5 && c6;
}

bool Recombinator::conformityA(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  bool c1,c2,c3,c4;

  c1 = inclusion(Facet(a,b,c));
  c2 = inclusion(Facet(a,c,d));
  c3 = inclusion(Facet(a,b,d));
  c4 = inclusion(Facet(b,c,d));

  //  if (((c1 && c2 && c3 && c4) || (!c1 && !c2 && !c3 && !c4))==false){
  //    // info si non conforme
  //    cout << "     treating facet made of abcd: " << a->getNum() << " " << b->getNum() << " " << c->getNum() << " " << d->getNum() << endl;
  //    cout << "c1 (abc) connu: " << c1 << endl;
  //    cout << "c2 (acd) connu: " << c2 << endl;
  //    cout << "c3 (abd) connu: " << c3 << endl;
  //    cout << "c4 (bcd) connu: " << c4 << endl;
  //  }

  return (c1 && c2 && c3 && c4) || (!c1 && !c2 && !c3 && !c4);
}

// return false si:
//- une des 12 arrêtes de l'hex se trouve dans tableB !!! (pas C !!!), càd si une arrete a été utilisée comme diagonale d'un autre hex
//- (ou bien) si, pour chaque face de l'hex, on a une diagonale dans tableB et pas l'autre
// ce test conformityB n'est-il pas redondant avec conformityA ???
bool Recombinator::conformityB(Hex &hex){
  bool flag1;
  bool flag2;
  bool c1,c2,c3,c4;
  bool c5,c6,c7,c8;
  bool c9,c10,c11,c12;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  a = hex.get_a();
  b = hex.get_b();
  c = hex.get_c();
  d = hex.get_d();
  e = hex.get_e();
  f = hex.get_f();
  g = hex.get_g();
  h = hex.get_h();

  flag1 = inclusion(Diagonal(a,b));
  flag1 = flag1 || inclusion(Diagonal(b,f));
  flag1 = flag1 || inclusion(Diagonal(f,e));
  flag1 = flag1 || inclusion(Diagonal(e,a));
  flag1 = flag1 || inclusion(Diagonal(d,c));
  flag1 = flag1 || inclusion(Diagonal(c,g));
  flag1 = flag1 || inclusion(Diagonal(g,h));
  flag1 = flag1 || inclusion(Diagonal(h,d));
  flag1 = flag1 || inclusion(Diagonal(b,c));
  flag1 = flag1 || inclusion(Diagonal(f,g));
  flag1 = flag1 || inclusion(Diagonal(e,h));
  flag1 = flag1 || inclusion(Diagonal(a,d));

  c1 = inclusion(Diagonal(a,f));
  c2 = inclusion(Diagonal(b,e));
  flag2 = (c1 && !c2) || (!c1 && c2);
  c3 = inclusion(Diagonal(d,g));
  c4 = inclusion(Diagonal(c,h));
  flag2 = flag2 || (c3 && !c4) || (!c3 && c4);
  c5 = inclusion(Diagonal(b,g));
  c6 = inclusion(Diagonal(c,f));
  flag2 = flag2 || (c5 && !c6) || (!c5 && c6);
  c7 = inclusion(Diagonal(e,g));
  c8 = inclusion(Diagonal(f,h));
  flag2 = flag2 || (c7 && !c8) || (!c7 && c8);
  c9 = inclusion(Diagonal(a,h));
  c10 = inclusion(Diagonal(d,e));
  flag2 = flag2 || (c9 && !c10) || (!c9 && c10);
  c11 = inclusion(Diagonal(a,c));
  c12 = inclusion(Diagonal(b,d));
  flag2 = flag2 || (c11 && !c12) || (!c11 && c12);

  if(flag1 || flag2){
    return 0;
  }
  else{
    return 1;
  }
}

// return false si une des 12 diagonales du cube se trouve dans tableC, càd a été utilisée comme arrête
bool Recombinator::conformityC(Hex &hex){
  bool flag;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  a = hex.get_a();
  b = hex.get_b();
  c = hex.get_c();
  d = hex.get_d();
  e = hex.get_e();
  f = hex.get_f();
  g = hex.get_g();
  h = hex.get_h();

  flag = duplicate(Diagonal(a,f));
  flag = flag || duplicate(Diagonal(b,e));
  flag = flag || duplicate(Diagonal(d,g));
  flag = flag || duplicate(Diagonal(c,h));
  flag = flag || duplicate(Diagonal(b,g));
  flag = flag || duplicate(Diagonal(c,f));
  flag = flag || duplicate(Diagonal(e,g));
  flag = flag || duplicate(Diagonal(f,h));
  flag = flag || duplicate(Diagonal(a,h));
  flag = flag || duplicate(Diagonal(d,e));
  flag = flag || duplicate(Diagonal(a,c));
  flag = flag || duplicate(Diagonal(b,d));

  if(flag){
    return 0;
  }
  else{
    return 1;
  }
}

// return true si les 6 faces de l'hex sont "faces_statuquo"
bool Recombinator::faces_statuquo(Hex &hex){
  bool c1,c2,c3,c4,c5,c6;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  a = hex.get_a();
  b = hex.get_b();
  c = hex.get_c();
  d = hex.get_d();
  e = hex.get_e();
  f = hex.get_f();
  g = hex.get_g();
  h = hex.get_h();

  c1 = faces_statuquo(a,b,c,d);
  c2 = faces_statuquo(e,f,g,h);
  c3 = faces_statuquo(a,b,f,e);
  c4 = faces_statuquo(b,c,g,f);
  c5 = faces_statuquo(d,c,g,h);
  c6 = faces_statuquo(d,a,e,h);

  return c1 && c2 && c3 && c4 && c5 && c6;
}

// return false si, parmis les deux paires de facets de la face, il existe un couple de facet qui soinent toutes les deux des tuples, mais correspondant à des geometric faces différentes. Bref, une arrête géométrique confondue avec une diagonale de la face.
bool Recombinator::faces_statuquo(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  bool ok;
  bool flag1,flag2;
  GFace *gf1,*gf2;
  Tuple tuple1,tuple2;
  std::multiset<Tuple>::iterator it1;
  std::multiset<Tuple>::iterator it2;

  ok = 1;

  gf1 = NULL;
  gf2 = NULL;

  tuple1 = Tuple(a,b,c);
  tuple2 = Tuple(c,d,a);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1!=tuples.end()){
    if(tuple1.get_hash()!=it1->get_hash()){
      break;
    }

    if(tuple1.same_vertices(*it1)){
      flag1 = 1;
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2!=tuples.end()){
    if(tuple2.get_hash()!=it2->get_hash()){
      break;
    }

    if(tuple2.same_vertices(*it2)){
      flag2 = 1;
      gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2){// si on a trouvé les deux tuples (abc) et (cda) dans la liste des tuples
    if(gf1!=gf2){// si les geometrical faces des deux tuples sont différentes
      ok = 0;
    }
  }

  // on fait pareil pour l'autre paire de facets, abd et bcd
  tuple1 = Tuple(a,b,d);
  tuple2 = Tuple(b,c,d);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1!=tuples.end()){
    if(tuple1.get_hash()!=it1->get_hash()){
      break;
    }

    if(tuple1.same_vertices(*it1)){
      flag1 = 1;
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2!=tuples.end()){
    if(tuple2.get_hash()!=it2->get_hash()){
      break;
    }

    if(tuple2.same_vertices(*it2)){
      flag2 = 1;
      gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2){
    if(gf1!=gf2){
      ok = 0;
    }
  }

  return ok;
}

void Recombinator::build_vertex_to_vertices(GRegion* gr){
  size_t i;
  int j;
  MElement* element;
  MVertex *a,*b,*c,*d;
  std::set<MVertex*> bin;
  std::map<MVertex*,std::set<MVertex*> >::iterator it;

  cout << "... stage1, building vertex->vertices connectivity " << endl;

  vertex_to_vertices.clear();

  int nbElements = gr->getNumMeshElements();
  double percentage=0.05;
  double done=0.;
  int progress = ceil(nbElements*percentage);
  for(i=0;i<gr->getNumMeshElements();i++){
    if(i%progress==0){
      done += percentage*100;
      cout << "..." << done << "% " << flush;
    }
    element = gr->getMeshElement(i);
    for(j=0;j<element->getNumVertices();j++){
      a = element->getVertex(j);
      b = element->getVertex((j+1)%4);
      c = element->getVertex((j+2)%4);
      d = element->getVertex((j+3)%4);

      it = vertex_to_vertices.find(a);
      if(it!=vertex_to_vertices.end()){
        it->second.insert(b);
        it->second.insert(c);
        it->second.insert(d);
      }
      else{
        bin.clear();
        bin.insert(b);
        bin.insert(c);
        bin.insert(d);
        vertex_to_vertices.insert(std::pair<MVertex*,std::set<MVertex*> >(a,bin));
      }
    }
  }
  cout << endl;
}

void Recombinator::build_vertex_to_elements(GRegion* gr){
  cout << "... stage2, building vertex->elements connectivity " << endl;
  size_t i;
  int j;
  MElement* element;
  MVertex* vertex;
  std::set<MElement*> bin;
  std::map<MVertex*,std::set<MElement*> >::iterator it;

  int nbElements = gr->getNumMeshElements();
  double percentage=0.05;
  double done=0.;
  int progress = ceil(nbElements*percentage);

  vertex_to_elements.clear();

  for(i=0;i<gr->getNumMeshElements();i++){
    if(i%progress==0){
      done += percentage*100;
      cout << "..." << done << "% " << flush;
    }
    element = gr->getMeshElement(i);
    for(j=0;j<element->getNumVertices();j++){
      vertex = element->getVertex(j);

      it = vertex_to_elements.find(vertex);
      if(it!=vertex_to_elements.end()){
        it->second.insert(element);
      }
      else{
        bin.clear();
        bin.insert(element);
        vertex_to_elements.insert(std::pair<MVertex*,std::set<MElement*> >(vertex,bin));
      }
    }
  }
  cout << endl;
}

// pour les 6 faces de l'hex, stocke les 4 "facet" (équivalent à PETriangle) possibles dans la table A
void Recombinator::build_hash_tableA(Hex hex){
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  a = hex.get_a();
  b = hex.get_b();
  c = hex.get_c();
  d = hex.get_d();
  e = hex.get_e();
  f = hex.get_f();
  g = hex.get_g();
  h = hex.get_h();

  build_hash_tableA(a,b,c,d);
  build_hash_tableA(e,f,g,h);
  build_hash_tableA(a,b,f,e);
  build_hash_tableA(b,c,g,f);
  build_hash_tableA(d,c,g,h);
  build_hash_tableA(d,a,e,h);
}

void Recombinator::build_hash_tableA(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  build_hash_tableA(Facet(a,b,c));
  build_hash_tableA(Facet(a,c,d));
  build_hash_tableA(Facet(a,b,d));
  build_hash_tableA(Facet(b,d,c));
}

void Recombinator::build_hash_tableA(Facet facet){
  bool flag;
  std::multiset<Facet>::iterator it;

  it = hash_tableA.find(facet);
  flag = 1;

  while(it!=hash_tableA.end()){
    if(facet.get_hash()!=it->get_hash()){
      break;// empoyer RANGE à la place ? + lisible ? + efficace ?
    }

    if(facet.same_vertices(*it)){
      flag = 0;
      break;
    }

    it++;
  }

  // à ce stade, flag==0 si facet existe dans la table

  if(flag){
    hash_tableA.insert(facet);
  }
}

// pour les 6 faces de l'hex, stoke les 2 "diagonal" possibles dans la table B
void Recombinator::build_hash_tableB(Hex hex){
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  a = hex.get_a();
  b = hex.get_b();
  c = hex.get_c();
  d = hex.get_d();
  e = hex.get_e();
  f = hex.get_f();
  g = hex.get_g();
  h = hex.get_h();

  build_hash_tableB(a,b,c,d);
  build_hash_tableB(e,f,g,h);
  build_hash_tableB(a,b,f,e);
  build_hash_tableB(b,c,g,f);
  build_hash_tableB(d,c,g,h);
  build_hash_tableB(d,a,e,h);
}

void Recombinator::build_hash_tableB(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  build_hash_tableB(Diagonal(a,c));
  build_hash_tableB(Diagonal(b,d));
}

void Recombinator::build_hash_tableB(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;

  it = hash_tableB.find(diagonal);
  flag = 1;

  while(it!=hash_tableB.end()){
    if(diagonal.get_hash()!=it->get_hash()){
      break;
    }

    if(diagonal.same_vertices(*it)){
      flag = 0;
      break;
    }

    it++;
  }

  if(flag){
    hash_tableB.insert(diagonal);
  }
}

// pour les 6 faces de l'hex, stoke les 12 arretes (aussi enregistrées comme "diagonal") possibles dans la table C
void Recombinator::build_hash_tableC(Hex hex){
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  a = hex.get_a();
  b = hex.get_b();
  c = hex.get_c();
  d = hex.get_d();
  e = hex.get_e();
  f = hex.get_f();
  g = hex.get_g();
  h = hex.get_h();

  build_hash_tableC(Diagonal(a,b));
  build_hash_tableC(Diagonal(b,c));
  build_hash_tableC(Diagonal(c,d));
  build_hash_tableC(Diagonal(d,a));
  build_hash_tableC(Diagonal(e,f));
  build_hash_tableC(Diagonal(f,g));
  build_hash_tableC(Diagonal(g,h));
  build_hash_tableC(Diagonal(h,e));
  build_hash_tableC(Diagonal(a,e));
  build_hash_tableC(Diagonal(b,f));
  build_hash_tableC(Diagonal(c,g));
  build_hash_tableC(Diagonal(d,h));
}

void Recombinator::build_hash_tableC(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;

  it = hash_tableC.find(diagonal);
  flag = 1;

  while(it!=hash_tableC.end()){
    if(diagonal.get_hash()!=it->get_hash()){
      break;
    }

    if(diagonal.same_vertices(*it)){
      flag = 0;
      break;
    }

    it++;
  }

  if(flag){
    hash_tableC.insert(diagonal);
  }
}

void Recombinator::print_vertex_to_vertices(GRegion* gr){
  size_t i;
  int j;
  SPoint3 p1,p2;
  MElement* element;
  MVertex* vertex;
  std::map<MVertex*,std::set<MVertex*> >::iterator it;
  std::set<MVertex*>::iterator it2;

  std::ofstream file("vertex_to_vertices.pos");
  file << "View \"test\" {\n";

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    for(j=0;j<element->getNumVertices();j++){
      vertex = element->getVertex(j);
      p1 = SPoint3(vertex->x(),vertex->y(),vertex->z());
      it = vertex_to_vertices.find(vertex);
      for(it2=(it->second).begin();it2!=(it->second).end();it2++){
        p2 = SPoint3((*it2)->x(),(*it2)->y(),(*it2)->z());
        print_segment(p1,p2,file);
      }
    }
  }
  file << "};\n";
}

void Recombinator::print_vertex_to_elements(GRegion* gr){
  size_t i;
  int j;
  MElement* element;
  MVertex* vertex;
  std::map<MVertex*,std::set<MElement*> >::iterator it;
  std::map<MVertex*,std::set<MVertex*> >::iterator it2;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    for(j=0;j<element->getNumVertices();j++){
      vertex = element->getVertex(j);
      it = vertex_to_elements.find(vertex);
      it2 = vertex_to_vertices.find(vertex);
      printf("%d %d\n",(int)(it->second).size(),(int)(it2->second).size());
    }
  }
}

void Recombinator::print_hash_tableA(){
  std::multiset<Facet>::iterator it;

  for(it=hash_tableA.begin();it!=hash_tableA.end();it++){
    printf("%lld\n",it->get_hash());
  }
}

void Recombinator::print_segment(SPoint3 p1,SPoint3 p2,std::ofstream& file){
  file << "SL ("
       << p1.x() << ", " << p1.y() << ", " << p1.z() << ", "
       << p2.x() << ", " << p2.y() << ", " << p2.z() << ")"
       << "{10, 20};\n";
}

double Recombinator::scaled_jacobian(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  double val;
  double l1,l2,l3;
  SVector3 vec1,vec2,vec3;

  vec1 = SVector3(b->x()-a->x(),b->y()-a->y(),b->z()-a->z());
  vec2 = SVector3(c->x()-a->x(),c->y()-a->y(),c->z()-a->z());
  vec3 = SVector3(d->x()-a->x(),d->y()-a->y(),d->z()-a->z());

  l1 = vec1.norm();
  l2 = vec2.norm();
  l3 = vec3.norm();

  val = dot(vec1,crossprod(vec2,vec3));
  return fabs(val)/(l1*l2*l3);
}

double Recombinator::max_scaled_jacobian(MElement* element,int& index){
  double val;
  double j1,j2,j3,j4;
  MVertex *a,*b,*c,*d;

  a = element->getVertex(0);
  b = element->getVertex(1);
  c = element->getVertex(2);
  d = element->getVertex(3);

  j1 = scaled_jacobian(a,b,c,d);
  j2 = scaled_jacobian(b,c,d,a);
  j3 = scaled_jacobian(c,d,a,b);
  j4 = scaled_jacobian(d,a,b,c);

  if(j1>=j2 && j1>=j3 && j1>=j4){
    index = 0;
    val = j1;
  }
  else if(j2>=j3 && j2>=j4 && j2>=j1){
    index = 1;
    val = j2;
  }
  else if(j3>=j4 && j3>=j1 && j3>=j2){
    index = 2;
    val = j3;
  }
  else{
    index = 3;
    val = j4;
  }

  return val;
}

double Recombinator::min_scaled_jacobian(Hex &hex){
  int i;
  double min;
  double j1,j2,j3,j4,j5,j6,j7,j8;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;
  std::vector<double> jacobians;

  a = hex.get_a();
  b = hex.get_b();
  c = hex.get_c();
  d = hex.get_d();
  e = hex.get_e();
  f = hex.get_f();
  g = hex.get_g();
  h = hex.get_h();

  j1 = scaled_jacobian(a,b,d,e);
  j2 = scaled_jacobian(b,a,c,f);
  j3 = scaled_jacobian(c,b,d,g);
  j4 = scaled_jacobian(d,a,c,h);
  j5 = scaled_jacobian(e,a,f,h);
  j6 = scaled_jacobian(f,b,e,g);
  j7 = scaled_jacobian(g,c,f,h);
  j8 = scaled_jacobian(h,d,e,g);

  jacobians.push_back(j1);
  jacobians.push_back(j2);
  jacobians.push_back(j3);
  jacobians.push_back(j4);
  jacobians.push_back(j5);
  jacobians.push_back(j6);
  jacobians.push_back(j7);
  jacobians.push_back(j8);

  min = 1000000000.0;
  for(i=0;i<8;i++){
    if(jacobians[i]<=min){
      min = jacobians[i];
    }
  }

  return min;
}

/*******************************************/
/****************class Prism****************/
/*******************************************/

Prism::Prism(){}

Prism::Prism(MVertex* a2,MVertex* b2,MVertex* c2,MVertex* d2,MVertex* e2,MVertex* f2){
  a = a2;
  b = b2;
  c = c2;
  d = d2;
  e = e2;
  f = f2;
}

Prism::~Prism(){}

double Prism::get_quality() const{
  return quality;
}

void Prism::set_quality(double new_quality){
  quality = new_quality;
}

MVertex* Prism::get_a(){
  return a;
}

MVertex* Prism::get_b(){
  return b;
}

MVertex* Prism::get_c(){
  return c;
}

MVertex* Prism::get_d(){
  return d;
}

MVertex* Prism::get_e(){
  return e;
}

MVertex* Prism::get_f(){
  return f;
}

void Prism::set_vertices(MVertex* a2,MVertex* b2,MVertex* c2,MVertex* d2,MVertex* e2,MVertex* f2){
  a = a2;
  b = b2;
  c = c2;
  d = d2;
  e = e2;
  f = f2;
}

bool Prism::operator<(const Prism& prism) const{
  return quality>prism.get_quality();
}

/***************************************************/
/****************class Supplementary****************/
/***************************************************/

Supplementary::Supplementary(){}

Supplementary::~Supplementary(){}

void Supplementary::execute(){
  GRegion* gr;
  GModel* model = GModel::current();
  GModel::riter it;

  for(it=model->firstRegion();it!=model->lastRegion();it++)
    {
      gr = *it;
      if(gr->getNumMeshElements()>0){
        execute(gr);
      }
    }
}

void Supplementary::execute(GRegion* gr){
  unsigned int i;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  printf("................PRISMS................\n");
  build_tuples(gr);
  init_markings(gr);

  build_vertex_to_vertices(gr);
  build_vertex_to_tetrahedra(gr);
  printf("connectivity\n");

  potential.clear();
  pattern(gr);
  printf("pattern\n");

  hash_tableA.clear();
  hash_tableB.clear();
  hash_tableC.clear();
  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    if(eight(element)){
      a = element->getVertex(0);
      b = element->getVertex(1);
      c = element->getVertex(2);
      d = element->getVertex(3);
      e = element->getVertex(4);
      f = element->getVertex(5);
      g = element->getVertex(6);
      h = element->getVertex(7);

      build_hash_tableA(a,b,c,d);
      build_hash_tableA(e,f,g,h);
      build_hash_tableA(a,b,f,e);
      build_hash_tableA(b,c,g,f);
      build_hash_tableA(d,c,g,h);
      build_hash_tableA(d,a,e,h);

      build_hash_tableB(a,b,c,d);
      build_hash_tableB(e,f,g,h);
      build_hash_tableB(a,b,f,e);
      build_hash_tableB(b,c,g,f);
      build_hash_tableB(d,c,g,h);
      build_hash_tableB(d,a,e,h);

      build_hash_tableC(Diagonal(a,b));
      build_hash_tableC(Diagonal(b,c));
      build_hash_tableC(Diagonal(c,d));
      build_hash_tableC(Diagonal(d,a));
      build_hash_tableC(Diagonal(e,f));
      build_hash_tableC(Diagonal(f,g));
      build_hash_tableC(Diagonal(g,h));
      build_hash_tableC(Diagonal(h,e));
      build_hash_tableC(Diagonal(a,e));
      build_hash_tableC(Diagonal(b,f));
      build_hash_tableC(Diagonal(c,g));
      build_hash_tableC(Diagonal(d,h));
    }
  }

  std::sort(potential.begin(),potential.end());

  merge(gr);

  rearrange(gr);

  statistics(gr);

  modify_surfaces(gr);
}

void Supplementary::init_markings(GRegion* gr){
  unsigned int i;
  MElement* element;

  markings.clear();

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    if(four(element)){
      markings.insert(std::pair<MElement*,bool>(element,false));
    }
  }
}

void Supplementary::pattern(GRegion* gr){
  size_t i;
  int j,k;
  double quality;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex *p,*q;
  std::vector<MVertex*> vertices;
  std::vector<MVertex*> already;
  std::set<MVertex*> bin1;
  std::set<MVertex*> bin2;
  std::set<MVertex*>::iterator it1;
  std::set<MVertex*>::iterator it2;
  Prism prism;

  vertices.resize(3);

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    if(four(element)){
      for(j=0;j<4;j++){
        a = element->getVertex(j);
        vertices[0] = element->getVertex((j+1)%4);
        vertices[1] = element->getVertex((j+2)%4);
        vertices[2] = element->getVertex((j+3)%4);
        for(k=0;k<3;k++){
          b = vertices[k%3];
          c = vertices[(k+1)%3];
          d = vertices[(k+2)%3];
          already.clear();
          already.push_back(a);
          already.push_back(b);
          already.push_back(c);
          already.push_back(d);
          bin1.clear();
          bin2.clear();
          find(b,d,already,bin1);
          find(c,d,already,bin2);
          for(it1=bin1.begin();it1!=bin1.end();it1++){
            p = *it1;
            for(it2=bin2.begin();it2!=bin2.end();it2++){
              q = *it2;
              if(p!=q && linked(p,q)){
                prism = Prism(a,b,c,d,p,q);
                quality = min_scaled_jacobian(prism);
                prism.set_quality(quality);
                if(valid(prism)){
                  potential.push_back(prism);
                }
              }
            }
          }
        }
      }
    }
  }
}

void Supplementary::merge(GRegion* gr){
  unsigned int i;
  int count;
  bool flag;
  double threshold;
  double quality;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;
  MElement* element;
  std::set<MElement*> parts;
  std::vector<MTetrahedron*> opt;
  std::set<MElement*>::iterator it;
  std::map<MElement*,bool>::iterator it2;
  Prism prism;

  count = 1;
  quality = 0.0;

  for(i=0;i<potential.size();i++){
    prism = potential[i];

    threshold = 0.15;
    if(prism.get_quality()<threshold){
      break;
    }

    a = prism.get_a();
    b = prism.get_b();
    c = prism.get_c();
    d = prism.get_d();
    e = prism.get_e();
    f = prism.get_f();

    parts.clear();
    find(a,prism,parts);
    find(b,prism,parts);
    find(c,prism,parts);
    find(d,prism,parts);
    find(e,prism,parts);
    find(f,prism,parts);

    flag = 1;
    for(it=parts.begin();it!=parts.end();it++){
      element = *it;
      it2 = markings.find(element);
      if(it2->second==1 && !sliver(element,prism)){
        flag = 0;
        break;
      }
    }
    if(!flag) continue;

    if(!valid(prism,parts)){
      continue;
    }

    if(!conformityA(prism)){
      continue;
    }

    if(!conformityB(prism)){
      continue;
    }

    if(!conformityC(prism)){
      continue;
    }

    if(!faces_statuquo(prism)){
      continue;
    }

    //printf("%d - %d/%d - %f\n",count,i,(int)potential.size(),prism.get_quality());
    quality = quality + prism.get_quality();
    for(it=parts.begin();it!=parts.end();it++){
      element = *it;
      it2 = markings.find(element);
      it2->second = 1;
    }
    gr->addPrism(new MPrism(a,b,c,d,e,f));
    build_hash_tableA(prism);
    build_hash_tableB(prism);
    build_hash_tableC(prism);
    count++;
  }

  opt.clear();
  opt.resize(gr->tetrahedra.size());
  opt = gr->tetrahedra;
  gr->tetrahedra.clear();

  for(i=0;i<opt.size();i++){
    element = (MElement*)(opt[i]);
    it2 = markings.find(element);
    if(it2->second==0){
      gr->tetrahedra.push_back(opt[i]);
    }
  }

  printf("prisms average quality (0->1) : %f\n",quality/count);
}

void Supplementary::rearrange(GRegion* gr){
  size_t i;
  MElement* element;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    element->setVolumePositive();
  }
}

void Supplementary::statistics(GRegion* gr){
  size_t i;
  int all_nbr,prism_nbr;
  double all_volume,prism_volume,volume;
  MElement* element;

  all_nbr = 0;
  prism_nbr = 0;
  all_volume = 0.0;
  prism_volume = 0.0;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    volume = element->getVolume();

    if(six(element)){
      prism_nbr = prism_nbr + 1;
      prism_volume = prism_volume + volume;
    }

    all_nbr = all_nbr + 1;
    all_volume = all_volume + volume;
  }

  printf("percentage of prisms (number) : %.2f\n",prism_nbr*100.0/all_nbr);
  printf("percentage of prisms (volume) : %.2f\n",prism_volume*100.0/all_volume);
}

void Supplementary::build_tuples(GRegion* gr){
  unsigned int i;
  MVertex *a,*b,*c;
  MElement* element;
  GFace* gf;
  std::list<GFace*> faces;
  std::list<GFace*>::iterator it;

  tuples.clear();
  triangles.clear();
  faces.clear();

  faces = gr->faces();

  for(it=faces.begin();it!=faces.end();it++)
    {
      gf = *it;

      for(i=0;i<gf->getNumMeshElements();i++){
        element = gf->getMeshElement(i);

        if(element->getNumVertices()==3){
          a = element->getVertex(0);
          b = element->getVertex(1);
          c = element->getVertex(2);

          tuples.insert(Tuple(a,b,c,element,gf));
        }
      }
    }
}

void Supplementary::modify_surfaces(GRegion* gr){
  unsigned int i;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;
  MElement* element;
  GFace* gf;
  std::list<GFace*> faces;
  std::vector<MElement*> opt;
  std::list<GFace*>::iterator it;
  std::set<MElement*>::iterator it2;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);

    if(element->getNumVertices()==6){
      a = element->getVertex(0);
      b = element->getVertex(1);
      c = element->getVertex(2);
      d = element->getVertex(3);
      e = element->getVertex(4);
      f = element->getVertex(5);

      modify_surfaces(a,d,e,b);
      modify_surfaces(a,d,f,c);
      modify_surfaces(b,e,f,c);
    }
  }

  faces = gr->faces();

  for(it=faces.begin();it!=faces.end();it++)
    {
      gf = *it;

      opt.clear();

      for(i=0;i<gf->getNumMeshElements();i++){
        element = gf->getMeshElement(i);

        if(element->getNumVertices()==3){
          it2 = triangles.find(element);
          if(it2==triangles.end()){
            opt.push_back(element);
          }
        }
      }

      gf->triangles.clear();

      for(i=0;i<opt.size();i++){
        gf->triangles.push_back((MTriangle*)opt[i]);
      }
    }
}

void Supplementary::modify_surfaces(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  bool flag1,flag2;
  MElement *element1,*element2;
  GFace *gf1;//,*gf2;
  Tuple tuple1,tuple2;
  std::multiset<Tuple>::iterator it1;
  std::multiset<Tuple>::iterator it2;

  gf1 = NULL;
  //gf2 = NULL;

  tuple1 = Tuple(a,b,c);
  tuple2 = Tuple(c,d,a);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1!=tuples.end()){
    if(tuple1.get_hash()!=it1->get_hash()){
      break;
    }

    if(tuple1.same_vertices(*it1)){
      flag1 = 1;
      element1 = it1->get_element();
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2!=tuples.end()){
    if(tuple2.get_hash()!=it2->get_hash()){
      break;
    }

    if(tuple2.same_vertices(*it2)){
      flag2 = 1;
      element2 = it2->get_element();
      //gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2){
    triangles.insert(element1);
    triangles.insert(element2);

    gf1->addQuadrangle(new MQuadrangle(a,b,c,d));
  }

  tuple1 = Tuple(a,b,d);
  tuple2 = Tuple(b,c,d);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1!=tuples.end()){
    if(tuple1.get_hash()!=it1->get_hash()){
      break;
    }

    if(tuple1.same_vertices(*it1)){
      flag1 = 1;
      element1 = it1->get_element();
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2!=tuples.end()){
    if(tuple2.get_hash()!=it2->get_hash()){
      break;
    }

    if(tuple2.same_vertices(*it2)){
      flag2 = 1;
      element2 = it2->get_element();
      //gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2){
    triangles.insert(element1);
    triangles.insert(element2);

    gf1->addQuadrangle(new MQuadrangle(a,b,c,d));
  }
}

bool Supplementary::four(MElement* element){
  if(element->getNumVertices()==4) return 1;
  else return 0;
}

bool Supplementary::five(MElement* element){
  if(element->getNumVertices()==5) return 1;
  else return 0;
}

bool Supplementary::six(MElement* element){
  if(element->getNumVertices()==6) return 1;
  else return 0;
}

bool Supplementary::eight(MElement* element){
  if(element->getNumVertices()==8) return 1;
  else return 0;
}

bool Supplementary::sliver(MElement* element,Prism prism){
  bool val;
  bool flag1,flag2,flag3,flag4;
  MVertex *a,*b,*c,*d;

  val = 0;
  a = element->getVertex(0);
  b = element->getVertex(1);
  c = element->getVertex(2);
  d = element->getVertex(3);

  flag1 = inclusion(a,prism.get_a(),prism.get_d(),prism.get_f(),prism.get_c());
  flag2 = inclusion(b,prism.get_a(),prism.get_d(),prism.get_f(),prism.get_c());
  flag3 = inclusion(c,prism.get_a(),prism.get_d(),prism.get_f(),prism.get_c());
  flag4 = inclusion(d,prism.get_a(),prism.get_d(),prism.get_f(),prism.get_c());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 = inclusion(a,prism.get_a(),prism.get_b(),prism.get_e(),prism.get_d());
  flag2 = inclusion(b,prism.get_a(),prism.get_b(),prism.get_e(),prism.get_d());
  flag3 = inclusion(c,prism.get_a(),prism.get_b(),prism.get_e(),prism.get_d());
  flag4 = inclusion(d,prism.get_a(),prism.get_b(),prism.get_e(),prism.get_d());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  flag1 = inclusion(a,prism.get_b(),prism.get_c(),prism.get_f(),prism.get_e());
  flag2 = inclusion(b,prism.get_b(),prism.get_c(),prism.get_f(),prism.get_e());
  flag3 = inclusion(c,prism.get_b(),prism.get_c(),prism.get_f(),prism.get_e());
  flag4 = inclusion(d,prism.get_b(),prism.get_c(),prism.get_f(),prism.get_e());
  if(flag1 && flag2 && flag3 && flag4) val = 1;

  return val;
}

bool Supplementary::valid(Prism prism,const std::set<MElement*>& parts){
  bool ok1,ok2,ok3,ok4;
  bool flag1A,flag1B,flag1C,flag1D;
  bool flag2A,flag2B,flag2C,flag2D;
  bool flag3A,flag3B,flag3C,flag3D;
  bool flag4,flag5;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  flag1A = inclusion(a,d,f,parts);
  flag1B = inclusion(a,f,c,parts);
  flag1C = inclusion(a,c,d,parts);
  flag1D = inclusion(c,d,f,parts);
  ok1 = (flag1A && flag1B) || (flag1C && flag1D);

  flag2A = inclusion(a,b,d,parts);
  flag2B = inclusion(b,d,e,parts);
  flag2C = inclusion(a,d,e,parts);
  flag2D = inclusion(a,b,e,parts);
  ok2 = (flag2A && flag2B) || (flag2C && flag2D);

  flag3A = inclusion(b,c,f,parts);
  flag3B = inclusion(b,e,f,parts);
  flag3C = inclusion(b,c,e,parts);
  flag3D = inclusion(c,e,f,parts);
  ok3 = (flag3A && flag3B) || (flag3C && flag3D);

  flag4 = inclusion(a,b,c,parts);
  flag5 = inclusion(d,e,f,parts);
  ok4 = flag4 && flag5;

  if(ok1 && ok2 && ok3 && ok4){
    return 1;
  }
  else{
    return 0;
  }
}

bool Supplementary::valid(Prism prism){
  double k;
  double eta1,eta2,eta3;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;

  k = 0.000001;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  eta1 = eta(a,d,f,c);
  eta2 = eta(a,b,e,d);
  eta3 = eta(b,c,f,e);

  if(eta1>k && eta2>k && eta3>k){
    return 1;
  }
  else{
    return 0;
  }
}

double Supplementary::eta(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  double val;
  MQuadrangle* quad;

  quad = new MQuadrangle(a,b,c,d);
  val = quad->etaShapeMeasure();
  delete quad;
  return val;
}

bool Supplementary::linked(MVertex* v1,MVertex* v2){
  bool flag;
  std::map<MVertex*,std::set<MVertex*> >::iterator it;
  std::set<MVertex*>::iterator it2;

  it = vertex_to_vertices.find(v1);
  flag = 0;

  if(it!=vertex_to_vertices.end()){
    for(it2=(it->second).begin();it2!=(it->second).end();it2++){
      if(*it2==v2){
        flag = 1;
        break;
      }
    }
  }

  return flag;
}

void Supplementary::find(MVertex* v1,MVertex* v2,const std::vector<MVertex*>& already,std::set<MVertex*>& final){
  std::map<MVertex*,std::set<MVertex*> >::iterator it1;
  std::map<MVertex*,std::set<MVertex*> >::iterator it2;

  it1 = vertex_to_vertices.find(v1);
  it2 = vertex_to_vertices.find(v2);

  if(it1!=vertex_to_vertices.end() && it2!=vertex_to_vertices.end()){
    intersection(it1->second,it2->second,already,final);
  }
}

void Supplementary::find(MVertex* vertex,Prism prism,std::set<MElement*>& final){
  bool flag1,flag2,flag3,flag4;
  MVertex *a,*b,*c,*d;
  std::map<MVertex*,std::set<MElement*> >::iterator it;
  std::set<MElement*>::iterator it2;

  it = vertex_to_tetrahedra.find(vertex);

  if(it!=vertex_to_tetrahedra.end()){
    for(it2=(it->second).begin();it2!=(it->second).end();it2++){
      a = (*it2)->getVertex(0);
      b = (*it2)->getVertex(1);
      c = (*it2)->getVertex(2);
      d = (*it2)->getVertex(3);

      flag1 = inclusion(a,prism);
      flag2 = inclusion(b,prism);
      flag3 = inclusion(c,prism);
      flag4 = inclusion(d,prism);

      if(flag1 && flag2 && flag3 && flag4){
        final.insert(*it2);
      }
    }
  }
}

void Supplementary::intersection(const std::set<MVertex*>& bin1,const std::set<MVertex*>& bin2,
                                 const std::vector<MVertex*>& already,std::set<MVertex*>& final){
  size_t i;
  bool ok;
  std::set<MVertex*> temp;
  std::set<MVertex*>::iterator it;

  std::set_intersection(bin1.begin(),bin1.end(),bin2.begin(),bin2.end(),std::inserter(temp,temp.end()));

  for(it=temp.begin();it!=temp.end();it++){
    ok = 1;

    for(i=0;i<already.size();i++){
      if((*it)==already[i]){
        ok = 0;
        break;
      }
    }

    if(ok){
      final.insert(*it);
    }
  }
}

bool Supplementary::inclusion(MVertex* vertex,Prism prism){
  bool flag;

  flag = 0;

  if(vertex==prism.get_a()) flag = 1;
  else if(vertex==prism.get_b()) flag = 1;
  else if(vertex==prism.get_c()) flag = 1;
  else if(vertex==prism.get_d()) flag = 1;
  else if(vertex==prism.get_e()) flag = 1;
  else if(vertex==prism.get_f()) flag = 1;

  return flag;
}

bool Supplementary::inclusion(MVertex* vertex,MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  bool flag;

  flag = 0;

  if(vertex==a) flag = 1;
  else if(vertex==b) flag = 1;
  else if(vertex==c) flag = 1;
  else if(vertex==d) flag = 1;

  return flag;
}

bool Supplementary::inclusion(MVertex* v1,MVertex* v2,MVertex* v3,const std::set<MElement*>& bin){
  bool ok;
  bool flag1,flag2,flag3;
  MVertex *a,*b,*c,*d;
  MElement* element;
  std::set<MElement*>::const_iterator it;

  ok = 0;

  for(it=bin.begin();it!=bin.end();it++){
    element = *it;

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);

    flag1 = inclusion(v1,a,b,c,d);
    flag2 = inclusion(v2,a,b,c,d);
    flag3 = inclusion(v3,a,b,c,d);

    if(flag1 && flag2 && flag3){
      ok = 1;
      break;
    }
  }

  return ok;
}

bool Supplementary::inclusion(Facet facet){
  bool flag;
  std::multiset<Facet>::iterator it;

  it = hash_tableA.find(facet);
  flag = 0;

  while(it!=hash_tableA.end()){
    if(facet.get_hash()!=it->get_hash()){
      break;
    }

    if(facet.same_vertices(*it)){
      flag = 1;
      break;
    }

    it++;
  }

  return flag;
}

bool Supplementary::inclusion(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;

  it = hash_tableB.find(diagonal);
  flag = 0;

  while(it!=hash_tableB.end()){
    if(diagonal.get_hash()!=it->get_hash()){
      break;
    }

    if(diagonal.same_vertices(*it)){
      flag = 1;
      break;
    }

    it++;
  }

  return flag;
}

bool Supplementary::duplicate(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;

  it = hash_tableC.find(diagonal);
  flag = 0;

  while(it!=hash_tableC.end()){
    if(diagonal.get_hash()!=it->get_hash()){
      break;
    }

    if(diagonal.same_vertices(*it)){
      flag = 1;
      break;
    }

    it++;
  }

  return flag;
}

bool Supplementary::conformityA(Prism prism){
  bool c1,c2,c3;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  c1 = conformityA(a,d,f,c);
  c2 = conformityA(a,d,e,b);
  c3 = conformityA(b,c,f,e);

  return c1 && c2 && c3;
}

bool Supplementary::conformityA(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  bool c1,c2,c3,c4;

  c1 = inclusion(Facet(a,b,c));
  c2 = inclusion(Facet(a,c,d));
  c3 = inclusion(Facet(a,b,d));
  c4 = inclusion(Facet(b,c,d));

  return (c1 && c2 && c3 && c4) || (!c1 && !c2 && !c3 && !c4);
}

bool Supplementary::conformityB(Prism prism){
  bool flag1;
  bool flag2;
  bool c1,c2,c3;
  bool c4,c5,c6;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  flag1 = inclusion(Diagonal(a,c));
  flag1 = flag1 || inclusion(Diagonal(d,f));
  flag1 = flag1 || inclusion(Diagonal(d,a));
  flag1 = flag1 || inclusion(Diagonal(f,c));
  flag1 = flag1 || inclusion(Diagonal(e,b));
  flag1 = flag1 || inclusion(Diagonal(d,e));
  flag1 = flag1 || inclusion(Diagonal(e,f));
  flag1 = flag1 || inclusion(Diagonal(a,b));
  flag1 = flag1 || inclusion(Diagonal(b,c));

  c1 = inclusion(Diagonal(a,f));
  c2 = inclusion(Diagonal(d,c));
  flag2 = (c1 && !c2) || (!c1 && c2);
  c3 = inclusion(Diagonal(a,e));
  c4 = inclusion(Diagonal(b,d));
  flag2 = flag2 || (c3 && !c4) || (!c3 && c4);
  c5 = inclusion(Diagonal(b,f));
  c6 = inclusion(Diagonal(c,e));
  flag2 = flag2 || (c5 && !c6) || (!c5 && c6);

  if(flag1 || flag2){
    return 0;
  }
  else{
    return 1;
  }
}

bool Supplementary::conformityC(Prism prism){
  bool flag;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  flag = duplicate(Diagonal(a,f));
  flag = flag || duplicate(Diagonal(d,c));
  flag = flag || duplicate(Diagonal(a,e));
  flag = flag || duplicate(Diagonal(b,d));
  flag = flag || duplicate(Diagonal(b,f));
  flag = flag || duplicate(Diagonal(c,e));

  if(flag){
    return 0;
  }
  else{
    return 1;
  }
}

bool Supplementary::faces_statuquo(Prism prism){
  bool c1,c2,c3;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  c1 = faces_statuquo(a,d,f,c);
  c2 = faces_statuquo(a,d,e,b);
  c3 = faces_statuquo(b,c,f,e);

  return c1 && c2 && c3;
}

bool Supplementary::faces_statuquo(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  bool ok;
  bool flag1,flag2;
  GFace *gf1,*gf2;
  Tuple tuple1,tuple2;
  std::multiset<Tuple>::iterator it1;
  std::multiset<Tuple>::iterator it2;

  ok = 1;

  gf1 = NULL;
  gf2 = NULL;

  tuple1 = Tuple(a,b,c);
  tuple2 = Tuple(c,d,a);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1!=tuples.end()){
    if(tuple1.get_hash()!=it1->get_hash()){
      break;
    }

    if(tuple1.same_vertices(*it1)){
      flag1 = 1;
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2!=tuples.end()){
    if(tuple2.get_hash()!=it2->get_hash()){
      break;
    }

    if(tuple2.same_vertices(*it2)){
      flag2 = 1;
      gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2){
    if(gf1!=gf2){
      ok = 0;
    }
  }

  tuple1 = Tuple(a,b,d);
  tuple2 = Tuple(b,c,d);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1!=tuples.end()){
    if(tuple1.get_hash()!=it1->get_hash()){
      break;
    }

    if(tuple1.same_vertices(*it1)){
      flag1 = 1;
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2!=tuples.end()){
    if(tuple2.get_hash()!=it2->get_hash()){
      break;
    }

    if(tuple2.same_vertices(*it2)){
      flag2 = 1;
      gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2){
    if(gf1!=gf2){
      ok = 0;
    }
  }

  return ok;
}

void Supplementary::build_vertex_to_vertices(GRegion* gr){
  size_t i;
  int j;
  MElement* element;
  MVertex *a,*b,*c,*d;
  std::set<MVertex*> bin;
  std::map<MVertex*,std::set<MVertex*> >::iterator it;

  vertex_to_vertices.clear();

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    if(four(element)){
      for(j=0;j<element->getNumVertices();j++){
        a = element->getVertex(j);
        b = element->getVertex((j+1)%4);
        c = element->getVertex((j+2)%4);
        d = element->getVertex((j+3)%4);

        it = vertex_to_vertices.find(a);
        if(it!=vertex_to_vertices.end()){
          it->second.insert(b);
          it->second.insert(c);
          it->second.insert(d);
        }
        else{
          bin.clear();
          bin.insert(b);
          bin.insert(c);
          bin.insert(d);
          vertex_to_vertices.insert(std::pair<MVertex*,std::set<MVertex*> >(a,bin));
        }
      }
    }
  }
}

void Supplementary::build_vertex_to_tetrahedra(GRegion* gr){
  unsigned int i;
  int j;
  MElement* element;
  MVertex* vertex;
  std::set<MElement*> bin;
  std::map<MVertex*,std::set<MElement*> >::iterator it;

  vertex_to_tetrahedra.clear();

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    if(four(element)){
      for(j=0;j<element->getNumVertices();j++){
        vertex = element->getVertex(j);

        it = vertex_to_tetrahedra.find(vertex);
        if(it!=vertex_to_tetrahedra.end()){
          it->second.insert(element);
        }
        else{
          bin.clear();
          bin.insert(element);
          vertex_to_tetrahedra.insert(std::pair<MVertex*,std::set<MElement*> >(vertex,bin));
        }
      }
    }
  }
}

void Supplementary::build_hash_tableA(Prism prism){
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  build_hash_tableA(a,d,f,c);
  build_hash_tableA(a,d,e,b);
  build_hash_tableA(b,c,f,e);
}

void Supplementary::build_hash_tableA(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  build_hash_tableA(Facet(a,b,c));
  build_hash_tableA(Facet(a,c,d));
  build_hash_tableA(Facet(a,b,d));
  build_hash_tableA(Facet(b,d,c));
}

void Supplementary::build_hash_tableA(Facet facet){
  bool flag;
  std::multiset<Facet>::iterator it;

  it = hash_tableA.find(facet);
  flag = 1;

  while(it!=hash_tableA.end()){
    if(facet.get_hash()!=it->get_hash()){
      break;
    }

    if(facet.same_vertices(*it)){
      flag = 0;
      break;
    }

    it++;
  }

  if(flag){
    hash_tableA.insert(facet);
  }
}

void Supplementary::build_hash_tableB(Prism prism){
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  build_hash_tableB(a,d,f,c);
  build_hash_tableB(a,d,e,b);
  build_hash_tableB(b,e,f,c);
}

void Supplementary::build_hash_tableB(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  build_hash_tableB(Diagonal(a,c));
  build_hash_tableB(Diagonal(b,d));
}

void Supplementary::build_hash_tableB(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;

  it = hash_tableB.find(diagonal);
  flag = 1;

  while(it!=hash_tableB.end()){
    if(diagonal.get_hash()!=it->get_hash()){
      break;
    }

    if(diagonal.same_vertices(*it)){
      flag = 0;
      break;
    }

    it++;
  }

  if(flag){
    hash_tableB.insert(diagonal);
  }
}

void Supplementary::build_hash_tableC(Prism prism){
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  build_hash_tableC(Diagonal(a,d));
  build_hash_tableC(Diagonal(d,f));
  build_hash_tableC(Diagonal(f,c));
  build_hash_tableC(Diagonal(a,c));
  build_hash_tableC(Diagonal(e,b));
  build_hash_tableC(Diagonal(d,e));
  build_hash_tableC(Diagonal(f,e));
  build_hash_tableC(Diagonal(a,b));
  build_hash_tableC(Diagonal(b,c));
}

void Supplementary::build_hash_tableC(Diagonal diagonal){
  bool flag;
  std::multiset<Diagonal>::iterator it;

  it = hash_tableC.find(diagonal);
  flag = 1;

  while(it!=hash_tableC.end()){
    if(diagonal.get_hash()!=it->get_hash()){
      break;
    }

    if(diagonal.same_vertices(*it)){
      flag = 0;
      break;
    }

    it++;
  }

  if(flag){
    hash_tableC.insert(diagonal);
  }
}

double Supplementary::scaled_jacobian(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  double val;
  double l1,l2,l3;
  SVector3 vec1,vec2,vec3;

  vec1 = SVector3(b->x()-a->x(),b->y()-a->y(),b->z()-a->z());
  vec2 = SVector3(c->x()-a->x(),c->y()-a->y(),c->z()-a->z());
  vec3 = SVector3(d->x()-a->x(),d->y()-a->y(),d->z()-a->z());

  l1 = vec1.norm();
  l2 = vec2.norm();
  l3 = vec3.norm();

  val = dot(vec1,crossprod(vec2,vec3));
  return fabs(val)/(l1*l2*l3);
}

double Supplementary::min_scaled_jacobian(Prism prism){
  int i;
  double min;
  double j1,j2,j3,j4,j5,j6;
  MVertex *a,*b,*c;
  MVertex *d,*e,*f;
  std::vector<double> jacobians;

  a = prism.get_a();
  b = prism.get_b();
  c = prism.get_c();
  d = prism.get_d();
  e = prism.get_e();
  f = prism.get_f();

  j1 = scaled_jacobian(a,b,c,d);
  j2 = scaled_jacobian(b,a,c,e);
  j3 = scaled_jacobian(c,a,b,f);
  j4 = scaled_jacobian(d,a,e,f);
  j5 = scaled_jacobian(e,b,d,f);
  j6 = scaled_jacobian(f,c,d,e);

  jacobians.push_back(j1);
  jacobians.push_back(j2);
  jacobians.push_back(j3);
  jacobians.push_back(j4);
  jacobians.push_back(j5);
  jacobians.push_back(j6);

  min = 1000000000.0;
  for(i=0;i<6;i++){
    if(jacobians[i]<=min){
      min = jacobians[i];
    }
  }

  return min;
}

/********************************************/
/****************class PostOp****************/
/********************************************/

PostOp::PostOp(){}

PostOp::~PostOp(){}

void PostOp::execute(bool flag){
  GRegion* gr;
  GModel* model = GModel::current();
  GModel::riter it;

  for(it=model->firstRegion();it!=model->lastRegion();it++)
    {
      gr = *it;
      if(gr->getNumMeshElements()>0){
        execute(gr,flag);
      }
    }
}

void PostOp::execute(GRegion* gr,bool flag){
  printf("................PYRAMIDS................\n");
  estimate1 = 0;
  estimate2 = 0;
  iterations = 0;

  build_tuples(gr);
  init_markings(gr);
  build_vertex_to_tetrahedra(gr);
  pyramids1(gr);
  rearrange(gr);

  if(flag){
    init_markings(gr);
    build_vertex_to_tetrahedra(gr);
    build_vertex_to_pyramids(gr);
    pyramids2(gr);
    rearrange(gr);
  }

  statistics(gr);

  modify_surfaces(gr);
}

void PostOp::init_markings(GRegion* gr){
  unsigned int i;
  MElement* element;

  markings.clear();

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    if(four(element) || five(element)){
      markings.insert(std::pair<MElement*,bool>(element,false));
    }
  }
}

void PostOp::pyramids1(GRegion* gr){
  unsigned int i;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;
  MElement* element;
  std::vector<MElement*> hexahedra;
  std::vector<MElement*> prisms;
  std::vector<MTetrahedron*> opt;
  std::map<MElement*,bool>::iterator it;

  hexahedra.clear();
  prisms.clear();

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    if(eight(element)){
      hexahedra.push_back(element);
    }
    else if(six(element)){
      prisms.push_back(element);
    }
  }

  for(i=0;i<hexahedra.size();i++){
    element = hexahedra[i];

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);
    e = element->getVertex(4);
    f = element->getVertex(5);
    g = element->getVertex(6);
    h = element->getVertex(7);

    pyramids1(a,b,c,d,gr);
    pyramids1(e,f,g,h,gr);
    pyramids1(a,b,f,e,gr);
    pyramids1(b,c,g,f,gr);
    pyramids1(d,c,g,h,gr);
    pyramids1(d,a,e,h,gr);
  }

  for(i=0;i<prisms.size();i++){
    element = prisms[i];

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);
    e = element->getVertex(4);
    f = element->getVertex(5);

    pyramids1(a,d,f,c,gr);
    pyramids1(a,b,e,d,gr);
    pyramids1(b,c,f,e,gr);
  }

  opt.clear();
  opt.resize(gr->tetrahedra.size());
  opt = gr->tetrahedra;
  gr->tetrahedra.clear();

  for(i=0;i<opt.size();i++){
    element = (MElement*)(opt[i]);
    it = markings.find(element);
    if(it->second==0){
      gr->tetrahedra.push_back(opt[i]);
    }
  }
}

void PostOp::pyramids2(GRegion* gr){
  unsigned int i;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;
  MElement* element;
  std::vector<MElement*> hexahedra;
  std::vector<MElement*> prisms;
  std::vector<MTetrahedron*> opt1;
  std::vector<MPyramid*> opt2;
  std::map<MElement*,bool>::iterator it;

  hexahedra.clear();
  prisms.clear();

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    if(eight(element)){
      hexahedra.push_back(element);
    }
    else if(six(element)){
      prisms.push_back(element);
    }
  }

  for(i=0;i<hexahedra.size();i++){
    element = hexahedra[i];

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);
    e = element->getVertex(4);
    f = element->getVertex(5);
    g = element->getVertex(6);
    h = element->getVertex(7);

    pyramids2(a,b,c,d,gr);
    pyramids2(e,f,g,h,gr);
    pyramids2(a,b,f,e,gr);
    pyramids2(b,c,g,f,gr);
    pyramids2(d,c,g,h,gr);
    pyramids2(d,a,e,h,gr);
  }

  for(i=0;i<prisms.size();i++){
    element = prisms[i];

    a = element->getVertex(0);
    b = element->getVertex(1);
    c = element->getVertex(2);
    d = element->getVertex(3);
    e = element->getVertex(4);
    f = element->getVertex(5);

    pyramids2(a,d,f,c,gr);
    pyramids2(a,b,e,d,gr);
    pyramids2(b,c,f,e,gr);
  }

  opt1.clear();
  opt1.resize(gr->tetrahedra.size());
  opt1 = gr->tetrahedra;
  gr->tetrahedra.clear();

  for(i=0;i<opt1.size();i++){
    element = (MElement*)(opt1[i]);
    it = markings.find(element);
    if(it->second==0){
      gr->tetrahedra.push_back(opt1[i]);
    }
  }

  opt2.clear();
  opt2.resize(gr->pyramids.size());
  opt2 = gr->pyramids;
  gr->pyramids.clear();

  for(i=0;i<opt2.size();i++){
    element = (MElement*)(opt2[i]);
    it = markings.find(element);
    if(it->second==0){
      gr->pyramids.push_back(opt2[i]);
    }
  }
}

void PostOp::pyramids1(MVertex* a,MVertex* b,MVertex* c,MVertex* d,GRegion* gr){
  MVertex* vertex;
  std::set<MElement*> bin;
  std::set<MElement*> bin1;
  std::set<MElement*> bin2;
  std::set<MElement*>::iterator it;
  std::map<MElement*,bool>::iterator it1;
  std::map<MElement*,bool>::iterator it2;

  bin1.clear();
  bin2.clear();
  find_tetrahedra(a,c,bin1);
  find_tetrahedra(b,d,bin2);

  bin.clear();
  for(it=bin1.begin();it!=bin1.end();it++){
    bin.insert(*it);
  }
  for(it=bin2.begin();it!=bin2.end();it++){
    bin.insert(*it);
  }

  if(bin.size()==2){
    it = bin.begin();
    it1 = markings.find(*it);
    it++;
    it2 = markings.find(*it);

    if(it1->second==0 && it2->second==0){
      vertex = find(a,b,c,d,*it);

      if(vertex!=0){
        gr->addPyramid(new MPyramid(a,b,c,d,vertex));
        it1->second = 1;
        it2->second = 1;
      }
    }
  }
}

void PostOp::pyramids2(MVertex* a,MVertex* b,MVertex* c,MVertex* d,GRegion* gr){
  bool flag;
  double x,y,z;
  MVertex* mid;
  MVertex *diagA,*diagB;
  MVertex *N1,*N2;
  MVertex *v1,*v2,*v3,*v4,*v5;
  MTetrahedron* temp;
  MPyramid* temp2;
  std::vector<MElement*> movables;
  std::set<MVertex*> Ns;
  std::set<MElement*> bin1;
  std::set<MElement*> bin2;
  std::set<MElement*> bin3;
  std::set<MElement*> bin4;
  std::set<MElement*> tetrahedra;
  std::set<MElement*> pyramids;
  std::set<MElement*>::iterator it;
  std::map<MElement*,bool>::iterator it2;

  flag = 0;

  bin1.clear();
  bin2.clear();
  find_tetrahedra(a,c,bin1);
  find_tetrahedra(b,d,bin2);
  if(bin1.size()!=0) flag = 1;

  bin3.clear();
  bin4.clear();
  find_pyramids(a,c,bin3);
  find_pyramids(b,d,bin4);
  if(bin3.size()!=0) flag = 1;

  tetrahedra.clear();
  for(it=bin1.begin();it!=bin1.end();it++){
    tetrahedra.insert(*it);
  }
  for(it=bin2.begin();it!=bin2.end();it++){
    tetrahedra.insert(*it);
  }

  pyramids.clear();
  for(it=bin3.begin();it!=bin3.end();it++){
    pyramids.insert(*it);
  }
  for(it=bin4.begin();it!=bin4.end();it++){
    pyramids.insert(*it);
  }

  /*if(pyramids.size()==0 && tetrahedra.size()==1){
    printf("tetrahedron deleted\n");
    it2 = markings.find(*tetrahedra.begin());
    it2->second = 1;
    return;
    }*/

  if(flag){
    diagA = a;
    diagB = c;
  }
  else{
    diagA = b;
    diagB = d;
  }

  Ns.clear();
  Ns.insert(diagA);
  Ns.insert(diagB);

  x = (diagA->x() + diagB->x())/2.0;
  y = (diagA->y() + diagB->y())/2.0;
  z = (diagA->z() + diagB->z())/2.0;

  mid = 0;
  movables.clear();

  if(tetrahedra.size()>0 || pyramids.size()>0){
    estimate1 = estimate1 + tetrahedra.size() + 2*pyramids.size();
    estimate2 = estimate2 + 1;

    mid = new MVertex(x,y,z,gr);
    gr->addMeshVertex(mid);

    temp2 = new MPyramid(a,b,c,d,mid);
    gr->addPyramid(temp2);
    markings.insert(std::pair<MElement*,bool>(temp2,false));
    build_vertex_to_pyramids(temp2);

    for(it=tetrahedra.begin();it!=tetrahedra.end();it++){
      N1 = other(*it,diagA,diagB);
      N2 = other(*it,diagA,diagB,N1);

      if(N1!=0 && N2!=0){
        Ns.insert(N1);
        Ns.insert(N2);

        temp = new MTetrahedron(N1,N2,diagA,mid);
        gr->addTetrahedron(temp);
        markings.insert(std::pair<MElement*,bool>(temp,false));
        build_vertex_to_tetrahedra(temp);
        movables.push_back(temp);

        temp = new MTetrahedron(N1,N2,diagB,mid);
        gr->addTetrahedron(temp);
        markings.insert(std::pair<MElement*,bool>(temp,false));
        build_vertex_to_tetrahedra(temp);
        movables.push_back(temp);

        it2 = markings.find(*it);
        it2->second = 1;
        erase_vertex_to_tetrahedra(*it);
      }
    }

    for(it=pyramids.begin();it!=pyramids.end();it++){
      v1 = (*it)->getVertex(0);
      v2 = (*it)->getVertex(1);
      v3 = (*it)->getVertex(2);
      v4 = (*it)->getVertex(3);
      v5 = (*it)->getVertex(4);

      if(v1!=diagA && v1!=diagB){
        Ns.insert(v1);
      }
      if(v2!=diagA && v2!=diagB){
        Ns.insert(v2);
      }
      if(v3!=diagA && v3!=diagB){
        Ns.insert(v3);
      }
      if(v4!=diagA && v4!=diagB){
        Ns.insert(v4);
      }
      if(v5!=diagA && v5!=diagB){
        Ns.insert(v5);
      }

      temp2 = new MPyramid(v1,v2,v3,v4,mid);
      gr->addPyramid(temp2);
      markings.insert(std::pair<MElement*,bool>(temp2,false));
      build_vertex_to_pyramids(temp2);

      if(different(v1,v2,diagA,diagB)){
        temp = new MTetrahedron(v1,v2,mid,v5);
        gr->addTetrahedron(temp);
        markings.insert(std::pair<MElement*,bool>(temp,false));
        build_vertex_to_tetrahedra(temp);
        movables.push_back(temp);
      }

      if(different(v2,v3,diagA,diagB)){
        temp = new MTetrahedron(v2,v3,mid,v5);
        gr->addTetrahedron(temp);
        markings.insert(std::pair<MElement*,bool>(temp,false));
        build_vertex_to_tetrahedra(temp);
        movables.push_back(temp);
      }

      if(different(v3,v4,diagA,diagB)){
        temp = new MTetrahedron(v3,v4,mid,v5);
        gr->addTetrahedron(temp);
        markings.insert(std::pair<MElement*,bool>(temp,false));
        build_vertex_to_tetrahedra(temp);
        movables.push_back(temp);
      }

      if(different(v4,v1,diagA,diagB)){
        temp = new MTetrahedron(v4,v1,mid,v5);
        gr->addTetrahedron(temp);
        markings.insert(std::pair<MElement*,bool>(temp,false));
        build_vertex_to_tetrahedra(temp);
        movables.push_back(temp);
      }

      it2 = markings.find(*it);
      it2->second = 1;
      erase_vertex_to_pyramids(*it);
    }

    mean(Ns,mid,movables);
  }
}

void PostOp::rearrange(GRegion* gr){
  unsigned int i;
  MElement* element;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    element->setVolumePositive();
  }
}

void PostOp::statistics(GRegion* gr){
  unsigned int i;
  MElement* element;

  nbr = 0;
  nbr8 = 0;
  nbr6 = 0;
  nbr5 = 0;
  nbr4 = 0;
  vol = 0.0;
  vol8 = 0.0;
  vol6 = 0.0;
  vol5 = 0.0;
  vol4 = 0.0;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);

    if(eight(element)){
      nbr8 = nbr8 + 1;
      vol8 = vol8 + element->getVolume();
    }

    if(six(element)){
      nbr6 = nbr6 + 1;
      vol6 = vol6 + element->getVolume();
    }

    if(five(element)){
      nbr5 = nbr5 + 1;
      vol5 = vol5 + workaround(element);
    }

    if(four(element)){
      nbr4 = nbr4 + 1;
      vol4 = vol4 + element->getVolume();
    }

    nbr = nbr + 1;

    if(!five(element)){
      vol = vol + element->getVolume();
    }
    else{
      //vol = vol + workaround(element);
      vol = vol + element->getVolume();
    }
  }

  printf("Number :\n");
  printf("  percentage of hexahedra : %.2f\n",nbr8*100.0/nbr);
  printf("  percentage of prisms : %.2f\n",nbr6*100.0/nbr);
  printf("  percentage of pyramids : %.2f\n",nbr5*100.0/nbr);
  printf("  percentage of tetrahedra : %.2f\n",nbr4*100.0/nbr);
  printf("Volume :\n");
  printf("  percentage of hexahedra : %.2f\n",vol8*100.0/vol);
  printf("  percentage of prisms : %.2f\n",vol6*100.0/vol);
  printf("  percentage of pyramids : %.2f\n",vol5*100.0/vol);
  printf("  percentage of tetrahedra : %.2f\n",vol4*100.0/vol);
  printf("Total number of elements : %d\n",gr->getNumMeshElements());
  printf("Total volume : %f\n",vol);
  printf("Misc : %d %d %d\n",estimate1,estimate2,iterations);
}

void PostOp::build_tuples(GRegion* gr){
  unsigned int i;
  MVertex *a,*b,*c;
  MElement* element;
  GFace* gf;
  std::list<GFace*> faces;
  std::list<GFace*>::iterator it;

  tuples.clear();
  triangles.clear();
  faces.clear();

  faces = gr->faces();

  for(it=faces.begin();it!=faces.end();it++)
    {
      gf = *it;

      for(i=0;i<gf->getNumMeshElements();i++){
        element = gf->getMeshElement(i);

        if(element->getNumVertices()==3){
          a = element->getVertex(0);
          b = element->getVertex(1);
          c = element->getVertex(2);

          tuples.insert(Tuple(a,b,c,element,gf));
        }
      }
    }
}

void PostOp::modify_surfaces(GRegion* gr){
  unsigned int i;
  MVertex *a,*b,*c,*d;//,*e;
  MElement* element;
  GFace* gf;
  std::list<GFace*> faces;
  std::vector<MElement*> opt;
  std::list<GFace*>::iterator it;
  std::set<MElement*>::iterator it2;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);

    if(element->getNumVertices()==5){
      a = element->getVertex(0);
      b = element->getVertex(1);
      c = element->getVertex(2);
      d = element->getVertex(3);
      //e = element->getVertex(4);

      modify_surfaces(a,b,c,d);
    }
  }

  faces = gr->faces();

  for(it=faces.begin();it!=faces.end();it++)
    {
      gf = *it;

      opt.clear();

      for(i=0;i<gf->getNumMeshElements();i++){
        element = gf->getMeshElement(i);

        if(element->getNumVertices()==3){
          it2 = triangles.find(element);
          if(it2==triangles.end()){
            opt.push_back(element);
          }
        }
      }

      gf->triangles.clear();

      for(i=0;i<opt.size();i++){
        gf->triangles.push_back((MTriangle*)opt[i]);
      }
    }
}

void PostOp::modify_surfaces(MVertex* a,MVertex* b,MVertex* c,MVertex* d){
  bool flag1,flag2;
  MElement *element1,*element2;
  GFace *gf1;//,*gf2;
  Tuple tuple1,tuple2;
  std::multiset<Tuple>::iterator it1;
  std::multiset<Tuple>::iterator it2;

  gf1 = NULL;
  //gf2 = NULL;

  tuple1 = Tuple(a,b,c);
  tuple2 = Tuple(c,d,a);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1!=tuples.end()){
    if(tuple1.get_hash()!=it1->get_hash()){
      break;
    }

    if(tuple1.same_vertices(*it1)){
      flag1 = 1;
      element1 = it1->get_element();
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2!=tuples.end()){
    if(tuple2.get_hash()!=it2->get_hash()){
      break;
    }

    if(tuple2.same_vertices(*it2)){
      flag2 = 1;
      element2 = it2->get_element();
      //gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2){
    triangles.insert(element1);
    triangles.insert(element2);

    gf1->addQuadrangle(new MQuadrangle(a,b,c,d));
  }

  tuple1 = Tuple(a,b,d);
  tuple2 = Tuple(b,c,d);

  it1 = tuples.find(tuple1);
  it2 = tuples.find(tuple2);

  flag1 = 0;
  flag2 = 0;

  while(it1!=tuples.end()){
    if(tuple1.get_hash()!=it1->get_hash()){
      break;
    }

    if(tuple1.same_vertices(*it1)){
      flag1 = 1;
      element1 = it1->get_element();
      gf1 = it1->get_gf();
    }

    it1++;
  }

  while(it2!=tuples.end()){
    if(tuple2.get_hash()!=it2->get_hash()){
      break;
    }

    if(tuple2.same_vertices(*it2)){
      flag2 = 1;
      element2 = it2->get_element();
      //gf2 = it2->get_gf();
    }

    it2++;
  }

  if(flag1 && flag2){
    triangles.insert(element1);
    triangles.insert(element2);

    gf1->addQuadrangle(new MQuadrangle(a,b,c,d));
  }
}

bool PostOp::four(MElement* element){
  if(element->getNumVertices()==4) return 1;
  else return 0;
}

bool PostOp::five(MElement* element){
  if(element->getNumVertices()==5) return 1;
  else return 0;
}

bool PostOp::six(MElement* element){
  if(element->getNumVertices()==6) return 1;
  else return 0;
}

bool PostOp::eight(MElement* element){
  if(element->getNumVertices()==8) return 1;
  else return 0;
}

bool PostOp::equal(MVertex* v1,MVertex* v2,MVertex* v3,MVertex* v4){
  if((v1==v3 && v2==v4) || (v1==v4 && v2==v3)){
    return 1;
  }
  else{
    return 0;
  }
}

bool PostOp::different(MVertex* v1,MVertex* v2,MVertex* v3,MVertex* v4){
  if(v1!=v3 && v1!=v4 && v2!=v3 && v2!=v4){
    return 1;
  }
  else{
    return 0;
  }
}

MVertex* PostOp::other(MElement* element,MVertex* v1,MVertex* v2){
  int i;
  MVertex* vertex;
  MVertex* pointer;

  pointer = 0;

  for(i=0;i<element->getNumVertices();i++){
    vertex = element->getVertex(i);
    if(vertex!=v1 && vertex!=v2){
      pointer = vertex;
      break;
    }
  }

  return pointer;
}

MVertex* PostOp::other(MElement* element,MVertex* v1,MVertex* v2,MVertex* v3){
  int i;
  MVertex* vertex;
  MVertex* pointer;

  pointer = 0;

  for(i=0;i<element->getNumVertices();i++){
    vertex = element->getVertex(i);
    if(vertex!=v1 && vertex!=v2 && vertex!=v3){
      pointer = vertex;
      break;
    }
  }

  return pointer;
}

void PostOp::mean(const std::set<MVertex*>& Ns,MVertex* mid,const std::vector<MElement*>& movables){
  unsigned int i;
  int j;
  bool flag;
  double x,y,z;
  double init_x,init_y,init_z;
  std::set<MVertex*>::const_iterator it;

  x = 0.0;
  y = 0.0;
  z = 0.0;

  init_x = mid->x();
  init_y = mid->y();
  init_z = mid->z();

  for(it=Ns.begin();it!=Ns.end();it++){
    x = x + (*it)->x();
    y = y + (*it)->y();
    z = z + (*it)->z();
  }

  x = x/Ns.size();
  y = y/Ns.size();
  z = z/Ns.size();

  for(i=0;i<movables.size();i++){
    movables[i]->setVolumePositive();
  }

  mid->setXYZ(x,y,z);

  for(j=0;j<100;j++){
    flag = 0;

    for(i=0;i<movables.size();i++){
      if(movables[i]->getVolume()<0.0){
        flag = 1;
      }
    }

    if(!flag){
      break;
    }

    x = 0.1*init_x + 0.9*mid->x();
    y = 0.1*init_y + 0.9*mid->y();
    z = 0.1*init_z + 0.9*mid->z();

    mid->setXYZ(x,y,z);
  }

  iterations = iterations + j;

  for(j=0;j<6;j++){
    flag = 0;

    for(i=0;i<movables.size();i++){
      if(movables[i]->gammaShapeMeasure()<0.2){
        flag = 1;
      }
    }

    if(!flag){
      break;
    }

    x = 0.1*init_x + 0.9*mid->x();
    y = 0.1*init_y + 0.9*mid->y();
    z = 0.1*init_z + 0.9*mid->z();

    mid->setXYZ(x,y,z);
  }

  iterations = iterations + j;
}

double PostOp::workaround(MElement* element){
  double volume;
  MTetrahedron* temp1;
  MTetrahedron* temp2;

  volume = 0.0;

  if(five(element)){
    temp1 = new MTetrahedron(element->getVertex(0),element->getVertex(1),element->getVertex(2),element->getVertex(4));
    temp2 = new MTetrahedron(element->getVertex(2),element->getVertex(3),element->getVertex(0),element->getVertex(4));
    volume = fabs(temp1->getVolume()) + fabs(temp2->getVolume());
    delete temp1;
    delete temp2;
  }

  return volume;
}

MVertex* PostOp::find(MVertex* v1,MVertex* v2,MVertex* v3,MVertex* v4,MElement* element){
  int i;
  MVertex* vertex;
  MVertex* pointer;

  pointer = 0;

  for(i=0;i<element->getNumVertices();i++){
    vertex = element->getVertex(i);
    if(vertex!=v1 && vertex!=v2 && vertex!=v3 && vertex!=v4){
      pointer = vertex;
      break;
    }
  }

  return pointer;
}

void PostOp::find_tetrahedra(MVertex* v1,MVertex* v2,std::set<MElement*>& final){
  std::map<MVertex*,std::set<MElement*> >::iterator it1;
  std::map<MVertex*,std::set<MElement*> >::iterator it2;

  it1 = vertex_to_tetrahedra.find(v1);
  it2 = vertex_to_tetrahedra.find(v2);

  if(it1!=vertex_to_tetrahedra.end() && it2!=vertex_to_tetrahedra.end()){
    intersection(it1->second,it2->second,final);
  }
}

void PostOp::find_pyramids(MVertex* v1,MVertex* v2,std::set<MElement*>& final){
  bool flag1,flag2,flag3,flag4;
  bool flag5,flag6,flag7,flag8;
  std::set<MElement*>::iterator it;
  std::map<MVertex*,std::set<MElement*> >::iterator it1;
  std::map<MVertex*,std::set<MElement*> >::iterator it2;
  std::set<MElement*> temp;

  it1 = vertex_to_pyramids.find(v1);
  it2 = vertex_to_pyramids.find(v2);

  temp.clear();

  if(it1!=vertex_to_pyramids.end() && it2!=vertex_to_pyramids.end()){
    intersection(it1->second,it2->second,temp);
  }

  for(it=temp.begin();it!=temp.end();it++){
    flag1 = equal(v1,v2,(*it)->getVertex(0),(*it)->getVertex(1));
    flag2 = equal(v1,v2,(*it)->getVertex(1),(*it)->getVertex(2));
    flag3 = equal(v1,v2,(*it)->getVertex(2),(*it)->getVertex(3));
    flag4 = equal(v1,v2,(*it)->getVertex(3),(*it)->getVertex(0));
    flag5 = equal(v1,v2,(*it)->getVertex(0),(*it)->getVertex(4));
    flag6 = equal(v1,v2,(*it)->getVertex(1),(*it)->getVertex(4));
    flag7 = equal(v1,v2,(*it)->getVertex(2),(*it)->getVertex(4));
    flag8 = equal(v1,v2,(*it)->getVertex(3),(*it)->getVertex(4));
    if(flag1 || flag2 || flag3 || flag4 || flag5 || flag6 || flag7 || flag8){
      final.insert(*it);
    }
  }
}

void PostOp::intersection(const std::set<MElement*>& bin1,const std::set<MElement*>& bin2,std::set<MElement*>& final){
  std::set_intersection(bin1.begin(),bin1.end(),bin2.begin(),bin2.end(),std::inserter(final,final.end()));
}

void PostOp::build_vertex_to_tetrahedra(GRegion* gr){
  unsigned int i;
  MElement* element;

  vertex_to_tetrahedra.clear();

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    if(four(element)){
      build_vertex_to_tetrahedra(element);
    }
  }
}

void PostOp::build_vertex_to_tetrahedra(MElement* element){
  int i;
  MVertex* vertex;
  std::set<MElement*> bin;
  std::map<MVertex*,std::set<MElement*> >::iterator it;

  for(i=0;i<element->getNumVertices();i++){
    vertex = element->getVertex(i);

    it = vertex_to_tetrahedra.find(vertex);
    if(it!=vertex_to_tetrahedra.end()){
      it->second.insert(element);
    }
    else{
      bin.clear();
      bin.insert(element);
      vertex_to_tetrahedra.insert(std::pair<MVertex*,std::set<MElement*> >(vertex,bin));
    }
  }
}

void PostOp::erase_vertex_to_tetrahedra(MElement* element){
  int i;
  MVertex* vertex;
  std::map<MVertex*,std::set<MElement*> >::iterator it;

  for(i=0;i<element->getNumVertices();i++){
    vertex = element->getVertex(i);

    it = vertex_to_tetrahedra.find(vertex);
    if(it!=vertex_to_tetrahedra.end()){
      it->second.erase(element);
    }
  }
}

void PostOp::build_vertex_to_pyramids(GRegion* gr){
  unsigned int i;
  MElement* element;

  vertex_to_pyramids.clear();

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    if(five(element)){
      build_vertex_to_pyramids(element);
    }
  }
}

void PostOp::build_vertex_to_pyramids(MElement* element){
  int i;
  MVertex* vertex;
  std::set<MElement*> bin;
  std::map<MVertex*,std::set<MElement*> >::iterator it;

  for(i=0;i<element->getNumVertices();i++){
    vertex = element->getVertex(i);

    it = vertex_to_pyramids.find(vertex);
    if(it!=vertex_to_pyramids.end()){
      it->second.insert(element);
    }
    else{
      bin.clear();
      bin.insert(element);
      vertex_to_pyramids.insert(std::pair<MVertex*,std::set<MElement*> >(vertex,bin));
    }
  }
}

void PostOp::erase_vertex_to_pyramids(MElement* element){
  int i;
  MVertex* vertex;
  std::map<MVertex*,std::set<MElement*> >::iterator it;

  for(i=0;i<element->getNumVertices();i++){
    vertex = element->getVertex(i);

    it = vertex_to_pyramids.find(vertex);
    if(it!=vertex_to_pyramids.end()){
      it->second.erase(element);
    }
  }
}


void Recombinator_Graph::pattern1(GRegion* gr){
  int size_init = hex_to_tet.size();
  size_t i;
  int index;
  double quality;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex *p,*q,*r,*s;
  std::vector<MVertex*> already;
  std::set<MVertex*> bin1;
  std::set<MVertex*> bin2;
  std::set<MVertex*> bin3;
  std::set<MVertex*> bin4;
  std::set<MVertex*>::iterator it1;
  std::set<MVertex*>::iterator it2;
  std::set<MVertex*>::iterator it3;
  std::set<MVertex*>::iterator it4;
  Hex *hex;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    // max_scaled_jacobian(element,index);
    // todo: ici, boucle sur index
    for (index = 0;index<4;index++){

      a = element->getVertex(index);
      b = element->getVertex((index+1)%4);
      c = element->getVertex((index+2)%4);
      d = element->getVertex((index+3)%4);

      already.clear();
      already.push_back(a);
      already.push_back(b);
      already.push_back(c);
      already.push_back(d);
      bin1.clear();
      bin2.clear();
      bin3.clear();
      find(b,d,already,bin1);
      find(b,c,already,bin2);
      find(c,d,already,bin3);

      for(it1=bin1.begin();it1!=bin1.end();it1++){
        p = *it1;
        for(it2=bin2.begin();it2!=bin2.end();it2++){
          q = *it2;
          for(it3=bin3.begin();it3!=bin3.end();it3++){
            r = *it3;
            if(p!=q && p!=r && q!=r){
              already.clear();
              already.push_back(a);
              already.push_back(b);
              already.push_back(c);
              already.push_back(d);
              already.push_back(p);
              already.push_back(q);
              already.push_back(r);
              bin4.clear();
              find(p,q,r,already,bin4);
              for(it4=bin4.begin();it4!=bin4.end();it4++){
                s = *it4;
                hex = new Hex(a,b,q,c,d,p,s,r);
                quality = min_scaled_jacobian(*hex);
                hex->set_quality(quality);
                fill_tet_to_hex_table(hex);
              }
            }
          }
        }
      }
    }
  }
  cout << "Nb of hex found, pattern1: " << hex_to_tet.size()-size_init << endl;
}


void Recombinator_Graph::pattern2(GRegion* gr){
  int size_init = hex_to_tet.size();
  size_t i;
  int index1,index2,index3,index4;
  double quality;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex *p,*q,*r,*s;
  std::set<MElement*> verif;
  Hex *hex;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    //diagonal(element,index1,index2);
    // todo: ici, boucle sur index
    for (index1=0;index1<4;index1++){
      for (index2=index1+1;index2<4;index2++){
        two_others(index1,index2,index3,index4);

        b = element->getVertex(index1);
        d = element->getVertex(index2);
        a = element->getVertex(index3);
        c = element->getVertex(index4);

        verif.clear();
        find(b,d,verif);
        if(verif.size()==6){
          s = find(a,b,d,c,verif);
          p = find(b,c,d,a,verif);
          if(s!=0 && p!=0){
            r = find(s,b,d,a,verif);
            q = find(p,b,d,c,verif);
            if(r!=0 && q!=0){
              hex = new Hex(a,s,b,c,d,r,q,p);
              quality = min_scaled_jacobian(*hex);
              hex->set_quality(quality);
              fill_tet_to_hex_table(hex);

              hex = new Hex(a,c,d,s,b,p,q,r);
              quality = min_scaled_jacobian(*hex);
              hex->set_quality(quality);
              fill_tet_to_hex_table(hex);
            }
          }
        }
      }
    }
  }
  cout << "Nb of hex found, pattern2: " << hex_to_tet.size()-size_init << endl;
}


void Recombinator_Graph::pattern3(GRegion* gr){
  int size_init = hex_to_tet.size();
  size_t i;
  int index1,index2,index3,index4;
  bool c1,c2,c3,c4,c5;
  bool c6,c7,c8,c9,c10;
  double quality;
  MElement* element;
  MVertex *a,*b,*c,*d;
  MVertex *p,*q,*r,*s;
  MVertex *fA,*fB,*bA,*bB;
  std::set<MElement*> verif1;
  std::set<MElement*> verif2;
  Hex *hex;

  for(i=0;i<gr->getNumMeshElements();i++){
    element = gr->getMeshElement(i);
    //diagonal(element,index1,index2);
    // todo: ici, boucle sur index
    for (index1=0;index1<4;index1++){
      for (index2=index1+1;index2<4;index2++){
        two_others(index1,index2,index3,index4);

        b = element->getVertex(index1);
        d = element->getVertex(index2);
        a = element->getVertex(index3);
        c = element->getVertex(index4);

        verif1.clear();
        verif2.clear();
        find(b,d,verif1);
        find(a,c,verif2);

        if(verif1.size()==4 && verif2.size()==4){
          fA = find(b,d,a,c,verif1);
          fB = find(b,d,c,a,verif1);
          bA = find(a,c,b,d,verif2);
          bB = find(a,c,d,b,verif2);

          if(fA!=0 && fB!=0 && bA!=0 && bB!=0 && fA!=fB && bA!=bB){
            if(scalar(fA,fB,a,b)>scalar(fA,fB,b,c) && scalar(bA,bB,a,b)>scalar(bA,bB,b,c)){
              if(distance(fA,b,c)<distance(fB,b,c)){
                p = fA;
                q = fB;
              }
              else{
                p = fB;
                q = fA;
              }

              if(distance(bA,b,c)<distance(bB,b,c)){
                r = bA;
                s = bB;
              }
              else{
                r = bB;
                s = bA;
              }

              c1 = linked(b,p);
              c2 = linked(c,p);
              c3 = linked(p,q);
              c4 = linked(a,q);
              c5 = linked(d,q);

              c6 = linked(b,r);
              c7 = linked(c,r);
              c8 = linked(r,s);
              c9 = linked(a,s);
              c10 = linked(d,s);

              if(c1 && c2 && c3 && c4 && c5 && c6 && c7 && c8 && c9 && c10){
                hex = new Hex(p,c,r,b,q,d,s,a);
                quality = min_scaled_jacobian(*hex);
                hex->set_quality(quality);
                fill_tet_to_hex_table(hex);
              }
            }
            else if(scalar(fA,fB,a,b)<=scalar(fA,fB,b,c) && scalar(bA,bB,a,b)<=scalar(bA,bB,b,c)){
              if(distance(fA,a,b)<distance(fB,a,b)){
                p = fA;
                q = fB;
              }
              else{
                p = fB;
                q = fA;
              }

              if(distance(bA,a,b)<distance(bB,a,b)){
                r = bA;
                s = bB;
              }
              else{
                r = bB;
                s = bA;
              }

              c1 = linked(b,p);
              c2 = linked(a,p);
              c3 = linked(p,q);
              c4 = linked(c,q);
              c5 = linked(d,q);

              c6 = linked(b,r);
              c7 = linked(a,r);
              c8 = linked(r,s);
              c9 = linked(c,s);
              c10 = linked(d,s);

              if(c1 && c2 && c3 && c4 && c5 && c6 && c7 && c8 && c9 && c10){
                hex = new Hex(p,b,r,a,q,c,s,d);
                quality = min_scaled_jacobian(*hex);
                hex->set_quality(quality);
                fill_tet_to_hex_table(hex);
              }
            }
          }
        }
      }
    }
  }
  cout << "Nb of hex found, pattern3: " << hex_to_tet.size()-size_init << endl;
}


// check if hex is ok, and insert in "potential" table
void Recombinator_Graph::fill_tet_to_hex_table(Hex *hex){
  const bool very_verbose = false;

  const bool bypass=true;


  if (very_verbose){
    cout << " fill_tet_to_hex_table:: treating hex " << hex << " made of ";
    for (int i=0;i<8;i++)
      cout << "  " << hex->getVertex(i)->getNum();
    cout << endl;
  }


  if (!valid(*hex)){
    if (very_verbose) cout << "NOT VALID hex !!! " << endl;
    delete hex;
    return;
  }

  MElement *element;
  std::set<MElement*> parts;
  // recovering all the tets forming the current hex
  parts.clear();
  find(hex->get_a(),*hex,parts);
  find(hex->get_b(),*hex,parts);
  find(hex->get_c(),*hex,parts);
  find(hex->get_d(),*hex,parts);
  find(hex->get_e(),*hex,parts);
  find(hex->get_f(),*hex,parts);
  find(hex->get_g(),*hex,parts);
  find(hex->get_h(),*hex,parts);

  if(!valid(*hex,parts)){
    if (very_verbose) cout << " NOT VALID hex (parts) " << endl;
    delete hex;
    return;
  }

  // storing all tets in tet_to_hex database (for use in indirect neighbors)
  // first, check if the hex has the right number of vertices (=8 !!!)
  // non, c'est pas toujours le cas !!! ???

  set<MVertex*> vertices;
  for(std::set<MElement*>::iterator it=parts.begin();it!=parts.end();it++){
    element = *it;
    for (int i=0;i<4;i++){
      vertices.insert(element->getVertex(i));
    }
  }

  if (vertices.size()!=8){
    if (very_verbose) cout << "------------- WARNING !!!!! An hex has " << vertices.size() << "vertices" << endl;
    delete hex;
    return;
  }



  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // le test suivant déconne, cf. cube à 125 hex... sais pas pourquoi, mais ça élimine des hex potentiels tout à fait valides (et nécessaires à la solution optimale)!!!
  // dans le cas cube125: ce test fait passer le #hex potentiels recensés par les patterns de recombinaison d'environ 1000 à 2434 ??? !!!, ça double aussi le nbre d'hex dans le graphe des pertes
  // en fait, si les noeuds par exemple a b c d deviennent b c d a, on a une rotation et un hex tout pourri... mais qui a même hash et mêmes noeuds ?!?!
  // now, check if the hex already exists...
  if (!bypass){
    std::multimap<unsigned long long, Hex* >::const_iterator itfind = find_the_created_potential_hex(hex,created_potential_hex);
    if (itfind!=created_potential_hex.end()){
      delete hex;
      if (very_verbose) cout <<  "------------- WARNING !!!!! fill_tet_to_hex_table:: current hex already exists in the created potentiel hex database. Not adding the hex." << endl;
      return;
    }
  }
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!
  // TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!  TODO !!!!



  // counting the number of triangular external faces. If different from 12, discard the hex !
  // if not, build the face/hex table
  std::multimap<unsigned long long, pair<PETriangle*,int> > faces_temp;
  for(std::set<MElement*>::iterator it_tet=parts.begin();it_tet!=parts.end();it_tet++){// for all tets
    for (int i=0;i<4;i++){// for all faces
      MFace f = (*it_tet)->getFace(i);
      add_face(f.getVertex(0), f.getVertex(1), f.getVertex(2), faces_temp);
    }
  }

  int count=0;
  std::multimap<unsigned long long, pair<PETriangle*,int> >::iterator it_face = faces_temp.begin();
  std::multimap<unsigned long long, pair<PETriangle*,int> >::iterator it_faceen = faces_temp.end();
  for (;it_face!=it_faceen;it_face++)// counting
    if (it_face->second.second==1)
      count++;

  if (count!=12){
    if (very_verbose) cout <<  "------------- WARNING !!!!! fill_tet_to_hex_table:: hex  has " << count << " faces ... discard the hex." << endl;
    delete hex;
    return;
  }


  it_face = faces_temp.begin();
  for (;it_face!=it_faceen;it_face++){// for all faces, storing the external faces
    PETriangle *t=it_face->second.first;
    if (it_face->second.second==1)
      add_face(t->getVertex(0), t->getVertex(1), t->getVertex(2), hex);
    else
      delete t;
  }

  // eventually storing the hex !
  for(std::set<MElement*>::iterator it=parts.begin();it!=parts.end();it++){
    element = *it;
    created_potential_hex.insert(make_pair(hex->get_hash(),hex));
    add_edges(hex);
    tet_to_hex[element].insert(hex);
    hex_to_tet[hex].insert(element);
  }

  if (very_verbose){
    export_single_hex_all(hex,"");
  }
}


void Recombinator_Graph::buildGraphOnly(unsigned int max_nb_cliques,string filename){
  GRegion* gr;
  GModel* model = GModel::current();
  GModel::riter it;

  for(it=model->firstRegion();it!=model->lastRegion();it++)
    {
      gr = *it;
      if(gr->getNumMeshElements()>0){
        buildGraphOnly(gr, max_nb_cliques,filename);
      }
    }
}


void Recombinator_Graph::buildGraphOnly(GRegion* gr, unsigned int max_nb_cliques,string filename){
  printf("................HEXAHEDRA................\n");

  hex_to_tet.clear();
  tet_to_hex.clear();
  created_potential_hex.clear();

  build_tuples(gr);

  Msg::Info("Building Connectivity...");
  build_vertex_to_vertices(gr);
  build_vertex_to_elements(gr);

  pattern1(gr);
  Msg::Info("Hex-merging pattern nb. 1...");
  pattern2(gr);
  Msg::Info("Hex-merging pattern nb. 2...");
  pattern3(gr);
  Msg::Info("Hex-merging pattern nb. 3...");



  create_losses_graph(gr);
  compute_hex_ranks();
  found_the_ultimate_max_clique=false;
}



void Recombinator_Graph::execute(){
  GRegion* gr;
  GModel* model = GModel::current();
  GModel::riter it;

  model->writeMSH("beforeyamakawa.msh");

  for(it=model->firstRegion();it!=model->lastRegion();it++)
    {
      gr = *it;
      if(gr->getNumMeshElements()>0){
        execute(gr);
      }
    }
}


void Recombinator_Graph::execute_blossom(unsigned int max_nb_cliques,string filename){
  GRegion* gr;
  GModel* model = GModel::current();
  GModel::riter it;

  model->writeMSH("beforeyamakawa.msh");

  for(it=model->firstRegion();it!=model->lastRegion();it++)
    {
      gr = *it;
      if(gr->getNumMeshElements()>0){
        execute_blossom(gr, max_nb_cliques,filename);
      }
    }
}


Recombinator_Graph::~Recombinator_Graph(){
  for (iter it = triangular_faces.begin();it!=triangular_faces.end();it++){
    delete it->second;
  }
  for (linemap::iterator it = edges_and_diagonals.begin();it!=edges_and_diagonals.end();it++){
    delete it->second;
  }
}


void Recombinator_Graph::createBlossomInfo(){

  throw;


  GRegion* gr;
  GModel* model = GModel::current();
  GModel::riter it;

  for(it=model->firstRegion();it!=model->lastRegion();it++)
    {
      gr = *it;
      //    if(gr->getNumMeshElements()>0){
      createBlossomInfo(gr);
      //    }
    }
}


void Recombinator_Graph::createBlossomInfo(GRegion *gr){

  throw;


  // remove quads, create triangles, and store blossom information (triangles pairs)
  std::list<GFace*> faces = gr->faces();
  GFace *gf;
  MElement *element;
  PETriangle *t11, *t12, *t21, *t22;

  cout << "recover blossom info" << endl;

  for(std::list<GFace*>::iterator it=faces.begin();it!=faces.end();it++){
    gf = *it;

    std::vector<MQuadrangle*>::iterator it_quad = gf->quadrangles.begin();

    for (;it_quad!=gf->quadrangles.end();it_quad++){
      element = *it_quad;

      // recovering triangular faces
      t11 = get_triangle(element, 0,1,2);
      t12 = get_triangle(element, 0,2,3);
      t21 = get_triangle(element, 0,1,3);
      t22 = get_triangle(element, 1,2,3);

      // creating blossom info (pairs of triangles)
      blossom_info[t11] = t12;
      blossom_info[t12] = t11;
      blossom_info[t21] = t22;
      blossom_info[t22] = t21;

      tri_to_gface_info[t11] = gf;
      tri_to_gface_info[t12] = gf;
      tri_to_gface_info[t21] = gf;
      tri_to_gface_info[t22] = gf;

      // adding triangles
      gf->addTriangle(new MTriangle(element->getVertex(0), element->getVertex(1), element->getVertex(2)));
      gf->addTriangle(new MTriangle(element->getVertex(0), element->getVertex(2), element->getVertex(3)));

    }
    // deleting quads
    gf->quadrangles.clear();
  }


  //  // cut pyramids in 2 tets, remove pyramids
  //  std::vector<MPyramid*>::iterator it_pyramid = gr->pyramids.begin();
  //  MPyramid *p;
  //  vector<const MVertex*>v;
  //  citer it_find_tri;
  //  cout << "start cutting pyramids" << endl;
  //  for (;it_pyramid!=gr->pyramids.end();it_pyramid++){
  //    // arbirary cut of the pyramid...
  //    p = *it_pyramid;
  //    // add tets
  //    gr->addTetrahedron(new MTetrahedron(p->getVertex(0), p->getVertex(1),p->getVertex(2),p->getVertex(4)));
  //    gr->addTetrahedron(new MTetrahedron(p->getVertex(0), p->getVertex(2),p->getVertex(3),p->getVertex(4)));
  //
  //    // add triangles to the right GFace
  //    v.clear();
  //    v.push_back(p->getVertex(0));
  //    v.push_back(p->getVertex(1));
  //    v.push_back(p->getVertex(2));
  //    t11 = new PETriangle(v);
  //    it_find_tri = find_the_triangle(t11, triangular_faces);
  //    if (it_find_tri != triangular_faces.end()){
  //      std::list<GFace*>::iterator it_find_face = std::find(faces.begin(), faces.end(),tri_to_gface_info[it_find_tri->second]);
  //      if (it_find_face!=faces.end()){
  //        (*it_find_face)->addTriangle(new MTriangle(p->getVertex(0), p->getVertex(1), p->getVertex(2)));
  //      }
  //      else
  //        cout << "WARNING blossom: face not found !  Can't add triangle !" << endl;
  //    }
  //    else
  //      cout << "WARNING blossom: triangle not found ! " << endl;
  //    delete t11;
  //
  //    v.clear();
  //    v.push_back(p->getVertex(0));
  //    v.push_back(p->getVertex(2));
  //    v.push_back(p->getVertex(3));
  //    t11 = new PETriangle(v);
  //    it_find_tri = find_the_triangle(t11, triangular_faces);
  //    if (it_find_tri != triangular_faces.end()){
  //      std::list<GFace*>::iterator it_find_face = std::find(faces.begin(), faces.end(),tri_to_gface_info[it_find_tri->second]);
  //      if (it_find_face!=faces.end()){
  //        (*it_find_face)->addTriangle(new MTriangle(p->getVertex(0), p->getVertex(2),p->getVertex(3)));
  //      }
  //      else
  //        cout << "WARNING blossom: face not found ! Can't add triangle !" << endl;
  //    }
  //    else
  //      cout << "WARNING blossom: triangle not found ! " << endl;
  //    delete t11;
  //  }
  //  // erase all pyramids
  //  cout << "erasing all pyramids" << endl;
  //  gr->pyramids.clear();




}


void Recombinator_Graph::execute_blossom(GRegion* gr, unsigned int max_nb_cliques,string filename){


  throw;

  printf("................HEXAHEDRA................\n");

  hex_to_tet.clear();
  tet_to_hex.clear();
  created_potential_hex.clear();

  build_tuples(gr);

  Msg::Info("Building Connectivity...");

  double a = Cpu();

  build_vertex_to_vertices(gr);
  build_vertex_to_elements(gr);

  pattern1(gr);
  Msg::Info("Hex-merging pattern nb. 1...");
  pattern2(gr);
  Msg::Info("Hex-merging pattern nb. 2...");
  pattern3(gr);
  Msg::Info("Hex-merging pattern nb. 3...");


  create_losses_graph(gr);
  // add points to potential hexas containing original blossom pairs of triangles
  compute_hex_ranks_blossom();

  double time_building_graph = (Cpu() - a);


  a=Cpu();
  // a criteria to stop when the whole domain is exclusively composed of hex
  clique_stop_criteria<Hex*> criteria(hex_to_tet, gr->tetrahedra.size());

  cliques_losses_graph<Hex*> cl(incompatibility_graph, hex_ranks, max_nb_cliques, hex_to_tet.size(),&criteria,export_the_clique_graphviz_format);
  cl.find_cliques();
  //cl.export_cliques();


  double time_cliques = (Cpu() - a) ;

  cout << "RECOMBINATOR_GRAPH timing:" << endl;
  cout << "  ------- TIME BUILDING GRAPH : " << time_building_graph << " s." << endl;
  cout << "  ------- TIME CLIQUE         : " << time_cliques << " s." << endl;



  int clique_number = 0;

  if (filename.empty()) filename.assign("mygraph.dot");
  //  export_clique_graphviz_format(cl,1,"mygraph2.dot");
  export_the_clique_graphviz_format(cl,clique_number,filename);

  merge_clique(gr,cl,clique_number);





  rearrange(gr);
  statistics(gr);
  modify_surfaces(gr);



  return;



  //  create_indirect_neighbors_graph();
  //  update_degree(gr,true);
  //  create_compatibility_graph();
  //
  //
  //  cout << "size edges : " << edges.size() << endl;
  //  cout << "size degree : " << idegree.size() << endl;
  //  cout << "size hex_to_tet : " << hex_to_tet.size() << endl;
  //
  //  hash_tableA.clear();
  //  hash_tableB.clear();
  //  hash_tableC.clear();
  //
  //  export_direct_neighbor_table(50);
  //  merge(gr);
  //
  //  rearrange(gr);
  //
  //  statistics(gr);
  //
  //  modify_surfaces(gr);
}


// return the triangular face ijk if it exists. If not, creates it and returns it.
PETriangle* Recombinator_Graph::get_triangle(MElement *element, int i, int j, int k){
  vector<const MVertex*> v;
  PETriangle *t;
  v.push_back(element->getVertex(i));
  v.push_back(element->getVertex(j));
  v.push_back(element->getVertex(k));
  t = new PETriangle(v);
  citer itfind = find_the_triangle(t,triangular_faces);
  if (itfind==triangular_faces.end()){
    itfind = triangular_faces.insert(make_pair(t->get_hash(),t));
  }
  else{
    delete t;
    t = itfind->second;
  }
  return t;
}

Recombinator_Graph::Recombinator_Graph(unsigned int _n,string filename):max_nb_cliques(_n),graphfilename(filename){
}

void Recombinator_Graph::execute(GRegion* gr){
  printf("................HEXAHEDRA................\n");

  hex_to_tet.clear();
  tet_to_hex.clear();
  created_potential_hex.clear();

  build_tuples(gr);

  Msg::Info("Building Connectivity...");
  build_vertex_to_vertices(gr);
  build_vertex_to_elements(gr);

  pattern1(gr);
  Msg::Info("Hex-merging pattern nb. 1...");
  pattern2(gr);
  Msg::Info("Hex-merging pattern nb. 2...");
  pattern3(gr);
  Msg::Info("Hex-merging pattern nb. 3...");



  create_losses_graph(gr);
  compute_hex_ranks();


  // a criteria to stop when the whole domain is exclusively composed of hex
  found_the_ultimate_max_clique=false;
  clique_stop_criteria<Hex*> criteria(hex_to_tet, gr->tetrahedra.size());


  cliques_losses_graph<Hex*> cl(incompatibility_graph, hex_ranks, max_nb_cliques, hex_to_tet.size(),&criteria,export_the_clique_graphviz_format);
  cl.find_cliques();
  //cl.export_cliques();


  found_the_ultimate_max_clique = cl.found_the_ultimate_max_clique;



  int clique_number = 0;
  if (graphfilename.empty()) graphfilename.assign("mygraph.dot");
  //export_clique_graphviz_format(cl,1,"mygraph2.dot");
  export_the_clique_graphviz_format(cl,clique_number,graphfilename);

  merge_clique(gr,cl,clique_number);

  rearrange(gr);
  statistics(gr);
  modify_surfaces(gr);



  return;



  //  create_indirect_neighbors_graph();
  //  update_degree(gr,true);
  //  create_compatibility_graph();
  //
  //
  //  cout << "size edges : " << edges.size() << endl;
  //  cout << "size degree : " << idegree.size() << endl;
  //  cout << "size hex_to_tet : " << hex_to_tet.size() << endl;
  //
  //  hash_tableA.clear();
  //  hash_tableB.clear();
  //  hash_tableC.clear();
  //
  //  export_direct_neighbor_table(50);
  //  merge(gr);
  //
  //  rearrange(gr);
  //
  //  statistics(gr);
  //
  //  modify_surfaces(gr);
}


void Recombinator_Graph::merge_clique(GRegion* gr, cliques_losses_graph<Hex*> &cl,int clique_number){

  multimap<int,set<Hex*> >::reverse_iterator it_all = cl.allQ.rbegin();
  multimap<int,set<Hex*> >::reverse_iterator it_allen = cl.allQ.rend();
  int clique_counter=0;
  std::set<MElement*> parts;
  int clique_size=0;

  for (int i=0;i<clique_number;i++){
    it_all++;
  }

  for (;it_all!=it_allen;it_all++,clique_counter++){
    if (clique_counter>=1) break;

    //cout << "--------------------- clique " << clique_counter << " made of ";
    clique_size = it_all->second.size();
    set<Hex*>::iterator ithex = it_all->second.begin();
    set<Hex*>::iterator ithexen = it_all->second.end();
    double quality=0.;
    int count=0;

    hash_tableA.clear();
    hash_tableB.clear();
    hash_tableC.clear();

    //    // sorting the hexahedra from the clique...
    //    multimap<double, Hex*> rank;
    //    create_boundaries_info_for_hex_ranking(gr);
    //    for (;ithex!=ithexen;ithex++){
    //      rank.insert(make_pair(get_hex_rank(*ithex),*ithex));
    //      //cout << "rank:" << get_hex_rank(*ithex) << endl;
    //    }
    //    multimap<double, Hex*>::iterator it_rank = rank.begin();
    //    multimap<double, Hex*>::iterator it_ranken = rank.end();

    //    set<Hex*> hex_to_export;

    for (;ithex!=ithexen;ithex++){ // brutal post-check: random pickup of hexahedra in clique
      Hex *current_hex = *ithex;


      //        cout << " clique merge: treating hex " << current_hex << " made of ";
      //        for (int i=0;i<8;i++)
      //          cout << "  " << current_hex->getVertex(i)->getNum();
      //        cout << endl;



      //    for (;it_rank!=it_ranken;it_rank++) // smarter post-check: sorting hexahedra first...
      //      Hex *current_hex = it_rank->second;

      //      export_single_hex_all(current_hex,"");

      if (!post_check_validation(current_hex))
        continue;

      // inserting the hex
      quality = quality + current_hex->get_quality();
      gr->addHexahedron(new MHexahedron(current_hex->get_a(), current_hex->get_b(),current_hex->get_c(),current_hex->get_d(),current_hex->get_e(),current_hex->get_f(),current_hex->get_g(),current_hex->get_h()));
      count++;
      //      hex_to_export.insert(current_hex);
      //      cout << " inserting " << current_hex << " made of ";
      //      for (int i=0;i<8;i++)
      //        cout << "  " << current_hex->getVertex(i)->getNum();
      //      cout << endl;


      // removing tets
      //      if (debug) cout << "  removing tets" << endl;
      std::set<MElement*>::iterator it_tet_to_remove = hex_to_tet[current_hex].begin();
      std::vector<MTetrahedron*>::iterator itfind_tet_region;
      for (;it_tet_to_remove!=hex_to_tet[current_hex].end();it_tet_to_remove++){
        itfind_tet_region = std::find(gr->tetrahedra.begin(),gr->tetrahedra.end(),(MTetrahedron*)(*it_tet_to_remove));
        if (itfind_tet_region!=gr->tetrahedra.end())
          gr->tetrahedra.erase(itfind_tet_region);
        //        else
        //          cout << " WARNING: MTetrahedron* " << (MTetrahedron*)(*it_tet_to_remove) << " not found !!! " << endl;
      }


      build_hash_tableA(*current_hex);
      build_hash_tableB(*current_hex);
      build_hash_tableC(*current_hex);

    }


    //    // removing tets
    //    for (set<Hex*>::iterator it_hex = hex_to_export.begin();it_hex!=hex_to_export.end();it_hex++){
    //      Hex *current_hex = *it_hex;
    //      if (debug) cout << "  removing tets" << endl;
    //      std::set<MElement*>::iterator it_tet_to_remove = hex_to_tet[current_hex].begin();
    //      std::vector<MTetrahedron*>::iterator itfind_tet_region;
    //      for (;it_tet_to_remove!=hex_to_tet[current_hex].end();it_tet_to_remove++){
    //        itfind_tet_region = std::find(gr->tetrahedra.begin(),gr->tetrahedra.end(),(MTetrahedron*)(*it_tet_to_remove));
    //        if (itfind_tet_region!=gr->tetrahedra.end())
    //          gr->tetrahedra.erase(itfind_tet_region);
    //        else
    //          cout << " WARNING: MTetrahedron* " << (MTetrahedron*)(*it_tet_to_remove) << " not found !!! " << endl;
    //      }
    //    }


    //export_all_hex(clique_counter,gr);
    // removing hexahedron
    //gr->hexahedra.clear();


    cout << " ------------------------------------------ #hex potentiels recensés par les patterns de recombinaison: " << hex_to_tet.size() << endl;
    cout << " ------------------------------------------ #hex potentiels recensés dans le graphe des pertes: " << nbhex_in_losses_graph << "   #connectivité moyenne: " << average_connectivity<< endl;
    cout << " ------------------------------------------ CLIQUE SIZE " << clique_size << endl;
    cout << " ------------------------------------------ Recombinator_Graph::merge_clique: nb hex created = " << count << endl;
    printf("hexahedra average quality (0->1) : %f\n",quality/count);
  }

  //  // exporting all hex infos
  //  for (set<Hex*>::iterator it=hex_to_export.begin();it!=hex_to_export.end();it++){
  //    Hex *hex = *it;
  //    cout << hex << " made of ";
  //    for (int i=0;i<8;i++){
  //      cout << "(" << hex->getVertex(i)->x() << "," << hex->getVertex(i)->y() << "," << hex->getVertex(i)->z() << ") ";
  //    }
  //    cout << endl;
  //  }
}



void Recombinator_Graph::merge(GRegion* gr){
  throw;
}


void Recombinator_Graph::export_tets(set<MElement*> &tetset, Hex* hex, string s){
  stringstream ss;
  ss << s.c_str();
  ss << "hexptr_";
  ss << hex;
  ss << "_tetparts.pos";
  ofstream out(ss.str().c_str());

  out << "View \"hex tets parts\" {" << endl;
  std::set<MElement*>::iterator it = tetset.begin();
  std::set<MElement*>::iterator iten = tetset.end();
  int count=0;
  for (;it!=iten;it++,count++){
    out << "SS(";
    for (int n=0;n<4;n++){
      const MVertex *v = (*it)->getVertex(n);
      out << v->x() << "," << v->y() << "," << v->z();
      if (n!=3) out << ",";
    }
    out << "){";
    for (int n=0;n<4;n++){
      out << count;
      if (n!=3) out << ",";
    }
    out << "};" << endl;

  }
  out << "};" << endl;
  out.close();
}


void Recombinator_Graph::export_single_hex_tet(Hex* hex,string s){
  stringstream ss;
  ss << s.c_str();
  ss << "hexptr_";
  ss << hex;
  ss << "_tet.pos";
  ofstream out(ss.str().c_str());

  out << "View \"hex tets\" {" << endl;
  std::set<MElement*>::iterator it = hex_to_tet[hex].begin();
  std::set<MElement*>::iterator iten = hex_to_tet[hex].end();
  int count=0;
  for (;it!=iten;it++,count++){
    out << "SS(";
    for (int n=0;n<4;n++){
      const MVertex *v = (*it)->getVertex(n);
      out << v->x() << "," << v->y() << "," << v->z();
      if (n!=3) out << ",";
    }
    out << "){";
    for (int n=0;n<4;n++){
      out << count;
      if (n!=3) out << ",";
    }
    out << "};" << endl;

  }
  out << "};" << endl;
  out.close();
}


void Recombinator_Graph::export_single_hex_all(Hex* hex,string s){
  export_single_hex(hex, s);
  export_single_hex_tet(hex, s);
  export_single_hex_faces(hex, s);
}


void Recombinator_Graph::export_single_hex(Hex* hex,string s){
  stringstream ss;
  ss << s.c_str();
  ss << "hexptr_";
  ss << hex;
  ss << ".pos";
  ofstream out(ss.str().c_str());

  out << "View \"hex\" {" << endl;
  out << "SH(";
  for (int n=0;n<8;n++){
    const MVertex *v = hex->getVertex(n);
    out << v->x() << "," << v->y() << "," << v->z();
    if (n!=7) out << ",";
  }
  out << "){";
  for (int n=0;n<8;n++){
    out << "0.";
    if (n!=7) out << ",";
  }
  out << "};" << endl;

  out << "};" << endl;
  out.close();
}



void Recombinator_Graph::export_single_hex_faces(Hex* hex,string s){
  stringstream ss;
  ss << s.c_str();
  ss << "hexptr_";
  ss << hex;
  ss << "_face.pos";
  ofstream out(ss.str().c_str());

  out << "View \"hex faces\" {" << endl;
  std::set<PETriangle*>::iterator it = hex_to_faces[hex].begin();
  std::set<PETriangle*>::iterator iten = hex_to_faces[hex].end();
  int count=0;
  for (;it!=iten;it++,count++){
    out << "ST(";
    for (int n=0;n<3;n++){
      const MVertex *v = (*it)->getVertex(n);
      out << v->x() << "," << v->y() << "," << v->z();
      if (n!=2) out << ",";
    }
    out << "){";
    for (int n=0;n<3;n++){
      out << count;
      if (n!=2) out << ",";
    }
    out << "};" << endl;

  }
  out << "};" << endl;
  out.close();
}



void Recombinator_Graph::export_hex_init_degree(GRegion *gr, const std::map<Hex*,int> &init_degree, const vector<Hex*> &chosen_hex){
  stringstream ss;
  ss << "init_degree";
  ss << ".pos";
  ofstream out(ss.str().c_str());

  std::vector<Hex*>::const_iterator it = chosen_hex.begin();
  out << "View \"hex\" {" << endl;
  for (;it!=chosen_hex.end();it++){
    out << "SH(";
    for (int n=0;n<8;n++){
      MVertex *v = (*it)->getVertex(n);
      out << v->x() << "," << v->y() << "," << v->z();
      if (n!=7) out << ",";
    }
    map<Hex*,int>::const_iterator itfind = init_degree.find(*it);
    out << "){";
    for (int n=0;n<8;n++){
      out << itfind->second;
      if (n!=7) out << ",";
    }
    out << "};" << endl;

  }
  out << "};" << endl;



  out.close();
}


void Recombinator_Graph::export_hexmesh_so_far(int &file){
  stringstream ss;
  stringstream ssinit;
  ss << "hex_mesh_temp";
  char chose[256];
  sprintf(chose, "_%0*d", 6, file);
  ss << chose;
  ss << ".msh";
  ofstream out(ss.str().c_str());

  GModel* model = GModel::current();
  model->save(ss.str().c_str());

  out.close();
}



void Recombinator_Graph::export_all_hex(int &file, GRegion *gr){
  stringstream ss;
  stringstream ssinit;
  ss << "hex_progression";
  ssinit << "hex_progression_initdegree";
  //  ss << file;
  char chose[256];
  sprintf(chose, "_%0*d", 6, file);
  ss << chose;
  ss << ".pos";
  ssinit << chose;
  ssinit << ".pos";
  ofstream out(ss.str().c_str());

  std::vector<MHexahedron*>::iterator it = gr->hexahedra.begin();
  int i=1;
  out << "View \"hex\" {" << endl;
  for (;it!=gr->hexahedra.end();it++,i++){
    out << "SH(";
    for (int n=0;n<8;n++){
      MVertex *v = (*it)->getVertex(n);
      out << v->x() << "," << v->y() << "," << v->z();
      if (n!=7) out << ",";
    }
    out << "){";
    for (int n=0;n<8;n++){
      out << i;
      if (n!=7) out << ",";
    }
    out << "};" << endl;

  }
  out << "};" << endl;



  out.close();
}


// check if the hex is good enough to be put into the graph. If not in the graph, it cannot be chosen...
bool Recombinator_Graph::is_not_good_enough(Hex* hex){

  //  // Hack
  //  return false;
  //  // End Hack


  //if((!faces_statuquo(*hex))){
  //if((hex->get_quality()<0.45)||(!faces_statuquo(*hex))){
  if((hex->get_quality()<0.5)||(!faces_statuquo(*hex))){
    //if((hex->get_quality()<0.55)||(!faces_statuquo(*hex))){
    //if((hex->get_quality()<0.72)||(!faces_statuquo(*hex))){
    //if((hex->get_quality()<0.65)||(!faces_statuquo(*hex))){
    return true;
  }
  return false;
}


// fills incompatibility_graph if two hex share a common (non-sliver!) tet
void Recombinator_Graph::create_indirect_neighbors_graph()
{
  std::map<MElement*, std::set<Hex*> >::iterator it_tet = tet_to_hex.begin();

  for (;it_tet!=tet_to_hex.end();it_tet++){
    std::set<Hex*>::iterator it_hex1 = it_tet->second.begin();
    for (;it_hex1!=it_tet->second.end();it_hex1++){
      Hex *hex = *it_hex1;

      //      cout << " create_indirect_neighbors_graph:: treating hex " << hex << " made of ";
      //      for (int i=0;i<8;i++)
      //        cout << "  " << hex->getVertex(i)->getNum();
      //      cout << endl;

      if (is_not_good_enough(hex)){
        continue;
      }
      graph::iterator itfind_graph = find_hex_in_graph(hex);
      if (itfind_graph==incompatibility_graph.end()){
        incompatibility_graph.insert(make_pair(hex->get_hash(),make_pair(hex,graph_data())));// this creates an entry if none exists. Important ! if hex is good, but surrounded by "not good enough" hex, it has to be in the graph anyway ! A single node in the graph, without any connection... the perfect lonely hex.
        set_of_all_hex_in_graph.insert(hex);
      }
      // check if the hex quality is sufficient to be put into the graph...
      //cout << "creating graph for hex " << hex << " with quality " << hex->get_quality() << endl;
      //      if (hex->get_quality()>=0.1)
      // check if the tet is a sliver or not...
      // if sliver, the tet should not be taken into account in the graph creation !
      bool is_sliver = sliver(it_tet->first,*hex);
      if (!is_sliver){
        //cout << " is not sliver, size it_tet->second:" << it_tet->second.size() << endl;
        std::set<Hex*>::iterator it_hex2 = it_tet->second.begin();
        for (;it_hex2!=it_tet->second.end();it_hex2++){
          if ((hex)!=(*it_hex2)){
            if (is_not_good_enough(*it_hex2)){
              continue;
            }
            //cout << "   hex put in graph, linked to hex " << *it_hex2 << endl;
            add_graph_entry(hex,*it_hex2);
            //cout << "hex's " << hex << " and " << *it_hex2 << " have one tet in common: " << it_tet->first << endl;
            //            incompatibility_graph[*it_hex2].insert(hex);
          }
        }
      }
      //      else{
      //        cout << " hex's " << hex << " has a sliver !!!!!!!!!!!!!!! : " << it_tet->first << endl;
      //      }
    }
  }
}


std::multimap<unsigned long long, Hex* >::const_iterator  Recombinator_Graph::find_the_created_potential_hex(Hex *hex, const std::multimap<unsigned long long, Hex*> &list){
  std::pair<std::multimap<unsigned long long, Hex* >::const_iterator, std::multimap<unsigned long long, Hex* >::const_iterator> range = list.equal_range(hex->get_hash());
  for (std::multimap<unsigned long long, Hex*>::const_iterator it=range.first;it!=range.second;it++){
    Hex *candidate = it->second;
    if (candidate->same_vertices(hex)){
      return it;
    }
  }
  return list.end();
}


std::multimap<unsigned long long, pair<PETriangle*,int> >::iterator  Recombinator_Graph::find_the_triangle(PETriangle *t, std::multimap<unsigned long long, pair<PETriangle*, int> > &list){
  std::pair<std::multimap<unsigned long long, pair<PETriangle*,int> >::iterator, std::multimap<unsigned long long, pair<PETriangle*,int> >::iterator> range = list.equal_range(t->get_hash());
  for (std::multimap<unsigned long long, pair<PETriangle*,int> >::iterator it=range.first;it!=range.second;it++){
    PETriangle *candidate = it->second.first;
    if (candidate->same_vertices(t)){
      it->second.second++;
      return it;
    }
  }
  return list.end();
}



Recombinator_Graph::citer  Recombinator_Graph::find_the_triangle(PETriangle *t, const trimap &list){
  std::pair<citer, citer> range = list.equal_range(t->get_hash());
  for (citer it=range.first;it!=range.second;it++){
    if (it->second->same_vertices(t)) return it;
  }
  return list.end();
}


Recombinator_Graph::linemap::const_iterator  Recombinator_Graph::find_the_line(PELine *t, const linemap &list){
  std::pair<linemap::const_iterator, linemap::const_iterator> range = list.equal_range(t->get_hash());
  for (linemap::const_iterator it=range.first;it!=range.second;it++){
    if (it->second->same_vertices(t)) return it;
  }
  return list.end();
}


void Recombinator_Graph::export_direct_neighbor_table(int max){
  stringstream ss;
  ss << "neighbors_table";
  ofstream out(ss.str().c_str());

  std::multimap<int,Hex*>::iterator it =  ndegree.begin();

  int counter=0;
  out << " n  neighbors_rank hex* quality" << endl;
  for (;it!=ndegree.end();it++,counter++){
    if (counter>=max) break;
    Hex *hex = it->second;
    out << counter << "  " << it->first << "  " << hex << "  " << hex->get_quality() << endl;
    stringstream ss2;
    ss2 << "neighbors_table_hex";
    char chose[256];
    sprintf(chose, "_%0*d", 2, counter);
    ss2 << chose;
    ss2 << ".pos";
    ofstream out2(ss2.str().c_str());
    out2 << "View \"hex\" {" << endl;
    out2 << "SH(";
    for (int n=0;n<8;n++){
      MVertex *v = hex->getVertex(n);
      out2 << v->x() << "," << v->y() << "," << v->z();
      if (n!=7) out2 << ",";
    }
    out2 << "){";
    for (int n=0;n<8;n++){
      out2 << it->first;
      if (n!=7) out2 << ",";
    }
    out2 << "};" << endl;
    out2 << "};" << endl;
    out2.close();
  }




  out.close();
}


// if two hex are not connected in the incompatibility_graph, they are compatible
void Recombinator_Graph::create_losses_graph(GRegion *gr)
{
  incompatibility_graph.clear();
  create_indirect_neighbors_graph();
  create_direct_neighbors_incompatibility_graph();


  // stats
  graph::iterator it =  incompatibility_graph.begin();
  graph::iterator ite =  incompatibility_graph.end();
  int total=0;
  for (;it!=ite;it++){
    total+=it->second.second.size();
  }
  nbhex_in_losses_graph = incompatibility_graph.size();
  cout << "total=" << total << endl;
  cout << "nbhex_in_losses_graph=" << nbhex_in_losses_graph << endl;
  average_connectivity = total/((double)(nbhex_in_losses_graph));
  cout << "#hex potentiels recensés dans le graphe des pertes: " << nbhex_in_losses_graph << "   #connectivité moyenne: " << average_connectivity<< endl;
  cout << "#hex potentiels recensés par les patterns de recombinaison: " << hex_to_tet.size() << endl;
};


// TODO: check only the direct neighbors !!! change the algo pour ne as parcourir les hex qui ont un tet commun. cad Filter au niveau des faces... juste les faces extérieures de l'hex !!! et attention aux slivers, du coup... c'est sans doute la source du pb...

// pour chaque hex, sortir un .pos avec l'hex, ses tets et ses faces extérieures pour checker...
// pourquoi pas sortir aussi tous les slivers à part... ?




// fills incompatibility_graph if two hex are incompatible direct neighbors,
// i.e. (they DO NOT have one tet in common) and (they are neighbors (face(s) in common) but DO NOT pass the compatibility tests)
void Recombinator_Graph::create_direct_neighbors_incompatibility_graph()
{

  vector<Hex*> visited_hex;
  std::map<Hex*, std::set<MElement*> >::iterator it_hex =  hex_to_tet.begin();
  for (;it_hex!=hex_to_tet.end();it_hex++){// for all hex
    Hex *hex = it_hex->first;
    if (is_not_good_enough(hex))
      continue;
    graph::iterator itfind_graph = find_hex_in_graph(hex);
    if (itfind_graph==incompatibility_graph.end()){
      incompatibility_graph.insert(make_pair(hex->get_hash(),make_pair(hex,graph_data())));// this creates an entry if none exists. Important ! if hex is good, but surrounded by "not good enough" hex, it has to be in the graph anyway ! A single node in the graph, without any connection... the perfect lonely hex.
      set_of_all_hex_in_graph.insert(hex);
    }

    hash_tableA.clear();
    hash_tableB.clear();
    hash_tableC.clear();
    build_hash_tableA(*hex);
    build_hash_tableB(*hex);
    build_hash_tableC(*hex);

    visited_hex.clear();

    std::set<PETriangle*>::iterator it_faces = hex_to_faces[hex].begin();
    std::set<PETriangle*>::iterator it_facesen = hex_to_faces[hex].end();
    for (;it_faces!=it_facesen;it_faces++){// i.e. for all triangular external face
      PETriangle *face = *it_faces;
      std::set<Hex*>::iterator it_neighbors = faces_to_hex[face].begin();
      std::set<Hex*>::iterator it_neighborsen = faces_to_hex[face].end();
      for (;it_neighbors!=it_neighborsen;it_neighbors++){// for all its neighbors
        if ((*it_neighbors)==hex) continue;
        Hex *other_hex = *it_neighbors;

        vector<Hex*>::iterator itfind_hex = std::find(visited_hex.begin(),visited_hex.end(),other_hex);
        if (itfind_hex!=visited_hex.end()) continue;// already done
        else visited_hex.push_back(other_hex);

        evaluate_hex_couple(hex,other_hex);
      }
    }
    // change following...
    std::set<PELine*>::iterator it_line = hex_to_edges[hex].begin();
    std::set<PELine*>::iterator it_lineen = hex_to_edges[hex].end();
    for (;it_line!=it_lineen;it_line++){// i.e. for all edges and diagonals -> check the hex neighbors too
      PELine *line = *it_line;
      std::set<Hex*>::iterator it_neighbors = edges_to_hex[line].begin();
      std::set<Hex*>::iterator it_neighborsen = edges_to_hex[line].end();
      for (;it_neighbors!=it_neighborsen;it_neighbors++){// for all its neighbors
        if ((*it_neighbors)==hex) continue;
        Hex *other_hex = *it_neighbors;

        vector<Hex*>::iterator itfind_hex = std::find(visited_hex.begin(),visited_hex.end(),other_hex);
        if (itfind_hex!=visited_hex.end()) continue;// already done
        else visited_hex.push_back(other_hex);

        evaluate_hex_couple(hex,other_hex);
      }
    }
  }


}


void Recombinator_Graph::evaluate_hex_couple(Hex* hex, Hex* other_hex)
{

  const bool very_verbose=false;

  if (very_verbose){
    //    export_single_hex_all(other_hex,"");
    //    export_single_hex_all(hex,"");
    cout << " evaluate_hex_couple:: treating hex " << hex << " made of ";
    for (int i=0;i<8;i++)
      cout << "  " << hex->getVertex(i)->getNum();
    cout << endl;
    cout << " evaluate_hex_couple:: treating other_hex " << other_hex << " made of ";
    for (int i=0;i<8;i++)
      cout << "  " << other_hex->getVertex(i)->getNum();
    cout << endl;
  }

  if (is_not_good_enough(other_hex)){
    if (very_verbose) cout << "hex " << hex << " not good enough" << endl;
    return;
  }

  if (find_hex_couple_in_graph(hex,other_hex)){
    if (very_verbose) cout << "already incompatible: hex's " << hex << " and " << other_hex << endl;
    return;
  }

  // count the number of faces in common...
  // intuitivement: si !=2, c'est incompatible
  //  bool two_faces_in_common=true;
  //  std::vector<PETriangle*> common(12);
  //  std::vector<PETriangle*>::iterator itfind_face = std::set_intersection (hex_to_faces[other_hex].begin(),hex_to_faces[other_hex].end(), hex_to_faces[hex].begin(), hex_to_faces[hex].end(), common.begin());
  //  common.resize(itfind_face-common.begin());
  //  if (common.size()!=2){
  //    two_faces_in_common=false;
  //  }

  // check compatibility between the two neighbors


  // if they do not pass the tests
  //-> incompatible !

  // the following depends on hex... on "hash_tables's"
  //        std::set<MElement*> parts = hex_to_tet[other_hex];
  //  std::set<MElement*> parts;
  //  find(other_hex->get_a(),*other_hex,parts);
  //  find(other_hex->get_b(),*other_hex,parts);
  //  find(other_hex->get_c(),*other_hex,parts);
  //  find(other_hex->get_d(),*other_hex,parts);
  //  find(other_hex->get_e(),*other_hex,parts);
  //  find(other_hex->get_f(),*other_hex,parts);
  //  find(other_hex->get_g(),*other_hex,parts);
  //  find(other_hex->get_h(),*other_hex,parts);
  //  if(!valid(*other_hex,parts)){
  //    if (very_verbose) cout << "valid incompatible: other_hex " << other_hex << " relative to " << hex << endl;
  //    add_graph_entry(hex,other_hex);
  //    return;
  //  }
  //  else if (very_verbose) cout << "valid compatible: other_hex " << other_hex << " relative to " << hex << endl;

  if(!conformityA(*other_hex)){
    if (very_verbose) cout << "conformA incompatible: other_hex " << other_hex << " relative to " << hex << endl;
    add_graph_entry(hex,other_hex);
    return;
  }
  else if (very_verbose) cout << "conformA compatible: other_hex " << other_hex << " relative to " << hex << endl;


  if(!conformityB(*other_hex)){
    if (very_verbose) cout << "conformB incompatible: other_hex " << other_hex << " relative to " << hex << endl;
    add_graph_entry(hex,other_hex);
    return;
  }
  else if (very_verbose) cout << "conformB compatible: other_hex " << other_hex << " relative to " << hex << endl;

  if(!conformityC(*other_hex)){
    if (very_verbose) cout << "conformC incompatible: other_hex " << other_hex << " relative to " << hex << endl;
    add_graph_entry(hex,other_hex);
    return;
  }
  else if (very_verbose) cout << "conformC compatible: other_hex " << other_hex << " relative to " << hex << endl;

  if(!faces_statuquo(*other_hex)){
    if (very_verbose) cout << "faces_statuquo incompatible: other_hex " << other_hex << " relative to " << hex << endl;
    add_graph_entry(hex,other_hex);
    return;
  }
  else if (very_verbose) cout << "faces_statuquo compatible: other_hex " << other_hex << " relative to " << hex << endl;

  if (very_verbose) cout << "other_hex " << other_hex << " relative to " << hex << " totaly compatible !!! " << endl;
  //  if (!two_faces_in_common){
  //    export_single_hex_all(other_hex,"");
  //    export_single_hex_all(hex,"");
  //
  //    //cout << "******************************** not two faces in common and compatible !!!********************************************************** " << endl;
  //  }
}


bool Recombinator_Graph::post_check_validation(Hex* current_hex)
{
  // post check...
  //  std::set<MElement*> parts;
  //  find(current_hex->get_a(),*current_hex,parts);
  //  find(current_hex->get_b(),*current_hex,parts);
  //  find(current_hex->get_c(),*current_hex,parts);
  //  find(current_hex->get_d(),*current_hex,parts);
  //  find(current_hex->get_e(),*current_hex,parts);
  //  find(current_hex->get_f(),*current_hex,parts);
  //  find(current_hex->get_g(),*current_hex,parts);
  //  find(current_hex->get_h(),*current_hex,parts);
  //  if(!valid(*current_hex,parts)){
  //    std::cout << "     not valid ! : hex " << current_hex  << " made of ";
  //    for (int i=0;i<8;i++)
  //      cout << "  " << current_hex->getVertex(i)->getNum();
  //    cout << endl;
  //    return false;
  //  }

  if(!conformityA(*current_hex)){
    std::cout << "     not conform A! : hex " << current_hex << " made of ";
    for (int i=0;i<8;i++)
      cout << "  " << current_hex->getVertex(i)->getNum();
    cout << endl;
    return false;
  }

  if(!conformityB(*current_hex)){
    std::cout << "     not conform B! : hex " << current_hex  << " made of ";
    for (int i=0;i<8;i++)
      cout << "  " << current_hex->getVertex(i)->getNum();
    cout << endl;
    return false;
  }

  if(!conformityC(*current_hex)){
    std::cout << "     not conform C! : hex " << current_hex  << " made of ";
    for (int i=0;i<8;i++)
      cout << "  " << current_hex->getVertex(i)->getNum();
    cout << endl;
    return false;
  }

  if(!faces_statuquo(*current_hex)){
    std::cout << "     not ok faces status quo! : hex " << current_hex << " made of ";
    for (int i=0;i<8;i++)
      cout << "  " << current_hex->getVertex(i)->getNum();
    cout << endl;
    return false;
  }

  // end post check...


  return true;
}


void Recombinator_Graph::add_face(const MVertex *a,const MVertex* b,const MVertex *c,std::multimap<unsigned long long, pair<PETriangle*,int> > &f)
{
  vector<const MVertex*> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  PETriangle *q = new PETriangle(v);
  std::multimap<unsigned long long, pair<PETriangle*,int> >::iterator itfind = find_the_triangle(q,f);
  if (itfind==f.end()){
    f.insert(make_pair(q->get_hash(),make_pair(q,1)));
  }
  else{
    delete q;
  }
}


void Recombinator_Graph::add_face(const MVertex *a,const MVertex* b,const MVertex *c,Hex *hex)
{
  vector<const MVertex*> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  PETriangle *q = new PETriangle(v);
  citer itfind = find_the_triangle(q,triangular_faces);
  if (itfind==triangular_faces.end()){
    itfind = triangular_faces.insert(make_pair(q->get_hash(),q));
  }
  else{
    delete q;
    q = itfind->second;
  }

  hex_to_faces[hex].insert(q);
  faces_to_hex[q].insert(hex);
}


void Recombinator_Graph::add_edges(Hex *hex)
{
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  a = hex->get_a();
  b = hex->get_b();
  c = hex->get_c();
  d = hex->get_d();
  e = hex->get_e();
  f = hex->get_f();
  g = hex->get_g();
  h = hex->get_h();

  fill_edges_table(a,b,c,d,hex);
  fill_edges_table(e,f,g,h,hex);
  fill_edges_table(a,b,f,e,hex);
  fill_edges_table(b,c,g,f,hex);
  fill_edges_table(d,c,g,h,hex);
  fill_edges_table(d,a,e,h,hex);
}


void Recombinator_Graph::fill_edges_table(const MVertex *a, const MVertex *b, const MVertex *c, const MVertex *d, Hex *hex)
{
  vector<const MVertex* > v;
  vector<const MVertex* > u;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  v.push_back(d);

  vector<const MVertex*>::const_iterator it1 = v.begin();
  for (;it1!=v.end();it1++){
    vector<const MVertex*>::const_iterator it2 = it1;
    for (;it2!=v.end();it2++){
      if (it1==it2) continue;

      u.clear();
      u.push_back(*it1);
      u.push_back(*it2);
      // see if already exists or not...
      PELine *l = new PELine(u);
      linemap::const_iterator itfind = find_the_line(l,edges_and_diagonals);
      if (itfind==edges_and_diagonals.end()){
        itfind = edges_and_diagonals.insert(make_pair(l->get_hash(),l));
      }
      else{
        delete l;
        l = itfind->second;
      }

      hex_to_edges[hex].insert(l);
      edges_to_hex[l].insert(hex);
    }
  }
}


Recombinator_Graph::graph::iterator Recombinator_Graph::find_hex_in_graph(Hex* hex)
{
  pair<graph::iterator, graph::iterator> range = incompatibility_graph.equal_range(hex->get_hash());
  if (range.first==range.second) return incompatibility_graph.end();

  graph::iterator it = range.first;
  for (;it!=range.second;it++){
    if (it->second.first==hex){
      return it;
    }
  }
  return incompatibility_graph.end();
}

Recombinator_Graph::graph_data::iterator Recombinator_Graph::find_hex_in_graphrow(Hex* hex, graph_data &row)
{
  pair<graph_data::iterator, graph_data::iterator> range = row.equal_range(hex->get_hash());
  if (range.first==range.second) return row.end();

  graph_data::iterator it = range.first;
  for (;it!=range.second;it++){
    if (it->second==hex){
      return it;
    }
  }
  return row.end();
}

bool Recombinator_Graph::find_hex_couple_in_graph(Hex* hex, Hex* other_hex)
{
  graph::iterator it = find_hex_in_graph(hex);
  if (it==incompatibility_graph.end()) return false;

  graph_data::iterator itt = find_hex_in_graphrow(other_hex, it->second.second);
  if (itt==it->second.second.end()) return false;
  return true;

}


void Recombinator_Graph::add_graph_entry(Hex* hex, Hex* other_hex)
{

  graph::iterator itfind_graph = find_hex_in_graph(hex);

  if (itfind_graph==incompatibility_graph.end()){
    itfind_graph = incompatibility_graph.insert(make_pair(hex->get_hash(),make_pair(hex, graph_data())));
    itfind_graph->second.second.insert(make_pair(other_hex->get_hash(),other_hex));
    set_of_all_hex_in_graph.insert(hex);
    return;
  }
  else{
    itfind_graph->second.second.insert(make_pair(other_hex->get_hash(),other_hex));
  }

}

void Recombinator_Graph::compute_hex_ranks()
{

  create_faces_connectivity();

  PETriangle* face;
  Hex *hex;
  double boundary_count;

  for (map<Hex*,set<PETriangle*> >::iterator it = hex_to_faces.begin();it!=hex_to_faces.end();it++){
    hex = it->first;
    boundary_count=0.;
    for (set<PETriangle*>::iterator itf = it->second.begin();itf!=it->second.end();itf++){
      face = *itf;
      if (faces_connectivity[face]==1) boundary_count+=1.;
    }
    //cout << " --- hex " << hex << " has " << boundary_count << " tri faces on boundaries, " << hex_to_faces[hex].size() << " total tri faces " << endl;
    map<Hex*,vector<double> >::iterator itfind = hex_ranks.find(hex);
    if (itfind==hex_ranks.end())
      hex_ranks.insert(make_pair(hex,vector<double>(1)));
    hex_ranks[hex][0] = boundary_count;
    hex_ranks[hex][1] = hex->get_quality();
  }
}


void Recombinator_Graph::create_faces_connectivity()
{
  for (std::map<MElement*, std::set<Hex*> >::iterator it_tet = tet_to_hex.begin(); it_tet!=tet_to_hex.end();it_tet++){
    add_face_connectivity(it_tet->first, 0,1,2);
    add_face_connectivity(it_tet->first, 0,1,3);
    add_face_connectivity(it_tet->first, 0,2,3);
    add_face_connectivity(it_tet->first, 1,2,3);
  }
}


void Recombinator_Graph::add_face_connectivity(MElement *tet, int i, int j, int k)
{
  vector<const MVertex*> v;
  PETriangle *t;
  v.push_back(tet->getVertex(i));
  v.push_back(tet->getVertex(j));
  v.push_back(tet->getVertex(k));
  t = new PETriangle(v);
  citer itfind = find_the_triangle(t,triangular_faces);
  if (itfind!=triangular_faces.end()){
    faces_connectivity[itfind->second]++;
  }
  delete t;
}

void Recombinator_Graph::compute_hex_ranks_blossom()
{

  create_faces_connectivity();

  PETriangle* face;
  Hex *hex;
  double boundary_count;
  MVertex *a,*b,*c,*d;
  MVertex *e,*f,*g,*h;

  for (map<Hex*,set<PETriangle*> >::iterator it = hex_to_faces.begin();it!=hex_to_faces.end();it++){
    hex = it->first;
    boundary_count=0.;
    for (set<PETriangle*>::iterator itf = it->second.begin();itf!=it->second.end();itf++){
      face = *itf;
      if (faces_connectivity[face]==1) boundary_count+=1.;
    }
    //cout << " --- hex " << hex << " has " << boundary_count << " tri faces on boundaries, " << hex_to_faces[hex].size() << " total tri faces " << endl;
    map<Hex*,vector<double> >::iterator itfind = hex_ranks.find(hex);
    if (itfind==hex_ranks.end())
      hex_ranks.insert(make_pair(hex,vector<double>(1)));
    hex_ranks[hex][0] = boundary_count;
    hex_ranks[hex][1] = hex->get_quality();


    a = hex->get_a();
    b = hex->get_b();
    c = hex->get_c();
    d = hex->get_d();
    e = hex->get_e();
    f = hex->get_f();
    g = hex->get_g();
    h = hex->get_h();

    int count_blossom=0;
    if (find_face_in_blossom_info(a,b,c,d)) count_blossom++;
    if (find_face_in_blossom_info(e,f,g,h)) count_blossom++;
    if (find_face_in_blossom_info(a,b,f,e)) count_blossom++;
    if (find_face_in_blossom_info(b,c,g,f)) count_blossom++;
    if (find_face_in_blossom_info(d,c,g,h)) count_blossom++;
    if (find_face_in_blossom_info(d,a,e,h)) count_blossom++;

    hex_ranks[hex][2] = count_blossom;

  }
}

bool Recombinator_Graph::find_face_in_blossom_info(MVertex *a, MVertex *b,
                                                   MVertex *c, MVertex *d)
{
  PETriangle *t1,*t2;

  t1 = get_triangle(a,b,c);
  t2 = get_triangle(a,c,d);

  if (is_blossom_pair(t1,t2))
    return true;


  t1 = get_triangle(a,b,d);
  t2 = get_triangle(b,c,d);
  if (is_blossom_pair(t1,t2))
    return true;

  return false;
}


PETriangle* Recombinator_Graph::get_triangle(MVertex*a, MVertex* b, MVertex *c)
{
  vector<const MVertex*> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  PETriangle *t = new PETriangle(v);
  citer it_find_tri = find_the_triangle(t, triangular_faces);
  delete t;
  return (it_find_tri->second);
}


bool Recombinator_Graph::is_blossom_pair(PETriangle *t1, PETriangle *t2)
{
  tripair::iterator itfind = blossom_info.find(t1);
  if (itfind!=blossom_info.end()){
    if (t2==itfind->second)
      return true;
  }
  return false;
}

