## Read given text file with 1 million random number in range 0 to 99. Do stencil average with radius of 9 using cpp cuda programming

### Assumed input is 1D array and did a radius 9 average which will average all 19 nearest number with pivot number at centroid.
1d_stencil_average_with_radius_9.cpp

### Assumed reading numbers in the text file as 2D array of 1000X1000 pixel. This time average is of 19X19 neighbourhood pixels. 
2d_stencil_average_with_radius_9.cpp

### Did this exercise in 2D because it resembes weighted sum or convulution operation with weight as 1 so no multiplication but sum. 

## Learnings

1. copying from host to device and back
2. Block , thread and stencil radius
