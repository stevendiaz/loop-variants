#include <stdlib.h>
#include <stdio.h>
#include <papi.h>

void print_counters(long long* counters) {
    printf("%lld L1 Cache misses \n%lld L1 Cache Misses \n%lld L2 Cache Accesses \n%lld L2 Cache Misses \n%lld Load/Store Instructions \n%lld FP instructions \n%lld Cycles\n\n ",
            counters[0],
            counters[1],
            counters[2],
            counters[3],
            counters[4],
            counters[5],
            counters[6] );
}

void ijk(int N, int* PAPI_events) {
    double A[N][N], B[N][N], X[N][N];
    memset(A, 0, N*N*sizeof(double));
    memset(B, 0, N*N*sizeof(double));
    memset(X, 0, N*N*sizeof(double));

    int i, j, k;
    long long counters[7];
    printf("++++++++++++++\n");
    printf("+   i-j-k    +\n");
    printf("+  %d x %d     +\n", N, N);
    PAPI_start_counters(PAPI_events, 7);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                X[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    PAPI_stop_counters(counters, 7);
    print_counters(counters);
}

void jik(int N, int* PAPI_events) {
    double A[N][N], B[N][N], X[N][N];
    memset(A, 0, N*N*sizeof(double));
    memset(B, 0, N*N*sizeof(double));
    memset(X, 0, N*N*sizeof(double));

    int j, i, k = 0;
    long long counters_jik[7];
    printf("++++++++++++++\n");
    printf("+   j-i-k    +\n");
    printf("+  %d x %d     +\n", N, N);
    PAPI_start_counters(PAPI_events, 7);
    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++) {
            for (k = 0; k < N; k++) {
                X[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    PAPI_stop_counters(counters_jik, 7);
    print_counters(counters_jik);
}

void jki(int N, int* PAPI_events) {
    double A[N][N], B[N][N], X[N][N];
    memset(A, 0, N*N*sizeof(double));
    memset(B, 0, N*N*sizeof(double));
    memset(X, 0, N*N*sizeof(double));

    int j, k, i = 0;
    long long counters_jki[7];
    printf("++++++++++++++\n");
    printf("+   j-k-i    +\n");
    printf("+  %d x %d     +\n", N, N);
    PAPI_start_counters(PAPI_events, 7);
    for (j = 0; j < N; j++) {
        for (k = 0; k < N; k++) {
            for (i = 0; i < N; i++) {
                X[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    PAPI_stop_counters(counters_jki, 7);
    print_counters(counters_jki);
}

void kji(int N, int* PAPI_events) {
    double A[N][N], B[N][N], X[N][N];
    memset(A, 0, N*N*sizeof(double));
    memset(B, 0, N*N*sizeof(double));
    memset(X, 0, N*N*sizeof(double));

    int k, j, i = 0;
    long long counters_kji[7];
    printf("++++++++++++++\n");
    printf("+   k-j-i    +\n");
    printf("+  %d x %d     +\n", N, N);
    PAPI_start_counters(PAPI_events, 7);
    for (k = 0; k < N; k++) {
        for (j = 0; j < N; j++) {
            for (i = 0; i < N; i++) {
                X[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    PAPI_stop_counters(counters_kji, 7);
    print_counters(counters_kji);
}

void ikj(int N, int* PAPI_events) {
    double A[N][N], B[N][N], X[N][N];
    memset(A, 0, N*N*sizeof(double));
    memset(B, 0, N*N*sizeof(double));
    memset(X, 0, N*N*sizeof(double));

    int i, k, j = 0;
    long long counters_ikj[7];
    printf("++++++++++++++\n");
    printf("+   i-k-j    +\n");
    printf("+  %d x %d     +\n", N, N);
    PAPI_start_counters(PAPI_events, 7);
    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k++) {
            for (j = 0; j < N; j++) {
                X[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    PAPI_stop_counters(counters_ikj, 7);
    print_counters(counters_ikj);
}

void kij(int N, int* PAPI_events) {
    double A[N][N], B[N][N], X[N][N];
    memset(A, 0, N*N*sizeof(double));
    memset(B, 0, N*N*sizeof(double));
    memset(X, 0, N*N*sizeof(double));

    int k, i, j = 0;
    long long counters_kij[7];
    printf("++++++++++++++\n");
    printf("+   k-i-j    +\n");
    printf("+  %d x %d     +\n", N, N);
    PAPI_start_counters(PAPI_events, 7);
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                X[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    PAPI_stop_counters(counters_kij, 7);
    print_counters(counters_kij);
}

void matrix_matrix_multiply(int N, int* PAPI_events) {
    ijk(N, PAPI_events);
    jik(N, PAPI_events);
    jki(N, PAPI_events);
    kji(N, PAPI_events);
    ikj(N, PAPI_events);
    kij(N, PAPI_events);
}

int main(int args, char *argv[]) {
    int PAPI_events[] = {
        PAPI_L1_ICM,
        PAPI_L1_DCM,
        PAPI_L2_DCA,
        PAPI_L2_DCM,
        PAPI_LST_INS,
        PAPI_FP_INS,
        PAPI_TOT_CYC };
    int MATRIX_SIZES[] = {
        6, 
        10,
        50 };
    PAPI_library_init(PAPI_VER_CURRENT);
    int num_counters = PAPI_num_counters();

    printf("This system has %d available PAPI counters\n", num_counters);
    int i = 0;
    for (i = 0; i < 3; i++) {
        matrix_matrix_multiply(MATRIX_SIZES[i], PAPI_events);
    }

    return 0;
}

