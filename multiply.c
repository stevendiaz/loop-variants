#include <stdlib.h>
#include <stdio.h>
#include <papi.h>

void print_counters(long long* counters, int num_events) {
    if (num_events == 2) {
        printf("%lld :X \n", counters[0]);
        printf("%lld :Y \n\n", counters[1]);
    }
    else {
        printf("%lld :X\n\n", counters[0]);
    }
}

void ijk(int N, int* PAPI_events, int num_events) {
    double A[N][N], B[N][N], X[N][N];
    memset(A, 0, N*N*sizeof(double));
    memset(B, 0, N*N*sizeof(double));
    memset(X, 0, N*N*sizeof(double));

    int i, j, k;
    long long counters[num_events];
    memset(counters, 0, num_events*sizeof(long long));
    printf("++++++++++++++\n");
    printf("+   i-j-k    +\n");
    printf("+  %d x %d    \n", N, N);
    PAPI_start_counters(PAPI_events, num_events);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                X[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    PAPI_stop_counters(counters, num_events);
    print_counters(counters, num_events);
}

void jik(int N, int* PAPI_events, int num_events) {
    double A[N][N], B[N][N], X[N][N];
    memset(A, 0, N*N*sizeof(double));
    memset(B, 0, N*N*sizeof(double));
    memset(X, 0, N*N*sizeof(double));

    int j, i, k = 0;
    long long counters_jik[num_events];
    memset(counters_jik, 0, num_events*sizeof(long long));
    printf("++++++++++++++\n");
    printf("+   j-i-k    +\n");
    printf("+  %d x %d    \n", N, N);
    PAPI_start_counters(PAPI_events, num_events);
    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++) {
            for (k = 0; k < N; k++) {
                X[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    PAPI_stop_counters(counters_jik, num_events);
    print_counters(counters_jik, num_events);
}

void jki(int N, int* PAPI_events, int num_events) {
    double A[N][N], B[N][N], X[N][N];
    memset(A, 0, N*N*sizeof(double));
    memset(B, 0, N*N*sizeof(double));
    memset(X, 0, N*N*sizeof(double));

    int j, k, i = 0;
    long long counters_jki[num_events];
    memset(counters_jki, 0, num_events*sizeof(long long));
    printf("++++++++++++++\n");
    printf("+   j-k-i    +\n");
    printf("+  %d x %d    \n", N, N);
    PAPI_start_counters(PAPI_events, num_events);
    for (j = 0; j < N; j++) {
        for (k = 0; k < N; k++) {
            for (i = 0; i < N; i++) {
                X[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    PAPI_stop_counters(counters_jki, num_events);
    print_counters(counters_jki, num_events);
}

void kji(int N, int* PAPI_events, int num_events) {
    double A[N][N], B[N][N], X[N][N];
    memset(A, 0, N*N*sizeof(double));
    memset(B, 0, N*N*sizeof(double));
    memset(X, 0, N*N*sizeof(double));

    int k, j, i = 0;
    long long counters_kji[num_events];
    memset(counters_kji, 0, num_events*sizeof(long long));
    printf("++++++++++++++\n");
    printf("+   k-j-i    +\n");
    printf("+  %d x %d    \n", N, N);
    PAPI_start_counters(PAPI_events, num_events);
    for (k = 0; k < N; k++) {
        for (j = 0; j < N; j++) {
            for (i = 0; i < N; i++) {
                X[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    PAPI_stop_counters(counters_kji, num_events);
    print_counters(counters_kji, num_events);
}

void ikj(int N, int* PAPI_events, int num_events) {
    double A[N][N], B[N][N], X[N][N];
    memset(A, 0, N*N*sizeof(double));
    memset(B, 0, N*N*sizeof(double));
    memset(X, 0, N*N*sizeof(double));

    int i, k, j = 0;
    long long counters_ikj[num_events];
    memset(counters_ikj, 0, num_events*sizeof(long long));
    printf("++++++++++++++\n");
    printf("+   i-k-j    +\n");
    printf("+  %d x %d    \n", N, N);
    PAPI_start_counters(PAPI_events, num_events);
    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k++) {
            for (j = 0; j < N; j++) {
                X[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    PAPI_stop_counters(counters_ikj, num_events);
    print_counters(counters_ikj, num_events);
}

void kij(int N, int* PAPI_events, int num_events) {
    double A[N][N], B[N][N], X[N][N];
    memset(A, 0, N*N*sizeof(double));
    memset(B, 0, N*N*sizeof(double));
    memset(X, 0, N*N*sizeof(double));

    int k, i, j = 0;
    long long counters_kij[num_events];
    memset(counters_kij, 0, num_events*sizeof(long long));
    printf("++++++++++++++\n");
    printf("+   k-i-j    +\n");
    printf("+  %d x %d    \n", N, N);
    PAPI_start_counters(PAPI_events, num_events);
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                X[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    PAPI_stop_counters(counters_kij, num_events);
    print_counters(counters_kij, num_events);
}

void matrix_matrix_multiply(int N, int* PAPI_events, int num_events) {
    ijk(N, PAPI_events, num_events);
    jik(N, PAPI_events, num_events);
    jki(N, PAPI_events, num_events);
    kji(N, PAPI_events, num_events);
    ikj(N, PAPI_events, num_events);
    kij(N, PAPI_events, num_events);
}

int main(int args, char *argv[]) {
    int L1_miss_rate[] = {
        PAPI_L1_DCM,
        PAPI_LD_INS };
    int L2_miss_rate[] = {
        PAPI_L2_DCM,
        PAPI_L2_DCA };
    int flop_counter[] = {
        PAPI_DP_OPS };
    int load_store_counters[] = {
        PAPI_LD_INS,
        PAPI_SR_INS };
    int total_counters[] = {
        PAPI_TOT_CYC,
        PAPI_TOT_INS };
    int MATRIX_SIZES[] = {
        50, 
        200,
        2000 };
    PAPI_library_init(PAPI_VER_CURRENT);
    int num_counters = PAPI_num_counters();
    printf("This system has %d available PAPI counters\n", num_counters);

    int i = 0;
    for (i = 0; i < 3; i++) {
        printf("X: L1 Misses\n");
        printf("Y: L1 Access\n"); 
        matrix_matrix_multiply(MATRIX_SIZES[i], L1_miss_rate, 2);
    }

    for (i = 0; i < 3; i++) {
        printf("X: L2 Misses\n");
        printf("Y: L2 Access\n");
        matrix_matrix_multiply(MATRIX_SIZES[i], L2_miss_rate, 2);
    }

    for (i = 0; i < 3; i++) {
        printf("X: FLOPS\n"); 
        matrix_matrix_multiply(MATRIX_SIZES[i], flop_counter, 1);
    }

    for (i = 0; i < 3; i++) {
        printf("X: Load Instructions\n");
        printf("Y: Store Instructions\n");
        matrix_matrix_multiply(MATRIX_SIZES[i], load_store_counters, 2);
    }

    for (i = 0; i < 3; i++) {
        printf("X: Total Cycles\n");
        printf("Y: Total Instructions\n"); 
        matrix_matrix_multiply(MATRIX_SIZES[i], total_counters, 2);
    }

    return 0;
}

