#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  int i, pid;
  FILE *fp;
  char str[32];

  for(i = 0; i < 5; i++){
    system("gmsh -pid fichier.msh fichier.pos > /tmp/gmsh.pid &");

    printf("computing %d...\n", i);
    sleep(2);

    fp = fopen("/tmp/gmsh.pid", "r");
    fscanf(fp, "%d", &pid);
    sprintf(str, "kill %d", pid);
    system(str);
  }    
} 
