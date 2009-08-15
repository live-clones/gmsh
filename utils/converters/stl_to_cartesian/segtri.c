
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "globals.h"
#include "stl.h"
#include "segtri.h"

/*------------Function prototypes. ----------------------------*/
int     StlFindLargestValue(stl_vertex v);
float   StlDot(stl_vertex a, stl_vertex b);
void    StlSubVec(stl_vertex a, stl_vertex b, stl_vertex *c);
char    StlInTri3D(stl_facet T, int m, stl_vertex r );
char    StlInTri2D(stl_vertex Tp[3], stl_vertex pp );
float   StlArea(stl_vertex q, stl_vertex b, stl_vertex c );
char    StlInPlane(stl_facet T, int m, stl_vertex q, stl_vertex r);
char    StlSegTriCross(stl_facet T, stl_vertex q, stl_vertex r );
float   StlVolume(stl_vertex a, stl_vertex b, stl_vertex c, stl_vertex d );
/*-------------------------------------------------------------------*/

/*---------------------------------------------------------------------
    'p': The segment lies wholly within the plane.
    'q': The q endpoint is on the plane (but not 'p').
    'r': The r endpoint is on the plane (but not 'p').
    '0': The segment lies strictly to one side or the other of the plane.
    '1': The segement intersects the plane, and 'p' does not hold.
---------------------------------------------------------------------*/
char StlSegPlaneInt(stl_plane P, stl_vertex q, stl_vertex r, stl_vertex *p, int *m)
{
    
    stl_vertex rq;
    float num, denom, t;
    
    num = P.D - StlDot(q, P.normal);
    
    StlSubVec(r, q, &rq);
    
    denom = StlDot(P.normal, rq);
    
    if ( ABS(denom) < C_EPS ) 
    {  
	/* Segment is parallel to plane. */
	if ( ABS(num) < C_EPS)   
	{
	    /* q is on plane. */
	    *m = StlFindLargestValue(P.normal);
	    return 'p';
	}
	else
	    return '0';
    }
    else
	t = num / denom;
    
    if (t < -C_EPS || t > 1 + C_EPS)
	return '0';
    
    if ( (C_EPS < t) && (t < 1 - C_EPS) )
    {
	*m = StlFindLargestValue(P.normal);
	p->x = q.x + t * (r.x - q.x);
	p->y = q.y + t * (r.y - q.y);
	p->z = q.z + t * (r.z - q.z);
	
	return '1';
    }
    else if ( t <= C_EPS ) /* t == 0 */
    {
	*m = StlFindLargestValue(P.normal);
	return 'q';
    }
    else if ( t >= 1 - C_EPS ) /* t == 1 */
    {
	*m = StlFindLargestValue(P.normal);
	return 'r';
    }
    
    return '0';
    
}

int StlFindLargestValue(stl_vertex nv)
{
    
    int m;
    int j;
    float tcur;			  /*temporary storage */
    float biggest = 0;    /* Largest component of normal vector. */
    float v[3];
    
    v[0] = nv.x;
    v[1] = nv.y;
    v[2] = nv.z;
    
    for (j = 0; j < 3; j++)
    {
	tcur = ABS(v[j]);
	
	if ( tcur > biggest) 
	{
	    biggest = tcur;
	    m = j;
	}
    }
    
    return m;
    
}

/*---------------------------------------------------------------------
a - b ==> c.
---------------------------------------------------------------------*/
void StlSubVec(stl_vertex a, stl_vertex b, stl_vertex *c)
{
    
    c->x = a.x - b.x;
    c->y = a.y - b.y;
    c->z = a.z - b.z;
    
}

/*---------------------------------------------------------------------
Returns the dot product of the two input vectors.
---------------------------------------------------------------------*/
float StlDot(stl_vertex a, stl_vertex b)
{
    
    float sum = 0;
    
    sum = a.x * b.x + a.y * b.y + a.z * b.z;
    
    return  sum;
    
}

/* Assumption: p lies in the plane containing T.
    Returns a char:
     'V': the query point p coincides with a Vertex of triangle T.
     'E': the query point p is in the relative interior of an Edge of triangle T.
     'F': the query point p is in the relative interior of a Face of triangle T.
     '0': the query point p does not intersect (misses) triangle T.
*/

char StlInTri3D( stl_facet T, int m, stl_vertex r )
{
    
    int j;  
    
    stl_vertex pp;      /* projected p */
    stl_vertex Tp[3];   /* projected T: three new vertices */
    
    /* Project out coordinate m in both p and the triangular face */
    
    for ( j = 0; j < 3; j++ ) 
    {
	if ( m == 0 )
	{
	    pp.x = r.y;
	    pp.y = r.z;
	    
	    Tp[j].x = T.vertex[j].y;
	    Tp[j].y = T.vertex[j].z;
	}
	
	if ( m == 1 )
	{
	    pp.x = r.x;
	    pp.y = r.z;
	    
	    Tp[j].x = T.vertex[j].x;
	    Tp[j].y = T.vertex[j].z;
	}
	
	if ( m == 2 )
	{
	    pp.x = r.x;
	    pp.y = r.y;
	    
	    Tp[j].x = T.vertex[j].x;
	    Tp[j].y = T.vertex[j].y;
	}
	
    }
    
    return (StlInTri2D(Tp, pp));
}

char StlInTri2D(stl_vertex Tp[3], stl_vertex pp )
{
    
    float area0, area1, area2;
    
    /* compute three AreaSign() values for pp w.r.t. each edge of the face in 2D */
    area0 = StlArea( pp, Tp[0], Tp[1] );
    area1 = StlArea( pp, Tp[1], Tp[2] );
    area2 = StlArea( pp, Tp[2], Tp[0] );
    
    if ( ( ABS(area0) < C_EPS ) && ( area1 > 0 ) && ( area2 > 0 ) ||
	 ( ABS(area1) < C_EPS ) && ( area0 > 0 ) && ( area2 > 0 ) ||
	 ( ABS(area2) < C_EPS ) && ( area0 > 0 ) && ( area1 > 0 ) ) 
	return 'E';
    
    if ( ( ABS(area0) < C_EPS ) && ( area1 < 0 ) && ( area2 < 0 ) ||
	 ( ABS(area1) < C_EPS ) && ( area0 < 0 ) && ( area2 < 0 ) ||
	 ( ABS(area2) < C_EPS ) && ( area0 < 0 ) && ( area1 < 0 ) ) 
	return 'E';
    
    if ( ( area0 >  0 ) && ( area1 > 0 ) && ( area2 > 0 ) ||
	 ( area0 <  0 ) && ( area1 < 0 ) && ( area2 < 0 ) )
	return 'F';
    
    if ( ( ABS(area0) < C_EPS ) && ( ABS(area1) < C_EPS ) ||
	 ( ABS(area0) < C_EPS ) && ( ABS(area2) < C_EPS ) ||
	 ( ABS(area1) < C_EPS ) && ( ABS(area2) < C_EPS ) )
	return 'V';
    
    return '0';  
}

float StlArea( stl_vertex a, stl_vertex b, stl_vertex c )  
{
    
    float area2;
    
    area2 = ( b.x - a.x ) * ( c.y - a.y ) -
	    ( c.x - a.x ) * ( b.y - a.y );
    
    return area2;
    
}                            

char StlTriPlaneCross(stl_facet T, stl_plane P, int *v)
{
    
    int code = '?';
    float d0, d1, d2;
    
    d0 = T.vertex[0].x * P.normal.x +
	 T.vertex[0].y * P.normal.y +
	 T.vertex[0].z * P.normal.z - P.D;
    
    d1 = T.vertex[1].x * P.normal.x +
	 T.vertex[1].y * P.normal.y +
	 T.vertex[1].z * P.normal.z - P.D;
    
    d2 = T.vertex[2].x * P.normal.x +
	 T.vertex[2].y * P.normal.y +
	 T.vertex[2].z * P.normal.z - P.D;
    
    if ((d0 > 0) && (d1 > 0) && (d2 > 0) ||
	(d0 < 0) && (d1 < 0) && (d2 < 0))
	return '0';
    
    // The triangle is completly on the plane
    // This will result in bad contours.
    // Another section should be chosen.
    if (d0 == 0 && d1 == 0 && d2 == 0)
    {
	return '?';
    }
    
    if (d0 == 0 && d1 == 0)
    {
	*v = 2;
	return '1';
    }
    
    if (d0 == 0 && d2 == 0)
    {
	*v = 1;
	return '1';
    }
    
    if (d1 == 0 && d2 == 0)
    {
	*v = 2;
	return '1';
    }
    
    if ((d0 <= 0) && (d1 > 0) && (d2 > 0) ||
	(d0 >= 0) && (d1 < 0) && (d2 < 0))
    {
	*v = 0;
	return '1';
    }
    
    if ((d0 > 0) && (d1 <= 0) && (d2 > 0) ||
	(d0 < 0) && (d1 >= 0) && (d2 < 0))
    {
	*v = 1;
	return '1';
    }
    
    if ((d0 > 0) && (d1 > 0) && (d2 <= 0) ||
	(d0 < 0) && (d1 < 0) && (d2 >= 0))
    {
	*v = 2;
	return '1';
    }
    
    return code;
}

char StlTriTriCross(stl_facet T0, stl_facet T1)
{
    
    int code = '?';
    float vol0, vol1, vol2;
    
    vol0 = StlVolume(T0.vertex[0], T0.vertex[1], T0.vertex[2], T1.vertex[0]); 
    vol1 = StlVolume(T0.vertex[0], T0.vertex[1], T0.vertex[2], T1.vertex[1]); 
    vol2 = StlVolume(T0.vertex[0], T0.vertex[1], T0.vertex[2], T1.vertex[2]); 
    
    /* Opposite sign: no intersection between triangle 1 and triangle 2 */
    if ( ( ( vol0 > 0 ) && ( vol1 > 0 ) && ( vol2 > 0 ) ) ||
	 ( ( vol0 < 0 ) && ( vol1 < 0 ) && ( vol2 < 0 ) ) )
	return '0';
    
    return code;
    
}

char StlSegTriInt(stl_facet T, stl_vertex q, stl_vertex r)
{
    
    int code = '?';
    int m = -1;
    stl_vertex p;
    stl_plane P;
    
    P.D = StlDot(T.vertex[0], T.normal);
    P.normal = T.normal;
    
    code = StlSegPlaneInt(P, q, r, &p, &m );
    
    if      ( code == '0')
	return '0';
    else if ( code == 'q')
	return StlInTri3D( T, m, q );
    else if ( code == 'r')
	return StlInTri3D( T, m, r );
    else if ( code == 'p' )
	return 'p';
    else if ( code == '1' )
	return StlSegTriCross( T, q, r );
    else
	return code;
    
}

/*---------------------------------------------------------------------
The signed volumes of three tetrahedra are computed, determined
by the segment qr, and each edge of the triangle.  
Returns a char:
   'v': the open segment includes a vertex of T.
   'e': the open segment includes a point in the relative interior of an edge
   of T.
   'f': the open segment includes a point in the relative interior of a face
   of T.
   '0': the open segment does not intersect triangle T.
---------------------------------------------------------------------*/

char StlSegTriCross(stl_facet T, stl_vertex q, stl_vertex r)
{
    
    float vol0, vol1, vol2;
    
    vol0 = StlVolume( q, T.vertex[0], T.vertex[1], r ); 
    vol1 = StlVolume( q, T.vertex[1], T.vertex[2], r ); 
    vol2 = StlVolume( q, T.vertex[2], T.vertex[0], r );
    
    /* Same sign: segment intersects interior of triangle. */
    if ( ( ( vol0 >  C_EPS ) && ( vol1 >  C_EPS ) && ( vol2 >  C_EPS ) ) || 
	 ( ( vol0 < -C_EPS ) && ( vol1 < -C_EPS ) && ( vol2 < -C_EPS ) ) )
	return 'f';
    
    /* Opposite sign: no intersection between segment and triangle */
    if ( ( ( vol0 > 0 ) || ( vol1 > 0 ) || ( vol2 > 0 ) ) &&
	 ( ( vol0 < 0 ) || ( vol1 < 0 ) || ( vol2 < 0 ) ) )
	return '0';
    
    /* Two zeros: segment intersects vertex. */
    else if ( ( ( ABS(vol0) < C_EPS ) && ( ABS(vol1) < C_EPS ) ) || 
	      ( ( ABS(vol0) < C_EPS ) && ( ABS(vol2) < C_EPS ) ) || 
	      ( ( ABS(vol1) < C_EPS ) && ( ABS(vol2) < C_EPS ) ) )
	return 'v';
    
    /* One zero: segment intersects edge. */
    else if ( ( ABS(vol0) < C_EPS ) || ( ABS(vol1) < C_EPS ) || ( ABS(vol2) < C_EPS ) )
	return 'e';
    else
	return '0';
    
}

float StlVolume( stl_vertex a, stl_vertex b, stl_vertex c, stl_vertex d )
{ 
    
    float vol;
    float bxdx, bydy, bzdz, cxdx, cydy, czdz;
    
    bxdx = b.x - d.x;
    bydy = b.y - d.y;
    bzdz = b.z - d.z;
    
    cxdx = c.x - d.x;
    cydy = c.y - d.y;
    czdz = c.z - d.z;
    
    vol =   (a.z - d.z) * (bxdx * cydy - bydy * cxdx)
	    + (a.y - d.y) * (bzdz * cxdx - bxdx * czdz)
	    + (a.x - d.x) * (bydy * czdz - bzdz * cydy);
    
    return vol;
    
}
