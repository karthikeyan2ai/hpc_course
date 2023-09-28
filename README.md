# hpc_course
some of hpc parallel programming code
# assignment 1: Fibonacci series with openmp
Used shared variable and critical and calculated time taken for different number of threads unfortunately time taken increases with thread
# serial code result
# Parallel code Result 
Input 10

Time taken with 1 threads: 3 microseconds

0 1 1 2 3 5 8 13 21 34 

Time taken with 2 threads: 59 microseconds

0 1 1 2 3 5 8 13 21 34 

Time taken with 3 threads: 51 microseconds

0 1 1 2 3 5 8 13 21 34 

Time taken with 4 threads: 96 microseconds

###  code needs to evaluated again

# assigmnet 3: integral of function

used reduction, shared and private; there is reduction in time and parallelisation achieved

# serial code result

input x:  1000 note: function is sin(x)

Integral value: 0.239812

Time taken: 17694 microseconds

# parallel code result

input x:  1000 note: function is sin(x)

Integral value: 0.239812

Time taken: 8873 microseconds

