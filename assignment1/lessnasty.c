/*
 * nasty.c
 */
#include <stdio.h>
#include <math.h>

/* OVERVIEW
TO DO 
[] get onto adroit 
[] run on adroit
[] intake() ?
[] save any kind of output ?
*  This will numerically integrate a damped driven oscillator system using the first-order forward Euler method
*  for a fixed total time (6pi)
* 
* Variable description
*
* t = time 
* dt = change in time
* x = position
* dx = change in position
* xold = x from previous iteration
* dxold = dx from previous iteration
*/


/* Prototype of ODEsolver() */
void ODEsolver(int timesteps, double driving_freq);

double intake1();


/*  main() 
*  will use ODEsolver() to itegrate the damped driven oscillator system
*  for several different driving frequencies [driving_freq] and integration timesteps [timesteps], 
*  over a fixed time---6pi [SIX_PI]. Then print the solutions */

int main()
{
  /* Local Variable Declaration 
  int timesteps = 0;
  double driving_freq = 0.0;
  */
  double driving_freq;
  driving_freq = intake1();
  printf("\nDriving Freq = %f", driving_freq);
  /*
  printf( "Please input the driving frequency: " );
  scanf("%lf", &driving_freq);

  printf( "Please input the integration interval: " );
  scanf("%d", &timesteps);
  
  ODEsolver(timesteps, driving_freq);
  */
}


/* ODEsolver()
% This function will numerically integrate the oscilaltor system using the first-order forward Euler
*/
void ODEsolver(int timesteps, double driving_freq)
{
  /* Local Variable Declaration */
  double t, dt, x, dx, xold, dxold;
  int i;

  /* initialize the variables */
  t = 0.0; 
  x = 0.0;
  dx = 0.0;
  dt = (6 * M_PI) / timesteps;

  /* Print the Input Values */  
  printf("\nDriving Frequency = %2.2f \n",driving_freq);
  printf( "Intergration interval = %d\n", timesteps);

  /* Print Title for Each Column  */
  printf("\n%8.2s %8.2s %8.2s\n", "t", "x", "dx");

  /* Print Initial Variable Values */
  printf("%8.2f %8.2f %8.2f\n", t, x, dx);
  
  /* Integration with first-order Forward Euler method */
  for (i=0; i < timesteps; ++i)
  {
    /* store values from previous iteration*/
    xold = x;
    dxold = dx;

    /* New x Value */
    x += dt * dxold;
    
    /* The Important Part: first-order  */
    dx += dt * (cos(driving_freq*t) - xold - 0.5*dxold);
    
    /* Add to Time Step*/
    t += dt;

    /* Print Output */
    printf("%8.2f %8.2f %8.2f\n", t, x, dx); 
  }
}


double intake1()
{
  double driving_freq;

  printf( "Please input the driving frequency: " );
  scanf("%lf", &driving_freq);
  printf( "Driving frequency input: %f", driving_freq );
  return driving_freq;
/*
  printf( "Please input the integration interval: " );
  scanf("%d", &timesteps);
  printf("\n");
*/
}
