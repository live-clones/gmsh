"""

"""
module gmsh

const clib = "libgmsh"

"""
Test test test
"""
function initialize(argv = Vector{String}(), readConfigFiles = true)
    ierr = Vector{Cint}(1)
    ccall(("gmshInitialize", clib), Void,
          (Cint, Ptr{Ptr{Cchar}}, Cint, Ptr{Cint}),
          length(argv), argv, readConfigFiles, ierr)
    println(ierr[1])
end

function open(name)
    ierr = Vector{Cint}(1)
    ccall(("gmshOpen", clib), Void, 
          (Cstring, Ptr{Cint}), 
          name, ierr)
end

module option

import ..gmsh

function setNumber(name, value)
    ierr = Vector{Cint}(1)
    ccall(("gmshOptionSetNumber", gmsh.clib), Void,
          (Cstring, Cdouble, Ptr{Cint}),
          name, value, ierr)
end

end # end of module option

module model

import ..gmsh

module mesh

import ...gmsh

function generate(dim = 3)
    ierr = Vector{Cint}(1)
    ccall(("gmshModelMeshGenerate", gmsh.clib), Void,
          (Cint, Ptr{Cint}),
          dim, ierr)
end

function getNodes(dim = -1, tag = -1)
    ierr = Vector{Cint}(1)
    api_nodeTags_ = Vector{Ptr{Cint}}(1)
    api_coord_ = Vector{Ptr{Cdouble}}(1)
    api_parametricCoord_ = Vector{Ptr{Cdouble}}(1)
    api_nodeTags_n_= Vector{Csize_t}(1)
    api_coord_n_ = Vector{Csize_t}(1)
    api_parametricCoord_n_ = Vector{Csize_t}(1)
    ccall(("gmshModelMeshGetNodes", gmsh.clib), Void,
          (Ptr{Ptr{Cint}}, Ptr{Csize_t},
           Ptr{Ptr{Cdouble}}, Ptr{Csize_t},
           Ptr{Ptr{Cdouble}}, Ptr{Csize_t},
           Cint, Cint, Ptr{Cint}),
          api_nodeTags_,
          api_nodeTags_n_,
          api_coord_,
          api_coord_n_,
          api_parametricCoord_,
          api_parametricCoord_n_,
          dim,
          tag,
          ierr)
    nodeTags = unsafe_wrap(Array, api_nodeTags_[1],
                           api_nodeTags_n_[1], true)
    coord = unsafe_wrap(Array, api_coord_[1],
                        api_coord_n_[1], true)
    parametricCoord = unsafe_wrap(Array, api_parametricCoord_[1],
                                  api_parametricCoord_n_[1], true)
    return nodeTags, coord, parametricCoord
end

function getElements(dim = -1, tag = -1)
    ierr = Vector{Cint}(1)
    api_elementTypes_ = Vector{Ptr{Cint}}(1)
    api_elementTags_ = Vector{Ptr{Ptr{Cint}}}(1)
    api_nodeTags_ = Vector{Ptr{Ptr{Cint}}}(1)    
    api_elementTypes_n_= Vector{Csize_t}(1)
    api_elementTags_n_= Vector{Ptr{Csize_t}}(1)
    api_elementTags_nn_= Vector{Csize_t}(1)
    api_nodeTags_n_= Vector{Ptr{Csize_t}}(1)
    api_nodeTags_nn_= Vector{Csize_t}(1)
    ccall(("gmshModelMeshGetElements", gmsh.clib), Void,
          (Ptr{Ptr{Cint}}, Ptr{Csize_t},
           Ptr{Ptr{Ptr{Cint}}}, Ptr{Ptr{Csize_t}}, Ptr{Csize_t},
           Ptr{Ptr{Ptr{Cint}}}, Ptr{Ptr{Csize_t}}, Ptr{Csize_t},           
           Cint, Cint, Ptr{Cint}),
          api_elementTypes_,
          api_elementTypes_n_,
          api_elementTags_,
          api_elementTags_n_,
          api_elementTags_nn_,
          api_nodeTags_,
          api_nodeTags_n_,
          api_nodeTags_nn_,
          dim,
          tag,
          ierr)
    elementTypes = unsafe_wrap(Array, api_elementTypes_[1], api_elementTypes_n_[1], true)
    api_tmp_elementTags_ = unsafe_wrap(Array, api_elementTags_[1], api_elementTags_nn_[1], true)
    api_tmp_elementTags_n_ = unsafe_wrap(Array, api_elementTags_n_[1], api_elementTags_nn_[1], true)
    elementTags = [ unsafe_wrap(Array, api_tmp_elementTags_[i], api_tmp_elementTags_n_[i], true) for i in 1:api_elementTags_nn_[1] ]
    api_tmp_nodeTags_ = unsafe_wrap(Array, api_nodeTags_[1], api_nodeTags_nn_[1], true)
    api_tmp_nodeTags_n_ = unsafe_wrap(Array, api_nodeTags_n_[1], api_nodeTags_nn_[1], true)
    nodeTags = [ unsafe_wrap(Array, api_tmp_nodeTags_[i], api_tmp_nodeTags_n_[i], true) for i in 1:api_nodeTags_nn_[1] ]
    return elementTypes, elementTags, nodeTags
end

end # end of module mesh

end # end of module model

end # end of module gmsh
