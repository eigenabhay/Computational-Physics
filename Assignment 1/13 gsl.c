#include <stdio.h>
#include <gsl/gsl_linalg.h>

int main()
{
    // Define the four matrices A1, A2, A3, A4
    double A1_data[] = {3, -1, 1, 3, 6, 2, 3, 3, 7};
    double A2_data[] = {10, -1, 0, -1, 10, -2, 0, -2, 10};
    double A3_data[] = {10, 5, 0, 0, 5, 10, -4, 0, 0, -4, 8, -1, 0, 0, -1, 5};
    double A4_data[] = {4, 1, 1, 0, 1, -1, -3, 1, 1, 0, 2, 1, 5, -1, -1, -1, -1, -1, 4, 0, 0, 2, -1, 1, 4};

    gsl_matrix_view A1 = gsl_matrix_view_array(A1_data, 3, 3);
    gsl_matrix_view A2 = gsl_matrix_view_array(A2_data, 3, 3);
    gsl_matrix_view A3 = gsl_matrix_view_array(A3_data, 4, 4);
    gsl_matrix_view A4 = gsl_matrix_view_array(A4_data, 5, 5);

    // Perform the LU decomposition
    gsl_permutation *perm1 = gsl_permutation_alloc(3);
    gsl_permutation *perm2 = gsl_permutation_alloc(3);
    gsl_permutation *perm3 = gsl_permutation_alloc(4);
    gsl_permutation *perm4 = gsl_permutation_alloc(5);

    int signum1, signum2, signum3, signum4;

    gsl_linalg_LU_decomp(&A1.matrix, perm1, &signum1);
    gsl_linalg_LU_decomp(&A2.matrix, perm2, &signum2);
    gsl_linalg_LU_decomp(&A3.matrix, perm3, &signum3);
    gsl_linalg_LU_decomp(&A4.matrix, perm4, &signum4);

    // Print the results
    printf("LU decomposition of A1 is correct: %s\n", (signum1 == 1) ? "Yes" : "No");
    printf("LU decomposition of A2 is correct: %s\n", (signum2 == 1) ? "Yes" : "No");
    printf("LU decomposition of A3 is correct: %s\n", (signum3 == 1) ? "Yes" : "No");
    printf("LU decomposition of A4 is correct: %s\n", (signum4 == 1) ? "Yes" : "No");

    // Free memory
    gsl_permutation_free(perm1);
    gsl_permutation_free(perm2);
    gsl_permutation_free(perm3);
    gsl_permutation_free(perm4);

    return 0;
}
