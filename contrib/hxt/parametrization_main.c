#include "hxt_option.h" // to be used
#include "hxt_parametrization.h"
#include "hxt_linear_system.h"

int main(int argc, char **argv) {

  if (argc < 2)
    return HXT_ERROR_MSG(HXT_STATUS_FAILED,"usage: parametrization input.msh");

  HXT_CHECK(hxtInitializeLinearSystems(&argc, &argv));
  HXTContext *context;
  HXT_CHECK(hxtContextCreate(&context));
  HXTMesh *mesh;
  HXT_CHECK(hxtMeshCreate(context, &mesh));
  HXT_CHECK(hxtMeshReadGmsh(mesh, argv[1]));
  
  printf("%f\n",mesh->vertices[0].coord[1]);

  HXTParametrization *param;
  HXT_CHECK(hxtParametrizationCreate(mesh,&param));
  
  int *colors=NULL, *nNodes=NULL, *nodes=NULL, nc;
  double *uv=NULL;
  HXT_CHECK(hxtParametrizationCompute(param,&colors,&nNodes,&nodes,&uv,&nc));


  /////////

  FILE* file = fopen("checkmyjob.msh","w");
  fprintf(file,"$MeshFormat\n"
               "2.2 0 %u\n"
               "$EndMeshFormat\n"
               "$Nodes\n"
               "%u\n",(unsigned) sizeof(double), mesh->numVertices);
  

  { /* print the nodes */
    uint32_t i;
    for (i=0; i<mesh->numVertices; i++)
      fprintf(file,"%u %f %f %f\n",i+1, mesh->vertices[i].coord[0], mesh->vertices[i].coord[1], mesh->vertices[i].coord[2]);
  }

  fprintf(file,"$EndNodes\n"
	  "$Elements\n"
	  "%lu\n",mesh->triangles.num);

  for (uint64_t i=0; i<mesh->triangles.num; i++){
    fprintf(file,"%lu 2 2 0 %d %u %u %u \n",i,
              colors[i],
              mesh->triangles.node[i*3]+1,
              mesh->triangles.node[i*3 + 1]+1,
              mesh->triangles.node[i*3 + 2]+1);
  }


  fputs("$EndElements\n",file);
  fclose(file);

  for(int c=0; c<nc; c++){
    
    char uname[32], vname[32];
    sprintf(uname,"nodedata_u_%d.msh",c);
    sprintf(vname,"nodedata_v_%d.msh",c);

    FILE  *uf = fopen(uname,"w");
    FILE  *vf = fopen(vname,"w");    
        
    fprintf(uf,"$MeshFormat\n2.2 0 8\n$EndMeshFormat\n$NodeData\n1\n\"u\"\n1\n0\n3\n0\n1\n%u\n",nNodes[c+1]-nNodes[c]);
    fprintf(vf,"$MeshFormat\n2.2 0 8\n$EndMeshFormat\n$NodeData\n1\n\"v\"\n1\n0\n3\n0\n1\n%u\n",nNodes[c+1]-nNodes[c]);
	

    
    for(int i=nNodes[c]; i<nNodes[c+1]; i++){
      fprintf(uf,"%u %f\n",nodes[i]+1,uv[2*i+0]);
      fprintf(vf,"%u %f\n",nodes[i]+1,uv[2*i+1]);
    }
      

    fprintf(uf,"$EndNodeData");
    fprintf(vf,"$EndNodeData");
    
    fclose(uf);
    fclose(vf);
  }

  
}
