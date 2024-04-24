#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Function to define the differential equation dy/dx = f(x, y)
double f(double t, double y) {
    return y-(t*t)+1; // Example: dy/dt=y-t^2+1
}

double calculate_y(double t) {
    return pow(t + 1, 2) - 0.5 * exp(t);
}

double calculate_error_bound(double t,double M, double L,double h,double a) {
    return ((h*M)/(2*L))*(exp(t-a)-1);
}


double* euler(double t0, double y0, double h, double tn, int n) {
    double t = t0;
    double y = y0;

    // Allocate memory for the array
    double* y_array = (double*)malloc((n+1) * sizeof(double));
    if (y_array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Store initial value of y
    y_array[0] = y0;

    // Perform Euler method
    for (int i = 1; i <= n; i++) {
        y = y + h * f(t, y); // Euler method formula
        t = t + h; // Increment t
        y_array[i] = y; // Store the value of y at each step
    }

    return y_array;
}


int main() {
    double t0, y0, tn, h,M,L;
    int n;

    t0=0;
    tn=2;
    y0=0.5;
    h=0.2;
    M=1.5;
    L=1;

    // Calculate the number of steps
    n = (int)((tn - t0) / h);

    // Apply Euler method and get the array of y values
    double* y_array = euler(t0, y0, h, tn, n);

    // Print the array of y values
    printf("t\t\t y_euler\t y_true\t\t error\t\t error_bound\n");
    for (int i = 0; i <= n; i++) {
        printf("%lf\t %lf\t %lf\t %lf\t %lf\n", t0 + i * h, y_array[i],calculate_y(t0+i*h),calculate_y(t0+i*h)-y_array[i],calculate_error_bound(t0+i*h,M,L,h,t0));
    }

    // Free allocated memory
    free(y_array);

    return 0;
}

