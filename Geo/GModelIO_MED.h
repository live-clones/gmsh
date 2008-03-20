#ifndef _GMODELIO_MED_H_
#define _GMODELIO_MED_H_

#include <string>
#include <map>
#include <vector>
#include <set>
#include <typeinfo>

#include "GEntity.h"
#include "GRegion.h"
#include "GEdge.h"
#include "GFace.h"
#include "Message.h"

#if defined(HAVE_MED)

extern "C"
{
           #include "med.h"
}

typedef std::map<med_geometrie_element,std::vector<int> >  connectivities;
typedef std::set<int>                  setFamille;

class MedIO ;

// _________________________________________ //
//                                           //
// Declaration  de la classe  ConversionData // 
// (implementation ds le cpp)                //
// ________________________________________  //
//
class ConversionData 
{
        public :

           ConversionData();

           std::map<int,med_geometrie_element> typesOfElts;
           std::map<int,std::list<int> > medVertexOrder;

           std::map<int,int> familleParDimension;
           std::map<int,int> famillefamille;

};

// _________________________________________________ //
//                                                   //
// Declaration  de la classe  TraiteMailledeBase     // 
// (implementations en fin de fichier)               //
// ________________________________________________  //

class Data 
{
    public :
    static ConversionData MyConversionData ;
};


template<class T> 
class TraiteMailledeBase : Data
{
  protected:

  static inline int RecupereFamille(const T &ele, const int dimension, MedIO & monDriver);
  template<class G> static void RecupereElement(const std::vector<G*> &ele, const int famille, MedIO& monDriver);

};


// _________________________________________________ //
//                                                   //
// Specialisations de la classe  TraiteMailledeBase  // 
// selon le type de maille                           //
// ________________________________________________  //

template <class T>
struct TraiteMaille : public TraiteMailledeBase<T> {
  static inline  void AddElement(const T& ele, MedIO & monDriver)
  { Msg(GERROR, "Wrong Call : basic Method AddElt"); };
};


template <>
struct TraiteMaille<GVertex> : public TraiteMailledeBase<GVertex> {
  static inline  void AddElement(const GVertex & ele, MedIO& monDriver) ;
  // l'implementation est  en fin de fichier pour pouvoir utiliser la methode AddNode de MedIO
};

template <>
struct TraiteMaille<GEdge> : public TraiteMailledeBase<GEdge> {
  static inline void AddElement(const GEdge & ele, MedIO& monDriver) 
  {
           RecupereElement (ele.lines,  RecupereFamille(ele, 1, monDriver), monDriver);
  }
};

template <>
struct TraiteMaille<GFace> : public TraiteMailledeBase<GFace> {
  static inline void AddElement(const GFace & ele,  MedIO&  monDriver) 
  {
           RecupereElement (ele.triangles,   RecupereFamille(ele, 2, monDriver), monDriver);
           RecupereElement (ele.quadrangles, RecupereFamille(ele, 2, monDriver), monDriver);
  }
};

template <>
struct TraiteMaille<GRegion> : public TraiteMailledeBase<GRegion>{
  static inline void AddElement(const GRegion & ele, MedIO &  monDriver) 
  {
           RecupereElement (ele.tetrahedra, RecupereFamille(ele, 3, monDriver), monDriver );
           RecupereElement (ele.hexahedra,  RecupereFamille(ele, 3, monDriver), monDriver);
           RecupereElement (ele.prisms,     RecupereFamille(ele, 3, monDriver), monDriver);
           RecupereElement (ele.pyramids,   RecupereFamille(ele, 3, monDriver), monDriver);
     }
};

// ______________________________________ //
//                                        //
// Declaration  de la classe  MedIO       // 
// (implementation ds le cpp)             //
// _____________________________________  //

class MVertex;
class MEdge;
class MedIO 
{
   public:
      MedIO();
      int SetFile   (const std::string& theFileName);
      int AddNode   (MVertex* const v, const int famille );
      int Ecrit     ();
      int CloseFile ();

   private :
      int CreateFamilles();
      int CreateElemt();

   public :
      connectivities LesConn;
      setFamille     numFamilles;
      std::vector<int>       families;
      std::map<int,int>      elements;
      std::map<med_geometrie_element,std::vector<int> > famElts;

   private :

      std::vector<med_float> coordonnees;
      std::vector<med_int>   numOpt;
  
      int _numOfNode;
      int _boolOpen;

      med_idt _fid;
      std::string  _FileName;
      std::string  _meshName;

   public : 
     static ConversionData MyConversionData ;
    
      
   template<class T>
   void TraiteMed(const std::set<T*,GEntityLessThan> & seq) 
   {
        typename std::set<T*,GEntityLessThan>::const_iterator iter=seq.begin();

        for ( ; iter != seq.end() ; ++iter)
        {
             const T& element= *(*iter);
             TraiteMaille<T>::AddElement(element, *this);
        }
   }
};

// _______________________________________________________________ //
//                                                                 //
// Implementation des Methodes des classes de type TraiteElement   // 
// qui utilisent MedIO                                             //
// _______________________________________________________________ //

void TraiteMaille<GVertex>::AddElement(const GVertex & ele, MedIO& monDriver)
{
     int famille = 0;
     if (ele.physicals.size() != 0 ) famille = ele.physicals[0];
     monDriver.AddNode(ele.mesh_vertices[0],famille);
}

//                                      *-*-*-*-*-*-*-*-*-*

template<class T> int TraiteMailledeBase<T>::RecupereFamille(const T &ele, const int dimension, MedIO & monDriver)
// 
// Dans le format MED, Les familles de mailles sont negatives (contrairement au physical group de GMSH)
// Les familles ne contiennent des mailles de la meme dimension 
{
     int famille = 0;
     if (ele.physicals.size() != 0) famille=ele.physicals[0];
     if (famille == 0) return 0; 

     if (famille > 0)  famille = -1 * famille;

     int familleInitiale=famille;
     while (MyConversionData.familleParDimension[famille] != dimension)
     {
        if (monDriver.numFamilles.find(famille) == monDriver.numFamilles.end())
        {   monDriver.numFamilles.insert(famille);
            MyConversionData.familleParDimension[famille]=dimension;
        }
         else famille=famille-1000;
     }

     MyConversionData.famillefamille[familleInitiale]=famille;
     return famille;
}

//                                      *-*-*-*-*-*-*-*-*-*

template<class T>
template<class G> void TraiteMailledeBase<T>::RecupereElement(const std::vector<G*> &ele, const int famille, MedIO& monDriver) 
// l'implementation aurait pu etre laissee avec la declaration (ok pour GCC 3.3.5)
// mais pour eviter des eventuels pb de portage il semble preferable de la separer
{

     typedef std::list<int>::const_iterator listIter;

     if (ele.size() == 0) return;
     const int type=ele[0]->getTypeForMSH();
     const med_geometrie_element medType= Data::MyConversionData.typesOfElts[type];

     for (unsigned int elt = 0; elt < ele.size(); ++elt) {
        const int monNum=ele[elt]->getNum();
        for (listIter monIter  = Data::MyConversionData.medVertexOrder[type].begin(); 
                      monIter != Data::MyConversionData.medVertexOrder[type].end(); 
                      ++monIter) {
              const int NoeudATraiter = *monIter - 1;
              const int Noeud = ele[elt]->getVertex(NoeudATraiter)->getNum();
              monDriver.AddNode(ele[elt]->getVertex(NoeudATraiter),0);
              monDriver.LesConn[medType].push_back(monDriver.elements[Noeud]);
           }
        monDriver.famElts[medType].push_back(famille);
        }
}

#endif               // du HAVE_LIBMED
#endif               // du define de _GMODELIO_MED_H_
