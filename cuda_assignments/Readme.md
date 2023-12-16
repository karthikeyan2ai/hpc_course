## Read given text file with 1 million random number in range 0 to 99. Do stencil average with radius of 9 using cpp cuda programming

### Assumed input is 1D array and did a radius 9 average which will average all 19 nearest number with pivot number at centroid.

### Assumed reading numbers in the text file as 2D array of 1000X1000 pixel. This time average is of 19X19 neighbourhood pixels. 

### Did this exercise because it resembes weighted sum or convulution operation with weight as 1 so no multiplication but sum. 

## Learnings

1. copying from host to device and back
2. Block , thread and stencil radius
