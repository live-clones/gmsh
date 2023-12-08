// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_bbox.h"

/* update the bounding box with an array of n vertices at once (far quicker) */
void hxtBboxAdd(HXTBbox* bbox, double* coord, const uint32_t n){
        double minx = DBL_MAX;
        double miny = DBL_MAX;
        double minz = DBL_MAX;

        double maxx = -DBL_MAX;
        double maxy = -DBL_MAX;
        double maxz = -DBL_MAX;

        #pragma omp parallel for reduction(min:minx,miny,minz) reduction(max:maxx, maxy, maxz)
        for (uint32_t i=0; i<n; i++) {
                if(coord[(size_t) 4*i  ]<minx)
                        minx=coord[(size_t) 4*i  ];
                if(coord[(size_t) 4*i+1]<miny)
                        miny=coord[(size_t) 4*i+1];
                if(coord[(size_t) 4*i+2]<minz)
                        minz=coord[(size_t) 4*i+2];

                if(coord[(size_t) 4*i  ]>maxx)
                        maxx=coord[(size_t) 4*i  ];
                if(coord[(size_t) 4*i+1]>maxy)
                        maxy=coord[(size_t) 4*i+1];
                if(coord[(size_t) 4*i+2]>maxz)
                        maxz=coord[(size_t) 4*i+2];
        }

        bbox->min[0] = minx;
        bbox->min[1] = miny;
        bbox->min[2] = minz;

        bbox->max[0] = maxx;
        bbox->max[1] = maxy;
        bbox->max[2] = maxz;
}


// void hxtBboxMerge(HXTBbox* bbox1, HXTBbox* bbox2, HXTBbox* bboxResult)
// {
//       unsigned i;
//       for (i=0; i<3; i++)
//       {
//               if(bbox1->min[i]<bbox2->min[i])
//                       bboxResult->min[i] = bbox1->min[i];
//               else
//                       bboxResult->min[i] = bbox2->min[i];
//               if(bbox1->max[i]>bbox2->max[i])
//                       bboxResult->max[i] = bbox1->max[i];
//               else
//                       bboxResult->max[i] = bbox2->max[i];
//       }
// }

