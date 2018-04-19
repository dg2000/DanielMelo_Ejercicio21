#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{
  double c = 1.0;

  double T = 0.5;

  double hx = 0.001;

  double ht = 0.001;

  double L = 2.0;

  int nx = (L/hx) + 1;

  int nt =(T/ht)+ 1;

  double* nuevo = new double[nx];

  double* viejo = new double[nx];

  double* original = new double[nx];

  nuevo[0] = 0.0;


   for (int i=0; i < nx; i++)
    {

      if (i*hx < 0.75)
	{
	  viejo[i] = 0.0;
	  original[i] = 0.0;
	}

      else if ( (i*hx > 0.75) && (i*hx < 1.25) )
	{
	  
	  viejo[i] = 1.0;
	  original[i] = 1.0;
	}

      else
	{
	  viejo[i] = 0.0;
	  original[i] = 0.0;
	}
    }


   for (int t = 0; t < nt; t++)
     {
       for ( int i = 1; i < nx-1; i++)
	 {

	   nuevo[i] = viejo[i] - c*ht*( viejo[i]-viejo[i-1] )/hx;
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

