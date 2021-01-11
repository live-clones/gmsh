// Bout de code pour calculer l'ordre de convergence 
// des dérivées par différences finies dans l'octree    

    bool computeConvergence = false;
    if(computeConvergence){

      HXT_CHECK(hxtForestDelete(&forest));
      HXT_CHECK(hxtForestOptionsDelete(&forestOptions));

      printf("Convergence des dérivées\n");
      // Compute rtree
      RTree<uint64_t, double, 3> triRTree;
      HXTBbox bbox_triangle;
      for(uint64_t i = 0; i < mesh->triangles.num; ++i){
        hxtBboxInit(&bbox_triangle);
        // Noeuds
        for(uint64_t j = 0; j < 3; ++j){
          double coord[3];
          uint32_t node = mesh->triangles.node[3*i+j];
          // Coordonnees
          for(uint32_t k = 0; k < 3; ++k){ coord[k] = mesh->vertices.coord[(size_t) 4*node+k]; }
          hxtBboxAddOne(&bbox_triangle, coord);
        }
        triRTree.Insert(bbox_triangle.min, bbox_triangle.max, i);
      }

      // Compute bbox of the mesh
      double  bbox_vertices[6];
      HXTBbox bbox_mesh;
      hxtBboxInit(&bbox_mesh);
      // Ajout de tous les points du maillage à la bounding box
      hxtBboxAdd(&bbox_mesh, mesh->vertices.coord, mesh->vertices.num);
      for(int i = 0; i < 3; ++i){
        bbox_vertices[i  ] = bbox_mesh.min[i];
        bbox_vertices[i+3] = bbox_mesh.max[i];
      }

      // if(_hbulk < 0 || _hmin < 0){
          double L = -1.0;
          for(int i = 0; i < 3; ++i)
            L = fmax(L, bbox_mesh.max[i] - bbox_mesh.min[i] );
          _hbulk < 0 ? _hbulk = L/4.   : _hbulk;
          // _hmin  < 0 ? _hmin  = L/1000. : _hmin;
          // Msg::Info("Bulk size is set to %f", _hbulk);
          // Msg::Info("Min  size is set to %f", _hmin);
        // }

      _hmax = 1e22;
      _hmin = 1e-22;
      // _hbulk = 0.25;

      HXT_CHECK(hxtForestOptionsCreate(&forestOptions));
      forestOptions->hmax = _hmax;  
      forestOptions->hmin = _hmin;  
      forestOptions->gradation = _gradation;
      forestOptions->nRefine = _nRefine;
      forestOptions->nodePerTwoPi = _nPointsPerCircle;
      forestOptions->nodePerGap = _nPointsPerGap;
      forestOptions->bbox = bbox_vertices;
      forestOptions->sizeFunction = NULL;
      forestOptions->nodalCurvature = nodalCurvature;
      forestOptions->nodeNormals = NULL;
      forestOptions->triRTree = &triRTree;
      forestOptions->mesh = mesh;

      std::vector<double> errorL2;
      std::vector<double> errorLInf;
      std::vector<double> minSize;
      std::vector<double> maxSize;

      forestOptions->hbulk = _hbulk;  
      HXT_CHECK(hxtForestCreate(0, NULL, &forest, NULL, forestOptions));
      HXT_CHECK(hxtForestRefine(forest));

      for(int i = 0; i < 3; ++i){    
        
        HXT_CHECK(hxtComputeGradientOnce(forest));

        double e, minsize, maxsize;
        HXT_CHECK(hxtL2NormGradient(forest, &e));
        errorL2.push_back(e);
        HXT_CHECK(hxtLInfNormGradient(forest, &e));
        errorLInf.push_back(e);
        HXT_CHECK(hxtGetSmallestCellSize(forest, &minsize));
        HXT_CHECK(hxtGetLargestCellSize(forest, &maxsize));
        minSize.push_back(minsize);
        maxSize.push_back(maxsize);

        // forestFile = GModel::current()->getName() + "_" + std::to_string(i) + ".pos";
        // HXT_CHECK(hxtForestExport(forest, forestFile.c_str()));
        HXT_CHECK(hxtForestRefineOneLevel(forest));

        // _hbulk /= 2.;

      }

      HXT_CHECK(hxtForestDelete(&forest));

      printf("Erreur L2 : \n");
      for(int i = 0; i < errorL2.size(); ++i){
        if(i > 0){
          double p1 = log(errorL2[i-1]/errorL2[i])/log(minSize[i-1]/minSize[i]);
          double p2 = log(errorL2[i-1]/errorL2[i])/log(maxSize[i-1]/maxSize[i]);
          printf("e[%d]/e[%d] = %f\n", i-1, i, errorL2[i-1]/errorL2[i]);
          printf("p1 = %f \t - \t p2 = %f\n", p1, p2);
        }
        printf("errorL2[%d] = %10.12e\n", i, errorL2[i]); 
      }

      printf("Erreur LInf : \n");
      for(int i = 0; i < errorLInf.size(); ++i){
        if(i > 0){
          double p1 = log(errorLInf[i-1]/errorLInf[i])/log(minSize[i-1]/minSize[i]);
          double p2 = log(errorLInf[i-1]/errorLInf[i])/log(maxSize[i-1]/maxSize[i]);
          printf("e[%d]/e[%d] = %f\n", i-1, i, errorLInf[i-1]/errorLInf[i]);
          printf("p1 = %f \t - \t p2 = %f\n", p1, p2);
        }
        printf("errorLInf[%d] = %10.12e\n", i, errorLInf[i]);
      }
    }