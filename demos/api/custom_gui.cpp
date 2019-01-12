#include <cmath>
#include <sstream>
#include <atomic>
#include "gmsh.h"

#if defined(_WIN32)
#include <windows.h>
#include <process.h>
#else
#include <pthread.h>
#endif

// This example shows how to implement a custom user interface running
// computationally expensive calculations in separate threads. The threads can
// update the user interface in real-time.

// flag that will be set to interrupt a calculation
std::atomic<int> stop_computation(0);

// a computationally expensive routine, that will be run in its own thread
void *compute(void *ptr)
{
  std::string *arg = static_cast<std::string*>(ptr);
  double k = 0.;
  int p = 0, n = 10000000;
  std::vector<double> progress;
  gmsh::onelab::getNumber("My App/Show progress?", progress);
  for(int j = 0; j < n; j++){
    // stop computation if requested by clicking on "Stop it!"
    if(stop_computation)
      break;
    k = sin(k) + cos(j / 45.);
    // show progress in real time?
    if(progress.size() && progress[0] && !(j % (n / 100))){
      p++;
      gmsh::onelab::setString(*arg, {std::to_string(p) + "%"});
      // any code in a thread other than the main thread that modifies the user
      // interface should be locked
      gmsh::fltk::lock();
      gmsh::logger::write(*arg + " progress " + std::to_string(p) + "%");
      gmsh::fltk::unlock();
      // ask the main thread to process pending events and to update the user
      // interface
      gmsh::fltk::awake("update");
    }
  }
  gmsh::onelab::setNumber(*arg + " result", {k});
  gmsh::onelab::setString("Action", {"done computing"});
  gmsh::fltk::awake("update");
  delete arg;
  return 0;
}

int main(int argc, char **argv)
{
  gmsh::initialize();

  // hide the standard Gmsh modules
  gmsh::option::setNumber("General.ShowModuleMenu", 0);

  // create some onelab parameters: the number of threads to create, a toggle to
  // enable/disable showing the progress of the computation in real time, and
  // the custom onelab button with its associated action (when pressed, it will
  // set the "Action" onelab variable to "should compute")
  gmsh::onelab::set
    ("[ { \"type\":\"number\", \"name\":\"My App/Number of threads\", \"values\":[2],"
     "    \"choices\":[1, 2, 3, 4], \"attributes\":{\"Highlight\":\"AliceBlue\"} },"
     "{ \"type\":\"number\", \"name\":\"My App/Show progress?\", \"values\":[1],"
     "  \"choices\":[0, 1] },"
     "{ \"type\":\"string\", \"name\":\"Button\", \"values\":[\"Do it!\", \"should compute\"],"
     "\"visible\":false } ]");

  // create the graphical user interface
  gmsh::fltk::initialize();

  while(1){
    // wait for an event
    gmsh::fltk::wait();

    // check if the user clicked on the custom onelab button by examining the
    // value of the "Action" onelab variable
    std::vector<std::string> a;
    gmsh::onelab::getString("Action", a);

    if(a.size() && a[0] == "should compute"){
      gmsh::onelab::setString("Action", {""});
      gmsh::onelab::setString("Button", {"Stop!", "should stop"});
      // force interface update (to show the new button label)
      gmsh::fltk::update();
      // start computationally intensive calculations in their own threads
      std::vector<double> v;
      gmsh::onelab::getNumber("My App/Number of threads", v);
      int n = v.size() ? static_cast<int>(v[0]) : 1;
      for(unsigned int i = 0; i < n; i++){
        std::ostringstream sstream;
        sstream << "My App/Thread " << i + 1;
        std::string *arg = new std::string(sstream.str());
        pthread_t t;
        pthread_create(&t, nullptr, compute, static_cast<void*>(arg));
        pthread_detach(t);
      }
    }
    if(a.size() && a[0] == "should stop"){
      stop_computation++;
    }
    if(a.size() && a[0] == "done computing"){
      // should not detach threads, and join them all here
      gmsh::onelab::setString("Action", {""});
      gmsh::onelab::setString("Button", {"Do it!", "should compute"});
      gmsh::fltk::update();
      stop_computation = false;
    }
  }

  gmsh::finalize();

  return 0;
}
