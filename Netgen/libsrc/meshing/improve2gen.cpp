#include <mystdlib.h>

#include "meshing.hpp"
#include <opti.hpp>

namespace netgen
{

  class ImprovementRule
  {
  public:
    ARRAY<Element2d> oldels;
    ARRAY<Element2d> newels;
    ARRAY<int> incelsonnode;
    ARRAY<int> reused;
    int bonus;
    int onp;
  };


  void MeshOptimize2d :: GenericImprove (Mesh & mesh)
  {
    if (!faceindex)
      {
	if (writestatus)
	  PrintMessage (3, "Generic Improve");

	for (faceindex = 1; faceindex <= mesh.GetNFD(); faceindex++)
	  GenericImprove (mesh);
      
	faceindex = 0;
      }

    int j, k, l, ri;
    int np = mesh.GetNP();
    int ne = mesh.GetNSE();
    SurfaceElementIndex sei;

    bool ok;
    int olddef, newdef;

    ARRAY<ImprovementRule*> rules;
    ARRAY<SurfaceElementIndex> elmap;
    ARRAY<int> elrot;
    ARRAY<PointIndex> pmap;
    ARRAY<PointGeomInfo> pgi;

    int surfnr = mesh.GetFaceDescriptor (faceindex).SurfNr();
  
    ImprovementRule * r1;

    // 2 triangles to quad
    r1 = new ImprovementRule;
    r1->oldels.Append (Element2d (1, 2, 3));
    r1->oldels.Append (Element2d (3, 2, 4));
    r1->newels.Append (Element2d (1, 2, 4, 3));
    r1->onp = 4;
    r1->bonus = 2;
    rules.Append (r1);

    // 2 quad to 1 quad
    r1 = new ImprovementRule;
    r1->oldels.Append (Element2d (1, 2, 3, 4));
    r1->oldels.Append (Element2d (4, 3, 2, 5));
    r1->newels.Append (Element2d (1, 2, 5, 4));
    r1->onp = 5;
    r1->bonus = 0;
    rules.Append (r1);

    // swap quads
    r1 = new ImprovementRule;
    r1->oldels.Append (Element2d (1, 2, 3, 4));
    r1->oldels.Append (Element2d (3, 2, 5, 6));
    r1->newels.Append (Element2d (1, 6, 3, 4));
    r1->newels.Append (Element2d (1, 2, 5, 6));
    r1->onp = 6;
    r1->bonus = 0;
    rules.Append (r1);

    // three quads to 2
    r1 = new ImprovementRule;
    r1->oldels.Append (Element2d (1, 2, 3, 4));
    r1->oldels.Append (Element2d (2, 5, 6, 3));
    r1->oldels.Append (Element2d (3, 6, 7, 4));
    r1->newels.Append (Element2d (1, 2, 5, 4));
    r1->newels.Append (Element2d (4, 5, 6, 7));
    r1->onp = 7;
    r1->bonus = -1;
    rules.Append (r1);

    // quad + 2 connected trigs to quad
    r1 = new ImprovementRule;
    r1->oldels.Append (Element2d (1, 2, 3, 4));
    r1->oldels.Append (Element2d (2, 5, 3));
    r1->oldels.Append (Element2d (3, 5, 4));
    r1->newels.Append (Element2d (1, 2, 5, 4));
    r1->onp = 5;
    r1->bonus = 0;
    rules.Append (r1);

    // quad + 2 non-connected trigs to quad (a and b)
    r1 = new ImprovementRule;
    r1->oldels.Append (Element2d (1, 2, 3, 4));
    r1->oldels.Append (Element2d (2, 6, 3));
    r1->oldels.Append (Element2d (1, 4, 5));
    r1->newels.Append (Element2d (1, 3, 4, 5));
    r1->newels.Append (Element2d (1, 2, 6, 3));
    r1->onp = 6;
    r1->bonus = 0;
    rules.Append (r1);

    r1 = new ImprovementRule;
    r1->oldels.Append (Element2d (1, 2, 3, 4));
    r1->oldels.Append (Element2d (2, 6, 3));
    r1->oldels.Append (Element2d (1, 4, 5));
    r1->newels.Append (Element2d (1, 2, 4, 5));
    r1->newels.Append (Element2d (4, 2, 6, 3));
    r1->onp = 6;
    r1->bonus = 0;
    rules.Append (r1);

    // two quad + trig -> one quad + trig
    r1 = new ImprovementRule;
    r1->oldels.Append (Element2d (1, 2, 3, 4));
    r1->oldels.Append (Element2d (2, 5, 6, 3));
    r1->oldels.Append (Element2d (4, 3, 6));
    r1->newels.Append (Element2d (1, 2, 6, 4));
    r1->newels.Append (Element2d (2, 5, 6));
    r1->onp = 6;
    r1->bonus = -1;
    rules.Append (r1);

    // swap quad + trig (a and b)
    r1 = new ImprovementRule;
    r1->oldels.Append (Element2d (1, 2, 3, 4));
    r1->oldels.Append (Element2d (2, 5, 3));
    r1->newels.Append (Element2d (2, 5, 3, 4));
    r1->newels.Append (Element2d (1, 2, 4));
    r1->onp = 5;
    r1->bonus = 0;
    rules.Append (r1);

    r1 = new ImprovementRule;
    r1->oldels.Append (Element2d (1, 2, 3, 4));
    r1->oldels.Append (Element2d (2, 5, 3));
    r1->newels.Append (Element2d (1, 2, 5, 3));
    r1->newels.Append (Element2d (1, 3, 4));
    r1->onp = 5;
    r1->bonus = 0;
    rules.Append (r1);




    ARRAY<int> mapped(rules.Size());
    ARRAY<int> used(rules.Size());
    used = 0;
    mapped = 0;

  

    for (ri = 0; ri < rules.Size(); ri++)
      {
	ImprovementRule & rule = *rules[ri];
	rule.incelsonnode.SetSize (rule.onp);
	rule.reused.SetSize (rule.onp);

	for (j = 1; j <= rule.onp; j++)
	  {
	    rule.incelsonnode.Elem(j) = 0;
	    rule.reused.Elem(j) = 0;
	  }

	for (j = 1; j <= rule.oldels.Size(); j++)
	  {
	    const Element2d & el = rule.oldels.Elem(j);
	    for (k = 1; k <= el.GetNP(); k++)
	      rule.incelsonnode.Elem(el.PNum(k))--;
	  }

	for (j = 1; j <= rule.newels.Size(); j++)
	  {
	    const Element2d & el = rule.newels.Elem(j);
	    for (k = 1; k <= el.GetNP(); k++)
	      {
		rule.incelsonnode.Elem(el.PNum(k))++;
		rule.reused.Elem(el.PNum(k)) = 1;
	      }
	  }
      }



  
    TABLE<int,PointIndex::BASE> elonnode(np);
    ARRAY<int,PointIndex::BASE> nelonnode(np);
    TABLE<int> nbels(ne);

    nelonnode = -4;

    for (sei = 0; sei < ne; sei++)
      {
	const Element2d & el = mesh[sei];
	if (el.GetIndex() == faceindex)
	  {
	    for (j = 0; j < el.GetNP(); j++)
	      elonnode.Add (el[j], sei);
	  }
	for (j = 0; j < el.GetNP(); j++)
	  nelonnode[el[j]]++;
      }

    for (sei = 0; sei < ne; sei++)
      {
	const Element2d & el = mesh[sei];
	if (el.GetIndex() == faceindex)
	  {
	    for (j = 0; j < el.GetNP(); j++)
	      {
		for (k = 0; k < elonnode[el[j]].Size(); k++)
		  {
		    int nbel = elonnode[el[j]] [k];
		    int used = 0;
		    for (l = 0; l < nbels[sei].Size(); l++)
		      if (nbels[sei][l] == nbel)
			used = 1;
		    if (!used)
		      nbels.Add (sei, nbel);
		  }
	      }
	  }
      }


    for (ri = 0; ri < rules.Size(); ri++)
      {
	const ImprovementRule & rule = *rules[ri];
      
	elmap.SetSize (rule.oldels.Size());
	elrot.SetSize (rule.oldels.Size());
	pmap.SetSize (rule.onp);
	pgi.SetSize (rule.onp);


	// loop over elements and rotations:
	/*
	  int nt = int (pow (ne, elmap.Size()));
	  for (i = 1; i <= nt; i++)
	  {
	  int hi = i-1;
	  for (j = 1; j <= elmap.Size(); j++)
	  {
	  elmap.Elem (j) = hi % ne + 1;
	  hi /= ne;
	  }
	*/

	for (sei = 0; sei < ne; sei++)
	  {
	    if (multithread.terminate)
	      break;

	    elmap[0] = sei;

	    int nnb = nbels[sei].Size();
	    int nt = int (pow (double(nnb), double(elmap.Size()-1)));

	    for (int i = 1; i <= nt; i++)
	      {
		int hi = i-1;
		for (j = 1; j < elmap.Size(); j++)
		  {
		    elmap[j] = nbels[sei][hi % nnb];
		    hi /= nnb;
		  }

		ok = 1;
		for (j = 0; j < elmap.Size(); j++)
		  {
		    const Element2d & el = mesh.SurfaceElement(elmap[j]);
		    const Element2d & rel = rule.oldels[j];
		   
		    if (el.GetNP() != rel.GetNP()) { ok = 0; break; }
		    if (el.IsDeleted()) { ok = 0; break; }
		  }
		
		if (!ok) continue;


		int nr = int (pow (4.0, elmap.Size()));
		for (int i2 = 1; i2 <= nr; i2++)
		  {
		    int hi2 = i2-1;
		    for (j = 1; j <= elmap.Size(); j++)
		      {
			elrot.Elem (j) = hi2 % 4 + 1;
			hi2 /= 4;
		      }
		  
		  
		    // check applicable 
		  
		    ok = 1;

		    // set mapped points
		    for (j = 1; j <= elmap.Size(); j++)
		      {
			const Element2d & el = mesh.SurfaceElement(elmap.Get(j));
			const Element2d & rel = rule.oldels.Get(j);
		      
			/*
			if (el.GetNP() != rel.GetNP())
			  {
			    ok = 0; 
			    break;
			  }
			*/

			for (k = 1; k <= el.GetNP(); k++)
			  {
			    /*
			    if (el.PNum(k) < PointIndex::BASE)
			      {
				ok = 0;
				break;
			      }
			    */
			    pmap.Elem(rel.PNum(k)) =
			      el.PNumMod(k+elrot.Get(j));
			    pgi.Elem(rel.PNum(k)) = 
			      el.GeomInfoPiMod(k+elrot.Get(j));
			  }
		      }
		    if (!ok) continue;

		    /*
		      (*testout) << "candidates found: " << endl;
		      for (j = 1; j <= elmap.Size(); j++)
		      {
		      const Element2d & el = mesh.SurfaceElement(elmap.Get(j));
		      (*testout) << "el " << elmap.Get(j) 
		      << ", rot = " << elrot.Get(j) << " "
		      << el << endl;
		      }
		    */
		  
	      
		    // check consistently mapped points:
		    for (j = 1; j <= elmap.Size(); j++)
		      {
			const Element2d & el = mesh.SurfaceElement(elmap.Get(j));
			const Element2d & rel = rule.oldels.Get(j);
		      
			for (k = 1; k <= el.GetNP(); k++)
			  {
			    if (pmap.Elem(rel.PNum(k)) != el.PNumMod(k+elrot.Get(j)))
			      ok = 0;
			  }
		      }  

		    if (!ok) continue;

		  
		    mapped[ri]++;
		  
		    /*
		      (*testout) << "application found: " << endl;
		      for (j = 1; j <= elmap.Size(); j++)
		      {
		      const Element2d & el = mesh.SurfaceElement(elmap.Get(j));
		      (*testout) << "el " << elmap.Get(j) 
		      << ", rot = " << elrot.Get(j) << " "
		      << el << endl;
		      }
		      (*testout) << "points:";
		      for (j = 1; j <= pmap.Size(); j++)
		      (*testout) << " " << pmap.Get(j);
		      (*testout) << endl;
		    */

		    olddef = 0;
		    for (j = 1; j <= pmap.Size(); j++)
		      olddef += sqr (nelonnode[pmap.Get(j)]);
		    olddef += rule.bonus;

		    newdef = 0;
		    for (j = 1; j <= pmap.Size(); j++)
		      if (rule.reused.Get(j))
			newdef += sqr (nelonnode[pmap.Get(j)] + 
				       rule.incelsonnode.Get(j));

		    if (newdef > olddef)
		      continue;

		    // calc metric badness
		    double bad1 = 0, bad2 = 0;
		    Vec3d n;

		    SelectSurfaceOfPoint (mesh.Point(pmap.Get(1)), pgi.Get(1));
		    GetNormalVector (surfnr, mesh.Point(pmap.Get(1)), pgi.Elem(1), n);
		  
		    for (j = 1; j <= rule.oldels.Size(); j++)
		      bad1 += mesh.SurfaceElement(elmap.Get(j)).CalcJacobianBadness (mesh.Points(), n);
		  
		    // check new element:
		    for (j = 1; j <= rule.newels.Size(); j++)
		      {
			const Element2d & rnel = rule.newels.Get(j);
			Element2d nel(rnel.GetNP());
			for (k = 1; k <= rnel.GetNP(); k++)
			  nel.PNum(k) = pmap.Get(rnel.PNum(k));

			bad2 += nel.CalcJacobianBadness (mesh.Points(), n);
		      }

		    if (bad2 > 1e3) continue;

		    if (newdef == olddef && bad2 > bad1) continue;
		  
	  
		    // generate new element:
		    for (j = 1; j <= rule.newels.Size(); j++)
		      {
			const Element2d & rnel = rule.newels.Get(j);
			Element2d nel(rnel.GetNP());
			nel.SetIndex (faceindex);
			for (k = 1; k <= rnel.GetNP(); k++)
			  {
			    nel.PNum(k) = pmap.Get(rnel.PNum(k));
			    nel.GeomInfoPi(k) = pgi.Get(rnel.PNum(k));
			  }
		      
			mesh.AddSurfaceElement(nel);
		      }
		  
		    for (j = 1; j <= rule.oldels.Size(); j++)
		      mesh.DeleteSurfaceElement (elmap.Get(j));

		    for (j = 1; j <= pmap.Size(); j++)
		      nelonnode[pmap.Get(j)] += rule.incelsonnode.Get(j);

		    used[ri]++;
		    break;
		  }
	      }
	  }
      }

    mesh.Compress();

    for (ri = 0; ri < rules.Size(); ri++)
      {
	PrintMessage (5, "rule ", ri+1, " ",
		      mapped[ri], "/", used[ri], " mapped/used");
      }

    int sum = 0;
    for (int i = 0; i < used.Size(); i++)
      sum += used[i];
  }




}
