/*
 * Gaussian.c
 * Melinda Grad
 * Quentin Fulsher
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

// Function Prototypes
void rowSolve(double A[], double b[], double x[], int n, int thread_count);

int main(int argc, char *argv){

	if(argc != 3){
		printf("Program needs 2 args: <filename> <numthreads>\n");
		exit(1);
	}
	// Read the file containing the matrix to be solved
	FILE *infile = fopen(argv[1], "r");
	if (infile == NULL){
		fprintf(stderr, "ERROR: Could not open file %s for reading\n", argv[1]);
		exit(1);
	}
	int thread_count = strtol(argv[2], NULL, 10);
	int m, n;
	
	// First line reads size of matrix mxn
	fscanf(infile, "%d %d", m, n);
	
	//TODO: Read in matrix A: m lines each containing a row of matrix A
	//TODO: Read in matrix b: last line ? contains values of vector b
	
}

/* TODO: Implement Gaussian Elimination
 * 
 * /
 


/* Function: rowSolve
 * Purpose: Solve a triangular system using the row
 * 			oriented algorithm
 * In args: A, b, n, thread_count
 * Out arg: x
 */
void rowSolve(double A[], double b[], double x[], int n, int thread_count){
	int i, j;
	double tmp;

#pragma omp parallel num_threads(thread_count) \
default(none) private(i,j) shared(A, b, x, n, tmp)
for(i= n-1; i >=0; i--) {
#pragma omp single
	tmp = b[i];

#pragma omp forreduction(+: tmp)
	for(j = i+1; j< n; j++) 
		tmp += -A[i*n+j]*x[j];

#pragma omp single
	x[i] = tmp/A[i*n+i];
}
} //end rowSolve




