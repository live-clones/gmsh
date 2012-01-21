# Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  main/Gmsh_printf.cpp main/Gmsh_exit.cpp
  main/user_params.c main/interface.c 
  submain/balance.c submain/divide.c submain/submain.c 
  input/input_assign.c 
  input/check_input.c input/input.c input/input_geom.c 
  input/input_graph.c input/read_params.c input/reflect_input.c 
  input/read_val.c 
  graph/check_graph.c graph/free_graph.c 
  graph/reformat.c graph/subgraph.c graph/graph_out.c 
  inertial/eigenvec2.c inertial/eigenvec3.c inertial/inertial.c 
  inertial/inertial1d.c inertial/inertial2d.c 
  inertial/inertial3d.c inertial/make_subgeom.c 
  klspiff/buckets.c klspiff/buckets_bi.c klspiff/buckets1.c 
  klspiff/bilistops.c klspiff/coarsen_kl.c klspiff/count_weights.c 
  klspiff/compress_ewgts.c klspiff/kl_init.c klspiff/kl_output.c 
  klspiff/klspiff.c klspiff/make_bndy_list.c 
  klspiff/make_kl_list.c klspiff/nway_kl.c 
  klvspiff/bpm_improve.c klvspiff/bucketsv.c 
  klvspiff/clear_dvals.c klvspiff/coarsen_klv.c 
  klvspiff/countup_vtx_sep.c klvspiff/find_bndy.c klvspiff/flow.c 
  klvspiff/klv_init.c klvspiff/klvspiff.c klvspiff/make_bpgraph.c 
  klvspiff/make_sep_list.c klvspiff/matching.c klvspiff/nway_klv.c 
  klvspiff/flatten.c 
  coarsen/coarsen.c coarsen/interpolate.c coarsen/makefgraph.c 
  coarsen/makeccoords.c 
  coarsen/coarsen1.c coarsen/makev2cv.c 
  coarsen/maxmatch.c coarsen/maxmatch1.c coarsen/maxmatch2.c 
  coarsen/maxmatch3.c coarsen/maxmatch4.c coarsen/maxmatch5.c 
  connect/add_edges.c connect/connected.c connect/find_edges.c 
  eigen/bidir.c eigen/bisect.c eigen/checkeig.c 
  eigen/checkeig_ext.c 
  eigen/checkorth.c eigen/cksturmcnt.c eigen/mkeigvecs.c
  eigen/eigensolve.c eigen/get_extval.c eigen/get_ritzvals.c 
  eigen/lanczos_FO.c eigen/lanczos_SO.c eigen/lanczos_SO_float.c 
  eigen/lanczos_ext.c eigen/lanczos_ext_float.c eigen/lanc_seconds.c
  eigen/lanpause.c eigen/makeorthlnk.c eigen/mkscanlist.c 
  eigen/orthog1.c eigen/orthogonalize.c eigen/orthogvec.c 
  eigen/ql.c eigen/rqi.c eigen/rqi_ext.c eigen/scale_diag.c 
  eigen/scanmax.c eigen/scanmin.c eigen/solistout.c 
  eigen/sorthog.c eigen/splarax.c eigen/sturmcnt.c 
  eigen/Tevec.c eigen/tri_solve.c eigen/warnings.c 
  symmlq/aprod.c symmlq/msolve.c symmlq/pow_dd.c 
  symmlq/symmlq.c symmlq/symmlqblas.c 
  tinvit/tinvit.c tinvit/pythag.c tinvit/epslon.c 
  optimize/determinant.c optimize/func2d.c 
  optimize/func3d.c optimize/opt2d.c optimize/opt3d.c 
  assign/assign.c assign/assign_out.c assign/mapper.c 
  assign/median.c assign/merge_assign.c 
  assign/rec_median.c assign/rotate.c assign/y2x.c 
  bpmatch/checkbp.c bpmatch/inits2d.c bpmatch/inits3d.c 
  bpmatch/genvals2d.c bpmatch/genvals3d.c bpmatch/map2d.c 
  bpmatch/map3d.c bpmatch/movevtxs.c 
  bpmatch/sorts2d.c bpmatch/sorts3d.c 
  refine_map/compute_cube_edata.c refine_map/compute_cube_vdata.c 
  refine_map/refine_cube.c refine_map/update_cube_edata.c 
  refine_map/update_cube_vdata.c refine_map/find_edge_cube.c 
  refine_map/init_cube_edata.c refine_map/compute_mesh_edata.c 
  refine_map/compute_mesh_vdata.c refine_map/find_edge_mesh.c 
  refine_map/init_mesh_edata.c refine_map/refine_mesh.c 
  refine_map/update_mesh_edata.c refine_map/update_mesh_vdata.c 
  refine_map/refine_map.c refine_map/make_comm_graph.c 
  refine_part/refine_part.c refine_part/kl_refine.c 
  refine_part/make_maps_ref.c refine_part/make_terms_ref.c 
  internal/force_internal.c internal/improve_internal.c 
  internal/check_internal.c 
  misc/define_subcubes.c misc/define_submeshes.c 
  misc/divide_procs.c misc/merge_goals.c misc/make_term_props.c 
  misc/count.c misc/countup.c misc/countup_cube.c 
  misc/countup_mesh.c misc/make_subgoal.c 
  misc/find_maxdeg.c misc/make_maps.c misc/make_setlists.c 
  misc/sequence.c misc/perturb.c misc/simple_part.c 
  misc/time_kernels.c misc/timing_chaco.c 
  util/affirm.c util/array_alloc_2D.c util/bit_reverse.c 
  util/checkpnt.c util/cpvec.c util/dot.c 
  util/doubleout.c util/input_int.c util/gray.c 
  util/machine_params.c util/makevwsqrt.c util/mkvec.c util/norm.c 
  util/normalize.c util/mergesort.c 
  util/randomize.c util/smalloc.c util/bail.c 
  util/scadd.c util/seconds.c util/setvec.c util/shell_sort.c 
  util/strout.c util/tri_prod.c util/true_or_false.c 
  util/update.c  util/vecout.c util/vecran.c 
  util/vecscale.c 
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/Chaco "${SRC};${HDR}")
