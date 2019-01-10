import gmsh
import sys
import math
import thread

# This example shows how to implement a custom user interface running
# computationally expensive calculations in separate threads. The threads can
# update the user interface in real-time.

gmsh.initialize()

# hide the standard Gmsh menu
gmsh.option.setNumber("General.ShowGmshMenu", 0)

# create some onelab parameters: the number of threads to create, a toggle to
# enable/disable showing the progress of the computation in real time, and the
# custom onelab button with its associated action (when pressed, it will set the
# "Action" onelab variable to "should compute")
gmsh.onelab.set("""
[
  { "type":"number", "name":"My App/Number of threads", "values":[2],
    "choices":[1, 2, 3, 4], "attributes":{"Highlight":"AliceBlue"} },
  { "type":"number", "name":"My App/Show progress?", "values":[1],
    "choices":[0, 1] },
  { "type":"string", "name":"Button", "values":["Do it!", "should compute"],
    "visible":false }
]
""")

# flag that will be set to interrupt a calculation
stop_computation = False

# a computationally expensive routine, that will be run in its own thread
def compute(arg):
    k = 0
    p = 0
    n = 1000000
    progress = gmsh.onelab.getNumber("My App/Show progress?")[0]
    for j in range(n):
        # stop computation if requested by clicking on "Stop it!"
        if stop_computation:
            break
        k = math.sin(k) + math.cos(j/45.)
        # show progress in real time?
        if progress == 1 and not j % (n / 100):
            p = p + 1
            gmsh.onelab.setString(arg, ["{0}%".format(p)])
            # any code in a thread other than the main thread that modifies the
            # user interface should be locked
            gmsh.fltk.lock()
            gmsh.logger.write("{0} progress {1}%".format(arg, p))
            gmsh.fltk.unlock()
            # ask the main thread to process pending events and to update the
            # user interface
            gmsh.fltk.awake("update")
    gmsh.onelab.setNumber(arg + " result", [k])
    gmsh.onelab.setString("Action", ["done computing"])
    gmsh.fltk.awake("update")
    return

# create the graphical user interface
gmsh.fltk.initialize()

while 1:
    # wait for an event
    gmsh.fltk.wait()

    # check if the user clicked on the custom onelab button by examining the
    # value of the "Action" onelab variable
    a = gmsh.onelab.getString("Action")

    if "should compute" in a:
        gmsh.onelab.setString("Action", [""])
        gmsh.onelab.setString("Button", ["Stop!", "should stop"])
        # force interface update (to show the new button label)
        gmsh.fltk.update()
        # start computationally intensive calculations in their own threads
        n = int(gmsh.onelab.getNumber("My App/Number of threads")[0])
        #for i in range(n):
        #    thread.start_new_thread(compute, ("My App/Thread {0}".format(i + 1),))
        thread.start_new_thread(compute, ("My App/Thread {0}".format(1),))

    if "should stop" in a:
        stop_computation = True

    if "done computing" in a:
        gmsh.onelab.setString("Action", [""])
        gmsh.onelab.setString("Button", ["Do it!", "should compute"])
        print("aaaaaaaaaaaaaa")
        gmsh.fltk.update()
        stop_computation = False

gmsh.finalize()
