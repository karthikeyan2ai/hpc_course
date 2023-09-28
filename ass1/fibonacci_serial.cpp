#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    int n = 10; // number of terms in the series
    int fib[n];

    // initialize the first two terms
    fib[0] = 0;
    fib[1] = 1;

    // calculate the series in serial
    auto start_time = high_resolution_clock::now(); // start the timer
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    auto end_time = high_resolution_clock::now(); // end the timer
    auto duration = duration_cast<microseconds>(end_time - start_time); // calculate the duration
    cout << "Time taken in serial: " << duration.count() << " microseconds" << endl;

    // print the series
    for (int i = 0; i < n; i++) {
        cout << fib[i] << " ";
    }
    cout << endl;

    return 0;
}
