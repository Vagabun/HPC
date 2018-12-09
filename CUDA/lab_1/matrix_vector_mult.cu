#include <iostream>

#define SIZE 3 //matrix height * width

using std::cout;
using std::endl;
using std::cerr;

__global__ void kernel(int *matrix, int *vector, int *answer) {
    int column = threadIdx.x;
    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        sum += matrix[SIZE * i + column] * vector[i];
    }
    answer[column] = sum;
}

__host__ void error_handler(cudaError_t err) {
    if (err != cudaSuccess) {
        cerr << cudaGetErrorString(err) << endl;
        exit(1);
    }   
}

__host__ void init_matrix(int (&matrix)[SIZE][SIZE]) {
    //int n = 1;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            //matrix[i][j] = n++;
           if (i == j)
               matrix[i][j] = 1;
           else
               matrix[i][j] = 0;
        }
    }
}

__host__ void init_vector(int (&vector)[SIZE]) {
    int n = 1;
    for (int i = 0; i < SIZE; ++i)
        vector[i] = n++;
}

//transpose and transform matrix into vector
__host__ void transpose_matrix(int (&matrix)[SIZE][SIZE], int (&flat_matrix)[SIZE * SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            flat_matrix[SIZE * j + i] = matrix[i][j];
        }
    }
}

__host__ void matrix_vector_multiplication() {
    int matrix[SIZE][SIZE] = { {} };
    int vector[SIZE] = {};
    int flat_matrix[SIZE * SIZE] = {};
    int answer[SIZE] = {};

    init_matrix(matrix);
    init_vector(vector);
    transpose_matrix(matrix, flat_matrix);

    int *dev_flat_matrix = NULL;
    int *dev_vector = NULL;
    int *dev_answer = NULL;

    error_handler(cudaMalloc((void**)&dev_flat_matrix, SIZE * SIZE * sizeof(int)));
    error_handler(cudaMalloc((void**)&dev_vector, SIZE * sizeof(int)));
    error_handler(cudaMalloc((void**)&dev_answer, SIZE * sizeof(int)));

    error_handler(cudaMemcpy(dev_flat_matrix, flat_matrix, SIZE * SIZE * sizeof(int), cudaMemcpyHostToDevice));
    error_handler(cudaMemcpy(dev_vector, vector, SIZE * sizeof(int), cudaMemcpyHostToDevice));

    int num_blocks = 1;
    dim3 threads_per_block(3);
    kernel<<<num_blocks, threads_per_block>>>(dev_flat_matrix, dev_vector, dev_answer);

    error_handler(cudaDeviceSynchronize());

    error_handler(cudaMemcpy(answer, dev_answer, SIZE * sizeof(int), cudaMemcpyDeviceToHost));

    for (int i = 0; i < SIZE; ++i)
        cout << answer[i] << " ";
    cout << endl;

}

__host__ int main() {

    matrix_vector_multiplication();

    return 0;
}
