#include <iostream>

#define SIZE 4
#define BLOCK_SIZE 16

using std::cout;
using std::endl;
using std::cerr;

__global__ void std_multiplication_kernel(int *dev_matrix_1, int *dev_matrix_2, int *dev_answer) {
    int idx = blockDim.x * blockIdx.x + threadIdx.x; //column
    int idy = blockDim.y * blockIdx.y + threadIdx.y; //row

    if (idx < SIZE && idy < SIZE) {
        int sum = 0;
        for (int i = 0; i < SIZE; ++i) {
            sum += dev_matrix_1[idy * SIZE + i] * dev_matrix_2[SIZE * i + idx];
        }
        dev_answer[idy * SIZE + idx] = sum;
    }
}

__host__ void error_handler(cudaError_t err) {
    if (err != cudaSuccess) {
        cerr << cudaGetErrorString(err) << endl;
        exit(1);
    }   
}

__host__ void output(int (&matrix)[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

__host__ void matrix_multiplication() {
    // const int matrix_1[SIZE][SIZE] = {
    //     {1, 0, 0, 0},
    //     {0, 1, 0, 0},
    //     {0, 0, 1, 0},
    //     {0, 0, 0, 1}
    // };

    const int matrix_1[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    const int matrix_2[SIZE][SIZE] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    int answer[SIZE][SIZE] = {};

    int *dev_matrix_1 = NULL;
    int *dev_matrix_2 = NULL;
    int *dev_answer = NULL;

    //allocation without pitching
    error_handler(cudaMalloc((void**)&dev_matrix_1, SIZE * SIZE * sizeof(int)));
    error_handler(cudaMalloc((void**)&dev_matrix_2, SIZE * SIZE * sizeof(int)));
    error_handler(cudaMalloc((void**)&dev_answer, SIZE * SIZE * sizeof(int)));

    //copy data from host to device
    error_handler(cudaMemcpy(dev_matrix_1, matrix_1, SIZE * SIZE * sizeof(int), cudaMemcpyHostToDevice));
    error_handler(cudaMemcpy(dev_matrix_2, matrix_2, SIZE * SIZE * sizeof(int), cudaMemcpyHostToDevice));

    dim3 blockDim(BLOCK_SIZE, BLOCK_SIZE);
    dim3 gridDim((SIZE + BLOCK_SIZE - 1)/BLOCK_SIZE, (SIZE + BLOCK_SIZE - 1)/BLOCK_SIZE);
    std_multiplication_kernel<<<gridDim, blockDim>>>(dev_matrix_1, dev_matrix_2, dev_answer);

    error_handler(cudaMemcpy(answer, dev_answer, SIZE * SIZE * sizeof(int), cudaMemcpyDeviceToHost));

    output(answer);

    error_handler(cudaFree(dev_matrix_1));
    error_handler(cudaFree(dev_matrix_2));
    error_handler(cudaFree(dev_answer));
}

__host__ int main() {

    matrix_multiplication();

    return 0;
}