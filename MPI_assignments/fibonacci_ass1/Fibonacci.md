### To run the code
mpic++ fibonacci.cpp -o fibonacci

mpirun -np <number_of_processes> ./fibonacci

output:

Process 0: Fibonacci(0) = 0
Process 0: Fibonacci(1) = 1
Process 0: Fibonacci(2) = 1
Process 0: Fibonacci(3) = 2
Process 0: Fibonacci(4) = 3
Process 0: Fibonacci(5) = 5
Process 0: Fibonacci(6) = 8
Process 0: Fibonacci(7) = 13
Process 0: Fibonacci(8) = 21
Process 0: Fibonacci(9) = 34
Process 0: Elapsed time = 6.1089e-05 seconds
