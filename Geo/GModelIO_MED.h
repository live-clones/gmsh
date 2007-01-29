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
typedef std::list<int>::const_iterator listIter;
typedef std::map<int,int>numero;
typedef std::set<int>setFamille;

class ConversionData 
{
	public :

 	   ConversionData();
	   int inMaxEltInMed(int clef);

           std::map<int,med_geometrie_element> typesOfElts;
           std::map<int,int> maxEltInMed;
           std::map<int,std::list<int> > medVertexOrder;

	   std::map<int,int> familleParDimension;
	   std::map<int,int> famillefamille;

};

class Data 
{
    public :
    static ConversionData MyConversionData ;
};


template<class T>
class MontraitementDeBase : Data
{
  protected:
  static inline int RecupereFamille(const T &ele, setFamille & numFamilles, const int dimension)
  {
     int famille = 0;
     if (ele.physicals.size() != 0) 
        famille=ele.physicals[0];
     if (famille == 0) return 0; 

     if (famille > 0)  famille = -1 * famille;

     // On verifie qu il s agit de la bonne dimension 
     int familleInitiale=famille;
     while (MyConversionData.familleParDimension[famille] != dimension)
     {
        if (numFamilles.find(famille) == numFamilles.end())
        {
     	    numFamilles.insert(famille);
	    MyConversionData.familleParDimension[famille]=dimension;
        }
	 else 
	{
           famille=famille-1000;
        }
	//Msg(INFO, "famille %d", famille);
     }

     MyConversionData.famillefamille[familleInitiale]=famille;
     return famille;
  }

  template < class G>
  static void RecupereElement(const std::vector<G*> &ele , connectivities &maMap, connectivities &mesFamilles, 
		              numero& elements , const int famille) {
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
	      maMap[medType].push_back(elements[Noeud]);
           }

	mesFamilles[medType].push_back(famille);
        }
  }
 };

template <class T>
struct MonTraitement : public MontraitementDeBase<T>{
  static inline  void AddElement(const T & ele,connectivities  & maMap, connectivities &mesFamilles, numero& elements ,setFamille& numFamilles)
   {
	 Msg(GERROR, "Wrong Call : basic Method AddElt");
   }
};

template <>
struct MonTraitement<GVertex> : public MontraitementDeBase<GVertex>{
  static inline  void AddElement(const GVertex & ele, connectivities  & maMap, connectivities &mesFamilles, numero& elements ,setFamille & numFamilles) {
  // Pour les Noeuds on ne fait rien ni sur la connectivite ni sur les familles
  }
};

template <>
struct MonTraitement<GEdge> : public MontraitementDeBase<GEdge>{
  static inline void AddElement(const GEdge & ele, connectivities  & maMap, connectivities &mesFamilles, numero& elements, setFamille & numFamilles) {
	   RecupereElement (ele.lines,  maMap, mesFamilles, elements, RecupereFamille(ele, numFamilles, 1));
     }
};

template <>
struct MonTraitement<GFace> : public MontraitementDeBase<GFace>{
  static inline void AddElement(const GFace & ele, connectivities  & maMap, connectivities &mesFamilles, numero& elements , setFamille & numFamilles) {
	   RecupereElement (ele.triangles,   maMap, mesFamilles, elements, RecupereFamille(ele, numFamilles, 2));
	   RecupereElement (ele.quadrangles, maMap, mesFamilles, elements, RecupereFamille(ele, numFamilles, 2));
     }
};

template <>
struct MonTraitement<GRegion> : public MontraitementDeBase<GRegion>{
  static inline void AddElement(const GRegion & ele, connectivities  & maMap, connectivities &mesFamilles, numero& elements, setFamille & numFamilles) {
	   RecupereElement (ele.tetrahedra, maMap, mesFamilles, elements, RecupereFamille(ele, numFamilles, 3));
	   RecupereElement (ele.hexahedra,  maMap, mesFamilles, elements, RecupereFamille(ele, numFamilles, 3));
	   RecupereElement (ele.prisms,     maMap, mesFamilles, elements, RecupereFamille(ele, numFamilles, 3));
	   RecupereElement (ele.pyramids,   maMap, mesFamilles, elements, RecupereFamille(ele, numFamilles, 3));
     }
};

template<class T> struct TraiteFamille
{
   static inline int GetFamille (const T& element)
   {
     // On ne traite pas les familles d 'elements a ce stade
     return 0;
   }
};

template<>
struct TraiteFamille<GVertex>
{
  static inline int GetFamille (const GVertex& element)
 {
     int famille = 0;
     if (element.physicals.size() != 0 ) famille = element.physicals[0];
     return famille;
 }
};

class MVertex;
class MEdge;
class MedIO 
{
   public:
      MedIO();
      int SetFile     (const std::string& theFileName);
      int AddVertex   (MVertex* const v, const int famille );
      int AddEdge     (MEdge* const e );
      int Ecrit	      ();
      int CloseFile   ();

   private :
      int CreateNodeFam();
      int CreateElemtFam();
      int CreateElemt();

   private :
      std::string  _FileName;
      std::map<med_geometrie_element,std::vector<int> > connectivities;
      std::map<med_geometrie_element,std::vector<int> > famElts;

      std::vector<med_float> coordonnees;
      std::vector<int> families;
      std::vector<med_int> numOpt;
      std::map<int,int> elements;
  
      std::set<int> numFamilles;
      int _numOfNode;

      int _boolOpen;
      med_idt _fid;
      std::string _meshName;

   public : 
     static ConversionData MyConversionData ;
    
      
template<class T>
void WriteNodes(const std::set<T*,GEntityLessThan> & seq) 
{
  typename std::set<T*,GEntityLessThan>::const_iterator iter=seq.begin();

  for ( ; iter != seq.end() ; ++iter)
  {
    const T& element= *(*iter);

    //Msg(INFO," Type d element  %s", typeid(element).name());

    // Traitement des Noeuds
    // Calcul du nombre de noeuds a stocker dans Med
    unsigned int thisSize=element.mesh_vertices.size();
    if (Data::MyConversionData.inMaxEltInMed(element.tag()) == 1) 
    {
         const unsigned int maxSize  = Data::MyConversionData.maxEltInMed[element.tag()];
         if (maxSize < thisSize) thisSize = maxSize ;
    };

    // stockage du Noeud
    int famille=TraiteFamille<T>::GetFamille(element);
    for (unsigned int i = 0; i < thisSize; ++i)
    {
    	AddVertex (element.mesh_vertices[i], famille);
    };

    // Stockage des Egdes
    MonTraitement<T>::AddElement(element,connectivities,famElts,elements,numFamilles);

  }
}
};


# endif

#endif
