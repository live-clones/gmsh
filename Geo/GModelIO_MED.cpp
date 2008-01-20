// $Id: GModelIO_MED.cpp,v 1.8 2008-01-20 11:39:47 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "MElement.h"
#include "MVertex.h"
#include "MEdge.h"
#include "Message.h"

#if defined(HAVE_MED)

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "GModelIO_MED.h"

extern "C" {
#include "med.h"
}

ConversionData Data::MyConversionData;

typedef std::list<int>::const_iterator listIter;

// _____________________________________________ //
//                                               //
// Implementation  de la classe  ConversionData  //
//  ____________________________________________ //

ConversionData::ConversionData()
{ 
	// Correspondance des types GMSH et MEd
	static const med_geometrie_element ValuesTypesOfElts[] = {  MED_SEG2,    MED_TRIA3,  MED_QUAD4,   MED_TETRA4,
								    MED_HEXA8,   MED_PENTA6, MED_PYRA5,   MED_SEG3, 
								    MED_TRIA6,   MED_QUAD8,  MED_TETRA10, MED_HEXA20, 
								    MED_PENTA15, MED_PYRA13, MED_POINT1,  MED_QUAD8,
								    MED_HEXA20,  MED_PENTA15, MED_PYRA13,  MED_NONE};
		
	int i=0;
	while (ValuesTypesOfElts[i] != MED_NONE)
	{
	   typesOfElts[i+1]=ValuesTypesOfElts[i];
	   ++i;
	}

	// **************************
	// Numérotation des Noeuds
	// **************************
	//
	// line ( 1er et 2nd Ordre)
	i=1;
	while ( i!=3 ) { 
	   medVertexOrder[1].push_back(i);
	   medVertexOrder[8].push_back(i);
	   ++i;
	}
	medVertexOrder[8].push_back(3);

	// tria
	i=1;
	while ( i!=4 ) { 
	   medVertexOrder[2].push_back(i);
	   medVertexOrder[9].push_back(i);
	   ++i;
	}
	medVertexOrder[9].push_back(4);
	medVertexOrder[9].push_back(5);
	medVertexOrder[9].push_back(6);

	// quad
	i=1;
	while ( i!=5 ) { 
	   medVertexOrder[3].push_back(i);
	   medVertexOrder[10].push_back(i);
	   medVertexOrder[16].push_back(i);
	   ++i;
	}
	medVertexOrder[10].push_back(5);
	medVertexOrder[16].push_back(5);
	medVertexOrder[10].push_back(6);
	medVertexOrder[16].push_back(6);
	medVertexOrder[10].push_back(7);
	medVertexOrder[16].push_back(7);
	medVertexOrder[10].push_back(8);
	medVertexOrder[16].push_back(8);

	// tetra
	static const int OrderforTetra[] = { 1, 3, 2, 4, 0 };
	i=0;
	while ( OrderforTetra[i] != 0 ) { 
	   medVertexOrder[4].push_back(OrderforTetra[i]);
	   medVertexOrder[11].push_back(OrderforTetra[i]);
	   ++i;
	}
	static const int OrderforTetra2[] = { 7, 6 , 5, 8 , 9 , 10, 0 }; 
	i=0;
	while ( OrderforTetra2[i] != 0 ) { 
	   medVertexOrder[11].push_back(OrderforTetra2[i]);
	   ++i;
	}

	// hexa
	// le 1 MED est le 1er Gmsh,   le 2nd Med est le 4ieme Gmsh , le 3 le 6 ...
	static const int OrderforHexa[] = { 1, 5, 8,  4, 2, 6, 7, 3, 0};
	i=0;
	while (OrderforHexa[i] != 0)
	{
	   medVertexOrder[5].push_back(OrderforHexa[i]);
	   medVertexOrder[12].push_back(OrderforHexa[i]);
	   medVertexOrder[17].push_back(OrderforHexa[i]);
	   ++i;
	};
	static const int OrderforHexa2[] = { 11,18,16,10,13,19,15,16,9,17,20,14, 0 }; 
	i=0;
	while ( OrderforHexa2[i] != 0 ) { 
	   medVertexOrder[12].push_back(OrderforHexa2[i]);
	   medVertexOrder[17].push_back(OrderforHexa2[i]);
	   ++i;
	}

	// Prism
	static const int OrderforPrism[] = { 1, 3, 2, 4, 6, 5, 0};
	i=0;
	while (OrderforPrism[i] != 0)
	{
	   medVertexOrder[6].push_back(OrderforPrism[i]);
	   medVertexOrder[13].push_back(OrderforPrism[i]);
	   medVertexOrder[18].push_back(OrderforPrism[i]);
	   ++i;
	};
	static const int OrderforPrism2[] = { 8, 10, 7, 14, 13, 15, 9, 12, 11, 0};
	i=0;
	while ( OrderforPrism2[i] != 0 ) { 
	   medVertexOrder[13].push_back(OrderforPrism2[i]);
	   medVertexOrder[18].push_back(OrderforPrism2[i]);
	   ++i;
	}


	//Pyra
	static const int OrderforPyra[] = { 1, 4, 3, 2, 5, 0};
	i=0;
	while (OrderforPyra[i] != 0)
	{
	   medVertexOrder[7].push_back(OrderforPyra[i]);
	   medVertexOrder[14].push_back(OrderforPyra[i]);
	   medVertexOrder[19].push_back(OrderforPyra[i]);
	   ++i;
	};
	static const int OrderforPyra2[] = { 7, 11 ,9 , 6, 8, 13, 12 , 10, 0};
	i=0;
	while ( OrderforPyra2[i] != 0 ) { 
	   medVertexOrder[14].push_back(OrderforPyra2[i]);
	   medVertexOrder[19].push_back(OrderforPyra2[i]);
	   ++i;
	}
};


// ____________________________________ //
//                                      //
// Implementation  de la classe  MedIO  //
//  ___________________________________ //

MedIO::MedIO() : _numOfNode(1), _boolOpen(0), _meshName("monMaillage")
{ 
};

// --------------------------------------------
int MedIO::SetFile(const std::string &FileName)
// --------------------------------------------
// Open Med File
// Headers Creation in Med File 
// Mesh Creation in Med File
{
   _FileName = FileName;
   // All Meshes are 3D and unstructured Meshes
   med_err ret = 0;
   char des[MED_TAILLE_DESC+1]="Med file generated by  Gmsh";

   _fid = MEDouvrir((char *) _FileName.c_str(),MED_CREATION);
   if (_fid < 0) {
       Msg(GERROR, "Unable to open file '%s'", _FileName.c_str());
       return 0;
   }

   if (MEDfichDesEcr(_fid,des) < 0) {
       Msg(GERROR, "Unable to write descriptor in file '%s'", _FileName.c_str());
       return 0;
   }

   std::string description = "gmsh";
   if (MEDmaaCr(_fid,(char *) _meshName.c_str(),3,MED_NON_STRUCTURE,(char *) description.c_str()) < 0) 
   {
       Msg(GERROR, "Error in Mesh Creation '%s'", _FileName.c_str());
       return 0;
   }
   _boolOpen=1;
    Msg(INFO, "File Open");
   return 1;
}
 
// -------------------------------------------------
int MedIO::AddNode(MVertex* v, const int famille)
// -------------------------------------------------
{ 
    //Msg(INFO, "Creation %d", v->getNum());
   
   if ( elements.find(v->getNum()) != elements.end() ) return 1;
   coordonnees.push_back((med_float)v->x());
   coordonnees.push_back((med_float)v->y());
   coordonnees.push_back((med_float)v->z());

   numOpt.push_back(v->getNum());
   elements[v->getNum()] = _numOfNode ;
   _numOfNode = _numOfNode + 1;

   families.push_back(famille);
   numFamilles.insert(famille);
   return 1;
}

// -------------------------------
int MedIO::CreateFamilles( )
// -------------------------------
{
   numFamilles.insert(0);
   std::set<int>::const_iterator itFam;
   for (itFam = numFamilles.begin(); itFam != numFamilles.end(); ++itFam) {
	med_err CR;
	if (*itFam != 0 )
	{ std::ostringstream oss;
          oss << *itFam;
          std::string fam = "F_" + oss.str();
          std::string group = "G_" + oss.str();
	  while (group.size() < 80) group = group + " ";
          CR = MEDfamCr (_fid, (char *) _meshName.c_str(),(char *)fam.c_str(),*itFam, 0,0,0,0,(char *)group.c_str(),1);
	  CR=0;
	}
	else
	{
          std::string fam = "Famille0";
          CR = MEDfamCr (_fid, (char *) _meshName.c_str(),(char *)fam.c_str(),*itFam, 0,0,0,0,0,0);
	}
        if ( CR < 0 )
        {
            Msg(GERROR, "Error in Family Creation '%d'", *itFam );
            return 0;
         }
   }
   return 1;
}


// -------------------------------
int MedIO::CreateElemt()
// -------------------------------
{
    std::map<int,med_geometrie_element>::const_iterator eltIter = Data::MyConversionData.typesOfElts.begin();
    for ( ; eltIter != Data::MyConversionData.typesOfElts.end(); ++eltIter ) {
       med_geometrie_element typemed =(*eltIter).second;
       if (typemed == MED_POINT1) continue;
       int nbNoeudElt = typemed % 100 ;
       int nbElements = LesConn[typemed].size() / nbNoeudElt;
       if (nbElements != 0 )
           med_err CR = MEDelementsEcr (_fid, (char*) _meshName.c_str(),(med_int) 3, 
		         &LesConn[typemed][0], MED_FULL_INTERLACE,
			 NULL, MED_FAUX, NULL, MED_FAUX,
			 &famElts[typemed][0],nbElements,
			   MED_MAILLE,typemed,MED_NOD);

    }
};
// ------------------------------------------
int MedIO::Ecrit()
// ------------------------------------------
{
    if (_boolOpen != 1)
    {
        Msg(GERROR, "File not Open");
	return 0;
    }

    int nbNoeuds=coordonnees.size() / 3;
    if (nbNoeuds != families.size())
    {
        Msg(GERROR, "bad Vectors");
	return 0;
    }

    // *********************
    // Creation des Familles
    // *********************
    int CRFam = CreateFamilles();
    if ( CRFam < 0 )
    {
       Msg(GERROR, "Error in Nodes Families Creation ");
       return 0;
    }

    // *************************
    // Creation des Coordonnees
    // *************************
    char nomcoo[3*MED_TAILLE_PNOM+1] = "x               y               z               ";
    char unicoo[3*MED_TAILLE_PNOM+1] = "inconnu         inconnu         inconnu         ";

    med_err CR = MEDnoeudsEcr(_fid, (char*) _meshName.c_str(),(med_int) 3, 
		              &coordonnees[0], MED_FULL_INTERLACE, MED_CART,
		              nomcoo,unicoo, NULL, MED_FAUX, 
			      &numOpt[0], MED_VRAI, 
			      &families[0], nbNoeuds);
    Msg(INFO, "%d ", CR);
    if ( CR < 0 )
    {
       Msg(GERROR, "Error in Nodes Creation ");
       return 0;
    }
    // ***************************
    // Creation des connectivités
    // ***************************
    int CRElt = CreateElemt();
    if ( CRElt < 0 )
    {
       Msg(GERROR, "Error in Elements Creation ");
       return 0;
    }
    return 1;
}

//--------------------
int MedIO::CloseFile()
//--------------------
{
   if (MEDfermer(_fid) < 0) 
   {
       Msg(GERROR, "Unable to close file '%s'",(char * ) _FileName.c_str());
       return 0;
   }
  return 1;
}


int GModel::writeMED(const std::string &name)
{

   MedIO MedDriver = MedIO();
   int CR1 = MedDriver.SetFile(name);

   renumberMeshVertices(noPhysicalGroups());
   MedDriver.TraiteMed(vertices);
   MedDriver.TraiteMed(edges);
   MedDriver.TraiteMed(faces);
   MedDriver.TraiteMed(regions);

   int CR2 = MedDriver.Ecrit();
   int CR3 = MedDriver.CloseFile();

   return CR1 * CR2 * CR3 ;
}

#else

int GModel::writeMED(const std::string &name)
{
  Msg(GERROR, "Gmsh has to be compiled with MED support to write '%s'",
      name.c_str());
  return 0;
}

#endif                // du HAVE_LIBMED

