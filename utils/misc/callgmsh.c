#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main(void)
{
  int i, pid;
  FILE *fp;

  for(i = 0; i < 5; i++){
    system("gmsh -pid fichier.msh fichier.pos > /tmp/gmsh.pid &");

    printf("computing %d...\n", i);
    sleep(2);

    fp = fopen("/tmp/gmsh.pid", "r");
    fscanf(fp, "%d", &pid);
    fclose(fp);

    kill(pid, 9);
  }    
} 
