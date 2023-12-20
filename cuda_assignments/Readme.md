## Read given text file with 1 million random number in range 0 to 99. Do stencil average with radius of 9 using cpp cuda programming

### Assumed input is 1D array and did a radius 9 average which will average all 19 nearest number with pivot number at centroid.
1d_stencil_average_with_radius_9.cu

## RUN USING CMD

nvcc 1d_stencil_average_with_radius_9.cu

## Output

First 10 inputs :
98
46
14
28
60
31
10
82
80
90
First 10 outputs :
28.3684
30.4737
34.3684
35.8947
38.4737
42.8947
43.4737
43.8421
48.6842
50.2105

### Assumed reading numbers in the text file as 2D array of 1000X1000 pixel. This time average is of 19X19 neighbourhood pixels. 
2d_stencil_average_with_radius_9.cpp

### Did this exercise in 2D because it resembes weighted sum or convulution operation with weight as 1 so no multiplication but sum. 

## Learnings

1. copying from host to device and back
2. Block , thread and stencil radius
