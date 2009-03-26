#ifndef behaviorCXX
#define behaviorCXX

#include "tetgen.h"

static REAL PI = 3.14159265358979323846264338327950288419716939937510582;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// tetgenbehavior()    Initialize veriables of 'tetgenbehavior'.             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

tetgenbehavior::tetgenbehavior()
{
  // Initialize command line switches.
  plc = 0;
  quality = 0;
  refine = 0;
  coarse = 0;
  metric = 0;
  minratio = 2.0;
  goodratio = 0.0;
  minangle = 20.0;
  goodangle = 0.0;
  maxdihedral = 165.0;
  mindihedral = 5.0;
  varvolume = 0;
  fixedvolume = 0;
  maxvolume = -1.0;
  regionattrib = 0;
  bowyerwatson = 1;
  convexity = 0;
  insertaddpoints = 0;
  diagnose = 0;
  conformdel = 0;
  zeroindex = 0;
  facesout = 0;
  edgesout = 0;
  neighout = 0;
  voroout = 0;
  meditview = 0;
  gidview = 0;
  geomview = 0;
  order = 1;
  nojettison = 0;
  nobound = 0;
  nonodewritten = 0;
  noelewritten = 0;
  nofacewritten = 0;
  noiterationnum = 0;
  nobisect = 0;
  steiner = -1;
  nomerge = 0;
  docheck = 0;
  quiet = 0;
  verbose = 0;
  useshelles = 0;
  epsilon = 1.0e-8;
  object = NONE;
  // Initialize strings
  commandline[0] = '\0';
  infilename[0] = '\0';
  outfilename[0] = '\0';
  addinfilename[0] = '\0';
  bgmeshfilename[0] = '\0';
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// versioninfo()    Print the version information of TetGen.                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenbehavior::versioninfo()
{
  printf("Develop Version (Started on August 9, 2008).\n");
  printf("\n");
  printf("Copyright (C) 2002 - 2008\n");
  printf("Hang Si\n");
  printf("Mohrenstr. 39, 10117 Berlin, Germany\n");
  printf("si@wias-berlin.de\n");
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// syntax()    Print list of command line switches and exit the program.     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenbehavior::syntax()
{
  printf("  tetgen [-prq_Ra_AiMYS_T_dzo_fenvgGOJBNEFICQVh] input_file\n");
  printf("    -p  Tetrahedralizes a piecewise linear complex (PLC).\n");
  printf("    -r  Reconstructs a previously generated mesh.\n");
  printf("    -q  Quality mesh generation (adding new mesh points to ");
  printf("improve mesh quality).\n");
  printf("    -R  Mesh coarsening (deleting redundant mesh points).\n");
  printf("    -a  Applies a maximum tetrahedron volume constraint.\n");
  printf("    -A  Assigns attributes to identify tetrahedra in different ");
  printf("regions.\n");
  printf("    -i  Inserts a list of additional points into mesh.\n");
  printf("    -M  Does not merge coplanar facets.\n");
  printf("    -Y  Suppresses boundary facets/segments splitting.\n");
  printf("    -S  Specifies maximum number of added points.\n");
  printf("    -T  Sets a tolerance for coplanar test (default 1e-8).\n");
  printf("    -d  Detects self-intersections of facets of the PLC.\n");
  printf("    -z  Numbers all output items starting from zero.\n");
  printf("    -o2 Generates second-order subparametric elements.\n");
  printf("    -f  Outputs all faces to .face file.");
  printf("file.\n");
  printf("    -e  Outputs all edges to .edge file.\n");
  printf("    -n  Outputs tetrahedra neighbors to .neigh file.\n");
  printf("    -v  Outputs Voronoi diagram to files.\n");
  printf("    -g  Outputs mesh to .mesh file for viewing by Medit.\n");
  printf("    -G  Outputs mesh to .msh file for viewing by Gid.\n");
  printf("    -O  Outputs mesh to .off file for viewing by Geomview.\n");
  printf("    -J  No jettison of unused vertices from output .node file.\n");
  printf("    -B  Suppresses output of boundary information.\n");
  printf("    -N  Suppresses output of .node file.\n");
  printf("    -E  Suppresses output of .ele file.\n");
  printf("    -F  Suppresses output of .face file.\n");
  printf("    -I  Suppresses mesh iteration numbers.\n");
  printf("    -C  Checks the consistency of the final mesh.\n");
  printf("    -Q  Quiet:  No terminal output except errors.\n");
  printf("    -V  Verbose:  Detailed information, more terminal output.\n");
  printf("    -h  Help:  A brief instruction for using TetGen.\n");
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// usage()    Print a brief instruction for using TetGen.                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

void tetgenbehavior::usage()
{
  printf("TetGen\n");
  printf("A Quality Tetrahedral Mesh Generator and 3D Delaunay ");
  printf("Triangulator\n");
  versioninfo();
  printf("\n");
  printf("What Can TetGen Do?\n");
  printf("\n");
  printf("  TetGen generates exact Delaunay tetrahedralizations, exact\n");
  printf("  constrained Delaunay tetrahedralizations, and quality ");
  printf("tetrahedral\n  meshes. The latter are nicely graded and whose ");
  printf("tetrahedra have\n  radius-edge ratio bounded, thus are suitable ");
  printf("for finite element and\n  finite volume analysis.\n"); 
  printf("\n");
  printf("Command Line Syntax:\n");
  printf("\n");
  printf("  Below is the command line syntax of TetGen with a list of ");
  printf("short\n");
  printf("  descriptions. Underscores indicate that numbers may optionally\n");
  printf("  follow certain switches.  Do not leave any space between a ");
  printf("switch\n");
  printf("  and its numeric parameter.  \'input_file\' contains input data\n");
  printf("  depending on the switches you supplied which may be a ");
  printf("  piecewise\n");
  printf("  linear complex or a list of nodes.  File formats and detailed\n");
  printf("  description of command line switches are found in user's ");
  printf("manual.\n");
  printf("\n");
  syntax();
  printf("\n");
  printf("Examples of How to Use TetGen:\n");
  printf("\n");
  printf("  \'tetgen object\' reads vertices from object.node, and writes ");
  printf("their\n  Delaunay tetrahedralization to object.1.node and ");
  printf("object.1.ele.\n");
  printf("\n");
  printf("  \'tetgen -p object\' reads a PLC from object.poly or object.");
  printf("smesh (and\n  possibly object.node) and writes its constrained ");
  printf("Delaunay\n  tetrahedralization to object.1.node, object.1.ele and ");
  printf("object.1.face.\n");
  printf("\n");
  printf("  \'tetgen -pq1.414a.1 object\' reads a PLC from object.poly or\n");
  printf("  object.smesh (and possibly object.node), generates a mesh ");
  printf("whose\n  tetrahedra have radius-edge ratio smaller than 1.414 and ");
  printf("have volume\n  of 0.1 or less, and writes the mesh to ");
  printf("object.1.node, object.1.ele\n  and object.1.face.\n");
  printf("\n");
  printf("Please send bugs/comments to Hang Si <si@wias-berlin.de>\n");
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// parse_commandline()    Read the command line, identify switches, and set  //
//                        up options and file names.                         //
//                                                                           //
// 'argc' and 'argv' are the same parameters passed to the function main()   //
// of a C/C++ program. They together represent the command line user invoked //
// from an environment in which TetGen is running.                           //
//                                                                           //
// When TetGen is invoked from an environment. 'argc' is nonzero, switches   //
// and input filename should be supplied as zero-terminated strings in       //
// argv[0] through argv[argc - 1] and argv[0] shall be the name used to      //
// invoke TetGen, i.e. "tetgen".  Switches are previously started with a     //
// dash '-' to identify them from the input filename.                        //
//                                                                           //
// When TetGen is called from within another program. 'argc' is set to zero. //
// switches are given in one zero-terminated string (no previous dash is     //
// required.), and 'argv' is a pointer points to this string.  No input      //
// filename is required (usually the input data has been directly created by //
// user in the 'tetgenio' structure).  A default filename 'tetgen-tmpfile'   //
// will be created for debugging output purpose.                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

bool tetgenbehavior::parse_commandline(int argc, char **argv)
{
  int startindex;
  int increment;
  int meshnumber;
  int scount;
  int i, j, k;
  char workstring[1024];

  // First determine the input style of the switches.
  if (argc == 0) {
    startindex = 0;                    // Switches are given without a dash.
    argc = 1;                    // For running the following for-loop once.
    commandline[0] = '\0';
  } else {
    startindex = 1;
    strcpy(commandline, argv[0]);
    strcat(commandline, " ");
  }
  
  // Rcount used to count the number of '-R' be used.
  scount = 0;

  for (i = startindex; i < argc; i++) {
    // Remember the command line switches.
    strcat(commandline, argv[i]);
    strcat(commandline, " ");
    if (startindex == 1) {
      // Is this string a filename?
      if (argv[i][0] != '-') {
        strncpy(infilename, argv[i], 1024 - 1);
        infilename[1024 - 1] = '\0';
        // Go to the next string directly.
        continue;                     
      }
    }
    // Parse the individual switch from the string.
    for (j = startindex; argv[i][j] != '\0'; j++) {
      if (argv[i][j] == 'p') {
        plc = 1;
      } else if (argv[i][j] == 'r') {
        refine = 1;
      } else if (argv[i][j] == 'R') {
        coarse = 1;
      } else if (argv[i][j] == 'q') {
        quality++;
        if (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
            (argv[i][j + 1] == '.')) {
          k = 0;
          while (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
                 (argv[i][j + 1] == '.')) {
            j++;
            workstring[k] = argv[i][j];
            k++;
          }
          workstring[k] = '\0';
          if (quality == 1) {
            minratio = (REAL) strtod(workstring, (char **) NULL);
          } else if (quality == 2) {
            mindihedral = (REAL) strtod(workstring, (char **) NULL);
          } else if (quality == 3) {
            maxdihedral = (REAL) strtod(workstring, (char **) NULL);
          }
        }
      } else if (argv[i][j] == 'm') {
        metric++;
      } else if (argv[i][j] == 'a') {
        if (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
            (argv[i][j + 1] == '.')) {
          fixedvolume = 1;
          k = 0;
          while (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
                 (argv[i][j + 1] == '.') || (argv[i][j + 1] == 'e') ||
                 (argv[i][j + 1] == '-') || (argv[i][j + 1] == '+')) {
            j++;
            workstring[k] = argv[i][j];
            k++;
          }
          workstring[k] = '\0';
          maxvolume = (REAL) strtod(workstring, (char **) NULL);
        } else {
          varvolume = 1;
        }
      } else if (argv[i][j] == 'A') {
        regionattrib++;
      } else if (argv[i][j] == 'b') {
        bowyerwatson = 0;
      } else if (argv[i][j] == 'c') {
        convexity++;
      } else if (argv[i][j] == 'i') {
        insertaddpoints = 1;
      } else if (argv[i][j] == 'd') {
        diagnose = 1;
      } else if (argv[i][j] == 'z') {
        zeroindex = 1;
      } else if (argv[i][j] == 'f') {
        facesout = 1;
      } else if (argv[i][j] == 'e') {
        edgesout++;
      } else if (argv[i][j] == 'n') {
        neighout++;
      } else if (argv[i][j] == 'v') {
        voroout = 1;
      } else if (argv[i][j] == 'g') {
        meditview = 1;
      } else if (argv[i][j] == 'G') {
        gidview = 1;
      } else if (argv[i][j] == 'O') {
        geomview = 1;
      } else if (argv[i][j] == 'M') {
        nomerge = 1;
      } else if (argv[i][j] == 'Y') {
        nobisect++;
      } else if (argv[i][j] == 'J') {
        nojettison = 1;
      } else if (argv[i][j] == 'B') {
        nobound = 1;
      } else if (argv[i][j] == 'N') {
        nonodewritten = 1;
      } else if (argv[i][j] == 'E') {
        noelewritten = 1;
        if (argv[i][j + 1] == '2') {
          j++;
          noelewritten = 2;
        }
      } else if (argv[i][j] == 'F') {
        nofacewritten = 1;
      } else if (argv[i][j] == 'I') {
        noiterationnum = 1;
      } else if (argv[i][j] == 'o') {
        if ((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) {
          k = 0;
          while ((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) {
            j++;
            workstring[k] = argv[i][j];
            k++;
          }
          workstring[k] = '\0';
          order = (int) strtol(workstring, (char **) NULL, 0);
        }
      } else if (argv[i][j] == 'S') {
        if (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
            (argv[i][j + 1] == '.')) {
          k = 0;
          while (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
                 (argv[i][j + 1] == '.') || (argv[i][j + 1] == 'e') ||
                 (argv[i][j + 1] == '-') || (argv[i][j + 1] == '+')) {
            j++;
            workstring[k] = argv[i][j];
            k++;
          }
          workstring[k] = '\0';
          steiner = (int) strtol(workstring, (char **) NULL, 0);
        } 
      } else if (argv[i][j] == 'D') {
        conformdel++;
      } else if (argv[i][j] == 'T') {
        if (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
            (argv[i][j + 1] == '.')) {
          k = 0;
          while (((argv[i][j + 1] >= '0') && (argv[i][j + 1] <= '9')) ||
                 (argv[i][j + 1] == '.') || (argv[i][j + 1] == 'e') ||
                 (argv[i][j + 1] == '-') || (argv[i][j + 1] == '+')) {
            j++;
            workstring[k] = argv[i][j];
            k++;
          }
          workstring[k] = '\0';
          epsilon = (REAL) strtod(workstring, (char **) NULL);
        } 
      } else if (argv[i][j] == 'C') {
        docheck++;
      } else if (argv[i][j] == 'Q') {
        quiet = 1;
      } else if (argv[i][j] == 'V') {
        verbose++;
      // } else if (argv[i][j] == 'v') {
        // versioninfo();
        // terminatetetgen(0);
      } else if ((argv[i][j] == 'h') || (argv[i][j] == 'H') ||
                 (argv[i][j] == '?')) {
        usage();
        terminatetetgen(0);
      } else {
        printf("Warning:  Unknown switch -%c.\n", argv[i][j]);
      }
    }
  }

  if (startindex == 0) {
    // Set a temporary filename for debugging output.
    strcpy(infilename, "tetgen-tmpfile");
  } else {
    if (infilename[0] == '\0') {
      // No input file name. Print the syntax and exit.
      syntax();
      terminatetetgen(0);
    }
    // Recognize the object from file extension if it is available.
    if (!strcmp(&infilename[strlen(infilename) - 5], ".node")) {
      infilename[strlen(infilename) - 5] = '\0';
      object = NODES;
    } else if (!strcmp(&infilename[strlen(infilename) - 5], ".poly")) {
      infilename[strlen(infilename) - 5] = '\0';
      object = POLY;
      plc = 1;
    } else if (!strcmp(&infilename[strlen(infilename) - 6], ".smesh")) {
      infilename[strlen(infilename) - 6] = '\0';
      object = POLY;
      plc = 1;
    } else if (!strcmp(&infilename[strlen(infilename) - 4], ".off")) {
      infilename[strlen(infilename) - 4] = '\0';
      object = OFF;
      plc = 1;
    } else if (!strcmp(&infilename[strlen(infilename) - 4], ".ply")) {
      infilename[strlen(infilename) - 4] = '\0';
      object = PLY;
      plc = 1;
    } else if (!strcmp(&infilename[strlen(infilename) - 4], ".stl")) {
      infilename[strlen(infilename) - 4] = '\0';
      object = STL;
      plc = 1;
    } else if (!strcmp(&infilename[strlen(infilename) - 5], ".mesh")) {
      infilename[strlen(infilename) - 5] = '\0';
      object = MEDIT;
      plc = 1;
    } else if (!strcmp(&infilename[strlen(infilename) - 4], ".vtk")) {
      infilename[strlen(infilename) - 4] = '\0';
      object = VTK;
      plc = 1;
    } else if (!strcmp(&infilename[strlen(infilename) - 4], ".ele")) {
      infilename[strlen(infilename) - 4] = '\0';
      object = MESH;
      refine = 1;
    }
  }
  plc = plc || diagnose;
  useshelles = plc || refine || coarse || quality;
  goodratio = minratio;
  goodratio *= goodratio;

  // Detect improper combinations of switches.
  if (plc && refine) {
    printf("Error:  Switch -r cannot use together with -p.\n");
    return false;
  }
  if (refine && (plc || noiterationnum)) {
    printf("Error:  Switches %s cannot use together with -r.\n",
           "-p, -d, and -I");
    return false;
  }
  if (diagnose && (quality || insertaddpoints || (order == 2) || neighout
      || docheck)) {
    printf("Error:  Switches %s cannot use together with -d.\n",
           "-q, -i, -o2, -n, and -C");
    return false;
  }

  // Be careful not to allocate space for element area constraints that 
  //   will never be assigned any value (other than the default -1.0).
  if (!refine && !plc) {
    varvolume = 0;
  }
  // Be careful not to add an extra attribute to each element unless the
  //   input supports it (PLC in, but not refining a preexisting mesh).
  if (refine || !plc) {
    regionattrib = 0;
  }
  // If '-a' or '-aa' is in use, enable '-q' option too.
  if (fixedvolume || varvolume) {
    if (quality == 0) {
      quality = 1;
    }
  }
  // Calculate the goodangle for testing bad subfaces.
  goodangle = cos(minangle * PI / 180.0);
  goodangle *= goodangle;

  increment = 0;
  strcpy(workstring, infilename);
  j = 1;
  while (workstring[j] != '\0') {
    if ((workstring[j] == '.') && (workstring[j + 1] != '\0')) {
      increment = j + 1;
    }
    j++;
  }
  meshnumber = 0;
  if (increment > 0) {
    j = increment;
    do {
      if ((workstring[j] >= '0') && (workstring[j] <= '9')) {
        meshnumber = meshnumber * 10 + (int) (workstring[j] - '0');
      } else {
        increment = 0;
      }
      j++;
    } while (workstring[j] != '\0');
  }
  if (noiterationnum) {
    strcpy(outfilename, infilename);
  } else if (increment == 0) {
    strcpy(outfilename, infilename);
    strcat(outfilename, ".1");
  } else {
    workstring[increment] = '%';
    workstring[increment + 1] = 'd';
    workstring[increment + 2] = '\0';
    sprintf(outfilename, workstring, meshnumber + 1);
  }
  // Additional input file name has the end ".a".
  strcpy(addinfilename, infilename);
  strcat(addinfilename, ".a");
  // Background filename has the form "*.b.ele", "*.b.node", ...
  strcpy(bgmeshfilename, infilename);
  strcat(bgmeshfilename, ".b");

  return true;
}

#endif // ifndef behaviorCXX
