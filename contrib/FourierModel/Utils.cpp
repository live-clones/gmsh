#include "Utils.h"

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

  //  cout << a << ' ' << b << ' ' << c << ' ' <<
  //     num << ' ' << root[0] << ' ' <<root[1] << ' ' << root[2] << endl; 

  return root;
}
