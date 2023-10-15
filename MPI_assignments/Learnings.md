## Assignment 1: Fibonacci series
 Understood MPI communicator

  Communicator is an object that defines a group of processes that can communicate with each other. 
  It acts as a virtual communication network that allows processes to send and receive messages.
  
  MPI_RANK is a predefined constant that represents the rank or identifier of a process within a communicator.
  Each process in an MPI program is assigned a unique rank, starting from 0 and incrementing sequentially.


## Assignment 2: Integral - Midpoint method

Learned to use MPI send and Receive

MPI_Send and MPI_Recv are used for point-to-point communication between two processes.

MPI_Send sends data from one process to another process.

MPI_Recv receives data sent by another process.

These functions are blocking, meaning they will not return until the communication is complete.
They require explicit specification of the source and destination processes.

## Assignment 3: LU Solve

Learned to use MPI_Scatter and MPI_Gather

MPI_Gather is a collective operation, meaning all processes in the communicator must participate.
The root process receives the gathered data in the receive buffer.

MPI_Scatter is a collective operation, meaning all processes in the communicator must participate.
Each process receives a portion of the scattered data in its receive buffer.
