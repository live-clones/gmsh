#include "hxt_bbox.h"

// /* create a new bounding box */
// HXTStatus hxtBboxCreate(HXTBbox** bboxP){
//         HXT_CHECK(
//                 hxtMalloc((void **) bboxP, sizeof(HXTBbox)) );

//         unsigned i;
//         for (i=0; i<3; i++)
//         {
//                 (*bboxP)->min[i] = DBL_MAX;
//                 (*bboxP)->max[i] = -DBL_MAX;
//         }

//         return HXT_STATUS_OK;
// }


// HXTStatus hxtBboxDelete(HXTBbox** bboxP){
//         HXT_CHECK(
//                 hxtFree((void **) bboxP) );

//         return HXT_STATUS_OK;
// }


/* update the bounding box with one new vertex */
HXTStatus hxtBboxAddOne(HXTBbox* bbox, double* coord){
        unsigned i;
        for (i=0; i<3; i++)
        {
                if(coord[i]<bbox->min[i])
                        bbox->min[i] = coord[i];
                if(coord[i]>bbox->max[i])
                        bbox->max[i] = coord[i];
        }

        return HXT_STATUS_OK;
}



/* update the bounding box with an array of n vertices at once (far quicker) */
HXTStatus hxtBboxAdd(HXTBbox* bbox, double* coord, const uint32_t n){

        #pragma omp parallel
        {
                hxtDeclareAligned double min[3] = {DBL_MAX, DBL_MAX, DBL_MAX};
                hxtDeclareAligned double max[3] = {-DBL_MAX, -DBL_MAX, -DBL_MAX};

                #pragma omp for nowait
                for (uint32_t i=0; i<n; i++)
                {
                        if(coord[(size_t) 4*i  ]<min[0])
                                min[0]=coord[(size_t) 4*i  ];
                        if(coord[(size_t) 4*i+1]<min[1])
                                min[1]=coord[(size_t) 4*i+1];
                        if(coord[(size_t) 4*i+2]<min[2])
                                min[2]=coord[(size_t) 4*i+2];

                        if(coord[(size_t) 4*i  ]>max[0])
                                max[0]=coord[(size_t) 4*i  ];
                        if(coord[(size_t) 4*i+1]>max[1])
                                max[1]=coord[(size_t) 4*i+1];
                        if(coord[(size_t) 4*i+2]>max[2])
                                max[2]=coord[(size_t) 4*i+2];
                }

                #pragma omp critical
                {
                        #pragma omp simd aligned(min,max:SIMD_ALIGN)
                        for (uint32_t i=0; i<3; i++)
                        {
                                if(min[i]<bbox->min[i])
                                        bbox->min[i] = min[i];
                                if(max[i]>bbox->max[i])
                                        bbox->max[i] = max[i];
                        }
                }
        }

        return HXT_STATUS_OK;
}


HXTStatus hxtBboxMerge(HXTBbox* bbox1, HXTBbox* bbox2, HXTBbox* bboxResult)
{
      unsigned i;
      for (i=0; i<3; i++)
      {
              if(bbox1->min[i]<bbox2->min[i])
                      bboxResult->min[i] = bbox1->min[i];
              else
                      bboxResult->min[i] = bbox2->min[i];
              if(bbox1->max[i]>bbox2->max[i])
                      bboxResult->max[i] = bbox1->max[i];
              else
                      bboxResult->max[i] = bbox2->max[i];
      }

      return HXT_STATUS_OK;
}

