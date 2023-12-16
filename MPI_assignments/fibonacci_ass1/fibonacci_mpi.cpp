#include <iostream>
#include <mpi.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char** argv) {
    int rank, size;
    int n = 10; 

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int local_start = rank * (n / size);
    int local_end = (rank + 1) * (n / size);

    double start_time = MPI_Wtime(); 

    for (int i = local_start; i < local_end; i++) {
        int result = fibonacci(i);
        std::cout << "Process " << rank << ": Fibonacci(" << i << ") = " << result << std::endl;
    }

    double end_time = MPI_Wtime(); 

    double elapsed_time = end_time - start_time; // Calculate time

    std::cout << "Process " << rank << ": Elapsed time = " << elapsed_time << " seconds" << std::endl;

    MPI_Finalize();
    return 0;
}
