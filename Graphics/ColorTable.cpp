/* $Id: ColorTable.cpp,v 1.2 2000-11-23 14:11:32 geuzaine Exp $ */

#include "Gmsh.h"
#include "ColorTable.h"
#include "Context.h"

extern Context_T CTX ;

void color_table_init_param(int number, ColorTable *ct, int rgb_flag, int alpha_flag){

  ct->ipar[COLORTABLE_NUMBER] = number;

  if(rgb_flag) {
    ct->ipar[COLORTABLE_INVERT]   = 0;
    ct->ipar[COLORTABLE_SWAP]     = 0;
    ct->ipar[COLORTABLE_ROTATE]   = 0;

    ct->fpar[COLORTABLE_CURVE]    = 0.0;
    ct->fpar[COLORTABLE_BIAS]     = 0.0;
    ct->fpar[COLORTABLE_BETA]     = 0.0;
  }
  if(alpha_flag) {
    ct->fpar[COLORTABLE_ALPHAPOW] = 2.;
    ct->fpar[COLORTABLE_ALPHAVAL] = 255.;
  }

}

void color_table_recompute(ColorTable *ct, int rgb_flag, int alpha_flag){
  float curve, bias;
  double gamma;
  int i,r,g,b,a,rotate;
  float s,t;
  
  ct->ipar[COLORTABLE_CHANGED] = 1 ;

  bias   = ct->fpar[COLORTABLE_BIAS];
  curve  = ct->fpar[COLORTABLE_CURVE];
  rotate = ct->ipar[COLORTABLE_ROTATE];

  for (i=0 ; i<ct->size ; i++) {
    
    if(i+rotate<0)
      s = (float) (i+rotate+ct->size) / (float) (ct->size-1);
    else if(i+rotate>ct->size-1)
      s = (float) (i+rotate-ct->size) / (float) (ct->size-1);
    else
      s = (float) (i+rotate) / (float) (ct->size-1);

    if(ct->ipar[COLORTABLE_SWAP]) s = 1.0 - s;
    
    if (rgb_flag) {

      switch(ct->ipar[COLORTABLE_NUMBER]){
      case 1 : /* vis5d */
	t = (curve+1.4) * (s - (1.+bias)/2.);
	r = (int)( 128.0 + 127.0 * atan( 7.0*t ) / 1.57  );
	g = (int)( 128.0 + 127.0 * (2 * exp(-7*t*t) - 1) );
	b = (int)( 128.0 + 127.0 * atan( -7.0*t ) / 1.57 );
	break;
      case 2: /* samcef */
	if (s-bias<=0.00){ 
	  r = 0 ; g = 0 ; b = 255 ;
	}
	else if(s-bias<=0.40){
	  r = 0 ; g = (int)((s-bias)*637.5) ; b = (int)(255.-(s-bias)*637.5) ;
	}
	else if(s-bias<=0.60){ 
	  r = (int)(1275.*(s-bias-0.4)) ; g = 255 ; b = 0 ;
	}
	else if(s-bias<=1.00){ 
	  r = 255 ; g = (int)(255.-637.5*(s-bias-0.6)) ; b = 0 ;
	}
	else {
	  r = 255 ; g = 0 ; b = 0 ;
	}
	break;
      case 3: /* rainbow */
	if (s-bias<=0.00) {
	  r = 0 ; g = 0 ; b = 255 ; 
	}
	else if(s-bias<=0.25+curve){ 
	  r = 0 ; g = (int)((s-bias)*(255./(0.25+curve))) ; b = 255 ; 
	}
	else if(s-bias<=0.50) { 
	  r = 0 ; g = 255 ; b = (int)(255.-(255./(0.25-curve))*(s-bias-0.25-curve)); 
	}
	else if(s-bias<=0.75-curve){ 
	  r = (int)((s-bias-0.5)*(255./(0.25-curve))); g = 255 ; b = 0 ; 
	}
	else if(s-bias<=1.00) { 
	  r = 255; g = (int)(255.-(255./(0.25+curve))*(s-bias-0.75+curve)) ; b = 0 ;
	}
	else { 
	  r = 255 ; g = 0 ; b = 0 ; 
	}
	break;
      case 4: /* blue-yellow-white */
#define myfct(a,b,c,d) ((a)+\
			(b)*(s-bias)+\
			(c)*(s-bias)*(s-bias)+\
			(d)*(s-bias)*(s-bias)*(s-bias))
#define clamp(x) x = (x)<0?0:((x)>255?255:(x))
	r = (int)(255. * myfct(-0.0506169, 2.81633, -1.87033, 0.0524573) ); 
	g = (int)(255. * myfct(0.0485868,  -1.26109, 6.3074, -4.12498)   );
	b = (int)(255. * myfct(0.364662,   1.50814, -7.36756, 6.51847 )  );	
	clamp(r); clamp(g); clamp(b);
#undef myfct
#undef clamp
	break;
      case 5: /* grayscale */
	if      (s-bias<=0.00){ r = g = b = 0 ; }
	else if (s-bias<=1.00){ r = g = b = (int)(255*(s-bias)); }
	else                  { r = g = b = 255 ; }
	break;
      case 6: /* monochrome */
	r = g = b = 0 ;
	break;
      default: /* grayscale without white */
	if      (s-bias<=0.00){ r = g = b = 0 ; }
	else if (s-bias<=1.00){ r = g = b = (int)(220*(s-bias)); }
	else                  { r = g = b = 220 ; }
	break;
      }

      if(ct->fpar[COLORTABLE_BETA]){
	if(ct->fpar[COLORTABLE_BETA] > 0.0)
	  gamma = 1. - ct->fpar[COLORTABLE_BETA];
	else
	  gamma = 1./(1.001 + ct->fpar[COLORTABLE_BETA]);
	r = (int)( 255. * pow((double)r/255.,gamma) );
	g = (int)( 255. * pow((double)g/255.,gamma) );
	b = (int)( 255. * pow((double)b/255.,gamma) );
      }

      if(ct->ipar[COLORTABLE_INVERT]){
	r = 255-r ;
	g = 255-g ;
	b = 255-b ;
      }

    }
    else {
      r = UNPACK_RED(   ct->table[i] );
      g = UNPACK_GREEN( ct->table[i] );
      b = UNPACK_BLUE(  ct->table[i] );
    }
    
    if (alpha_flag) {
      if (ct->fpar[COLORTABLE_ALPHAVAL]<0) {
	a = (int)( 255.0 * pow( s, ct->fpar[COLORTABLE_ALPHAPOW] ) );
      }
      else {
	a = (int)( ct->fpar[COLORTABLE_ALPHAVAL] );
      }
    }
    else {
      a = UNPACK_ALPHA( ct->table[i] );
    }
    
    ct->table[i] = PACK_COLOR( r, g, b, a );
  }
  
}


/*
 * File format is ASCII:
 *    $COL
 *    <table_size>
 *    <r> <g> <b> <a>    - n lines of rgba values as integers in [0,255]
 *    .....
 *    <r> <g> <b> <a>
 */
void save_color_table(FILE *fp, ColorTable *ct){
  int i, r, g, b, a;  

  fprintf(fp, "$COL\n");
  fprintf(fp, "%d\n", ct->size);
  for (i=0;i<ct->size;i++) {
    r = UNPACK_RED( ct->table[i] );
    g = UNPACK_GREEN( ct->table[i] );
    b = UNPACK_BLUE( ct->table[i] );
    a = UNPACK_ALPHA( ct->table[i] );
    fprintf(fp, "%d %d %d %d\n", r, g, b, a );
  }
}

void load_color_table(FILE *fp, ColorTable *ct){
  int i, r, g, b, a;
  
  fscanf(fp, "$COL\n");
  fscanf(fp, "%d\n", &ct->size);

  if(ct->size>COLORTABLE_NBMAX_COLOR){
    Msg(ERROR, "Too many colors in ColorTable (%d > %d)", 
	ct->size, COLORTABLE_NBMAX_COLOR);
    return;
  }

  for (i=0;i<ct->size;i++) {
    fscanf(fp, "%d %d %d %d\n", &r, &g, &b, &a);
    ct->table[i] = PACK_COLOR(r, g, b, a);
  }
}

