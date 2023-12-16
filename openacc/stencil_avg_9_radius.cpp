#include <iostream>
#include <fstream>
#include <vector>
#include <openacc.h>

#define RADIUS 9

void stencil_average(float *input, float *output, int size)
{
    #pragma acc data copyin(input[0:size]) copyout(output[0:size])
    {
        #pragma acc parallel loop gang vector_length(256)
        for (int idx = 0; idx < size; idx++)
        {
            float pix_val = 0;
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
}

int main()
{
    const int size = 1000000;
    float *h_input = new float[size];
    float *h_output = new float[size];
    std::ifstream infile("data-age.txt");
    int i = 0;
    while (infile >> h_input[i])
    {
        i++;
    }
    stencil_average(h_input, h_output, size);
    delete[] h_input;
    delete[] h_output;

    return 0;
}
