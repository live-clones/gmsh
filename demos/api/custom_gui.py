import gmsh
import sys
import json
import math
import thread

# This example shows how to implement a custom user interface using onelab,
# running a computationally computation in a separate thread

gmsh.initialize()
gmsh.option.setNumber("General.Terminal", 1)

# create a onelab parameter that will be used to toggle progress messages
gmsh.onelab.set("""
{ "type":"number", "name":"Show progress?", "values":[0], "choices":[0, 1] },
""")

# set a custom onelab button with an associated "Action"
gmsh.onelab.setString("Button", ["Do it!", "should compute"])

# flag that will be set to interrupt a calculation
stop_computation = False

# a computatially heaving routine, that will be run in its own thread
def compute():
    k = 0
    p = 0
    progress = gmsh.onelab.getNumber("Show progress?")
    for j in range(10000000):
        if stop_computation:
            break
        k = math.sin(k) + math.cos(j/45.)
        # show progress in the GUI and in the message log
        if len(progress) and progress[0] == 1 and not j % 100000:
            p = p + 1
            # any code in a thread other than the main thread that can modify
            # the GUI should be locked
            gmsh.fltk.lock()
            gmsh.logger.write("thread progress {0}/100".format(p))
            gmsh.fltk.unlock()
            # ask the main thread to process pending events
            gmsh.fltk.awake()
    gmsh.onelab.setNumber("Result", [k])
    gmsh.onelab.setString("Action", ["done computing"])
    gmsh.fltk.awake()
    return

i = 1

# create the GUI
gmsh.fltk.initialize()

while 1:
    # wait for an event
    gmsh.fltk.wait()

    # check if the user ckicked on the custom onelab button by examining the
    # value of the "Action" onelab variable
    a = gmsh.onelab.getString("Action")

    if "should compute" in a:
        gmsh.onelab.setString("Action", [""])
        gmsh.onelab.setString("Button", ["Stop!", "should stop"])
        # force GUI update (to show the new button label)
        gmsh.fltk.update()
        # start computationally intensive calculation in its own thread
        thread.start_new_thread(compute, ())

    if "should stop" in a:
        stop_computation = True

    if "done computing" in a:
        gmsh.onelab.setString("Action", [""])
        gmsh.onelab.setString("Button", ["Do it!", "should compute"])
        msg = "Run {0} result = {1}".format(i, gmsh.onelab.getNumber("Result"))
        gmsh.logger.write(msg)
        gmsh.fltk.update()
        stop_computation = False
        i = i + 1

gmsh.finalize()
