#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate a uniform random number between 0 and 1
double uniform_random() {
    return rand() / (RAND_MAX + 1.0);
}

// Function to generate an exponential random number with mean 0.5
double exponential_random() {
    double lambda = 0.5;
    return -lambda * log(1.0 - uniform_random());
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Open a file to save the random numbers
    FILE *file = fopen("exp_deviates.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Generate and save 10,000 exponential random numbers
    for (int i = 0; i < 10000; i++) {
        double exp_deviate = exponential_random();
        fprintf(file, "%f\n", exp_deviate);
    }

    // Close the file
    fclose(file);

    return 0;
}

