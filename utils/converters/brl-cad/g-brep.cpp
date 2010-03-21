/*
    (C) 2009 Mark van Doesburg, Technolution B.V.

    Distributed under GPL version 2

    Use this program to translate a BRL-CAD file to a brep file which
    can be read using OpenCASCADE.

    format: g-brep {filename} {model} [model] ...

 */

#include "BRLFile.h"
#include <string>

main(int argc, char **argv)
{
    if(argc<3) {
        cerr << "Filename and object name(s) required\n";
        return 1;
    }
    BRLFile solid(argv[1],BRLFile::Cutting|BRLFile::BRL);
    int connect=1;
    for(int i=2; i<argc; i++) {
        if(argv[i][0]=='-') {
            switch(argv[i][1]) {
            case 'c': connect=0; break;
            default:
                cerr << "Unknown option :" << argv[i] << "\n";
                return 1;
            }
        } else if(solid.AddModel(argv[i])) {
            cerr << "Cannot find model " << argv[i] << '\n';
            return 1;
        }
    }
    if(connect)
        solid.Connect(); 
    else
        solid.Collect();

    std::string newname=argv[1];
    int start=newname.find(".g");
    if(start==std::string::npos) {
        newname+=".brep";
        std::cerr << "Cannot find the .g extension, writing to: "
            << newname << std::endl;
    } else
        newname.replace(start,newname.length(),".brep");
    solid.SaveBRep(newname.c_str());
    //solid.Dump(cout);
}
