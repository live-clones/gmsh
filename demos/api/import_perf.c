#include <gmshc.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double tag(int N, int i, int j)
{
  return (N + 1) * i + j + 1;
};

int main()
{
  int ierr = 0;
  gmshInitialize(0, NULL, 0, &ierr);

  int N = 2500;

  double tic = gmshLoggerGetWallTime(&ierr);
  // x, y, z coordinates of all the nodes
  double *coords = malloc((N + 1) * (N + 1) * 3 * sizeof(double));
  // tags of corresponding nodes
  size_t *nodes = malloc((N + 1) * (N + 1) * sizeof(size_t));
  // connectivities (node tags) of triangle elements
  size_t *tris = malloc(N * N * 2 * 3 * sizeof(size_t));

  int k = 0, l = 0;
  for(int i = 0; i < N + 1; i++) {
    for(int j = 0; j < N + 1; j++) {
      nodes[k] = tag(N, i, j);
      coords[3 * k] = (double)i / N;
      coords[3 * k + 1] = (double)j / N;
      coords[3 * k + 2] = 0.05 * sin(10 * (double)(i + j) / N);
      k++;
      if(i > 0 && j > 0) {
        tris[6 * l] = tag(N, i - 1, j - 1);
        tris[6 * l + 1] = tag(N, i, j - 1);
        tris[6 * l + 2] = tag(N, i - 1, j);
        tris[6 * l + 3] = tag(N, i, j - 1);
        tris[6 * l + 4] = tag(N, i, j);
        tris[6 * l + 5] = tag(N, i - 1, j);
        l++;
      }
    }
  }

  double toc = gmshLoggerGetWallTime(&ierr);
  printf("==> created nodes and connectivities in %g seconds\n", toc - tic);

  tic = gmshLoggerGetWallTime(&ierr);
  int surf = gmshModelAddDiscreteEntity(2, -1, NULL, 0, &ierr);
  toc = gmshLoggerGetWallTime(&ierr);
  printf("==> created surface in %g seconds\n", toc - tic);

  tic = gmshLoggerGetWallTime(&ierr);
  gmshModelMeshAddNodes(2, 1, nodes, (N + 1) * (N + 1),
                        coords, (N + 1) * (N + 1) * 3, NULL, 0, &ierr);
  toc = gmshLoggerGetWallTime(&ierr);
  printf("==> imported nodes in %g seconds\n", toc - tic);

  tic = gmshLoggerGetWallTime(&ierr);
  gmshModelMeshAddElementsByType(1, 2, NULL, 0, tris, N * N * 2 * 3, &ierr);
  toc = gmshLoggerGetWallTime(&ierr);
  printf("==> imported elements in %g seconds\n", toc - tic);

  tic = gmshLoggerGetWallTime(&ierr);
  gmshOptionSetNumber("Mesh.Binary", 1, &ierr);
  gmshWrite("import_perf.msh", &ierr);
  toc = gmshLoggerGetWallTime(&ierr);
  printf("==> wrote to disk in %g seconds\n", toc - tic);

  tic = gmshLoggerGetWallTime(&ierr);
  gmshMerge("import_perf.msh", &ierr);
  toc = gmshLoggerGetWallTime(&ierr);
  printf("==> read from disk in %g seconds\n", toc - tic);

  //gmshFltkRun(&ierr);

  gmshFinalize(&ierr);
  return 0;
}
