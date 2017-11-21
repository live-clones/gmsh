#include <stdio.h>
#include "gmshc.h"

#define chk(ierr) if (ierr != 0) {fprintf(stderr, "ERROR on line %i in function '%s': gmsh function return non-zero error code: %i\n",__LINE__, __FUNCTION__,ierr); gmshcFinalize(); exit(ierr);}

void genGeometry() {
  int ierr;
  ierr = gmshcModelCreate("square");
  ierr = gmshcModelGeoAddPoint(0,0,0,0.1,1,NULL);chk(ierr);
  ierr = gmshcModelGeoAddPoint(1,0,0,0.1,2,NULL);chk(ierr);
  ierr = gmshcModelGeoAddPoint(1,1,0,0.1,3,NULL);chk(ierr);
  ierr = gmshcModelGeoAddPoint(0,1,0,0.1,4,NULL);chk(ierr);
  ierr = gmshcModelGeoAddLine(1,2,1,NULL); chk(ierr);
  ierr = gmshcModelGeoAddLine(2,3,2,NULL); chk(ierr);
  ierr = gmshcModelGeoAddLine(3,4,3,NULL); chk(ierr);
  // try automatic assignement of tag
  int line4;
  ierr = gmshcModelGeoAddLine(4,1,-1,&line4); chk(ierr);
  printf("line4 received tag %i\n\n", line4);
  int ll[] = {1,2,3,line4};
  ierr = gmshcModelGeoAddLineLoop(ll,4,1,NULL); chk(ierr);
  int s[] = {1};
  ierr = gmshcModelGeoAddPlaneSurface(ll,1,6,NULL); chk(ierr);
  ierr = gmshcModelGeoSynchronize(); chk(ierr);
}

void printMesh() {
  int ierr;
  int *dimTags;
  size_t ndimTags;

  ierr = gmshcModelGetEntities(&dimTags, &ndimTags, -1); chk(ierr);

  for (size_t ie = 0; ie < ndimTags/2; ++ie) {
    int *types, **elementTags, **vertexTags;
    size_t ntypes, *nelementTags, nnelementTags, *nvertexTags, nnvertexTags;

    ierr = gmshcModelGetMeshElements(dimTags[ie*2+0], dimTags[ie*2+1], &types, &ntypes, &elementTags, &nelementTags, &nnelementTags, &vertexTags, &nvertexTags, &nnvertexTags); chk(ierr);

    printf("entity %i of dim %i\n", dimTags[ie*2+1], dimTags[ie*2+0]);
    for (size_t i = 0; i < nnelementTags; ++i) {
      printf("  %lu elements of type %i : ", nelementTags[i], types[i]);
      size_t nnodesbyel = nvertexTags[i]/nelementTags[i];
      for (size_t j = 0; j < nelementTags[i] && j < 3; ++j) {
        printf("%i ( ", elementTags[i][j]);
        for (size_t k = 0; k < nnodesbyel; ++k)
          printf("%i ", vertexTags[i][j*nnodesbyel+k]);
        printf(") ");
      }
      if (nelementTags[i] > 3)
        printf("...");
      printf("\n");
    }

    free(types);
    for (size_t i = 0; i < nnelementTags; ++i)
      free(elementTags[i]);
    for (size_t i = 0; i < nnvertexTags; ++i)
      free(vertexTags[i]);
    free(nelementTags);
    free(nvertexTags);
  }
  free(dimTags);
}

void genError() {
  int ierr;
  printf("\n** generate an error **\n");
  ierr = gmshcModelGetMeshElements(999, 999, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL); chk(ierr);
}

int main(int argc, char **argv) {
  int ierr;
  gmshcInitialize(argc, argv);
  genGeometry();
  ierr = gmshcModelMesh(2); chk(ierr);
  ierr = gmshcExport("square.msh"); chk(ierr);
  printMesh();
  genError();
  ierr = gmshcFinalize(); chk(ierr);
}
