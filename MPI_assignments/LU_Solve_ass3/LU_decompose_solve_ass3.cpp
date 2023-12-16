#include <iostream>
#include <vector>
#include <mpi.h>

// Function to perform LU decomposition
void luDecomposition(std::vector<std::vector<double>>& A, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = k + 1; i < n; i++) {
            A[i][k] /= A[k][k];
            for (int j = k + 1; j < n; j++) {
                A[i][j] -= A[i][k] * A[k][j];
            }
        }
    }
}

// Function to solve the linear system using LU decomposition
void luSolve(std::vector<std::vector<double>>& A, std::vector<double>& b, std::vector<double>& x, int n) {
    // Forward substitution
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            b[i] -= A[i][j] * x[j];
        }
        x[i] = b[i];
    }

    // Backward substitution
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int n = 1000;
    int local_n = n / size;

    // Generate the matrix A and vector b
    std::vector<std::vector<double>> A(n, std::vector<double>(n));
    std::vector<double> b(n);
    std::vector<double> x(n);

    // Initialize A and b with random values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 100;
        }
        b[i] = rand() % 100;
    }

    // Distribute submatrices among processes
    std::vector<std::vector<double>> local_A(local_n, std::vector<double>(n));
    std::vector<double> local_b(local_n);
    std::vector<double> local_x(local_n);

    MPI_Scatter(A.data(), local_n * n, MPI_DOUBLE, local_A.data(), local_n * n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Scatter(b.data(), local_n, MPI_DOUBLE, local_b.data(), local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Perform LU decomposition
    luDecomposition(local_A, local_n);

    // Gather the updated submatrices on the root process
    MPI_Gather(local_A.data(), local_n * n, MPI_DOUBLE, A.data(), local_n * n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Solve the linear system using LU decomposition
    luSolve(A, b, x, n);

    // Gather the solution vector on the root process
    MPI_Gather(local_x.data(), local_n, MPI_DOUBLE, x.data(), local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        // Print the solution vector
        for (int i = 0; i < n; i++) {
            std::cout << "x[" << i << "] = " << x[i] << std::endl;
        }
    }

    MPI_Finalize();
    return 0;
}
