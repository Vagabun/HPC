#include <iostream>
#include <cuda.h>
#include <cuda_runtime.h>

#define N 10

void error_handler(cudaError_t err) {
    if (err != cudaSuccess) {
        std::cerr << cudaGetErrorString(err) << std::endl;
        exit(1);
    }
}

__global__ void kernel(int *a, int *b, int *c) {
    int tid = blockIdx.x;
    if (tid < N)
        c[tid] = a[tid] + b[tid];
}

__host__ int main() {
    int *a, *b, *c;
    int a_host[N], b_host[N], c_host[N];

    error_handler(cudaMalloc((void**)&a, N * sizeof(int)));
    error_handler(cudaMalloc((void**)&b, N * sizeof(int)));
    error_handler(cudaMalloc((void**)&c, N * sizeof(int)));

    for (int i = 0; i < N; i++) {
        a_host[i] = i;
        b_host[i] = i * i;
    }

    error_handler(cudaMemcpy(a, a_host, sizeof(int) * N, cudaMemcpyHostToDevice));
    error_handler(cudaMemcpy(b, b_host, sizeof(int) * N, cudaMemcpyHostToDevice));

    kernel <<<N, 1>>> (a, b, c);
    cudaDeviceSynchronize();

    error_handler(cudaMemcpy(c_host, c, sizeof(int) * N, cudaMemcpyDeviceToHost));

    std::cout << "first vector: ";
    for (int i = 0; i < N; i++) {
        std::cout << a_host[i] << " ";
    }
    std::cout << std::endl << "second vector: ";
    for (int i = 0; i < N; i++) {
        std::cout << b_host[i] << " ";
    }
    std::cout << std::endl << "result vector: ";
    for (int i = 0; i < N; i++) {
        std::cout << c_host[i] << " ";
    }
    std::cout << std::endl;

    cudaFree(a);
    cudaFree(b);
    cudaFree(c);

    return 0;
}
