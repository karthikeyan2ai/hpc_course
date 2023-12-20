#include <iostream>
#include <fstream>
#include <vector>
#include <cuda_runtime.h>

#define RADIUS 9
#define BLOCK_SIZE 256

__global__ void stencil_average(float *input, float *output, int size)
{
    __shared__ float temp[BLOCK_SIZE + 2*RADIUS];
    int gindex = threadIdx.x + blockDim.x * blockIdx.x;
    int lindex = threadIdx.x + RADIUS;
   
    temp[lindex] = input[gindex];
    if(threadIdx.x < RADIUS){
        temp[lindex-RADIUS] = input[gindex-RADIUS];
        temp[lindex+BLOCKSIZE] = input[gindex+BLOCKSIZE];
    }
 
    __syncthreads();
    float result = 0;
    for(int offset=-RADIUS;offset<=RADIUS;offset++){
        result += temp[lindex+offset];
    }
    if(gindex < size){
        output[gindex] = result/(RADIUS*2+1);
    }
}

int main()
{
    const int size = 1000000;
    float *host_input = new float[size];
    float *host_output = new float[size];
    std::ifstream infile("input.txt");
    int i = 0;
    while (infile >> host_input[i])
    {
        i++;
    }
    float *device_input, *device_output;
    cudaMalloc(&device_input, size * sizeof(float));
    cudaMalloc(&device_output, size * sizeof(float));
    cudaMemcpy(device_input, host_input, size * sizeof(float), cudaMemcpyHostToDevice);

    dim3 block_size(BLOCK_SIZE);
    dim3 gridevice_size((size + block_size.x - 1) / block_size.x);

    stencil_average<<<gridevice_size, block_size>>>(device_input, device_output, size);

    cudaMemcpy(host_output, device_output, size * sizeof(float), cudaMemcpyDeviceToHost);
    cudaFree(device_input);
    cudaFree(device_output);

    std::cout << "Sample Output for 100 :" << std::endl;

    for(int i=0;i<100;++i){
        std::cout << host_output[i] << std::endl;
    }

    std::cout << "Sample Input for 100 :" << std::endl;
    for(int i=0;i<size;++i){
        std::cout << host_input[i] << std::endl;

    delete[] host_input;
    delete[] host_output;
    return 0;
}
