function msh = load_gmsh2(filename)

%% Reads a mesh in msh format, version 1 or 2

% Copyright (C) 2007  JP Moitinho de Almeida (moitinho@civil.ist.utl.pt)
% based on load_gmsh.m supplied with gmsh-2.0

% Structure msh has the following elements:

% msh.NODES_PER_TYPE_OF_ELEMENT - Number of nodes for each type of element
% msh.MIN, msh.MAX - Bounding box
% msh.nbNod - Number of nodes
% msh.nbElm - Total number of elements
% msh.nbType(i) - Number of elements of type i (i in 1:19)
% msh.POS(i,j) - j'th coordinate of node i (j in 1:3, i in 1:msh.nbNod)
% msh.ELE_INFOS(i,1) - id of element i (i in 1:msh.nbElm)
% msh.ELE_INFOS(i,2) - type of element i
% msh.ELE_INFOS(i,3) - number of tags for element i
% msh.ELE_INFOS(i,4) - Dimension (0D, 1D, 2D or 3D) of element i
% msh.ELE_TAGS(i,j) - Tags of element i (j in 1:msh.ELE_INFOS(i,3))
% msh.ELE_NODES(i,j) - Nodes of element i (j in 1:k, with
%                       k = msh.NODES_PER_TYPE_OF_ELEMENT(msh.ELE_INFOS(i,2)))

msh.MIN = [ inf; inf; inf ];
msh.MAX = [ -inf; -inf; -inf ];

%
% These definitions need to be updated when new elemens types are added to gmsh
%
%   0  0  0  0  0  0  0  0  0  1  1  1  1  1  1  1  1  1  1 
%   1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9 
msh.NODES_PER_TYPE_OF_ELEMENT = [ 
    2  3  4  4  8  6  5  3  6  9 10 27 18 14  1  8 20 15 13 ];
%
%       0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2
%       1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
Dim = [ 1 2 2 3 3 3 3 1 2 2 3 3 3 3 0 3 3 3 3 ];

ntypes = length(msh.NODES_PER_TYPE_OF_ELEMENT);

fid = fopen(filename, 'r');
fileformat = 0; % Assume wrong file

tline = fgetl(fid);
if (feof(fid))
    disp (sprintf('Empty file: %s',  filename));
    msh = [];
    return;
end

%% Read mesh type
if (strcmp(tline, '$NOD'))
    fileformat = 1;
elseif (strcmp(tline, '$MeshFormat'))
    fileformat = 2;
    tline = fgetl(fid);
    if (feof(fid))
        disp (sprintf('Syntax error (no version) in: %s',  filename));
        fileformat = 0;
    end
    [ form ] = sscanf( tline, '%f %d %d');
    if (form(1) ~= 2)
        disp (sprintf('Unknown mesh format: %s', tline));
        fileformat = 0;
    end
    if (form(2) ~= 0)
        disp ('Sorry, this program can only read ASCII format');
        fileformat = 0;
    end
    fgetl(fid);    % this should be $EndMeshFormat
    if (feof(fid))
        disp (sprintf('Syntax error (no $EndMeshFormat) in: %s',  filename));
        fileformat = 0;
    end
    tline = fgetl(fid);    % this should be $Nodes
    if (feof(fid))
        disp (sprintf('Syntax error (no $Nodes) in: %s',  filename));
        fileformat = 0;
    end
end

if (~fileformat)
    msh = [];
    return
end

%% Read nodes

if strcmp(tline, '$NOD') || strcmp(tline, '$Nodes')
    msh.nbNod = fscanf(fid, '%d', 1);
    msh.POS = zeros(msh.nbNod, 3);
    for I=1:msh.nbNod
        % iNod =
        fscanf(fid, '%d', 1);
        X = fscanf(fid, '%g', 3);
        % IDS(iNod) = I;                      % Is it safe to assume that the nodes are sequentially presented?
        msh.MAX = max(msh.MAX, X);
        msh.MIN = min(msh.MIN, X);
        msh.POS(I,:) = X;
    end
    fgetl(fid); % End previous line
    fgetl(fid); % Has to be $ENDNOD $EndNodes
end

%% Read elements
tline = fgetl(fid);
if strcmp(tline,'$ELM') || strcmp(tline, '$Elements')
    msh.nbElm = fscanf(fid, '%d', 1);
    msh.ELE_INFOS = zeros(msh.nbElm, 4); % 1 - id, 2 - type, 3 -tags, 4 - Dimension
    msh.ELE_NODES = zeros(msh.nbElm,1); % i - Element, j - ElNodes
    if eq(fileformat, 1)
        ntags = 2;
    else
        ntags = 3; % just a prediction
    end
    msh.ELE_TAGS = zeros(msh.nbElm, ntags);
    msh.nbType = zeros(ntypes,1);
    for I = 1:msh.nbElm
        if (fileformat == 2)
            msh.ELE_INFOS(I, 1:3) = fscanf(fid, '%d', 3);
            ntags = msh.ELE_INFOS(I,3);
            msh.ELE_TAGS(I, 1:ntags) = fscanf(fid, '%d', ntags);
        else
            aux = fscanf(fid, '%d', 5);
            msh.ELE_INFOS(I, 1:2) = aux(1:2);
            msh.ELE_INFOS(I, 3) = 2;
            msh.ELE_TAGS(I, :) = aux(3:4);
        end
        type = msh.ELE_INFOS(I, 2);
        msh.nbType(type) = msh.nbType(type) + 1;
        msh.ELE_INFOS(I, 4) = Dim(type);
        nnodes = msh.NODES_PER_TYPE_OF_ELEMENT(type);
        NODES_ELEM = fscanf(fid, '%d', nnodes);
        msh.ELE_NODES(I, 1:nnodes) = NODES_ELEM;
    end
    fgetl(fid); % End previous line
    fgetl(fid); % Has to be $ENDELM or $EndElements
else
    disp('Error reading elements');
    fileformat = 0;
end

if (fileformat == 0)
    msh = [];
end

fclose(fid);
return;
