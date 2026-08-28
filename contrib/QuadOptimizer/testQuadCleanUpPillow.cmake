if(NOT DEFINED GMSH_EXECUTABLE OR NOT DEFINED TEST_GEO)
  message(FATAL_ERROR "GMSH_EXECUTABLE and TEST_GEO are required")
endif()

get_filename_component(TEST_DIRECTORY "${TEST_GEO}" DIRECTORY)
execute_process(
  COMMAND "${GMSH_EXECUTABLE}" "${TEST_GEO}"
          -parse_and_exit -nopopup -v 5
  WORKING_DIRECTORY "${TEST_DIRECTORY}"
  RESULT_VARIABLE status
  OUTPUT_VARIABLE output
  ERROR_VARIABLE error)
set(log "${output}${error}")
if(NOT status EQUAL 0)
  message(FATAL_ERROR "QuadCleanUp pillow driver failed:\n${log}")
endif()

string(REGEX MATCHALL "QuadCleanUp: [^\n\r]*" summaries "${log}")
list(LENGTH summaries summary_count)
if(NOT summary_count EQUAL 2)
  message(FATAL_ERROR "Expected two QuadCleanUp summaries:\n${log}")
endif()
list(GET summaries 0 first_summary)
list(GET summaries 1 second_summary)
if(NOT first_summary MATCHES
     "^QuadCleanUp: 1 faces, 0 topology changes, 1 pillows \\(8 quads\\)," OR
   NOT first_summary MATCHES "bad elements 0 -> 0" OR
   NOT first_summary MATCHES "absolute violations 0 -> 0")
  message(FATAL_ERROR "The smoothed pillow was not accepted:\n${log}")
endif()
if(NOT second_summary MATCHES
     "^QuadCleanUp: 1 faces, 0 topology changes, 0 pillows \\(0 quads\\)," OR
   NOT second_summary MATCHES "bad elements 0 -> 0" OR
   NOT second_summary MATCHES "absolute violations 0 -> 0")
  message(FATAL_ERROR "The second pillow pass changed the mesh:\n${log}")
endif()

string(REGEX MATCHALL "QuadCleanUp fixed point: [^\n\r]*" fixed_points
       "${log}")
list(LENGTH fixed_points fixed_point_count)
if(NOT fixed_point_count EQUAL 2)
  message(FATAL_ERROR "Expected two fixed-point summaries:\n${log}")
endif()
list(GET fixed_points 1 second_fixed_point)
if(NOT second_fixed_point MATCHES "swaps=0 diamonds=0, smoothed=0")
  message(FATAL_ERROR "The second QuadCleanUp was not a fixed point:\n${log}")
endif()

string(REGEX MATCHALL "QuadCleanUp pillow audit: [^\n\r]*" pillow_audits
       "${log}")
list(LENGTH pillow_audits pillow_audit_count)
if(NOT pillow_audit_count EQUAL 2)
  message(FATAL_ERROR "Expected two pillow audits:\n${log}")
endif()
list(GET pillow_audits 0 first_pillow_audit)
list(GET pillow_audits 1 second_pillow_audit)
if(NOT first_pillow_audit MATCHES
     "visited=2 accepted=1 alreadyPresent=1 insertedQuads=8")
  message(FATAL_ERROR "The pillow insertion audit is incomplete:\n${log}")
endif()
if(NOT second_pillow_audit MATCHES
     "visited=1 accepted=0 alreadyPresent=1 insertedQuads=0")
  message(FATAL_ERROR "The existing pillow topology was not recognized:\n${log}")
endif()

string(REGEX MATCHALL "QuadOptimizer size: [^\n\r]*" size_audits "${log}")
list(LENGTH size_audits size_audit_count)
if(NOT size_audit_count EQUAL 2)
  message(FATAL_ERROR "Expected two pillow size audits:\n${log}")
endif()
list(GET size_audits 0 first_size)
list(GET size_audits 1 second_size)
# The duplicate rim starts at about 2e-4 from the hole. Thus an accepted
# pillow with finalBelow=0 proves that the post-Winslow candidate, rather than
# the infinitesimal construction, was audited and committed.
foreach(size_audit IN ITEMS "${first_size}" "${second_size}")
  if(NOT size_audit MATCHES
     "^QuadOptimizer size: target=4 minimum=1 maximum=10 ")
    message(FATAL_ERROR "Pillow size criteria were not propagated:\n${log}")
  endif()
  foreach(field IN ITEMS initialBelow initialAbove initialInvalid
                         finalBelow finalAbove finalInvalid)
    if(NOT size_audit MATCHES "${field}=0([ ]|$)")
      message(FATAL_ERROR "Pillow size requirement ${field}=0 is missing:\n${log}")
    endif()
  endforeach()
endforeach()
