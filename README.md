# Array Inversions
The number of inversions is given by the number of pairs (i,j) in the array for which the following is true:   
*The index j is greater than the index i : **i < j**    
*The value in the position given by index i is greater than the value in the position given by j: **Array[i] > Array[j]**    

This problem can be easily solved using two for loops, but that takes **Θ(n²)** which is not very efficient for large arrays.   
This code aims to solve this problem in **Θ(n log n)** time using merge sort, which is an divide and conquer algorithm. 

The code takes a text file as input, via command line argument. The first line must contain the number of items in the array,   
while the following lines have one value each.

**Example:**   

10   
54044   
14108   
79294   
29649   
25260   
60660   
2995   
53777   
49689   
9083   
   
# To run the code:   
Compile using g++ and run the executable ./<executable> <txt>
