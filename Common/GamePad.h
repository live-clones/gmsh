// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// Contributed by Gilles Marckmann <gilles.marckmann@ec-nantes.fr>

#ifndef _GAMEPAD_H_
#define _GAMEPAD_H_

#define GP_RANGE 1.0
#define GP_DEV 16
#define GP_BUTTONS 32
#define GP_AXES 6



#if defined(WIN32) || defined(__APPLE__)

   class GamePad {
   public:
     bool active;
     bool toggle_status[GP_BUTTONS];
     bool event_read;
     double frequency;
     GamePad();
     ~GamePad();
     double axe[GP_AXES];
     bool button[GP_BUTTONS];
     bool toggle(const int _nbut);
     int read_event();
     void affiche();
     int button_map[10];
     int axe_map[8];
   private:
     int gamepad_fd;
     //  js_event event;
     //  __u32 version;
     //  __u8 axes;
     //  __u8 buttons;
     char name[256];
   };



#else // !win32 => linux/apple


   #include <linux/joystick.h>
   #include <fcntl.h>

   #define GAMEPAD_DEV "/dev/input/js0"

   class GamePad {
   public:
     bool active;
     bool toggle_status[GP_BUTTONS];
     bool event_read;
     double frequency;
     GamePad();
     ~GamePad();
     double axe[GP_AXES];
     bool button[GP_BUTTONS];
     bool toggle(const int _nbut);
     int read_event();
     void affiche();
     int button_map[10];
     int axe_map[8];


   private:
     //  time_t  rawtime;
     int gamepad_fd;
     js_event event;
     __u32 version;
     __u8 axes;
     __u8 buttons;
     char name[256];
   };

#endif //win32

#endif // _GAMEPAD_H_
