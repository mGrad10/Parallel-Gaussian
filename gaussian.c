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

int main(int argc, char *argv[]){
	
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

	// Vars
	int thread_count = strtol(argv[2], NULL, 10);
	int m=0, n=0;
	
	// First line reads size of matrix mxn
	int ret = fscanf(infile, "%d %d", &m, &n);
	printf(" Rows: %d\n Cols: %d\n", m, n);
	double *A = malloc(sizeof(double)*m*n);
	double *b = malloc(sizeof(double)*m);

	//TODO: Read in matrix A: m lines each containing a row of matrix A
	//TODO: Read in matrix b: last line ? contains values of vector b
		
	int i =0;
	while(ret == m*n && ret!= EOF){
		for( i = 0; i< m; i++){
			fscanf(infile,"%f", &A[i]);
			printf("%f\n", A[i]);
		}	
	}
	int j = 0;
	for(j = 0; j<m; j++){
		printf("%f\n", A[i]);

	}
	free(A);
	free(b);
	fclose(infile);	
}

/* TODO: Implement Gaussian Elimination
 * 
 * 
void gaussian(double A[], double b[], int n){
	
	for(int i =0; i < n-1; i++){
#pragma omp parallel for
		for(int j = i; j < N; j++){
			double temp = A[j][i]/A[i][i];
			for(int k = i; k < N; k++){
				A[j][k] -= (temp * A[i][k]);
				b[j] -= (temp*b[i]);
			}
		}
	}
}
*/
 
/* Function: rowSolve
 * Purpose: Solve a triangular system using the row
 * 			oriented algorithm
 * In args: A, b, n, thread_count
 * Out arg: x
 
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
*/



