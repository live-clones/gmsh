# Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
# concorde97/BIGGUY/bg_test.c
  concorde97/BIGGUY/bigguy.c
  concorde97/CUT/connect.c
  concorde97/CUT/cut_st.c
# concorde97/CUT/mc_main.c
  concorde97/CUT/mincut.c
  concorde97/CUT/segments.c
  concorde97/CUT/shrink.c
  concorde97/EDGEGEN/edgegen.c
# concorde97/EDGEGEN/eg_main.c
  concorde97/EDGEGEN/xnear.c
# concorde97/FMATCH/fm_main.c
  concorde97/FMATCH/fmatch.c
# concorde97/KDTREE/kd_main.c
  concorde97/KDTREE/kdbuild.c
  concorde97/KDTREE/kdnear.c
  concorde97/KDTREE/kdspan.c
  concorde97/KDTREE/kdtwoopt.c
# concorde97/LINKERN/flip_ary.c
# concorde97/LINKERN/flip_bt0.c
# concorde97/LINKERN/flip_bt1.c
# concorde97/LINKERN/flip_bt2.c
# concorde97/LINKERN/flip_bt3.c
# concorde97/LINKERN/flip_bt4.c
# concorde97/LINKERN/flip_bt5.c
# concorde97/LINKERN/flip_btc.c
# concorde97/LINKERN/flip_btd.c
# concorde97/LINKERN/flip_btr.c
# concorde97/LINKERN/flip_ll0.c
# concorde97/LINKERN/flip_ll1.c
# concorde97/LINKERN/flip_ll2.c
# concorde97/LINKERN/flip_ll3.c
# concorde97/LINKERN/flip_ll4.c
# concorde97/LINKERN/flip_ll5.c
# concorde97/LINKERN/flip_ll6.c
# concorde97/LINKERN/flip_ll7.c
  concorde97/LINKERN/flip_ll8.c
# concorde97/LINKERN/flip_ll9.c
# concorde97/LINKERN/flip_llA.c
# concorde97/LINKERN/flip_llB.c
# concorde97/LINKERN/flip_llC.c
# concorde97/LINKERN/flip_llD.c
# concorde97/LINKERN/flip_sg1.c
# concorde97/LINKERN/flip_sg2.c
# concorde97/LINKERN/flip_sg3.c
# concorde97/LINKERN/flip_sp1.c
# concorde97/LINKERN/flip_sp2.c
# concorde97/LINKERN/flip_try.c
# concorde97/LINKERN/flip_tw2.c
# concorde97/LINKERN/flip_two.c
  concorde97/LINKERN/linkern.c
# concorde97/LINKERN/lk_main.c
# concorde97/LP/lpcplex.c
  concorde97/LP/lpsolve.c
  concorde97/TSP/bcontrol.c
  concorde97/TSP/branch.c
  concorde97/TSP/cliqhash.c
  concorde97/TSP/cliqwork.c
#concorde97/TSP/concorde.c
  concorde97/TSP/control.c
  concorde97/TSP/cutcall.c
  concorde97/TSP/cutpool.c
  concorde97/TSP/edgemap.c
  concorde97/TSP/ex_price.c
  concorde97/TSP/generate.c
# concorde97/TSP/poolcat.c
  concorde97/TSP/prob_io.c
  concorde97/TSP/qsparse.c
  concorde97/TSP/teething.c
  concorde97/TSP/tighten.c
  concorde97/TSP/tsp_lp.c
  concorde97/TSP/xtour.c
  concorde97/UTIL/allocrus.c
  concorde97/UTIL/bgetopt.c
  concorde97/UTIL/dheaps_i.c
  concorde97/UTIL/edg2cyc.c
  concorde97/UTIL/edgelen.c
  concorde97/UTIL/fastread.c
  concorde97/UTIL/genhash.c
  concorde97/UTIL/getdata.c
  concorde97/UTIL/priority.c
  concorde97/UTIL/safe_io.c
  concorde97/UTIL/sortrus.c
  concorde97/UTIL/urandom.c
  concorde97/UTIL/util.c
  concorde97/UTIL/zeit.c
  concorde97/XSTUFF/Xallcuts.c
  concorde97/XSTUFF/Xblobs.c
  concorde97/XSTUFF/Xblock.c
  concorde97/XSTUFF/Xblossom.c
  concorde97/XSTUFF/Xcclean.c
  concorde97/XSTUFF/Xclique.c
  concorde97/XSTUFF/Xcuthash.c
  concorde97/XSTUFF/Xcutload.c
  concorde97/XSTUFF/Xcuts.c
  concorde97/XSTUFF/Xcututil.c
  concorde97/XSTUFF/Xflow.c
  concorde97/XSTUFF/Xgomhu.c
  concorde97/XSTUFF/Xgraph.c
  concorde97/XSTUFF/Xnecklac.c
  concorde97/XSTUFF/Xnewkids.c
  concorde97/XSTUFF/Xourallo.c
  concorde97/XSTUFF/Xpqnew.c
  concorde97/XSTUFF/Xshrink.c
  concorde97/XSTUFF/Xstuff.c
# concorde97/XSTUFF/Xtest.c
  MATCH/match.c MATCH/matprice.c
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/blossom "${SRC};${HDR}")
