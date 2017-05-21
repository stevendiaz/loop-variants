#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BILLION 1000000000L

void matrix_matrix_multiply(int N) {
    double A[N][N], B[N][N], X[N][N];
    memset(A, 0, N*N*sizeof(double));
    memset(B, 0, N*N*sizeof(double));
    memset(X, 0, N*N*sizeof(double));

    int i, j, k;
    struct timespec start, end;
    long long diff = 0;
    printf("++++++++++++++\n");
    printf("+   i-j-k    +\n");
    printf("+  %d x %d     +\n", N, N);
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                X[i][j] += A[i][k] + B[k][j];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    printf("elapsed time = %llu nanoseconds\n\n", (long long unsigned int) diff);


    j, i, k = 0;
    struct timespec start_jik, end_jik;
    diff = 0;
    printf("++++++++++++++\n");
    printf("+   j-i-k    +\n");
    printf("+  %d x %d     +\n", N, N);
    clock_gettime(CLOCK_MONOTONIC, &start_jik);
    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++) {
            for (k = 0; k < N; k++) {
                X[i][j] += A[i][k] + B[k][j];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end_jik);
    diff = BILLION * (end_jik.tv_sec - start_jik.tv_sec) + end_jik.tv_nsec - start_jik.tv_nsec;
    printf("elapsed time = %llu nanoseconds\n\n", (long long unsigned int) diff);


    j, k, i = 0;
    struct timespec start_jki, end_jki;
    diff = 0;
    printf("++++++++++++++\n");
    printf("+   j-k-i    +\n");
    printf("+  %d x %d     +\n", N, N);
    clock_gettime(CLOCK_MONOTONIC, &start_jki);
    for (j = 0; j < N; j++) {
        for (k = 0; k < N; k++) {
            for (i = 0; i < N; i++) {
                X[i][j] += A[i][k] + B[k][j];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end_jki);
    diff = BILLION * (end_jki.tv_sec - start_jki.tv_sec) + end_jki.tv_nsec - start_jki.tv_nsec;
    printf("elapsed time = %llu nanoseconds\n\n", (long long unsigned int) diff);

    k, j, i = 0;
    struct timespec start_kji, end_kji;
    diff = 0;
    printf("++++++++++++++\n");
    printf("+   k-j-i    +\n");
    printf("+  %d x %d     +\n", N, N);
    clock_gettime(CLOCK_MONOTONIC, &start_kji);
    for (k = 0; k < N; k++) {
        for (j = 0; j < N; j++) {
            for (i = 0; i < N; i++) {
                X[i][j] += A[i][k] + B[k][j];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end_kji);
    diff = BILLION * (end_kji.tv_sec - start_kji.tv_sec) + end_kji.tv_nsec - start_kji.tv_nsec;
    printf("elapsed time = %llu nanoseconds\n\n", (long long unsigned int) diff);

    i, k, j = 0;
    struct timespec start_ikj, end_ikj;
    diff = 0;
    printf("++++++++++++++\n");
    printf("+   i-k-j    +\n");
    printf("+  %d x %d     +\n", N, N);
    clock_gettime(CLOCK_MONOTONIC, &start_ikj);
    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k++) {
            for (j = 0; j < N; j++) {
                X[i][j] += A[i][k] + B[k][j];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end_ikj);
    diff = BILLION * (end_ikj.tv_sec - start_ikj.tv_sec) + end_ikj.tv_nsec - start_ikj.tv_nsec;
    printf("elapsed time = %llu nanoseconds\n\n", (long long unsigned int) diff);


    k, i, j = 0;
    struct timespec start_kij, end_kij;
    diff = 0;
    printf("++++++++++++++\n");
    printf("+   k-i-j    +\n");
    printf("+  %d x %d     +\n", N, N);
    clock_gettime(CLOCK_MONOTONIC, &start_kij);
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                X[i][j] += A[i][k] + B[k][j];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end_kij);
    diff = BILLION * (end_kij.tv_sec - start_kij.tv_sec) + end_kij.tv_nsec - start_kij.tv_nsec;
    printf("elapsed time = %llu nanoseconds\n\n", (long long unsigned int) diff);

}

int main(int args, char *argv[]) {
    int MATRIX_SIZES[] = {
        50,
        200,
        2000 };

    int i = 0;
    for (i = 0; i < 3; i++) {
        matrix_matrix_multiply(MATRIX_SIZES[i]);
    }

    return 0;
}

