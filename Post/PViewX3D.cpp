// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// PViewX3D is a extension for Post-processing outputs :
// creates a file in X3D format with the same features as
// what is visible in post-processing screen.
// contact : gilles.marckmann@ec-nantes.fr

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "PViewDataList.h"
#include "PViewDataGModel.h"
#include "VertexArray.h"
#include "StringUtils.h"
#include "Context.h"
#include "OS.h"
#include <ctime>
#include "SBoundingBox3d.h"
#include <math.h>     
#include "PViewX3D.h"

bool PView::writeX3D(const std::string &fileName )
{
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );

  FILE *fp = Fopen(fileName.c_str(), "w");
  if(!fp){
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return false;
  }

  // x3 Header ---------------------------------------------------------------------------
  fprintf(fp,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
  fprintf(fp,"<!DOCTYPE X3D PUBLIC \"ISO//Web3D//DTD X3D 3.3//EN\" \"http://www.web3d.org/specifications/x3d-3.3.dtd\">\n");
  fprintf(fp,"<X3D profile='Interchange' version='3.3'  xmlns:xsd='http://www.w3.org/2001/XMLSchema-instance' >\n"); 
  fprintf(fp,"<head>\n");
  fprintf(fp,"   <meta name='title' content='PView'/> \n");
  fprintf(fp,"   <meta name='description' content='%s'/>\n", fileName.c_str());
  fprintf(fp,"   <meta name='creator' content='gmsh'/> \n");
  fprintf(fp,"   <meta name='created' content='%s'/>\n", asctime(timeinfo) );
  fprintf(fp,"</head>\n");
  // Viewport ---------------------------------------------------------------------------
  SBoundingBox3d bb(0.,0.,0.,0.,0.,0.);
  for(std::vector<PView*>::iterator pvit=PView::list.begin() ; pvit < PView::list.end(); pvit++){
    PViewData *data = (*pvit)->getData(true);
    PViewOptions *opt = (*pvit)->getOptions();
    if( !data->getDirty() && opt->visible ) {
      bb+= data->getBoundingBox(opt->timeStep);
    }
  }
  SPoint3 _center = bb.center();
  double _diagonal = bb.diag();
  fprintf(fp,"<Scene>\n");
  fprintf(fp,"<Viewpoint description='Book View' orientation='0 0. 1. 0.' position='%g %g %g'/> \n",
	  _center.x(), _center.y() , _center.z()+_diagonal*1.2  );
  fprintf(fp,"<Background skyColor='.7 .7 1'/> \n");
  //****************
  // HUD : Head Up Display
  fprintf(fp,"<ProtoDeclare appinfo='Heads-up display (HUD)' name='HeadsUpDisplay'> \n");
  fprintf(fp,"      <ProtoInterface> \n");
  fprintf(fp,"        <field accessType='inputOutput' appinfo='offset position for HUD' name='screenOffset' type='SFVec3f' value='%g %g %g'/> \n",  _center.x(), _center.y() , 5*_center.z()+_diagonal*1.2 ); 
  fprintf(fp,"        <field accessType='inputOutput' appinfo='X3D content positioned at HUD offset' name='children' type='MFNode'>   \n");
  fprintf(fp,"        </field>  \n");
  fprintf(fp,"        <field accessType='outputOnly' appinfo='HUD position update (in world coordinates) relative to original location' name='position_changed' type='SFVec3f'/>   \n");
  fprintf(fp,"        <field accessType='outputOnly' appinfo='HUD orientation update relative to original location' name='orientation_changed' type='SFRotation'/> \n");
  fprintf(fp,"      </ProtoInterface> \n");
  fprintf(fp,"      <ProtoBody> \n");
  fprintf(fp,"        <Group bboxCenter=\"%g %g %g\"> \n",  _center.x(), _center.y() , _center.z() );
  fprintf(fp,"          <Transform DEF='HudContainer'> \n");
  fprintf(fp,"            <Transform> \n");
  fprintf(fp,"              <IS> \n");
  fprintf(fp,"                <connect nodeField='translation' protoField='screenOffset'/> \n");
  fprintf(fp,"              </IS> \n");
  fprintf(fp,"              <Group> \n");
  fprintf(fp,"                <IS> \n");
  fprintf(fp,"                  <connect nodeField='children' protoField='children'/> \n");
  fprintf(fp,"                </IS> \n");
  fprintf(fp,"              </Group> \n");
  fprintf(fp,"            </Transform> \n");
  fprintf(fp,"          </Transform> \n");
  fprintf(fp,"          <ProximitySensor DEF='HereIAm' size='10000000 10000000 10000000'> \n");
  fprintf(fp,"            <IS> \n");
  fprintf(fp,"              <connect nodeField='position_changed' protoField='position_changed'/> \n");
  fprintf(fp,"              <connect nodeField='orientation_changed' protoField='orientation_changed'/> \n");
  fprintf(fp,"            </IS> \n");
  fprintf(fp,"          </ProximitySensor> \n");
  fprintf(fp,"          <ROUTE fromField='orientation_changed' fromNode='HereIAm' toField='rotation' toNode='HudContainer'/> \n");
  fprintf(fp,"          <ROUTE fromField='position_changed' fromNode='HereIAm' toField='translation' toNode='HudContainer'/> \n");
  fprintf(fp,"        </Group> \n");
  fprintf(fp,"      </ProtoBody> \n");
  fprintf(fp,"    </ProtoDeclare>  \n");
  fprintf(fp,"   <Background skyColor='.7 .7 1'/>  \n");
  fprintf(fp,"    <Viewpoint description='Book View' orientation='0 0. 1. 0.' position='%g %g %g'/> \n",  _center.x(), _center.y() , _center.z()+_diagonal*1.2  ); 
  fprintf(fp,"    <!-- ProtoDeclare is the \"cookie cutter\" template, ProtoInstance creates an actual occurrence --> \n");
  fprintf(fp,"    <ProtoInstance DEF='HeadsUpDisplay' name='HeadsUpDisplay'> \n");
  fprintf(fp,"      <!-- example: upper left-hand corner of screen (x=-2, y=1) and set back z=-5 from user view --> \n");
  fprintf(fp,"      <fieldValue name='screenOffset' value='%g %g %g'/> \n",  _center.x(),  _center.y() ,  _center.z()-.2*_diagonal );
  fprintf(fp,"      <fieldValue name='children'> \n");
  /*---------------------------------------------------------
  fprintf(fp,"        <Shape> \n");
  fprintf(fp,"            <Text string='\"HUD : place for legend\" \"stay fixed while user navigates\"'> \n");
  fprintf(fp,"            <FontStyle justify='\"MIDDLE\" \"MIDDLE\"' size='0.02'/> \n");
  fprintf(fp,"          </Text> \n");
  fprintf(fp,"          <Appearance> \n");
  fprintf(fp,"            <Material diffuseColor='0. 0. 0.'/> \n");
  fprintf(fp,"          </Appearance> \n");
  fprintf(fp,"        </Shape> \n");
  ------------------------------------------------------------*/

  // here contour legends in frame (-.45,-.28, 0.) and (.45, .28,0.) : viewport .9 x .56

  std::vector<PView*> scales;
  for(unsigned int i = 0; i < PView::list.size(); i++){
    PViewData *data = PView::list[i]->getData();
    PViewOptions *opt = PView::list[i]->getOptions();
    if(!data->getDirty() 
       && opt->visible && opt->showScale 
       &&  opt->type == PViewOptions::Plot3D && data->getNumElements() 
       &&  PView::list[i]->_ctx->isVisible(PView::list[i])
       )
      scales.push_back(PView::list[i]);
  }
  if(!scales.empty()) {
   char label[1024];
    double maxw = 0.;
    for(unsigned int i = 0; i < scales.size(); i++) {
      PViewOptions *opt = scales[i]->getOptions();
      sprintf(label, opt->format.c_str(), -M_PI * 1.e-4);
      maxw = std::max(maxw, drawContext::global()->getStringWidth(label));
    }

    const  double tic = 10., bar_size = 16.;    double width = 0., width_prev = 0., width_total = 0.;

    for(unsigned int i = 0; i < scales.size(); i++) {
      PView *p = scales[i];
      PViewData *data = p->getData();
      PViewOptions *opt = p->getOptions();
      double vph =  p->_ctx->viewport[3] - p->_ctx->viewport[1];
      double vpw =  p->_ctx->viewport[2] - p->_ctx->viewport[0];
      double xfactor = .9 /vpw;
      double yfactor = .56/vph;
      double ratio =2.*min(xfactor,yfactor);
 
      if(!opt->autoPosition) {
	double w = opt->size[0], h = opt->size[1];
	double x = opt->position[0], y = opt->position[1] - h;
	int c = p->_ctx->fix2dCoordinates(&x, &y);
	if(c & 1) x -= w ;
	if(c & 2) y += h / 2.;

	x -=vpw/2.;	y -=vph/2.;
	writeX3DScale(fp, p, x*xfactor, y*yfactor, w*xfactor, h*yfactor, tic*yfactor/2, CTX::instance()->post.horizontalScales,ratio);
      }
      else if(CTX::instance()->post.horizontalScales){
	double ysep = 20.;
	double xc = ( p->_ctx->viewport[2] -  p->_ctx->viewport[0]) / 2.;
	if(scales.size() == 1){
	  double w = ( p->_ctx->viewport[2] -  p->_ctx->viewport[0]) / 2., h = bar_size;
	  double x = xc - w / 2., y =  p->_ctx->viewport[1] + ysep;

	x -=vpw/2.;	y -=vph/2.;
	writeX3DScale(fp, p, x*xfactor, y*yfactor, w*xfactor, h*yfactor, tic*yfactor/2, 1,ratio);
	}
	else{
	  double xsep = maxw / 4. + ( p->_ctx->viewport[2] -  p->_ctx->viewport[0]) / 10.;
	  double w = ( p->_ctx->viewport[2] -  p->_ctx->viewport[0] - 4 * xsep) / 2.;
	  if(w < 20.) w = 20.;
	  double h = bar_size;
	  double x = xc - (i % 2 ? -xsep / 1.5 : w + xsep / 1.5);
	  double y =  p->_ctx->viewport[1] + ysep +
	    (i / 2) * (bar_size + tic +2 * drawContext::global()->getStringHeight() + ysep);

	x -=vpw/2.;	y -=vph/2.;
	  writeX3DScale(fp, p, x*xfactor, y*yfactor, w*xfactor, h*yfactor, tic*yfactor/2, 1,ratio);
	}
      }
      else{
	double xsep = 20.;
	double dy = 2. * drawContext::global()->getStringHeight();
	if(scales.size() == 1){
	  double ysep = ( p->_ctx->viewport[3] -  p->_ctx->viewport[1]) / 6.;
	  double w = bar_size, h =  p->_ctx->viewport[3] -  p->_ctx->viewport[1] - 2 * ysep - dy;
	  double x =  p->_ctx->viewport[0] + xsep, y =  p->_ctx->viewport[1] + ysep + dy;

	x -=vpw/2.;	y -=vph/2.;
	    writeX3DScale(fp, p, x*xfactor, y*yfactor, w*xfactor, h*yfactor, tic*yfactor/2, 1,ratio);

	}
	else{
	  double ysep = ( p->_ctx->viewport[3] -  p->_ctx->viewport[1]) / 15.;
	  double w = bar_size;
	  double h = ( p->_ctx->viewport[3] -  p->_ctx->viewport[1] - 3 * ysep - 2.5 * dy) / 2.;
	  double x =  p->_ctx->viewport[0] + xsep + width_total + (i / 2) * xsep;
	  double y =  p->_ctx->viewport[1] + ysep + dy + (1 - i % 2) * (h + 1.5 * dy + ysep);

	x -=vpw/2.;	y -=vph/2.;
	  writeX3DScale(fp, p, x*xfactor, y*yfactor, w*xfactor, h*yfactor, tic*yfactor/2, 1,ratio);

	}
	// compute width
	width_prev = width;
	sprintf(label, opt->format.c_str(), -M_PI * 1.e-4);
	width = bar_size + tic + drawContext::global()->getStringWidth(label);
	if(opt->showTime){
	  char tmp[256];
	  sprintf(tmp, opt->format.c_str(), data->getTime(opt->timeStep));
	  sprintf(label, "%s (%s)", data->getName().c_str(), tmp);
	}
	else
	  sprintf(label, "%s", data->getName().c_str());
	width = std::max(width, drawContext::global()->getStringWidth(label));
	if(i % 2) width_total += std::max(bar_size + width, bar_size + width_prev);
      }
    }
  }

  // end of contour legend
  // frame to visualize HUD if necessary----------------------------------------
  /*
  fprintf(fp,"        <Shape>\n");
  fprintf(fp,"            <IndexedFaceSet solid=\"false\" colorPerVertex=\"true\" coordIndex=\"0 1 2 3 -1\">\n");
  fprintf(fp,"              <Coordinate point= \"  -.45 -.28 0.      .45 -.28 0.      .45 .28 0.      -.45 .28 0. \" />\n");
  fprintf(fp,"              <Color color= \"0 0 0, 0 0 0, 1 1 1, 1 1 1\" /> \n");
  fprintf(fp,"            </IndexedFaceSet>\n");
  fprintf(fp,"            <Appearance> \n");
  fprintf(fp,"              <Material  transparency='0.75' /> \n");
  fprintf(fp,"            </Appearance> \n");
  fprintf(fp,"        </Shape>");
  */
  //-----------------------------------------------------------------------------
  fprintf(fp,"      </fieldValue> \n");
  fprintf(fp,"    </ProtoInstance> \n");
 

  // geometrical objects
  for(std::vector<PView*>::iterator pvit=PView::list.begin() ; pvit < PView::list.end(); pvit++){
    PViewData *data = (*pvit)->getData(true);
    PViewOptions *opt = (*pvit)->getOptions();
    if( !data->getDirty() && opt->visible ) {
      VertexArray *va;
      // points ------------------------NOT TREATED YET-------------------------------
      va=(*pvit)->va_points;
      for(int ipt = 0; ipt < va->getNumVertices(); ipt++){
	float *p = va->getVertexArray(3 * ipt);
	// glColor4ubv((GLubyte *)va_points->getColorArray(4 * ipt));
	double f = 1.;
	if(opt->pointType > 1){
	  char *n = va->getNormalArray(3 * ipt);
	  f = char2float(*n);
	}
	if(opt->pointType == 2){
	  int s = (int)(opt->pointSize * f);
	  if(s){
	    fprintf(fp,"points : %g %g %g\n", p[0], p[1], p[2]);
	  }
	}
	else
	  fprintf(fp,"sphere : %g %g %g \n", p[0], p[1], p[2] );
      }


      // lines -----------------------------------------------------------------------
      va=(*pvit)->va_lines;
      fprintf(fp,"<Shape> \n");
      fprintf(fp,"   <IndexedLineSet coordIndex=' ");
      for(int ipt = 0; ipt < va->getNumVertices(); ipt += 2){
	if(opt->lineType != 2 && opt->lineType != 1) {  
	  fprintf(fp,"%i %i %i ",ipt,ipt+1,-1);
	}
      }
      fprintf(fp,"'> \n");
      fprintf(fp,"   <Coordinate DEF='TurnPoints' point=' ");
      for(int ipt = 0; ipt < va->getNumVertices(); ipt += 2){
	if(opt->lineType != 2 && opt->lineType != 1) {  
	  float *p0 = va->getVertexArray(3 * ipt);
	  float *p1 = va->getVertexArray(3 * (ipt + 1));
	  fprintf(fp,"%g %g %g %g %g %g ",  p0[0], p0[1], p0[2], p1[0], p1[1], p1[2]); 
	}
      }
      fprintf(fp,"'/>\n");
      fprintf(fp,"   </IndexedLineSet> \n");
      fprintf(fp,"   <Appearance> \n");
      fprintf(fp,"      <Material emissiveColor='0 0 0'/>\n"); 
      fprintf(fp,"      <LineProperties containerField='lineProperties'> \n");
      fprintf(fp,"      </LineProperties> \n");
      fprintf(fp,"   </Appearance> \n");
      fprintf(fp,"</Shape>\n");


      //vectors --------------------colored arrow replaced by colored cones-------------------
      va=(*pvit)->va_vectors;

      for(int i = 0; i < va->getNumVertices(); i += 2){
	float *s = va->getVertexArray(3 * i);
	float *v = va->getVertexArray(3 * (i + 1));
	unsigned char *c = va->getColorArray(4 * i);
	double rgba[4];
	UnsignedChar2rgba(c,rgba) ;    
	double l = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	double lmax = opt->tmpMax;
	if((l || opt->vectorType == 6) && lmax){
	  double scale=.5/_diagonal;
	  double theta=acos(v[1]/l); 
	  fprintf(fp,"<Transform rotation='%g %g %g %g' translation='%e %e %e' >\n"
		  ,v[2],0.,-v[0],theta
		  ,s[0]+.5*scale*v[0],s[1]+.5*scale*v[1],s[2]+.5*scale*v[2]);
	  fprintf(fp,"<Shape>\n");
	  fprintf(fp,"   <Cone bottomRadius='%g' height='%g'/>\n",
		  .05*l*scale,
		  l*scale);
	  fprintf(fp,"           <Appearance>\n");
	  fprintf(fp,"             <Material diffuseColor='%g %g %g'/>\n",rgba[0], rgba[1], rgba[2]);
	  fprintf(fp,"           </Appearance>\n");
	  fprintf(fp,"</Shape>\n");
	  fprintf(fp,"</Transform>\n");
	}
      }
  
       //triangles --------------------------colored triangles -------------------------------
      va=(*pvit)->va_triangles;

      fprintf(fp,"<Transform> \n");
      fprintf(fp,"<Shape> \n");
      fprintf(fp,"   <IndexedTriangleSet index=' ");
      for(int ipt = 0; ipt < va->getNumVertices(); ipt += 3){  
	fprintf(fp,"%i %i %i ",ipt,ipt+1,ipt+2);  
      }
      fprintf(fp,"   ' solid='false' ccw='true' colorPerVertex='true' normalPerVertex='true' containerField='geometry'> \n");
      fprintf(fp,"      <Coordinate point='");
      for(int ipt = 0; ipt < va->getNumVertices(); ipt += 3){
	float *p0 = va->getVertexArray(3 * ipt);
	float *p1 = va->getVertexArray(3 * (ipt + 1));
	float *p2 = va->getVertexArray(3 * (ipt + 2));
	fprintf(fp,"%e %e %e %e %e %e %e %e %e " 
		, p0[0], p0[1], p0[2]
		, p1[0], p1[1], p1[2]
		, p2[0], p2[1], p2[2]);
      }
      fprintf(fp,"      '/> \n");
      fprintf(fp,"      <Color color='");
      for(int ipt = 0; ipt < va->getNumVertices(); ipt += 3){
	unsigned char *c0 = va->getColorArray(4 * ipt);
	unsigned char *c1 = va->getColorArray(4 * (ipt+1));
	unsigned char *c2 = va->getColorArray(4 * (ipt+2));
	double rgba0[4] , rgba1[4] ,rgba2[4];
	UnsignedChar2rgba(c0,rgba0) ;    
	UnsignedChar2rgba(c1,rgba1) ;    
	UnsignedChar2rgba(c2,rgba2) ;    
	fprintf(fp,"%g %g %g %g %g %g %g %g %g " 
		, rgba0[0],rgba0[1],rgba0[2]
		, rgba1[0],rgba1[1],rgba1[2]
		, rgba2[0],rgba2[1],rgba2[2]);
      }
      fprintf(fp,"      '/>\n"); 
      fprintf(fp,"   </IndexedTriangleSet> \n");
      fprintf(fp,"</Shape> \n");
      fprintf(fp,"</Transform> \n");


    }
  }// end loop of pvit

  fprintf(fp,"</Scene>\n");
  fprintf(fp,"</X3D>\n");
  fclose(fp);
  return true;

}



static void writeX3DScale(FILE *fp, PView *p, double xmin, double ymin,
			  double width, double height, double tic, int horizontal,double ratio)
{
  // use adaptive data if available
  PViewData *data = p->getData(true);
  PViewOptions *opt = p->getOptions();

  if(opt->externalViewIndex >= 0){
    opt->tmpMin = opt->externalMin;
    opt->tmpMax = opt->externalMax;
  }
  else if(opt->rangeType == PViewOptions::Custom){
    opt->tmpMin = opt->customMin;
    opt->tmpMax = opt->customMax;
  }
  else if(opt->rangeType == PViewOptions::PerTimeStep){
    opt->tmpMin = data->getMin(opt->timeStep);
    opt->tmpMax = data->getMax(opt->timeStep);
  }
  else{
    opt->tmpMin = data->getMin();
    opt->tmpMax = data->getMax();
  }

  writeX3DScaleBar(fp, p, xmin, ymin, width, height, tic, horizontal);
  writeX3DScaleValues(fp, p, xmin, ymin, width, height, tic, horizontal,ratio);
  writeX3DScaleLabel (fp, p, xmin, ymin, width, height, tic, horizontal,ratio);
}


static void writeX3DScaleBar(FILE *fp, PView *p, double xmin, double ymin, double width,
			     double height, double tic, int horizontal)
{
  PViewOptions *opt = p->getOptions();
  double box = (horizontal ? width : height) / (opt->nbIso ? opt->nbIso : 1);

  for(int i = 0; i < opt->nbIso; i++) {
    if(opt->intervalsType == PViewOptions::Continuous 
       || opt->intervalsType == PViewOptions::Discrete 
       || opt->intervalsType == PViewOptions::Numeric){
      fprintf(fp,"        <Shape> \n");
      fprintf(fp,"           <IndexedFaceSet colorPerVertex='true' normalPerVertex='true' coordIndex='0 1 2 3 -1' solid='false' ccw='true' > \n");
      fprintf(fp,"              <Coordinate point='");
      if(horizontal){
	fprintf(fp,"%e %e %e %e %e %e %e %e %e %e %e %e " 
		,xmin + i * box      , ymin, 0.
		,xmin + (i + 1) * box, ymin, 0.
		,xmin + (i + 1) * box, ymin + height, 0.
		,xmin + i * box      , ymin + height, 0.);
      }
      else{
	fprintf(fp,"%e %e %e %e %e %e %e %e %e %e %e %e " 
		,xmin, ymin + i * box, 0.
		,xmin + width, ymin + i * box, 0.
		,xmin + width, ymin + (i + 1) * box, 0.
		,xmin, ymin + (i + 1) * box, 0.);
      }
      fprintf(fp,"      '/> \n");
    
      if(opt->intervalsType == PViewOptions::Discrete 
	 || opt->intervalsType == PViewOptions::Numeric){
	double rgba[4]= { .5,.5,.5,1. };
	unsigned int col = opt->getColor(i, opt->nbIso);
	unsignedInt2RGBA(col,rgba[0],rgba[1],rgba[2],rgba[3]);
	fprintf(fp,"              <Color color=' %g %g %g  %g %g %g  %g %g %g  %g %g %g '/>\n"
		, rgba[0],rgba[1],rgba[2], rgba[0],rgba[1],rgba[2], rgba[0],rgba[1],rgba[2], rgba[0],rgba[1],rgba[2] );
      }
      else if(opt->intervalsType == PViewOptions::Continuous){
	double dv = (opt->tmpMax - opt->tmpMin) / (opt->nbIso ? opt->nbIso : 1);
	double v1 = opt->tmpMin + i * dv;
	double v2 = opt->tmpMin + (i + 1) * dv;
	unsigned int col1 = opt->getColor(v1, opt->tmpMin, opt->tmpMax, true);
	unsigned int col2 = opt->getColor(v2, opt->tmpMin, opt->tmpMax, true);
	double rgba1[4]= { .5,.5,.5,1. };
	double rgba2[4]= { .5,.5,.5,1. };
	unsignedInt2RGBA(col1,rgba1[0],rgba1[1],rgba1[2],rgba1[3]);
	unsignedInt2RGBA(col2,rgba2[0],rgba2[1],rgba2[2],rgba2[3]);
	fprintf(fp,"              <Color color=' %g %g %g  %g %g %g  %g %g %g  %g %g %g '/>\n"
		, rgba1[0],rgba1[1],rgba1[2], rgba2[0],rgba2[1],rgba2[2], rgba2[0],rgba2[1],rgba2[2], rgba1[0],rgba1[1],rgba1[2] );
      }
      fprintf(fp,"           </IndexedFaceSet> \n");
    }
    else{
      fprintf(fp,"        <Shape> \n");
      fprintf(fp,"           <IndexedLineSet colorPerVertex='true'  coordIndex='0 1 -1'  > \n");
      fprintf(fp,"              <Coordinate point='");
      if(horizontal){
	fprintf(fp,"%e %e %e %e %e %e  ",xmin+box/2.+i*box , ymin , 0.,xmin+box/2.+i*box , ymin+height , 0.);
      }
      else{
	fprintf(fp,"%e %e %e %e %e %e  ",xmin , ymin + box / 2. + i * box, 0.,xmin + width , ymin + box / 2. + i * box , 0.);
      }
      fprintf(fp,"      '/> \n");
      double rgba[4]= { .5,.5,.5,1. };
      unsigned int col = opt->getColor(i, opt->nbIso);
      unsignedInt2RGBA(col,rgba[0],rgba[1],rgba[2],rgba[3]);
      fprintf(fp,"              <Color color=' %g %g %g  %g %g %g '/>\n", rgba[0],rgba[1],rgba[2], rgba[0],rgba[1],rgba[2] );
      fprintf(fp,"           </IndexedLineSet> \n");
    }
    fprintf(fp,"        </Shape> \n");
  }
}




static void  writeX3DScaleValues(FILE *fp, PView *p, double xmin, double ymin,
				 double width, double height, double tic, int horizontal,double ratio)
{
  PViewOptions *opt = p->getOptions();
  if(!opt->nbIso) return;
  double font_h = drawContext::global()->getStringHeight(); // total font height
  double font_a = drawContext::global()->getStringHeight() -  drawContext::global()->getStringDescent(); // height above ref pt
  char label[1024];
  sprintf(label, opt->format.c_str(), -M_PI * 1.e-4);
  double maxw = drawContext::global()->getStringWidth(label);
  font_h *=ratio;font_a *=ratio;
  maxw *=ratio;
  int nbv = opt->nbIso;
  double f = (opt->intervalsType == PViewOptions::Discrete ||
              opt->intervalsType == PViewOptions::Numeric ||
              opt->intervalsType == PViewOptions::Continuous) ? 2 : 2.5;

  if(horizontal && width < nbv * maxw){
    if(width < f * maxw) nbv = 1;
    else nbv = 2;
  }
  else if(!horizontal && height < nbv * font_h ){
    if(height < f * font_h) nbv = 1;
    else nbv = 2;
  }
  double box = (horizontal ? width : height) / opt->nbIso;
  double vbox = (horizontal ? width : height) / nbv;

  glColor4ubv((GLubyte *) & CTX::instance()->color.text);

  if(opt->intervalsType == PViewOptions::Discrete ||
     opt->intervalsType == PViewOptions::Numeric ||
     opt->intervalsType == PViewOptions::Continuous){
    for(int i = 0; i < nbv + 1; i++) {
      double v = opt->getScaleValue(i, nbv + 1, opt->tmpMin, opt->tmpMax);
      sprintf(label, opt->format.c_str(), v);
      if(horizontal){
        writeX3DStringCenter( fp,label, xmin + i * vbox, ymin + height + tic, 0.,font_h );
      }
      else{
        writeX3DStringCenter( fp,label, xmin + width + tic,ymin + i * vbox - font_a*ratio / 3., 0.,font_h );
      }
    }
  }
  else{
    if(opt->nbIso > 2 && (nbv == 1 || nbv == 2)){
      vbox = (vbox * nbv - box) / nbv;
      nbv++;
    }
    for(int i = 0; i < nbv; i++) {
      double v = opt->getScaleValue(i, nbv, opt->tmpMin, opt->tmpMax);
      sprintf(label, opt->format.c_str(), v);
      if(horizontal){
        writeX3DStringCenter( fp,label, xmin + box / 2. + i * vbox,ymin + height + tic, 0.,font_h );
      }
      else{
        writeX3DStringCenter( fp,label, xmin + width + tic,ymin + box / 2. + i * vbox - font_a / 3., 0.,font_h );
      }
    }
  }
}

static void writeX3DScaleLabel(FILE *fp , PView *p, double xmin, double ymin,
			       double width, double height, double tic, int horizontal,double ratio)
{
  PViewOptions *opt = p->getOptions();
  PViewData *data;

  // requested by Laurent: but is this really what we should be doing?
  if(opt->externalViewIndex >= 0 && opt->externalViewIndex < (int)PView::list.size())
    data = PView::list[opt->externalViewIndex]->getData();
  else
    data = p->getData();
  double font_h = drawContext::global()->getStringHeight();
  font_h *=ratio*1.2;
  char label[1024];
  int nt = data->getNumTimeSteps();
  if((opt->showTime == 1 && nt > 1) || opt->showTime == 2){
    char tmp[256];
    sprintf(tmp, opt->format.c_str(), data->getTime(opt->timeStep));
    sprintf(label, "%s (%s)", data->getName().c_str(), tmp);
  }
  else if((opt->showTime == 3 && nt > 1) || opt->showTime == 4){
    sprintf(label, "%s (%d/%d)", data->getName().c_str(), opt->timeStep,data->getNumTimeSteps() - 1);
  }
  else
    sprintf(label, "%s", data->getName().c_str());

  if(horizontal){
    writeX3DStringCenter( fp,label,  xmin + width / 2., ymin + height + tic + .9  * font_h, 0.,font_h );
  }
  else{
    writeX3DStringCenter( fp,label,  xmin, ymin - 2 * font_h, 0.,font_h );
  }
}




static void writeX3DStringCenter( FILE *fp,char *label,double x, double y, double z,double font_size){
  fprintf(fp,"              <Transform translation='%g %g %g'>  \n",x,y,0.);
  fprintf(fp,"                <Shape> \n");
  fprintf(fp,"                  <Text  string='\"%s\"'>\n",label);
  fprintf(fp,"	                  <FontStyle justify='\"MIDDLE\" \"MIDDLE\"' size=' %g '/>  \n",font_size);
  fprintf(fp,"	                </Text>\n");
  fprintf(fp,"	                <Appearance>\n");
  fprintf(fp,"                    <Material diffuseColor='0. 0. 0. '/>\n");
  fprintf(fp,"                  </Appearance>\n");
  fprintf(fp,"                </Shape>\n");
  fprintf(fp,"              </Transform> \n");

}
