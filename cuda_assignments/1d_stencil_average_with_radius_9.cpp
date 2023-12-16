#include <iostream>
#include <fstream>
#include <vector>
#include <cuda_runtime.h>

#define RADIUS 9
#define BLOCK_SIZE 256

__global__ void stencil_average(float *input, float *output, int size)
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < size)
    {
        float val = 0;
        int count = 0;
        for (int i = -RADIUS; i <= RADIUS; i++)
        {
            int cur_idx = idx + i;
            if (cur_idx >= 0 && cur_idx < size)
            {
                val += input[cur_idx];
                count++;
            }
        }
        output[idx] = val / count;
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

    delete[] host_input;
    delete[] host_output;
    return 0;
}
