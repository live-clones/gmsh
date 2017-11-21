#include <stdio.h>
#include "gmshc.h"

#define chk(ierr) if (ierr != 0) {fprintf(stderr, "ERROR on line %i in function '%s': gmsh function return non-zero error code: %i\n",__LINE__, __FUNCTION__,ierr); gmshcFinalize(NULL); exit(ierr);}

void genGeometry() {
  int ierr;
  gmshcModelCreate("square",&ierr);chk(ierr);
  gmshcModelGeoAddPoint(0,0,0,0.1,1,&ierr);chk(ierr);
  gmshcModelGeoAddPoint(1,0,0,0.1,2,&ierr);chk(ierr);
  gmshcModelGeoAddPoint(1,1,0,0.1,3,&ierr);chk(ierr);
  gmshcModelGeoAddPoint(0,1,0,0.1,4,&ierr);chk(ierr);
  gmshcModelGeoAddLine(1,2,1,&ierr); chk(ierr);
  gmshcModelGeoAddLine(2,3,2,&ierr); chk(ierr);
  gmshcModelGeoAddLine(3,4,3,&ierr); chk(ierr);
  // try automatic assignement of tag
  int line4 = gmshcModelGeoAddLine(4,1,-1,&ierr); chk(ierr);
  printf("line4 received tag %i\n\n", line4);
  int ll[] = {1,2,3,line4};
  gmshcModelGeoAddLineLoop(ll,4,1,&ierr); chk(ierr);
  int s[] = {1};
  gmshcModelGeoAddPlaneSurface(ll,1,6,&ierr); chk(ierr);
  gmshcModelGeoSynchronize(&ierr); chk(ierr);
}

void printMesh() {
  int ierr;
  int *dimTags;
  size_t ndimTags;

  gmshcModelGetEntities(&dimTags, &ndimTags, -1,&ierr); chk(ierr);

  for (size_t ie = 0; ie < ndimTags/2; ++ie) {
    int *types, **elementTags, **vertexTags;
    size_t ntypes, *nelementTags, nnelementTags, *nvertexTags, nnvertexTags;

    gmshcModelGetMeshElements(dimTags[ie*2+0], dimTags[ie*2+1], &types, &ntypes, &elementTags, &nelementTags, &nnelementTags, &vertexTags, &nvertexTags, &nnvertexTags,&ierr); chk(ierr);

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
  gmshcModelGetMeshElements(999, 999, NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&ierr); chk(ierr);
}

int main(int argc, char **argv) {
  int ierr;
  gmshcInitialize(argc, argv);
  genGeometry();
  gmshcModelMesh(2,&ierr); chk(ierr);
  gmshcExport("square.msh",&ierr); chk(ierr);
  printMesh();
  genError();
  gmshcFinalize(&ierr); chk(ierr);
}
