# hpc_course
some of hpc parallel programming code
# assignment 1: Fibonacci series with openmp
Used shared variable and critical and calculated time taken for different number of threads unfortunately time taken increases with thread
# serial code result

Time taken in serial: 0 microseconds

0 1 1 2 3 5 8 13 21 34 

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
# ass1 learning

### shared 
all threads can access and modify the variable.
### critical
specify a section of code that must be executed by only one thread at a time.

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

# ass3 learning
understood reduction and private
## Reduction
The reduction operation combines the values of the variable across all threads, and the final result is stored in the original variable. For example, in the code above, we use reduction(+:integral) to specify that the integral variable should be summed across all threads. This ensures that each thread has its own copy of the integral variable, and the final result is the sum of all the thread-local copies.

## private

 This is useful when each thread needs its own copy of a variable to avoid race conditions or to ensure thread safety. In the code above, we use private(x, y, xm, ym) to specify that the x, y, xm, and ym variables should have a separate copy for each thread. This ensures that each thread has its own copy of these variables, and they are not shared among threads.
