#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<fftw3.h>

double gaussian(double x) 
{
    return(exp(-x*x));
    }
int main()
{
int n=1024;
double x_min=-40;
double x_max=40;
double delta=(x_max-x_min)/(n-1);
fftw_complex *in=(fftw_complex*) fftw_malloc(sizeof(fftw_complex)*n);
fftw_complex *out=(fftw_complex*) fftw_malloc(sizeof(fftw_complex)*n);

int i;
double x;
double x_vals[n],y_vals[n];

for(i=0;i<n;i++)
{
x=x_min+i*delta;
in[i][0]=gaussian(x);
in[i][1]=0;
}


fftw_plan p=fftw_plan_dft_1d(n,in,out,FFTW_FORWARD,FFTW_ESTIMATE);
fftw_execute(p);
fftw_destroy_plan(p);

for(i=0;i<n;i++)
{
printf("%f %f ",out[i][0]/sqrt(n),out[i][1]/sqrt(n));
printf("\n");
}
fftw_free(in);
return 0;
}
