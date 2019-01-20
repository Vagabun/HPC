#include <iostream>

#define SIZE 4
#define BLOCK_SIZE 16

using namespace std;

typedef void (*dev_func_t)(int *element);

__device__ void mult_by_2(int *element) { //<=> callback
    *element *= 2;
}

__global__ void kernel(int *dev_matrix, dev_func_t dev_function) {
    int idx = blockDim.x * blockIdx.x + threadIdx.x; //column
    if (idx < SIZE) {
        for (int i = 0; i < SIZE; ++i)
            (*dev_function)(&dev_matrix[SIZE * i + idx]);
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

//static pointer to device function
__device__ dev_func_t p_func = mult_by_2;

__host__ void map() {

    int matrix[SIZE][SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Initial matrix" << endl;
    output(matrix);

    int *dev_matrix = NULL;

    dev_func_t h_func; //host pointer to device func

    error_handler(cudaMalloc((void**)&dev_matrix, SIZE * SIZE * sizeof(int)));
    error_handler(cudaMemcpy(dev_matrix, matrix, SIZE * SIZE * sizeof(int), cudaMemcpyHostToDevice));
    error_handler(cudaMemcpyFromSymbol(&h_func, p_func, sizeof(dev_func_t)));

    dev_func_t callback = h_func;

    //kernel start
    //kernel<<<1, 1>>>(dev_matrix, myfunc); //test

    dim3 blockDim(BLOCK_SIZE);
    dim3 gridDim((SIZE + BLOCK_SIZE - 1)/BLOCK_SIZE, (SIZE + BLOCK_SIZE - 1)/BLOCK_SIZE);
    kernel<<<gridDim, blockDim>>>(dev_matrix, callback);

    error_handler(cudaMemcpy(matrix, dev_matrix, SIZE * SIZE * sizeof(int), cudaMemcpyDeviceToHost));

    cout << endl << "After Map (multiply each element by 2):" << endl;
    output(matrix);

    error_handler(cudaFree(dev_matrix));
}

__host__ int main() {

    map();
    return 0;
}