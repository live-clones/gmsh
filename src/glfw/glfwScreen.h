// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GLFW_SCREEN_H
#define GLFW_SCREEN_H

#include <GLFW/glfw3.h>

// Scene::Host::screen of a scene held by GLFW: the primary monitor
inline void glfwScreen(int &height, float &scale)
{
  GLFWmonitor *monitor = glfwGetPrimaryMonitor();
  if(!monitor) return;
  if(const GLFWvidmode *mode = glfwGetVideoMode(monitor)) height = mode->height;
  float sy = 1.f;
  glfwGetMonitorContentScale(monitor, &scale, &sy);
}

#endif
