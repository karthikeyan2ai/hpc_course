#include <iostream>
#include <fstream>
#include <vector>
#include <cuda_runtime.h>

#define RADIUS 9
#define BLOCK_SIZE 256

__global__ void stencil_average(int *input, int *output, int width, int height)
{
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < height && col < width)
    {
        int 2d_sum = 0;
        int count = 0;
        for (int i = -RADIUS; i <= RADIUS; i++)
        {
            for (int j = -RADIUS; j <= RADIUS; j++)
            {
                int cur_row = row + i;
                int cur_col = col + j;
                if (cur_row >= 0 && cur_row < height && cur_col >= 0 && cur_col < width)
                {
                    2d_sum += input[cur_row * width + cur_col];
                    count++;
                }
            }
        }
        output[row * width + col] = 2d_sum / count;
    }
}

int main()
{
    // assume 1D array input as 1000x1000 2d array i.e doing 2d stencil average instead of 1d average
  
    const int width = 1000;
    const int height = 1000;
    const int size = width * height;
    int *h_input = new int[size];
    int *h_output = new int[size];
    
    std::ifstream infile("input.txt");
    int i = 0;
    while (infile >> h_input[i])
    {
        i++;
    }

    int *d_input, *d_output;
    cudaMalloc(&d_input, size * sizeof(int));
    cudaMalloc(&d_output, size * sizeof(int));

    cudaMemcpy(d_input, h_input, size * sizeof(int), cudaMemcpyHostToDevice);

    dim3 block_size(BLOCK_SIZE, BLOCK_SIZE);
    dim3 grid_size((width + block_size.x - 1) / block_size.x, (height + block_size.y - 1) / block_size.y);

    stencil_average<<<grid_size, block_size>>>(d_input, d_output, width, height);

    cudaMemcpy(h_output, d_output, size * sizeof(int), cudaMemcpyDeviceToHost);

    cudaFree(d_input);
    cudaFree(d_output);

    delete[] h_input;
    delete[] h_output;

    return 0;
}
