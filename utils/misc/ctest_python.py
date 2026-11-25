# Runs a test written in Python for ctest:
#
#   python ctest_python.py test.py [arguments of the test]
#
# The test is skipped (exit code 77) instead of failing when the Gmsh Python
# module cannot be used on the machine (it is not found, or it does not load
# the Gmsh library), or when the test needs a module that is not installed.

import runpy
import sys

try:
    import gmsh
    gmsh.initialize()
    gmsh.finalize()
except Exception as e:
    print("Skipped: the Gmsh Python module is not operational (%s)" % e)
    sys.exit(77)

sys.argv = sys.argv[1:]
try:
    runpy.run_path(sys.argv[0], run_name="__main__")
except ImportError as e:
    print("Skipped: %s" % e)
    sys.exit(77)
