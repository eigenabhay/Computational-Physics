#include<stdio.h>
#include<math.h>
#include<gsl/gsl_fft_complex.h>

#define REAL(z,i) ((z)[2*(i)])
#define IMAG(z,i) ((z)[2*(i)+1])

double sinc(double x)
{
if(x==0)
return 1;
else 
return sin(x)/x;
}

int main()
{
int i;
double x;
int n=1024;
double data[2*n];
double x_min=-40;
double x_max=40;
double delta=(x_max-x_min)/(n-1);
for(i=0;i<n;i++)
{
x=x_min+i*delta;
REAL(data,i)=sinc(x);
IMAG(data,i)=0.0;
}

gsl_fft_complex_radix2_forward(data,1,n);
for(i=0;i<n;i++)
{
printf("%f %f",data[2*i]/sqrt(n),data[2*i+1]/sqrt(n));
printf("\n");
}
return 0;
}
