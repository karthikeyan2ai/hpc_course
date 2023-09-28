#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

// Define the function to integrate
double f(double x, double y) {
    return sin(x*y);
}

int main() {
    // Define the number of intervals in each dimension
    int n = 1000;

    // Define the step size in each dimension
    double h = 1.0/n;

    // Define the midpoint of each interval in each dimension
    double x, y, xm, ym;

    // Initialize the integral value
    double integral = 0.0;

    // Start the timer
    auto start = high_resolution_clock::now();

    // Perform the midpoint method
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Calculate the midpoint of the current interval
            xm = (i + 0.5)*h;
            ym = (j + 0.5)*h;

            // Add the contribution of the current interval to the integral
            integral += f(xm, ym)*h*h;
        }
    }

    // Stop the timer
    auto stop = high_resolution_clock::now();

    // Calculate the time taken for the computation
    auto duration = duration_cast<microseconds>(stop - start);

    // Print the result and the time taken
    cout << " input x:  " << n << " note: function is sin(x)"<< endl;
    cout << "Integral value: " << integral << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}
