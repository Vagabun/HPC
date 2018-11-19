#include <iostream>
#include <cuda.h>
#include <cuda_runtime.h>

#define N 10


__global__ void kernel(int *a, int *b, int *c) {
    int tid = blockIdx.x;
    if (tid < N)
        c[tid] = a[tid] + b[tid];
}

int main() {
    int *a, *b, *c;
    int a_host[N], b_host[N], c_host[N];

    cudaMalloc((void**)&a, N * sizeof(int));
    cudaMalloc((void**)&b, N * sizeof(int));
    cudaMalloc((void**)&c, N * sizeof(int));

    for (int i = 0; i < N; i++) {
        a_host[i] = i;
        b_host[i] = i * i;
    }

    cudaMemcpy(a, a_host, sizeof(int) * N, cudaMemcpyHostToDevice);
    cudaMemcpy(b, b_host, sizeof(int) * N, cudaMemcpyHostToDevice);

    kernel <<<N, 1>>> (a, b, c);
    cudaDeviceSynchronize();

    cudaMemcpy(c_host, c, sizeof(int) * N, cudaMemcpyDeviceToHost);

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
