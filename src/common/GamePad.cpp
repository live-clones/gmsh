// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Gilles Marckmann <gilles.marckmann@ec-nantes.fr>
//    default map is "THRUSTMASTER FireStorm Dual Power"-like
//
//                    ######                                   ######
//                   # but5 #                                 # but7 #
//                 .########..                               ..#######.
//                ............                               .......... .
//               ...#######...                              ...########..
//               ..# but4 #...                              ...# but6  #..
//              ...########.......                     ........#########..
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
//   .......................##   |   ##.. # b9 #...##   |   ##.......................
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

#include <math.h>
#include <cstring>
#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include "GamePad.h"

#if !defined(WIN32)
#include <unistd.h>
#endif

GamePad::GamePad() : active(false), frequency(.01)
{
#if defined(WIN32)
  gamepad_fd = 0;
  for (int i = JOYSTICKID1 ; i < JOYSTICKID2 ; i++)  {
    if(JOYERR_NOERROR == joyGetDevCaps(i, &caps, sizeof(JOYCAPS)) ) {
      /*
      std::cout << "Joystick/Gamepad detected: "<< name ;
      std::cout << " ( "  << (int)caps.wNumAxes <<" axes /" ;
      std::cout << (int)caps.wNumButtons <<" buttons)" << std::endl;
      std::cout << "  Driver name ....... " << caps.szPname << std::endl;
      std::cout << "  Manufacturer ID ... " << caps.wMid << std::endl;
      std::cout << "  Product ID ........ " << caps.wPid << std::endl;
      std::cout << "  RegKey ............ " << caps.szRegKey << std::endl;
      std::cout << "  OEMVxD ............ " << caps.szOEMVxD << std::endl;
      std::cout << "  wXmin ............. " << caps.wXmin << std::endl;
      std::cout << "  wXmax ............. " << caps.wXmax << std::endl;
      std::cout << "  wYmin ............. " << caps.wYmin << std::endl;
      std::cout << "  wYmax ............. " << caps.wYmax << std::endl;
      std::cout << "  wZmin ............. " << caps.wZmin << std::endl;
      std::cout << "  wZmax ............. " << caps.wZmax << std::endl;
      std::cout << "  wPeriodMin ........ " << caps.wPeriodMin << std::endl;
      std::cout << "  wPeriodMax ........ " << caps.wPeriodMax << std::endl;
      std::cout << "  wRmin ............. " << caps.wRmin << std::endl;
      std::cout << "  wRmax ............. " << caps.wRmax << std::endl;
      std::cout << "  wUmin ............. " << caps.wUmin << std::endl;
      std::cout << "  wUmax ............. " << caps.wUmax << std::endl;
      std::cout << "  wVmin ............. " << caps.wVmin << std::endl;
      std::cout << "  wVmax ............. " << caps.wVmax << std::endl;
      */
      if((1./frequency < (double)caps.wPeriodMin) ||
         (1./frequency > (double)caps.wPeriodMax)){
        frequency=.1/(double)caps.wPeriodMin;
      }
      gamepad_fd = i;
      axes = std::min(GP_AXES,(int)caps.wNumAxes + 2);
      buttons = std::min(GP_BUTTONS,(int)caps.wNumButtons);
      for (int i = 0; i < buttons; i++) button[i] = false;
      for (int i = 0; i < axes; i++) axe[i] = 0.;
      active = true;
    }
  }
  for(int i = 0; i < buttons; i++) button[i] = 0;
  for(int i = 0; i < axes; i++) axe[i] = 0;
  joyGetPosEx(gamepad_fd, &infoex);
  infoex.dwFlags = JOY_RETURNALL;
#elif defined(HAVE_LINUX_JOYSTICK)
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
#endif
  if(active){
    for (int i = 0; i < std::min(9, (int)buttons); i++) {
      button[i] = false;toggle_status[i] = false;
    }
    for (int i = 0; i < std::min(7, (int)axes); i++) axe[i] = 0.;
    for (int i = 0; i < std::min(9, (int)buttons); i++) button_map[i] = i;
    for (int i = 0; i < std::min(7, (int)axes); i++) axe_map[i] = i;
    axe_map[6]=1;
    // another recognized map "Thrustmaster Run'N' Drive Wireless PS3"
    // warning :: on Windows we dont have the human-friendly Model Name of the Gamepad
    if(strcmp(name, "Thrustmaster Run'N' Drive Wireless PS3") == 0){
      button_map[0] = 1;
      button_map[1] = 0;
      button_map[5] = 6;
      button_map[6] = 5;
    }
  }
}

GamePad::~GamePad()
{
   active = false;
#if defined(HAVE_LINUX_JOYSTICK)
  if (gamepad_fd)  close(gamepad_fd);
   gamepad_fd = 0;
#endif
}

bool GamePad::toggle(const int _nbut)
{
  bool res;
  if(toggle_status[_nbut]){ res = true; toggle_status[_nbut] = false; }
  else{ res = false; }
  return res;
}

int GamePad::read_event()
{
#if defined(WIN32)
  infoex.dwFlags = JOY_RETURNALL;
  joyGetPosEx(gamepad_fd, &infoex) ;
  axe[0] = (double)((1. * infoex.dwXpos - 32767.) / 32767.);
  axe[1] = (double)((1. * infoex.dwYpos - 32767.) / 32767.);
  axe[2] = (double)((1. * infoex.dwRpos - 32767.) / 32767.);
  axe[3] = (double)((1. * infoex.dwZpos - 32767.) / 32767.);
  if(infoex.dwPOV < 38000.) {
    double alpha = 3.14159 / 18000. * infoex.dwPOV;
    axe[4] = 1.001 * sin(alpha);
    axe[5] = -1.001 * cos(alpha);
  }
  else{
    axe[4] = axe[5] = 0.;
  }
  for (int i = 0; i < 6; i++) if(fabs(axe[i]) < .01) axe[i] = 0.;
  bool event = false;
  int event_num = 0;
  bool event_value = false;
  for (int i = 0; i < buttons; i++){
    int bin = pow(2.0, i);
    if(button[i] != (bool)(infoex.dwButtons & bin)) {
      event = true;
      event_num = i;
      event_value = (bool)(infoex.dwButtons & bin);
    }
  }
  if(event){
    if(button[event_num] == 0 && event_value){ toggle_status[event_num] = true; }
    button[event_num] = event_value;
  }
  /*
    std::cout<< "--------------------" << std::endl;
    std::cout<< infoex.dwXpos << std::endl;
    std::cout<< infoex.dwYpos << std::endl;
    std::cout<< infoex.dwZpos << std::endl;
    std::cout<< infoex.dwRpos << std::endl;
    std::cout<< infoex.dwUpos << std::endl;
    std::cout<< infoex.dwVpos << std::endl;
    std::cout<< infoex.dwButtons << std::endl;
    std::cout<< infoex.dwButtonNumber << std::endl;
    std::cout<< infoex.dwPOV << std::endl;
  */
#elif defined(HAVE_LINUX_JOYSTICK)
  int result = read(gamepad_fd, &event, sizeof(event));
  if (result > 0){
    switch (event.type){
    case JS_EVENT_INIT:
      break;
    case JS_EVENT_INIT | JS_EVENT_AXIS:
      break;
    case JS_EVENT_INIT | JS_EVENT_BUTTON:
      break;
    case JS_EVENT_AXIS:
      axe[(int)event.number] = (double)event.value / 32767.;
      break;
    case JS_EVENT_BUTTON:
      if(button[(int)event.number] == 0. && (bool)event.value) {
        toggle_status[(int)event.number] = true;
      }
      button[(int)event.number] = (bool)event.value ;
      break;
    default:
      break;
    }
  }
#endif
  return 1;
}

void GamePad::affiche()
{
  for (int i = 0; i < 6; i++) std::cout << "_________";
  std::cout << std::endl; std::cout << "  axis ";
  for (int i = 0; i < 6; i++) std::cout << " | "<<i;
  std::cout << std::endl;  std::cout << "       ";
  for (int i = 0; i < 6; i++) std::cout << " | "<< axe[i] ;
  std::cout << std::endl;
  for (int i = 0; i < 10; i++) std::cout << "_____";
  std::cout << std::endl;  std::cout << " b.";
  for (int i = 0; i < 10; i++) std::cout << " | " << i;
  std::cout << std::endl;  std::cout << "   ";
  for (int i = 0; i < 10; i++) std::cout << " | " << button[i];
  std::cout << std::endl;
  for (int i = 0; i < 10; i++) std::cout << "_____";
  std::cout << std::endl;
}
