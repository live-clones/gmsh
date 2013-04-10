// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// Contributed by Gilles Marckmann <gilles.marckmann@ec-nantes.fr>


#if defined(WIN32) || defined(__APPLE__)


   #include <cstring>
   #include <string>
   #include <iostream>
   #include <stdio.h>
   #include "GamePad.h"

   GamePad::GamePad() : active(false), frequency(.01), gamepad_fd(0) {
     for (int i=0;i<9;i++) button_map[i]=i;
     for (int i=0;i<7;i++)    axe_map[i]=i;
     axe_map[6]=1;
     //  other recognized map "Thrustmaster Run'N' Drive Wireless PS3"
     if ( strcmp(name,"Thrustmaster Run'N' Drive Wireless PS3" ) == 0){
       button_map[0]=1;
       button_map[1]=0;
       button_map[5]=6;
       button_map[6]=5;
     }
   }

   GamePad::~GamePad() {  gamepad_fd = 0;}

   bool GamePad::toggle(const int _nbut) {
     bool res;
     if( toggle_status[_nbut] ){ res = true; toggle_status[_nbut]=false;}
     else { res=false;  }
     return res;
   }

   int GamePad::read_event() {  return 1;}

   void GamePad::affiche() {}




#else // if !win32 => if linux/apple

   #include <cstring>
   #include <string>
   #include <iostream>
   #include <stdio.h>
   #include "GamePad.h"
   #include "Context.h"
   #include <unistd.h>

   GamePad::GamePad() : active(false), frequency(.01), gamepad_fd(0) {
     gamepad_fd = open(GAMEPAD_DEV, O_RDONLY | O_NONBLOCK);
     if (gamepad_fd > 0) {
       ioctl(gamepad_fd, JSIOCGNAME(256), name);
       ioctl(gamepad_fd, JSIOCGVERSION, &version);
       ioctl(gamepad_fd, JSIOCGAXES, &axes);
       ioctl(gamepad_fd, JSIOCGBUTTONS, &buttons);
       std::cout << "Joystick/Gamepad detected: " <<  name ;
       std::cout << " (version " << version  << " / " ;
       std::cout << (int)axes <<" axes /" ;
       std::cout << (int)buttons <<" buttons)" << std::endl;
       active = true;
     }

     //    default map is "THRUSTMASTER FireStorm Dual Power"-like
     //
     //                    ######                                   ######
     //                   # but5 #                                 # but7 #
     //                 .########..                               ..#######.
     //                ............                               .......... .
     //               ...#######...                              ...########..
     //               ..# but4 #...                              ...# but6  #..
     //              ...########....... but9           but10........#########..
     //              ....................                 .....................
     //            .......#...................        ..........................
     //           ......axis5..........................................####.......
     //          ........ #...........................................# b3 #.......
     //         ..........#...........................................#    #.......
     //         ...###< axis4 >###...............................####..####..####...
     //        ...........#.....................................# b1 #......# b2 #...
     //       ............#.....................................#    #......#    #....
     //       ............#......................................####........####.....
     //      .............#.............................................####...........
     //      ..........................................................# b0 #..........
     //     ...........................................................#    #...........
     //     .......................#######................#######.......####............
     //    ......................#  axis1 ##............## axis3 ##......................
     //    .....................##    |    ##..........##    |    ##.....................
     //   ......................#<--axis0-->#..........#<--axis2--> #.....................
     //   ......................##    |    ##. .####. .##    |    ##......................
     //   .......................##   |   ##.. # b8 #...##   |   ##.......................
     //  ..........................#######......####......#######.........................
     //  ..................................................................................
     //  .....................    ..........             .........    .....................
     //  ....................                                          ....................
     //  ..................                                              ..................
     // ..................                                                ..................
     // ..................                                                 .................
     // .................                                                   ................
     // ................                                                     ...............
     //  ..............                                                       ..............
     //  .............                                                         ............
     //  ............                                                          ............
     //   ..........                                                             ..........
     //    .......                                                                ........
     //     ....                                                                     ...
     //

     for (int i=0;i<9;i++) button_map[i]=i;
     for (int i=0;i<7;i++)    axe_map[i]=i;
     axe_map[6]=1;


     //  other recognized map "Thrustmaster Run'N' Drive Wireless PS3"
     if ( strcmp(name,"Thrustmaster Run'N' Drive Wireless PS3" ) == 0){
       button_map[0]=1;
       button_map[1]=0;
       button_map[5]=6;
       button_map[6]=5;
     }

   }

   GamePad::~GamePad() {
     if (gamepad_fd > 0) {    active = false;    close(gamepad_fd);  }
     gamepad_fd = 0;
   }

   bool GamePad::toggle(const int _nbut) {
     bool res;
     if( toggle_status[_nbut] ){ res = true; toggle_status[_nbut]=false;}
     else { res=false;  }
     return res;
   }

   int GamePad::read_event() {
     int result = read(gamepad_fd, &event, sizeof(event)) ;
     if (result > 0)
       {
	 //   time( &rawtime );
	 switch (event.type)
	   {
	   case JS_EVENT_INIT:
	     break;
	   case JS_EVENT_INIT | JS_EVENT_AXIS:
	     break;
	   case JS_EVENT_INIT | JS_EVENT_BUTTON:
	     break;
	   case JS_EVENT_AXIS:
	     //	std::cout<< "------"<<rawtime<<"---- " <<std::endl;
	     axe[(int)event.number]=(double)event.value/32767. ;
	     break;
	   case JS_EVENT_BUTTON:
	     //	std::cout<< "------"<<rawtime<<"---- " <<std::endl;
	     if(button[(int)event.number]==0. && (bool)event.value)
	       { toggle_status[(int)event.number]=true; }
	     button[(int)event.number]=(bool)event.value ;

	     break;
	   default:
	     break;
	   }
       }
     //  std::cout<< "------"<<rawtime<<"---- " <<std::endl;
     //  else if (event_read){changed=false;}
     return 1;

   }


   void GamePad::affiche() {
     //	printf ("----------------------------------------------\n");
     for (int i=0;i<axes;i++) printf ("___________");
     printf ("\n");
     for (int i=0;i<axes;i++) printf ("  axis %2d |",i);
     printf ("\n");
     for (int i=0;i<axes;i++) printf (" %7f |", axe[i] );
     printf ("\n");
     for (int i=0;i<buttons;i++) printf ("_______");
     printf ("\n");
     for (int i=0;i<buttons;i++) printf (" b.%2d |",i);
     printf ("\n");
     for (int i=0;i<buttons;i++) printf (" %4d |",button[i]);
     printf ("\n");
     for (int i=0;i<buttons;i++) printf ("_______");
     printf ("\n");
   }



#endif // win32
