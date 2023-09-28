#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;

    cout << "Enter a positive integer: ";
    cin >> n;

    // check if the input is valid
    if (n <= 0)        {
 cout << "Invalid input!";
        return 0;
    }

    // generate the Fibonacci series and measure the time taken
    auto start = high_resolution_clock::now();
    cout << t1 << " " << t2 << " ";
    for (int i = 3; i <= n; ++i) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        cout << nextTerm << " ";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // print the time taken
    cout << "\nTime taken: " << duration.count() << " microseconds" << endl;

    return 0;
}
