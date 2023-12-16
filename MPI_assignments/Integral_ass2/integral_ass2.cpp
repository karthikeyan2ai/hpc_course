#include <iostream>
#include <cmath>
#include <mpi.h>

double f(double x) {
    return x * x;
}

double midpoint_method(double a, double b, int n) {
    double h = (b - a) / n;
    double partial_sum = 0.0;

    for (int i = 1; i <= n; i++) {
        double x = a + (i - 0.5) * h;
        partial_sum += f(x);
    }

    return partial_sum * h;
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double a = 0.0;
    double b = 2.0;
    int n = 10;

    // Distribute subintervals among processes
    int local_n = n / size;
    double local_a = a + rank * local_n * (b - a) / n;
    double local_b = local_a + local_n * (b - a) / n;

    double start_time = MPI_Wtime(); 

    // Perform partial calculation
    double local_result = midpoint_method(local_a, local_b, local_n);

    // Gather partial results on the root process
    double global_result;
    if (rank == 0) {
        global_result = local_result;
        for (int i = 1; i < size; i++) {
            double partial_result;
            MPI_Recv(&partial_result, 1, MPI_DOUBLE, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            global_result += partial_result;
        }
    } else {
        MPI_Send(&local_result, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }

    if (rank == 0) {
        std::cout << "Approximation of the integral: " << global_result << std::endl;
    }
    double end_time = MPI_Wtime(); 
    double elapsed_time = end_time - start_time; // Calculate elapsed time
    std::cout << "Process " << rank << ": Elapsed time = " << elapsed_time << " seconds" << std::endl;
    MPI_Finalize();
    return 0;
}
