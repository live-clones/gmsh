#include <QApplication>

#include <gmsh/Gmsh.h>

#include "window.h"

int main(int argc, char *argv[])
{
  GmshInitialize(argc, argv);
  GmshSetOption("General", "Terminal", 1.);
  for(int i = 1; i < argc; i++) GmshMergeFile(argv[i]);

  QApplication app(argc, argv);
  Window window;
  window.show();
  return app.exec();
}
