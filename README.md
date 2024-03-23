# Array Inversions Counter

An inversion in an array `Array` is a pair of elements `Array[i]` and `Array[j]` for which the following is true:

- The index `j` is greater than the index `i` : `i < j`    
- The element at index `i` is greater than the element at index `j`: `Array[i] > Array[j]`

Counting inversions is a common problem in computer science, and is often used to assess the degree of "sortedness" of an array. This problem can be easily solved by a strategy that uses nested loops, however this requires **Θ(n²)** time, making it inefficient for large arrays.  

This implementation solves this problem in **Θ(n log n)** time using by utilizing the merge sort algorithm.



## Input format: ##
The program expects an input file passed as a command-line argument. The input file should be formatted as follows:

- The first line contains a single integer, `n`, representing the number of elements in the array.
- The subsequent `n` lines contain the integers of the array, one per line.

### Example input: ###
```
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
```

## Compilation and Execution

To run this program, you will need to compile the C++ code and execute the resulting executable, passing the path to your input file as a command line argument.
First, ensure you have a C++ compiler (like `g++`) installed on your system. Compile the source code using the following command:

```bash
g++ inversions.cpp -o inv_counter
```

Then execute the program with the following command, replacing `<input_file>` with the path to the file containing the array elements:

```
./inv_counter <input_file>
```
