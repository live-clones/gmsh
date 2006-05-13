function gmesh = load_gmsh ( filename )
   [fid,ierr] = mopen ( filename, 'r');
	if ierr <> 0 then;
  		mclose(fid);
		error('no such file: '+filename)
	end
    gmesh = [];
    gmesh.MIN = zeros(3,1);
    gmesh.MAX = zeros(3,1);

   while 1
        endoffile = 0;

        while (1)
            // jump over irrelevant text
            tline = mgetl(fid,1);
            if meof(fid), endoffile=1,break, end
            if (part(tline,1) == '$'),  break, end  
        end
        if (endoffile == 1), break, end
        if (part(tline,1:4) == '$NOD' | part(tline,1:4) == '$Nod')
            disp('reading nodes')
            gmesh.nbNod = mfscanf (1, fid, '%d');
	         gmesh.POS = zeros (gmesh.nbNod, 3);
            for(I=1:gmesh.nbNod)
                iNod = mfscanf(1,fid,'%d');
                X = mfscanf(3,fid,'%g');
                IDS(iNod) = I;
                if (I == 1)
                    gmesh.MIN = X;
                    gmesh.MAX = X;
                else
                    if (gmesh.MAX(1) < X(1)), gmesh.MAX(1)=X(1);end
                    if (gmesh.MAX(2) < X(2)), gmesh.MAX(2)=X(2);end
                    if (gmesh.MAX(3) < X(3)), gmesh.MAX(3)=X(3);end
                    if (gmesh.MIN(1) > X(1)), gmesh.MIN(1)=X(1);end
                    if (gmesh.MIN(2) > X(2)), gmesh.MIN(2)=X(2);end
                    if (gmesh.MIN(3) > X(3)), gmesh.MIN(3)=X(3);end
                    end
                gmesh.POS(I,1) = X(1);
                gmesh.POS(I,2) = X(2);
                gmesh.POS(I,3) = X(3);
            end
            // Here we have to read two lines, instead of one, in order to continue. 
            // The reason may be due to an unread end-of-line character from the previous
            // scan.
            tline = mgetl(fid,2); // read 2 dummy lines
            disp('nodes have been read')

        elseif(part(tline,1:4)=='$ELM' | part(tline,1:4)=='$Ele')
            disp('reading elements')
            gmesh.nbElm = mfscanf (1,fid, '%d');
            gmesh.ELE_INFOS = zeros (gmesh.nbElm,5);
            gmesh.nbLines = 0;
            gmesh.nbPoints = 0;
            gmesh.nbTriangles = 0;
            gmesh.nbQuads = 0;
            gmesh.nbPrism=0;
            gmesh.nbPyr=0;
            gmesh.nbTet = 0;
            gmesh.nbHex = 0;
            gmesh.nbQTriangles = 0;
            gmesh.nbQQuads = 0;
            gmesh.POINTS=[];
            gmesh.LINES=[];
            gmesh.TRIANGLES=[];
            gmesh.QUADS=[];
            gmesh.TETS=[];
            gmesh.HEXA=[];
            gmesh.PRISM=[];
            gmesh.PYRAMID=[];
            gmesh.QTRIANGLES=[];
            gmesh.QQUADS=[];
            for (I=1:gmesh.nbElm)
                if (part(tline,1:4)=='$Ele')
                   // file is in GMSH version 2.0 format
                   gmesh.ELE_INFOS(I,1:3) = mfscanf(3,fid,'%d')';
                   n_of_tags = gmesh.ELE_INFOS(I,3);
                   gmesh.ELE_INFOS(I,4+(1:n_of_tags)) = mfscanf(n_of_tags,fid,'%d')';
                   // the number of points
                   select gmesh.ELE_INFOS(I,2)
                   case 15 then,  np=1; 
                   case  1 then,  np=2; 
                   case  2 then,  np=3; 
                   case  3 then,  np=4; 
                   case  4 then,  np=4; 
                   case  5 then,  np=8; 
                   case  6 then,  np=6; 
                   case  7 then,  np=5; 
                   case  9 then,  np=6; 
                   case 10 then,  np=9; 
                   end
                   NODES_ELEM = mfscanf(np,fid,'%d')';
                else
                   // version 1.0 format
                   gmesh.ELE_INFOS(I,:) = mfscanf(5,fid,'%d')';
                   NODES_ELEM = mfscanf(gmesh.ELE_INFOS(I,5),fid,'%d')';
                end
                select gmesh.ELE_INFOS(I,2)
                case 15 then  // point
                    gmesh.nbPoints = gmesh.nbPoints + 1;
                    gmesh.POINTS =[gmesh.POINTS; IDS(NODES_ELEM (1))' I];
                case 1 then // beam
                    gmesh.nbLines = gmesh.nbLines + 1;
                    gmesh.LINES =[gmesh.LINES; IDS(NODES_ELEM (1:2))' I];
                case 2 then // triangle
                    gmesh.nbTriangles = gmesh.nbTriangles + 1;
                    gmesh.TRIANGLES = [gmesh.TRIANGLES; IDS(NODES_ELEM (1:3))' I];
                case 3 then // quadrangle
                    gmesh.nbQuads = gmesh.nbQuads + 1;
                    gmesh.QUADS =[gmesh.QUADS; IDS(NODES_ELEM (1:4))' I];
                case 4 then // tetrahedron (4 node)
                    gmesh.nbTet = gmesh.nbTet + 1;
                    gmesh.TETS = [gmesh.TETS; IDS(NODES_ELEM (1:4))' I];
                case 5 then // hexahedron (8 nodes)
                    gmesh.nbHex = gmesh.nbHex + 1;
                    gmesh.HEXA =[gmesh.HEXA; IDS(NODES_ELEM (1:8))' I];
                case 6 then // prism (6 nodes)
                    gmesh.nbPrism = gmesh.nbPrism + 1;
                    gmesh.PRISM =[gmesh.PRISM; IDS(NODES_ELEM (1:6))' I];
                case 7 then // pyramid (5 nodes)
                    gmesh.nbPyr = gmesh.nbPyr + 1;
                    gmesh.PYRAMID =[gmesh.PYRAMID; IDS(NODES_ELEM (1:5))' I];
                case 9 then // second order triangle (6 nodes)
                    gmesh.nbQTriangles = gmesh.nbQTriangles + 1;
                    gmesh.QTRIANGLES = [gmesh.QTRIANGLES; IDS(NODES_ELEM (1:6))' I];
                case 10 then // second order quadrangle (9 nodes)
                    gmesh.nbQQuads = gmesh.nbQQuads + 1;
                    gmesh.QQUADS = [gmesh.QQUADS; IDS(NODES_ELEM (1:9))' I];
                else
                    disp(' ')
                    warning('Unknown element type ' + string(gmesh.ELE_INFOS(I,2)) + ' !')
                end
            end
            disp('elements have been read')
            tline = mgetl(fid,1);
        end  // 
    end  // while
mclose (fid);
endfunction
