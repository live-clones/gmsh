#include <cmath>
#include <thread>
#include "gmsh.h"

// This example shows how to implement a custom user interface running
// computationally expensive calculations in separate threads. The threads can
// update the user interface in real-time.

// flag that will be set to interrupt a calculation
bool stop_computation = false;

// a computationally expensive routine, that will be run in its own thread
void compute(const std::string &arg)
{
  std::vector<double> iterations, progress;
  gmsh::onelab::getNumber("My App/Iterations", iterations);
  gmsh::onelab::getNumber("My App/Show progress?", progress);
  int n = iterations.size() ? static_cast<int>(iterations[0]) : 1;
  bool show = (progress.size() && progress[0]) ? true : false;
  int p = 0;
  double k = 0., last_refresh = 0.;
  for(int j = 0; j < n; j++){
    // stop computation if requested by clicking on "Stop it!"
    if(stop_computation)
      break;
    k = sin(k) + cos(j / 45.);
    // show progress in real time?
    if(show && n > 1 && !(j % (n / 100))){
      p++;
      gmsh::onelab::setString(arg, {std::to_string(p) + "%"});
      // any code in a thread other than the main thread that modifies the user
      // interface should be locked
      gmsh::fltk::lock();
      gmsh::logger::write(arg + " progress " + std::to_string(p) + "%");
      gmsh::fltk::unlock();
      // ask the main thread to process pending events and to update the user
      // interface, maximum 10 times per second
      if(gmsh::logger::time() - last_refresh > 0.1){
        last_refresh = gmsh::logger::time();
        gmsh::fltk::awake("update");
      }
    }
  }
  gmsh::onelab::setNumber(arg + " result", {k});
  gmsh::onelab::setString("Action", {"done computing"});
  gmsh::fltk::awake("update");
}

int main(int argc, char **argv)
{
  gmsh::initialize();

  // hide the standard Gmsh modules
  gmsh::option::setNumber("General.ShowModuleMenu", 0);

  // create some onelab parameters to control the number of iterations and
  // threads, the progress display and the custom onelab button (when pressed,
  // it will set the "Action" onelab variable to "should compute")
  gmsh::onelab::set(R"( [
    { "type":"number", "name":"My App/Iterations", "values":[1e6],
      "attributes":{"Highlight":"AliceBlue"} },
    { "type":"number", "name":"My App/Number of threads", "values":[2],
      "choices":[1, 2, 3, 4], "attributes":{"Highlight":"AliceBlue"} },
    { "type":"number", "name":"My App/Show progress?", "values":[1],
      "choices":[0, 1] },
    { "type":"string", "name":"Button", "values":["Do it!", "should compute"],
      "visible":false }
  ] )");

  // create the graphical user interface
  gmsh::fltk::initialize();

  while(1){
    // wait for an event
    gmsh::fltk::wait();

    // check if the user clicked on the custom onelab button by examining the
    // value of the "Action" onelab variable
    std::vector<std::string> action;
    gmsh::onelab::getString("Action", action);
    if(action.empty()){
      continue;
    }
    else if(action[0] == "should compute"){
      gmsh::onelab::setString("Action", {""});
      gmsh::onelab::setString("Button", {"Stop!", "should stop"});
      // force interface update (to show the new button label)
      gmsh::fltk::update();
      // start computationally intensive calculations in their own threads
      std::vector<double> v;
      gmsh::onelab::getNumber("My App/Number of threads", v);
      int n = v.size() ? static_cast<int>(v[0]) : 1;
      for(unsigned int i = 0; i < n; i++){
        std::thread t(compute, "My App/Thread " + std::to_string(i + 1));
        t.detach();
      }
    }
    else if(action[0] == "should stop"){
      stop_computation = true;
    }
    else if(action[0] == "done computing"){
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
