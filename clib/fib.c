// High Precision Fibonacci Calculator
// Uses linear recurrence method

#include <stdlib.h>
#include <stdio.h>


// naive matrix multiplication, but fast enough here
// assumes square matrices size 2
long long ** mult(long long ** A, long long ** B)
{
    int size = 2;
    int mod_by = 1000000007; //modulus specified by assignment

    long long ** C = (long long **) calloc(2, sizeof(long long));
    for (int i=0; i<2; i++) {
 	C[i] = (long long *) calloc(2, sizeof(long long)); }

    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            for (int k=0; k<size; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod_by;
    }}}
    return C;
}


long long ** matrix_pow(long long ** A, long long p)
{
    int size = 2;

    //if pow==1 return original matrix
    if (p == 1) return A;

    if (p % 2) return mult(A, matrix_pow(A, p - 1));

    A = matrix_pow(A, p / 2);
    return mult(A, A);
}



// returns the N-th term of Fibonacci sequence
long long fib(long long N) {

    int mod_by = 1000000007; //modulus specified by assignment

    //fib init values
    long long F[2];
    F[0] = 1, F[1] = 1;

    //transformation matrix
    long long ** T = (long long **) calloc(2, sizeof(long long));
    for (int i=0; i<2; i++) {
 	T[i] = (long long *) calloc(2, sizeof(long long));}
    T[0][0] = 0, T[0][1] = 1, T[1][0] = 1, T[1][1] = 1;

    if (N == 1) return 1;

    T = matrix_pow(T, N - 1);

    // pull solution from first row of transformation matrix
    long long ans = 0;
    for (int i=0; i<2; i++) {
        ans = (ans + T[0][i] * F[i]) % mod_by;
        }
    free(T);

    return ans;
}


void fib_string(int index, long long N, long long soln[]) {
	if (N == 0) {
		printf("ERROR: 0th fibonnaci number does not exist, use 1 instead.");
		return 1;
	}
    soln[index] = fib(N);
}


long long main() {
    //used for testing
    long long soln = fib(100000000000000);
    printf("\nFib soln: %llu\n", soln);
  
    return 0;
}
