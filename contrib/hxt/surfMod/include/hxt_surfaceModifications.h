#ifndef HXT_SURFACE_MODIFICATIONS_H
#define HXT_SURFACE_MODIFICATIONS_H

#include "hxt_mesh.h"

typedef struct {
	int x;
	// uint32_t* node;
	// uint32_t* color; // color of the simplex it was inserted into
	// uint8_t* dim; // dimension of the simplex it was inserted into
	// uint32_t num;
	// uint32_t size;
} HXTSurfMod;


void hxt_surfMod_print(HXTSurfMod *mod);

#endif
