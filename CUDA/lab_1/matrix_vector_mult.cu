#include <iostream>

// #define SIZE 128 //matrix height/width, for std_kernel
#define SIZE 4 //matrix height/width, for shared_kernel
#define BLOCK_SIZE 2 //threads per block, for shared_kernel

using std::cout;
using std::endl;
using std::cerr;

__global__ void std_kernel(int *matrix, int *vector, int *answer) {
    int t_id = blockDim.x * blockIdx.x + threadIdx.x; // t_id (thread id) <=> column id
    int sum = 0;
    if (t_id < SIZE) {
        for (int i = 0; i < SIZE; ++i)
            sum += matrix[SIZE * i + t_id] * vector[i];
        answer[t_id] = sum;
    }
}

__host__ void error_handler(cudaError_t err) {
    if (err != cudaSuccess) {
        cerr << cudaGetErrorString(err) << endl;
        exit(1);
    }   
}

//init identity matrix
__host__ void init_matrix(int (&matrix)[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
           if (i == j)
               matrix[i][j] = 1;
           else
               matrix[i][j] = 0;
}

__host__ void init_vector(int (&vector)[SIZE]) {
    int n = 1;
    for (int i = 0; i < SIZE; ++i)
        vector[i] = n++;
}

//transpose and transform matrix into vector
__host__ void transpose_matrix(int (&matrix)[SIZE][SIZE], int (&linear_matrix)[SIZE * SIZE]) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            linear_matrix[SIZE * j + i] = matrix[i][j];
}

__host__ void output(int (&answer)[SIZE]) {
    for (int i = 0; i < SIZE; ++i)
        cout << answer[i] << " ";
    cout << endl;
}

__host__ void std_matrix_vector_multiplication() {
    int matrix[SIZE][SIZE] = { {} };
    int vector[SIZE] = {};
    int linear_matrix[SIZE * SIZE] = {};
    int answer[SIZE] = {};

    init_matrix(matrix);
    init_vector(vector);
    transpose_matrix(matrix, linear_matrix);

    int *dev_linear_matrix = NULL;
    int *dev_vector = NULL;
    int *dev_answer = NULL;

    error_handler(cudaMalloc((void**)&dev_linear_matrix, SIZE * SIZE * sizeof(int)));
    error_handler(cudaMalloc((void**)&dev_vector, SIZE * sizeof(int)));
    error_handler(cudaMalloc((void**)&dev_answer, SIZE * sizeof(int)));

    error_handler(cudaMemcpy(dev_linear_matrix, linear_matrix, SIZE * SIZE * sizeof(int), cudaMemcpyHostToDevice));
    error_handler(cudaMemcpy(dev_vector, vector, SIZE * sizeof(int), cudaMemcpyHostToDevice));

    //const int num_blocks = 1;
    //dim3 threads_per_block(32);
    //std_kernel<<<num_blocks, threads_per_block>>>(dev_linear_matrix, dev_vector, dev_answer);
    
    const int threads_per_block = 32;
    std_kernel<<<(SIZE + (threads_per_block - 1))/threads_per_block, threads_per_block>>>(dev_linear_matrix, dev_vector, dev_answer);

    error_handler(cudaMemcpy(answer, dev_answer, SIZE * sizeof(int), cudaMemcpyDeviceToHost));
    output(answer);

    error_handler(cudaFree(dev_linear_matrix));
    error_handler(cudaFree(dev_vector));
    error_handler(cudaFree(dev_answer));
}

__global__ void shared_kernel(int *dev_matrix, int *dev_vector, int *dev_answer) {
    int idx = blockDim.x * blockIdx.x + threadIdx.x;
    int sum = 0;
    __shared__ int vector_cache[SIZE];

    for (int i = 0; i < (SIZE + BLOCK_SIZE - 1)/BLOCK_SIZE; ++i) { //(SIZE + BLOCK_SIZE - 1)/BLOCK_SIZE - total size of blocks 
        int stride = BLOCK_SIZE * i; //offset 
        vector_cache[threadIdx.x] = dev_vector[stride + threadIdx.x];
        __syncthreads();
        for (int j = 0; j < BLOCK_SIZE; ++j) {
            if (stride + j < SIZE)
                sum += dev_matrix[(stride + j) * SIZE + idx] * vector_cache[j];
        }
        __syncthreads();
    }
    dev_answer[idx] = sum;
}

__host__ void shared_matrix_vector_multiplication() {
    // const int matrix[SIZE][SIZE] = {
    //     {1, 0, 0, 0},
    //     {0, 1, 0, 0},
    //     {0, 0, 1, 0},
    //     {0, 0, 0, 1}
    // };
    const int matrix[SIZE][SIZE] = {
        {1, 5, 9, 13},
        {2, 6, 10, 14},
        {3, 7, 11, 15},
        {4, 8, 12, 16}
    };
    //const int vector[SIZE] = {1, 2, 3, 4};
    const int vector[SIZE] = {1, 1, 1, 1};
    int answer[SIZE] = {};

    int *dev_matrix = NULL;
    int *dev_vector = NULL;
    int *dev_answer = NULL;

    //allocate memory on device
    error_handler(cudaMalloc((void**)&dev_matrix, SIZE * SIZE * sizeof(int)));
    error_handler(cudaMalloc((void**)&dev_vector, SIZE * sizeof(int)));
    error_handler(cudaMalloc((void**)&dev_answer, SIZE * sizeof(int)));

    //copy data from host to device
    error_handler(cudaMemcpy(dev_matrix, matrix, SIZE * SIZE * sizeof(int), cudaMemcpyHostToDevice));
    error_handler(cudaMemcpy(dev_vector, vector, SIZE * sizeof(int), cudaMemcpyHostToDevice));

    dim3 blockDim(BLOCK_SIZE);
    dim3 gridDim((SIZE + blockDim.x - 1)/blockDim.x);
    shared_kernel<<<gridDim, blockDim>>>(dev_matrix, dev_vector, dev_answer);
    
    //const int threads_per_block = 2;
    //shared_kernel<<<(SIZE + (threads_per_block - 1))/threads_per_block, threads_per_block>>>(dev_linear_matrix, dev_vector, dev_answer);

    error_handler(cudaMemcpy(answer, dev_answer, SIZE * sizeof(int), cudaMemcpyDeviceToHost));
    output(answer);

    error_handler(cudaFree(dev_matrix));
    error_handler(cudaFree(dev_vector));
    error_handler(cudaFree(dev_answer));
}

__host__ int main() {

    //std_matrix_vector_multiplication();
    shared_matrix_vector_multiplication();

    return 0;
}
