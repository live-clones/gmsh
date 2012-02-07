 /**
 * Project : Java Wrapping of Gmsh
 * Copyright : see Gmsh Copyright
 * License : see Gmsh License
 * Contrat number : internal Artenum development 
 * Developed by: Artenum SARL
 * Creation : august 2011
 * authors : Benjamin JEANTY-RUARD - Artenum
 * Status : final
 */




package com.artenum.sample;

import org.geuz.gmsh.generated.GModel;
import org.geuz.gmsh.generated.WrapGmsh;

/**
 * This class is an example of use of Gmsh wrapping in Java.
 * 
 * @author benjamin jeanty-ruard
 * 
 */
public class EssaiGmsh_v2 {
    
    static {
        try {
            System.loadLibrary("WrapGmsh");
        } catch (final UnsatisfiedLinkError e) {
            System.err
                    .println("Native code library failed to load. See the chapter on Dynamic Linking Problems in the SWIG Java documentation for help.\n" + e);
            System.exit(1);
        }
        
    }
    
    public static void main(final String[] args) {
        
        // initialization of gmsh
        WrapGmsh.GmshInitialize(0, null);
        
        final GModel m1 = new GModel();
        
        // import information contained in .geo file inside GModel m1
        GModel.readGEO("t5.geo");
        
        // mesh the geometry defined in the GModel m
        m1.mesh(3);
        
        // write .msh file which contains informations about mesh in GModel m.
        m1.writeMSH("t5.msh");
        
        WrapGmsh.GmshFinalize();
        
    }
    
}
