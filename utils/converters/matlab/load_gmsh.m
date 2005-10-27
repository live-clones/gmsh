function mesh = load_gmsh ( filename )
% Reads a 2D mesh in msh format, version 1
    mesh = [];    
    mesh.MIN = zeros(3,1);
    mesh.MAX = zeros(3,1);
    fid = fopen ( filename, 'r');
    while 1
        endoffile = 0;
        while 1
            tline = fgetl(fid);
            if feof(fid), endoffile=1,break, end
            if tline(1) == '$'  break, end  
        end
        if endoffile == 1 , break, end
            
        if tline (2) == 'N' && tline(3) == 'O'
            disp('reading nodes')
            mesh.nbNod = fscanf (fid, '%d',1);
	        mesh.POS = zeros (mesh.nbNod, 3);
            for(I=1:mesh.nbNod)
                iNod = fscanf(fid,'%d',1);
                X = fscanf(fid,'%g',3);
                IDS(iNod) = I;
                if (I == 1)
                    mesh.MIN = X;
                    mesh.MAX = X;
                else
                    if (mesh.MAX(1) < X(1))mesh.MAX(1)=X(1);end
                    if (mesh.MAX(2) < X(2))mesh.MAX(2)=X(2);end
                    if (mesh.MAX(3) < X(3))mesh.MAX(3)=X(3);end
                    if (mesh.MIN(1) > X(1))mesh.MIN(1)=X(1);end
                    if (mesh.MIN(2) > X(2))mesh.MIN(2)=X(2);end
                    if (mesh.MIN(3) > X(3))mesh.MIN(3)=X(3);end
                    end
                mesh.POS(I,1) = X(1);
                mesh.POS(I,2) = X(2);
                mesh.POS(I,3) = X(3);
            end
            tline = fgetl(fid);
            disp('nodes have been read')

        else if tline (2) == 'E' && tline(3) == 'L'
            disp('reading elements')
            mesh.nbElm = fscanf (fid, '%d',1);
            mesh.ELE_INFOS = zeros (mesh.nbElm,5);
            mesh.nbBeams = 0;
            mesh.nbPoints = 0;
            mesh.nbTriangles = 0;
            mesh.nbQuads = 0;
            mesh.nbTet = 0;
            mesh.POINTS=zeros(mesh.nbElm,2);
            mesh.BEAMS=zeros(mesh.nbElm,3);
            mesh.TRIANGLES=zeros(mesh.nbElm,4);
            mesh.QUADS=zeros(mesh.nbElm,5);
            mesh.TETS=zeros(mesh.nbElm,5);
            for(I=1:mesh.nbElm)
                mesh.ELE_INFOS(I,:) = fscanf (fid,'%d',5);
                NODES_ELEM = fscanf (fid,'%d',mesh.ELE_INFOS(I,5));
                if (mesh.ELE_INFOS(I,2) == 15) %% point
                    mesh.nbPoints = mesh.nbPoints + 1;
                    mesh.POINTS ( mesh.nbPoints,1 ) = IDS (NODES_ELEM ( 1) );
                    mesh.POINTS ( mesh.nbPoints,2 ) = I;
                end
                if (mesh.ELE_INFOS(I,2) == 1) %% beam
                    mesh.nbBeams = mesh.nbBeams + 1;
                    mesh.BEAMS ( mesh.nbBeams,1 ) = IDS (NODES_ELEM ( 1) );
                    mesh.BEAMS ( mesh.nbBeams,2 ) = IDS (NODES_ELEM ( 2) );   
                    mesh.BEAMS ( mesh.nbBeams,3 ) = I;   
                end
                if (mesh.ELE_INFOS(I,2) == 2) %% triangle
                   mesh.nbTriangles = mesh.nbTriangles + 1;
                   mesh.TRIANGLES ( mesh.nbTriangles , 1) = IDS (NODES_ELEM ( 1) );
                   mesh.TRIANGLES ( mesh.nbTriangles , 2) = IDS (NODES_ELEM ( 2) );
                   mesh.TRIANGLES ( mesh.nbTriangles , 3) = IDS (NODES_ELEM ( 3) );
                   mesh.TRIANGLES ( mesh.nbTriangles , 4) = I;
                end
                if (mesh.ELE_INFOS(I,2) == 3) %% quadrangle
                   mesh.nbQuads = mesh.nbQuads + 1;
                   mesh.QUADS ( mesh.nbQuads , 1) = IDS (NODES_ELEM ( 1) );
                   mesh.QUADS ( mesh.nbQuads , 2) = IDS (NODES_ELEM ( 2) );
                   mesh.QUADS ( mesh.nbQuads , 3) = IDS (NODES_ELEM ( 3) );
                   mesh.QUADS ( mesh.nbQuads , 4) = IDS (NODES_ELEM ( 4) );
                   mesh.QUADS ( mesh.nbQuads , 5) = I;
                end
                if (mesh.ELE_INFOS(I,2) == 4) %% tet
                   mesh.nbTet = mesh.nbTet + 1;
                   mesh.QUADS ( mesh.nbTet , 1) = IDS (NODES_ELEM ( 1) );
                   mesh.QUADS ( mesh.nbTet , 2) = IDS (NODES_ELEM ( 2) );
                   mesh.QUADS ( mesh.nbTet , 3) = IDS (NODES_ELEM ( 3) );
                   mesh.QUADS ( mesh.nbTet , 4) = IDS (NODES_ELEM ( 4) );
                   mesh.QUADS ( mesh.nbTet , 5) = mesh.ELE_INFOS(I,3);
                end

            end
            tline = fgetl(fid);
            disp('elements have been read')
        end
    end
fclose (fid);
