# {#mainpage}

mt-Metis
=============================

mt-Metis is a multithreaded multilevel graph partitioning an ordering tool. It
is based on the algorithms used in Metis and ParMetis 
(http://cs.umn.edu/~metis).


The 'mtmetis' Executable
-----------------------------

To partition a graph with mt-Metis into 16 parts:

    mtmetis test.graph 16 test.part

To generate a nested dissection ordering a of a graph/matrix:

    mtmetis -p nd test.graph test.perm  

Many other runtime parameters are available. Use 
the '-h' option to view these.

    mtmetis -h

Be warned that many of the options are for experimentation purposes and may
signficantly effect the performance and functionality of mt-Metis.
    


The mt-Metis API
-------------------------------

The file [mtmetis.h](@ref mtmetis.h) is the header that should be included
by external programs wishing link to mt-Metis. There are two high level
functions, mtmetis_partkway() for partitioning, and mtmetis_nd() for generating
orderings. At this time mt-Metis is highly experimental, and its
API is subject to change.

