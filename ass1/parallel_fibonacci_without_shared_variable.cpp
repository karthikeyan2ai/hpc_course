#include <iostream>
#include <omp.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int n = 10; // number of terms in the series
    int fib[n];

    // initialize the first two terms
    fib[0] = 0;
    fib[1] = 1;

    // calculate the series in parallel using OpenMP
    for (int num_threads = 1; num_threads <= 4; num_threads++) {
        omp_set_num_threads(num_threads); // set the number of threads
        auto start_time = high_resolution_clock::now(); // start the timer
        #pragma omp parallel for
        for (int i = 2; i < n; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        auto end_time = high_resolution_clock::now(); // end the timer
        auto duration = duration_cast<microseconds>(end_time - start_time); // calculate the duration
        cout << "Time taken with " << num_threads << " threads: " << duration.count() << " microseconds" << endl;

        // print the series
        for (int i = 0; i < n; i++) {
            cout << fib[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
