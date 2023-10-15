### To run the code

mpic++ midpoint_mpi.cpp -o midpoint_mpi

mpirun -n <number_of_processes> ./midpoint_mpi

### Problem explained with example

Let’s say we want to approximate the integral of the function f(x) = x^2 on the interval [0, 2] using 4 subintervals.

Interval: [a, b] = [0, 2]
Number of subintervals: n = 4
Width of each subinterval: h = (2 - 0) / 4 = 0.5
Midpoints: x1 = 0 + (1 - 0.5) * 0.5 = 0.25, x2 = 0 + (2 - 0.5) * 0.5 = 0.75, x3 = 0 + (3 - 0.5) * 0.5 = 1.25, x4 = 0 + (4 - 0.5) * 0.5 = 1.75
Function values: f(x1) = 0.25^2 = 0.0625, f(x2) = 0.75^2 = 0.5625, f(x3) = 1.25^2 = 1.5625, f(x4) = 1.75^2 = 3.0625
Approximation of the integral: Σ[f(xi) * h] = (0.0625 * 0.5) + (0.5625 * 0.5) + (1.5625 * 0.5) + (3.0625 * 0.5) = 2.125
Therefore, the midpoint method approximation of the integral of f(x) = x^2 on the interval [0, 2] using 4 subintervals is 2.125.
