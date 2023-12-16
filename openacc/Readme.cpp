### How to run this file

Either run it with gcc
g++ -fopenacc -O2 -o stencil_avg_9_radius stencil_avg_9_radius.cpp

Or run it with PGI compiler
pgc++ -acc -fast -Minfo=accel stencil_avg_9_radius.cpp -o stencil_avg_9_radius

This generates executable "stencil_avg_9_radius"

run the executable as " ./stencil_avg_9_radius "
