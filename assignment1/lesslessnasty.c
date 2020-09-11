/*
 * nasty.c
 */
#include <stdio.h>
#include <math.h>


/* OVERVIEW
*  This will numerically integrate a damped driven oscillator system using thfor a fixed total time (6pi) */

/* Global Variable Declaration */
/* AL use define statements for variables that never change. The convention is to capitalize every letter */
#define SIX_PI = 6*M_PI;

/* double six_pi = 6*M_PI; */    /*6pi never changes, so we will make sure that is impossible*/

/* Prototype of ODEsolver() */
void ODEsolver(int timesteps, double driving_freq);

/* main()
*  will use ODEsolver() to itegrate the damped driven oscillator system
*  for several different driving frequencies [driving_freq] and integration timesteps [timesteps],
*  over a fixed time---6pi [six_pi]. Then print the solutions */
int main()
{
  /* Local Variable Declaration */
  /* AL This looks pretty good but you could make a loop so you don't have to type ODEsolver 6 times. Ideally you'd also loop through both values of driving_freq but its a little complicated.*/

  int timesteps;
  double driving_freq;

  driving_freq = 0.5;
  for(timesteps=10; timesteps<= 40; timesteps=timesteps*2)
  {
    ODEsolver(timesteps, driving_freq);
  }

  driving_freq = 2.0;
  for(timesteps=10; timesteps<= 40; timesteps=timesteps*2)
  {
    ODEsolver(timesteps, driving_freq);
  }

  /* timesteps = 10;
  driving_freq =  0.5;
  ODEsolver(timesteps, driving_freq);

  timesteps = 20;
  driving_freq =  0.5;
  ODEsolver(timesteps, driving_freq);

  timesteps = 40;
  driving_freq =  0.5;
  ODEsolver(timesteps, driving_freq);

  timesteps = 10;
  driving_freq =  2.0;
  ODEsolver(timesteps, driving_freq);

  timesteps = 20;
  driving_freq =  2.0;
  ODEsolver(timesteps, driving_freq);

  timesteps = 40;
  driving_freq =  2.0;
  ODEsolver(timesteps, driving_freq); */

}


/* This function will solve...
*/
void ODEsolver(int timesteps, double driving_freq)
{
  /* Local Variable Declaration */
  double t, dt, x, dx, xold, dxold;
  int i;

  t = 0.0;
  x = 0.0;
  dx = 0.0;
  dt = SIX_PI / timesteps;

  /* Print Title for each column  */
  printf("t     x    dx");

  /* new line  */
  printf("\n");

  /* Print Initial Variable Values */
  printf("%15.8f %15.8f %15.8f\n", t, x, dx);

  /* Integration with first-order Forward Euler method */
  for (i=0; i < timesteps; ++i)
  {
    /* store values from previous iteration*/
    xold = x;
    dxold = dx;

    /* new x value */
    x += dt * dxold;

    /* The important part */
    dx += dt * (cos(driving_freq*t) - xold - 0.5*dxold);

    /* add to time step */
    t += dt;

    /* print output */
    printf("%15.8f %15.8f %15.8f\n", t, x, dx);

  }
  /* new line  */
  printf("\n");

}
