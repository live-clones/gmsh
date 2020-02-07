#include "hxt_edge.h"
#include "hxt_sort.h"



static HXTStatus hxtDoubleLongestEdge(HXTEdges *e, int tri, double *l)
{
  uint32_t *ed = &e->tri2edg[3*tri];
  *l=0;
  
  for(int i=0; i<3; i++){
    uint64_t *tr= &e->edg2tri[2*ed[i]];
    
    if(tr[1]==(uint64_t)-1)
      continue;

    if(*l<hxtEdgesLength(e,ed[i]))
      *l=hxtEdgesLength(e,ed[i]);
  }
    return HXT_STATUS_OK;
    
}


static HXTStatus hxtLongestEdge(HXTEdges *edges, int tri,int *ie,int comp)
{
  
  uint32_t *ed = &edges->tri2edg[3*tri];
  double longest = hxtEdgesLength(edges,comp);
  *ie=comp;
  for(int i=0; i<3; i++){
    uint64_t *tr= &edges->edg2tri[2*ed[i]];
    
    if(tr[1]==(uint64_t)-1)
      continue;

    if(longest<hxtEdgesLength(edges,ed[i])){
      longest=hxtEdgesLength(edges,ed[i]);
      *ie = ed[i];
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtLongestEdgeBisection(HXTEdges *edges,int nrefinements)
{

  double threshold = 0, counter=0;
  for(uint32_t ie=0; ie<edges->numEdges; ie++)
    if(edges->edg2tri[2*ie+1]==(uint64_t)-1){
      threshold+= hxtEdgesLength(edges,ie);
      counter++;
    }
  if (counter>0)
    threshold/=counter;

  // longest-edge bisection: boundary edges are not splitted
  for(int ir=0; ir<nrefinements; ir++){
    HXTEdges *e = edges;
    HXTMesh *m = edges->edg2mesh;


    
    uint64_t *flag=NULL;
    HXT_CHECK(hxtMalloc(&flag,m->triangles.num*sizeof(uint64_t)));
    for(uint64_t it=0; it<m->triangles.num; it++){
      double l;
      HXT_CHECK(hxtDoubleLongestEdge(e,it,&l));
      if(l>2*threshold)
        flag[it] = 0;
      else
        flag[it] = 1;
    }

    int maxVert = m->vertices.num;
    int maxTri = m->triangles.num;
    int maxEdg = e->numEdges;
    uint64_t initialNumberOfTriangles = m->triangles.num;
    for(uint64_t it=0; it<initialNumberOfTriangles; it++){
      if(flag[it] > 0)
        continue;

      while(flag[it]==0){
        int ti = (int) it, tj;
        int ei,ej;
        for(int ib=0; ib<3; ib++){
          if (e->edg2tri[2*e->tri2edg[3*it+ib]+1] == (uint64_t) -1)
            continue;
          else{
            hxtLongestEdge(e,it,&ej,e->tri2edg[3*it+ib]);
            break;
          }
        }
        do{       
          HXT_CHECK(hxtLongestEdge(e,ti,&ei,ej));
          tj = e->edg2tri[2*ei+0]==ti ? e->edg2tri[2*ei+1] : e->edg2tri[2*ei+0];
          HXT_CHECK(hxtLongestEdge(e,tj,&ej,ei));
          ti =  e->edg2tri[2*ej+0]==tj ? e->edg2tri[2*ej+1] : e->edg2tri[2*ej+0];
        }while(ei!=ej);

        m->vertices.num += 1;
        if(m->vertices.num > maxVert){
          maxVert *= 2;
          HXT_CHECK(hxtAlignedRealloc(&m->vertices.coord,4*maxVert*sizeof(double)));
        }
        int ni = e->node[2*ei+0], nj = e->node[2*ei+1];

        for(int xj=0; xj<3; xj++)
          m->vertices.coord[4*(m->vertices.num-1)+xj] = ( m->vertices.coord[4*ni+xj] + m->vertices.coord[4*nj+xj] )/2.;

        m->triangles.num +=2;
        if(m->triangles.num > maxTri){
          maxTri *= 2;
          HXT_CHECK(hxtAlignedRealloc(&m->triangles.node,3*maxTri*sizeof(uint32_t)));
          HXT_CHECK(hxtAlignedRealloc(&m->triangles.colors,maxTri*sizeof(uint16_t)));
          HXT_CHECK(hxtRealloc(&e->tri2edg,3*maxTri*sizeof(uint32_t)));
        }
        int tti = m->triangles.num-2, ttj = tti+1;
        int e0 = e->numEdges, e1=e0+1, e2=e1+1;
        for(int ic=0; ic<3; ic++){
          if(m->triangles.node[3*ti+ic]==ni && m->triangles.node[3*ti+(ic+1)%3]==nj){
            m->triangles.node[3*ti+(ic+1)%3] = m->vertices.num-1;

            m->triangles.node[3*tti+0] = m->vertices.num-1;
            m->triangles.node[3*tti+1] = nj;
            m->triangles.node[3*tti+2] = m->triangles.node[3*ti+(ic+2)%3];
            e->tri2edg[3*tti+0] = e0;
            e->tri2edg[3*tti+1] = e->tri2edg[3*ti+(ic+1)%3];
            e->tri2edg[3*tti+2] = e1;

            e->tri2edg[3*ti+(ic+1)%3] = e1;

            uint64_t *t_ = &e->edg2tri[2*e->tri2edg[3*tti+1]];
            if(t_[0]==ti)
              t_[0] = tti;
            else
              t_[1] = tti;

          }
          else if (m->triangles.node[3*ti+ic]==nj && m->triangles.node[3*ti+(ic+1)%3]==ni) {
            m->triangles.node[3*ti+ic] = m->vertices.num-1;

            m->triangles.node[3*tti+0] = nj;
            m->triangles.node[3*tti+1] = m->vertices.num-1;
            m->triangles.node[3*tti+2] = m->triangles.node[3*ti+(ic+2)%3];
            e->tri2edg[3*tti+0] = e0;
            e->tri2edg[3*tti+1] = e1;
            e->tri2edg[3*tti+2] = e->tri2edg[3*ti+(ic+2)%3];

            e->tri2edg[3*ti+(ic+2)%3] = e1;


            uint64_t *t_ = &e->edg2tri[2*e->tri2edg[3*tti+2]];
            if(t_[0]==ti)
              t_[0] = tti;
            else
              t_[1] = tti;

          }
          if(m->triangles.node[3*tj+ic]==nj && m->triangles.node[3*tj+(ic+1)%3]==ni){
            m->triangles.node[3*tj+(ic+1)%3] = m->vertices.num-1;

            m->triangles.node[3*ttj+0] = m->vertices.num-1;
            m->triangles.node[3*ttj+1] = ni;
            m->triangles.node[3*ttj+2] = m->triangles.node[3*tj+(ic+2)%3];
            e->tri2edg[3*ttj+0] = ei;
            e->tri2edg[3*ttj+1] = e->tri2edg[3*tj+(ic+1)%3];
            e->tri2edg[3*ttj+2] = e2;

            e->tri2edg[3*tj+(ic+1)%3] = e2;
            e->tri2edg[3*tj+ic] = e0;

            uint64_t *t_ = &e->edg2tri[2*e->tri2edg[3*ttj+1]];
            if(t_[0]==tj)
              t_[0] = ttj;
            else
              t_[1] = ttj;


          }
          else if (m->triangles.node[3*tj+ic]==ni && m->triangles.node[3*tj+(ic+1)%3]==nj){

            m->triangles.node[3*tj+ic] = m->vertices.num-1;

            m->triangles.node[3*ttj+0] = ni;
            m->triangles.node[3*ttj+1] = m->vertices.num-1;
            m->triangles.node[3*ttj+2] = m->triangles.node[3*tj+(ic+2)%3];
            e->tri2edg[3*ttj+0] = ei;
            e->tri2edg[3*ttj+1] = e2;
            e->tri2edg[3*ttj+2] = e->tri2edg[3*tj+(ic+2)%3];

            e->tri2edg[3*tj+ic] = e0;
            e->tri2edg[3*tj+(ic+2)%3] = e2;

            uint64_t *t_ = &e->edg2tri[2*e->tri2edg[3*ttj+2]];
            if(t_[0]==tj)
              t_[0] = ttj;
            else
              t_[1] = ttj;    

          }
        }//end for      
        e->numEdges +=3;
        if(e->numEdges > maxEdg){
          maxEdg *= 2;
          HXT_CHECK(hxtRealloc(&e->node,2*maxEdg*sizeof(uint32_t)));
          HXT_CHECK(hxtRealloc(&e->color,maxEdg*sizeof(uint16_t)));
          HXT_CHECK(hxtRealloc(&e->edg2tri,2*maxEdg*sizeof(uint64_t)));
        }
        e->node[2*ei+1] = m->vertices.num-1;
        e->edg2tri[2*ei+0] = ti;
        e->edg2tri[2*ei+1] = ttj;       
        e->node[2*e0+0] = m->vertices.num-1;
        e->node[2*e0+1] = nj;
        e->edg2tri[2*e0+0] = tti;
        e->edg2tri[2*e0+1] = tj;
        e->node[2*e1+0] = m->vertices.num-1;
        e->node[2*e1+1] = m->triangles.node[3*tti+2];
        e->edg2tri[2*e1+0] = ti;
        e->edg2tri[2*e1+1] = tti;
        e->node[2*e2+0] = m->vertices.num-1;
        e->node[2*e2+1] = m->triangles.node[3*ttj+2];
        e->edg2tri[2*e2+0] = tj;
        e->edg2tri[2*e2+1] = ttj;


        if (ti < initialNumberOfTriangles)
          flag[ti] = 1;
        if (tj < initialNumberOfTriangles)
          flag[tj] = 1;

      }// end while flag[it]==0
    }//end for it


    /*
    if(threshold>0)
      for(uint64_t it=0; it<m->triangles.num; it++){
        double l;
        HXT_CHECK(hxtDoubleLongestEdge(e,it,&l));
        if(l>2*threshold && nrefinements<10){
          nrefinements++;
          break;
        }
      }
    */

  }//end refinement

 
  

  return HXT_STATUS_OK;
}



static uint64_t hxtLengthKey(uint32_t* edgeID, HXTEdges* edges){
  double l = hxtEdgesLength(edges,*edgeID);
  return double_to_u64(l);
}


HXTStatus hxtEdgeRefinement(HXTEdges *edges,int nrefinements)
{

  double threshold = 0, counter=0;
  for(uint32_t ie=0; ie<edges->numEdges; ie++)
    if(edges->edg2tri[2*ie+1]==(uint64_t)-1){
      threshold+= hxtEdgesLength(edges,ie);
      counter++;
    }
  if (counter>0)
    threshold/=counter;
  else{
    for(uint32_t ie=0; ie<edges->numEdges; ie++)
      threshold+= hxtEdgesLength(edges,ie);
    threshold /= edges->numEdges;
  }
  threshold *= 2;

  
  //bisection of longest edges first; boundary edges are not splitted
  for(int ir=0; ir<nrefinements; ir++){
    HXTEdges *e = edges;
    HXTMesh *m = edges->edg2mesh;



    uint32_t* edgIdx = NULL;
    HXT_CHECK(hxtMalloc(&edgIdx,edges->numEdges*sizeof(uint32_t)));

    for(uint32_t edg=0; edg<edges->numEdges; edg++)
      edgIdx[edg] = edg;

    HXTSORT64_UNIFORM(uint32_t, edgIdx, edges->numEdges, UINT64_MAX, hxtLengthKey, edges);

    
    int maxVert = m->vertices.num;
    int maxTri = m->triangles.num;
    uint32_t initialNumberOfEdges = e->numEdges;
    int  maxEdg = initialNumberOfEdges;
    //splitting from longest edge to smallest one
    //splitted edges were larger than thredshold
    //boundary edges are never splitted
    for(uint32_t edg=initialNumberOfEdges-1; edg>=0; edg--){
      uint32_t ie = edgIdx[edg];
      if(hxtEdgesLength(e,ie)<threshold)
	break;
      if(e->edg2tri[2*ie+1]==(uint64_t)-1)
	continue;
      m->vertices.num += 1;
      if(m->vertices.num > maxVert){
	maxVert *= 2;
	HXT_CHECK(hxtAlignedRealloc(&m->vertices.coord,4*maxVert*sizeof(double)));
      }
      int ni = e->node[2*ie+0], nj = e->node[2*ie+1];
      int ti = (int) e->edg2tri[2*ie+0], tj = (int) e->edg2tri[2*ie+1];
      for(int xj=0; xj<3; xj++)
	m->vertices.coord[4*(m->vertices.num-1)+xj] = ( m->vertices.coord[4*ni+xj] + m->vertices.coord[4*nj+xj] )/2.;

      m->triangles.num +=2;
      if(m->triangles.num > maxTri){
	maxTri *= 2;
	HXT_CHECK(hxtAlignedRealloc(&m->triangles.node,3*maxTri*sizeof(uint32_t)));
	HXT_CHECK(hxtAlignedRealloc(&m->triangles.colors,maxTri*sizeof(uint16_t)));
	HXT_CHECK(hxtRealloc(&e->tri2edg,3*maxTri*sizeof(uint32_t)));
      }
      int tti = m->triangles.num-2, ttj = tti+1;
      int e0 = e->numEdges, e1=e0+1, e2=e1+1;
      for(int ic=0; ic<3; ic++){
	if(m->triangles.node[3*ti+ic]==ni && m->triangles.node[3*ti+(ic+1)%3]==nj){
	  m->triangles.node[3*ti+(ic+1)%3] = m->vertices.num-1;

	  m->triangles.node[3*tti+0] = m->vertices.num-1;
	  m->triangles.node[3*tti+1] = nj;
	  m->triangles.node[3*tti+2] = m->triangles.node[3*ti+(ic+2)%3];
	  e->tri2edg[3*tti+0] = e0;
	  e->tri2edg[3*tti+1] = e->tri2edg[3*ti+(ic+1)%3];
	  e->tri2edg[3*tti+2] = e1;

	  e->tri2edg[3*ti+(ic+1)%3] = e1;

	  uint64_t *t_ = &e->edg2tri[2*e->tri2edg[3*tti+1]];
	  if(t_[0]==ti)
	    t_[0] = tti;
	  else
	    t_[1] = tti;

	}
	else if (m->triangles.node[3*ti+ic]==nj && m->triangles.node[3*ti+(ic+1)%3]==ni) {
	  m->triangles.node[3*ti+ic] = m->vertices.num-1;

	  m->triangles.node[3*tti+0] = nj;
	  m->triangles.node[3*tti+1] = m->vertices.num-1;
	  m->triangles.node[3*tti+2] = m->triangles.node[3*ti+(ic+2)%3];
	  e->tri2edg[3*tti+0] = e0;
	  e->tri2edg[3*tti+1] = e1;
	  e->tri2edg[3*tti+2] = e->tri2edg[3*ti+(ic+2)%3];

	  e->tri2edg[3*ti+(ic+2)%3] = e1;


	  uint64_t *t_ = &e->edg2tri[2*e->tri2edg[3*tti+2]];
	  if(t_[0]==ti)
	    t_[0] = tti;
	  else
	    t_[1] = tti;

	}
	if(m->triangles.node[3*tj+ic]==nj && m->triangles.node[3*tj+(ic+1)%3]==ni){
	  m->triangles.node[3*tj+(ic+1)%3] = m->vertices.num-1;

	  m->triangles.node[3*ttj+0] = m->vertices.num-1;
	  m->triangles.node[3*ttj+1] = ni;
	  m->triangles.node[3*ttj+2] = m->triangles.node[3*tj+(ic+2)%3];
	  e->tri2edg[3*ttj+0] = ie;
	  e->tri2edg[3*ttj+1] = e->tri2edg[3*tj+(ic+1)%3];
	  e->tri2edg[3*ttj+2] = e2;

	  e->tri2edg[3*tj+(ic+1)%3] = e2;
	  e->tri2edg[3*tj+ic] = e0;

	  uint64_t *t_ = &e->edg2tri[2*e->tri2edg[3*ttj+1]];
	  if(t_[0]==tj)
	    t_[0] = ttj;
	  else
	    t_[1] = ttj;


	}
	else if (m->triangles.node[3*tj+ic]==ni && m->triangles.node[3*tj+(ic+1)%3]==nj){

	  m->triangles.node[3*tj+ic] = m->vertices.num-1;

	  m->triangles.node[3*ttj+0] = ni;
	  m->triangles.node[3*ttj+1] = m->vertices.num-1;
	  m->triangles.node[3*ttj+2] = m->triangles.node[3*tj+(ic+2)%3];
	  e->tri2edg[3*ttj+0] = ie;
	  e->tri2edg[3*ttj+1] = e2;
	  e->tri2edg[3*ttj+2] = e->tri2edg[3*tj+(ic+2)%3];

	  e->tri2edg[3*tj+ic] = e0;
	  e->tri2edg[3*tj+(ic+2)%3] = e2;

	  uint64_t *t_ = &e->edg2tri[2*e->tri2edg[3*ttj+2]];
	  if(t_[0]==tj)
	    t_[0] = ttj;
	  else
	    t_[1] = ttj;    

	}
      }//end for      
      e->numEdges +=3;
      if(e->numEdges > maxEdg){
	maxEdg *= 2;
	HXT_CHECK(hxtRealloc(&e->node,2*maxEdg*sizeof(uint32_t)));
	HXT_CHECK(hxtRealloc(&e->color,maxEdg*sizeof(uint16_t)));
	HXT_CHECK(hxtRealloc(&e->edg2tri,2*maxEdg*sizeof(uint64_t)));
      }
      e->node[2*ie+1] = m->vertices.num-1;
      e->edg2tri[2*ie+0] = ti;
      e->edg2tri[2*ie+1] = ttj;       
      e->node[2*e0+0] = m->vertices.num-1;
      e->node[2*e0+1] = nj;
      e->edg2tri[2*e0+0] = tti;
      e->edg2tri[2*e0+1] = tj;
      e->node[2*e1+0] = m->vertices.num-1;
      e->node[2*e1+1] = m->triangles.node[3*tti+2];
      e->edg2tri[2*e1+0] = ti;
      e->edg2tri[2*e1+1] = tti;
      e->node[2*e2+0] = m->vertices.num-1;
      e->node[2*e2+1] = m->triangles.node[3*ttj+2];
      e->edg2tri[2*e2+0] = tj;
      e->edg2tri[2*e2+1] = ttj;


      
      


      
    }//end for ie


    
    for(uint32_t ie=0; ie<e->numEdges; ie++)
      if(hxtEdgesLength(e,ie)>threshold){
	nrefinements++;
	break;
      }
    
  }//end for ir
  printf("nrefinements:\t %d\n",nrefinements);
  return HXT_STATUS_OK;
}


