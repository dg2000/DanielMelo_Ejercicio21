#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;

double gauss(double x, double s)
{
  double centro = 1.0;

  double pi = 3.14159;
  
  double a = 1/(s*pow(2.0*pi, 0.5));

  double b = -(x-centro)*(x-centro)/(2.0*s*s);

  return exp(b);
}



int main()
{
  double c = 1.0;

  double T = 0.5;

  double hx = 0.01;

  double ht = 0.01;

  double L = 2.0;

  double s = 0.1;

  int nx = (L/hx) + 1;

  int nt =(T/ht)+ 1;

  double* nuevo = new double[nx];

  double* viejo = new double[nx];

  double* original = new double[nx];

  for( int i = 0; i < nx; i++)
    {
      viejo[i] = gauss(i*hx, s);
      original[i] = gauss(i*hx, s);
    }
  


   for (int t = 0; t < nt; t++)
     {
       for ( int i = 1; i < nx-1; i++)
	 {

	   nuevo[i] = viejo[i] - gauss(i*hx, s)*ht*( viejo[i]-viejo[i-1] )/hx;
	 }
     

       for (int i = 0; i < nx; i++)
	 {
	   viejo[i] = nuevo[i];
	 }
     }
   
       
	   
   for (int i = 0; i < nx; i++)
     {
       cout << i*hx << " " << nuevo[i] << " " << original[i] <<  endl;
     }

   return 0;
}

