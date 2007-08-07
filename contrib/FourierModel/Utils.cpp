#include "Utils.h"
#include "Message.h"

std::vector<double> SolveCubic(double a, double b, double c)
{
  std::vector<double> root;
  // find real roots of polynomial a*x^3+ b*x +c=0

  double tol=pow(10.0, -12.);

  double error=1.;
  int maxiter=100; int iter=0;

  std::vector<double> initial_guess(5);
  initial_guess[0]=0.;
  initial_guess[1]=1.;
  initial_guess[2]=-1.;
  initial_guess[3]=0.5;
  initial_guess[4]=-0.5;
  
  bool find=0; int init=0;
  double x0=0., x1, f, df;
  
  while (find==0 && init< 5){

      init=init+1;
      x0=initial_guess[init-1];
      error=1.; iter=0;

      while (error>tol && iter<maxiter){

        f=a*x0*x0*x0+b*x0+c;
        df=a*3.*x0*x0+b;

        x1=x0-f/df;

        error=std::abs(x1-x0);
        x0=x1;
        iter=iter+1;
      }

      if (iter<maxiter){
        find=1;
      }
  }

  if (find) {
    root.push_back(x0);

    //%polynomial a*x^3+ b*x +c=(x-x0)*(a*x^2+bb*x+cc)
    //%where bb=a*x0, cc=-c/x0 (=b-a*x^2);
  
    double aa=a, bb=a*x0, cc=b-a*x0*x0;
    double D=bb*bb-4.*aa*cc;
    
    if (D>=0.){
      root.push_back((-bb+sqrt(D))/2./aa);
      root.push_back((-bb-sqrt(D))/2./aa);
    }
  
    // it seems that the solution obtained by quadratic formula
    //is not so accurate --> used as initial guess.

    if (root.size() == 3){
      for (int i=0 ; i < 2 ; i++){
	x0=root[i+1];
	error=1.; iter=0;
	while (error>tol && iter<maxiter){
	  
	  f=a*x0*x0*x0+b*x0+c;
	  df=a*3.*x0*x0+b;
	  
	  x1=x0-f/df;
	  
	  error=std::abs(x1-x0);
	  x0=x1;
	  iter=iter+1;
	}
	root[i+1]=x0;
      }
    }
  }

  return root;
}

std::vector<double> SolveCubic(double a, double b, double c, double d)
{
  std::vector<double> root;
  // find real roots of polynomial a*x^3 + b*x^2 + c*x + d=0

  double tol=pow(10.0, -12.);

  double error=1.;
  int maxiter=100; int iter=0;

  std::vector<double> initial_guess(5);
  initial_guess[0]=0.;
  initial_guess[1]=1.;
  initial_guess[2]=-1.;
  initial_guess[3]=0.5;
  initial_guess[4]=-0.5;
  
  bool find=0; int init=0;
  double x0=0., x1, f, df;
  
  while (find==0 && init< 5){

      init=init+1;
      x0=initial_guess[init-1];
      error=1.; iter=0;

      while (error>tol && iter<maxiter){

        f=a*x0*x0*x0+b*x0*x0+c*x0+d;
        df=3.*a*x0*x0+2.*b*x0+c;

        x1=x0-f/df;

        error=std::abs(x1-x0);
        x0=x1;
        iter=iter+1;
      }

      if (iter<maxiter){
        find=1;
      }
  }

  if (find) {
    root.push_back(x0);

    //%polynomial a*x^3 + b*x^2 + c*x + d = (x-x0)*(a*x^2+bb*x+cc)
    //%where bb=a*x0, cc=-c/x0 (=b-a*x^2);
  
    double aa=a, bb=b+a*x0, cc=c+b*x0+a*x0*x0;
    double D=bb*bb-4.*aa*cc;
    
    if (D>=0.){
      root.push_back((-bb+sqrt(D))/2./aa);
      root.push_back((-bb-sqrt(D))/2./aa);
    }
  
    /*
    // it seems that the solution obtained by quadratic formula
    //is not so accurate --> used as initial guess.

    if (root.size() == 3){
      for (int i=0 ; i < 2 ; i++){
	x0=root[i+1];
	error=1.; iter=0;
	while (error>tol && iter<maxiter){
	  
	  f=a*x0*x0*x0+b*x0+c;
	  df=a*3.*x0*x0+b;
	  
	  x1=x0-f/df;
	  
	  error=std::abs(x1-x0);
	  x0=x1;
	  iter=iter+1;
	}
	root[i+1]=x0;
      }
    }
    */
  }

  return root;
}

void  find(std::vector<int> &a, int length, std::vector<int> &q, int &num){

  int i,j=0;

  for (i=0 ; i < length ; i++){
    if (a[i]!=0){
      q[j]=i+1;
      j=j+1;
    }
  }
  num=j;
}

int minVec(std::vector<int> &a,int n){
//   vector<int> a(n);
//   copyVec(aa,n,a);
  int i;
  int s=a[0];

  for (i=1;i<n ;i++){
    if (s>a[i]){
      s=a[i];
    }
  }
  return s;
}

int maxVec(std::vector<int> &a,int n){
//   vector<int> a(n);
//   copyVec(aa,n,a);
  int i;
  int s=a[0];

  for (i=1;i<n ;i++){
    if (s<a[i]){
      s=a[i];
    }
  }
  return s;
}

std::vector<std::vector<int> > ones(int row, int col){
  std::vector<std::vector<int> > tmp(row, std::vector<int> (col));
  for (int i=0 ; i < row ; i++){
    for (int j=0 ; j < col ; j++){
      tmp[i][j]=1;
    }
  }
  return tmp;
}

void plotSceneViewer(int app, char* bffer, std::vector<int> &color,
                      std::vector<std::vector<double> > &x,
                      std::vector<std::vector<double> > &y,
                      std::vector<std::vector<double> > &z, int ROW, int COL,
                      std::vector<std::vector<int> > &mask){

  std::fstream outfile;
  if (app==0){
    outfile.open(bffer, std::ios::out);
  }else{
    outfile.open(bffer, std::ios::out | std::ios::app);
  }

  if (outfile.fail())
    {
      Msg::Error("Could not open readfile.txt");
      exit(1);
    }
  if (app==0){//not appending
    outfile  << "#Inventor V2.1 ascii" << std::endl;
    outfile  << "#created by allplot.cpp" << std::endl;
  }

  outfile  << "Separator {" << std::endl;
  outfile  << "  Material {" << std::endl;
  outfile  << "    diffuseColor [" << std::endl;
  outfile  << "      " << ' ' << color[0] << ' ' << color[1] << ' ' << color[2] << std::endl;
  outfile  << "    ]" << std::endl;
  outfile  << "  }" << std::endl;
  outfile  << "  IndexedTriangleStripSet {" << std::endl;;
  outfile  << "    vertexProperty VertexProperty {"<< std::endl;;
  outfile  << "      vertex [" << std::endl;
  //outfile  << "        " << ' ' << x(0,0) << ' ' << y(0,0) << ' ' << z(0,0);

  int i, j;

  for (j=0 ; j < COL ; j++){
    for (i=0 ; i < ROW ; i++){
      if (i==0 & j==0 ){
          outfile  << "        " << ' ' << x[i][j] << ' ' << y[i][j] << ' ' << z[i][j];
      }else{
        outfile  <<"," << ' ' << ' ' << std::endl;
        outfile  << "        " << ' ' << x[i][j] << ' ' << y[i][j] << ' ' << z[i][j];
      }
    }
  }

  outfile  <<' ' << std::endl;
  outfile  << "      ]" << std::endl;
  outfile  << "    }" << std::endl;
  outfile  << "    coordIndex [" << std::endl;

  int jump=ROW;
  int col, row;
  int startrow, startoffset, endrow, endoffset;
  std::vector<int> qq(ROW), qw(ROW);
  int num1,num2,min1,min2,max1,max2;

  //  for (col=0 ; col < ROW-1 ; col++){
  for (col=0 ; col < COL-1 ; col++){
    //copyColToVec(mask, ROW, col, qq);
    for (int i=0 ; i < ROW ; i++){
      qq[i]=mask[i][col];
    }

    find(qq, ROW, qw,  num1);//cout << num1 << endl;

    if (num1!=0){
      min1=minVec(qw,num1);
      max1=maxVec(qw,num1);
    }

    //  copyColToVec(mask, ROW, col+1, qq);
    for (int i=0 ; i < ROW ; i++){
      qq[i]=mask[i][col+1];
    }

    find(qq, ROW, qw,  num2);
    if (num2!=0){
      min2=minVec(qw,num2);
      max2=maxVec(qw,num2);
    }

    if (num1!=0 & num2!=0){
      startrow=std::max(min1,min2)-1;
      startoffset=min1-min2;

      if (startoffset>0){
        outfile  << "     " << ' ' << (col+1)*jump+startrow << ' ' <<"," << ' ' <<
          col*jump+startrow << ' ' <<"," << ' ' << (col+1)*jump+startrow-1  << ' '<<"," << ' ' << "-1,"<< std::endl;
      }else if (startoffset<0){
        outfile  << "     " << ' ' << (col+1)*jump+startrow << ' ' <<"," << ' '<< 
          col*jump+startrow << ' ' <<"," << ' ' << col*jump+startrow-1 <<' ' << "," << ' ' << "-1,"<< std::endl;
      }

      endrow=std::min(max1,max2)-1;
      endoffset=max1-max2;

      if (endoffset>0){
        outfile  << "     " << ' ' <<(col+1)*jump+endrow<< ' ' <<"," << ' ' <<
          col*jump+endrow+1 << ' ' <<"," << ' ' << col*jump+endrow << ' '<< "," << ' ' << "-1,"<<std::endl;
      }else if (endoffset<0){
        outfile  << "     " << ' ' <<(col+1)*jump+endrow << ' ' << "," << ' ' <<
          (col+1)*jump+endrow+1 << ' ' <<"," << ' ' << col*jump+endrow <<' ' <<"," << ' ' << "-1,"<< std::endl;
      }

      outfile << "     " << ' ' << col*jump+startrow << ' ' <<"," << ' ' << (col+1)*jump+startrow<< ' ' << "," ;

      for (row= startrow+1; row <= endrow ; row++){
        outfile << col*jump+row << ' '  <<"," << ' '<< (col+1)*jump+row<< ' ' << ",";
      }
    }
      outfile << " -1," << std::endl;
  }

  outfile  << "    ]" << std::endl;
  outfile  << "  }" << std::endl;
  outfile  << "}" << std::endl;

  outfile.close();
}
