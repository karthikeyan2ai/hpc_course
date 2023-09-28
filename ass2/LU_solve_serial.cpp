#include <iostream>
#include <chrono>
#include <random>

using namespace std;

int main()
{
    // Generate random matrix and vector
    double A[1000][1000];
    double b[1000];
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            A[i][j] = distribution(generator);
        }
        b[i] = distribution(generator);
    }

    // Start timer
    auto start = std::chrono::high_resolution_clock::now();

    // Perform LU factorization
    for (int k = 0; k < 1000;k++) {
        for (int i = k + 1; i < 1000; i++) {
            A[i][k] /= A[k][k];
            for (int j = k + 1; j < 1000; j++) {
                A[i][j] -= A[i][k] * A[k][j];
            }
        }
    }

    // LU Solve 
    for (int k = 1; k < 1000; k++) {
        for (int i = k; i < 1000; i++) {
            b[i] -= A[i][k - 1] * b[k - 1];
        }
    }
    for (int k = 999; k >= 0; k--) {
        b[k] /= A[k][k];
        for (int i = 0; i < k; i++) {
            b[i] -= A[i][k] * b[k];
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // Print
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
    // Print solution
   std::cout << "Solution of first 10 elements alone:" << std::endl;
   for (int i = 0; i < 10; i++) {
     std::cout << b[i] << std::endl;
   }
}
    
