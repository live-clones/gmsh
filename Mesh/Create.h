#ifndef _CREATE_H_
#define _CREATE_H_

int compareNXE (const void *a, const void *b);
int compareFxE (const void *a, const void *b);
int compareSurfaceLoop (const void *a, const void *b);
int compareEdgeLoop (const void *a, const void *b);
int compareHexahedron (const void *a, const void *b);
int comparePrism (const void *a, const void *b);
int comparePyramid (const void *a, const void *b);
int compareQuality (const void *a, const void *b);
int compareCurve (const void *a, const void *b);
int compareAttractor (const void *a, const void *b);
int compareSurface (const void *a, const void *b);
int compareVolume (const void *a, const void *b);
int compareSxF (const void *a, const void *b);

Attractor * Create_Attractor (int Num, double lc1, double lc2, double Radius,
                              Vertex * v, Curve * c, Surface * s);
void Add_SurfaceLoop (int Num, List_T * intlist, Mesh * M);
void Add_PhysicalGroup (int Num, int typ, List_T * intlist, Mesh * M);
void Add_EdgeLoop (int Num, List_T * intlist, Mesh * M);

void End_Curve (Curve * c);
void End_Surface (Surface * s);

Curve *Create_Curve (int Num, int Typ, int Order, List_T * Liste,
                     List_T * Knots, int p1, int p2, double u1, double u2);
void Free_Curve(void *a, void *b);

Surface * Create_Surface (int Num, int Typ, int Mat);
void Free_Surface(void *a, void *b);

Volume * Create_Volume (int Num, int Typ, int Mat);
void Free_Volume(void *a, void *b);

Hexahedron * Create_Hexahedron (Vertex * v1, Vertex * v2, Vertex * v3, Vertex * v4,
                              Vertex * v5, Vertex * v6, Vertex * v7, Vertex * v8);
void Free_Hexahedron(void *a, void *b);

Prism * Create_Prism (Vertex * v1, Vertex * v2, Vertex * v3,
                      Vertex * v4, Vertex * v5, Vertex * v6);
void Free_Prism(void *a, void *b);

Pyramid * Create_Pyramid (Vertex * v1, Vertex * v2, Vertex * v3,
			  Vertex * v4, Vertex * v5);
void Free_Pyramid(void *a, void *b);

#endif
