#include <iostream>
#include <fstream>
#include <cstdlib> 

/* Implemented by João Chervinski (2017) */

using namespace std;

long int inversions = 0; // Counter for the number of inversions

void merge(int *array, int start, int end, int middle, int *aux) {
    int auxIndex = start; // Temp array index
    int firstHalfIndex = start; // First subarray index
    int secondHalfIndex = middle + 1; // Second subarray index

    while (firstHalfIndex <= middle && secondHalfIndex <= end) {
        if (array[secondHalfIndex] >= array[firstHalfIndex]) {
            // The order is already correct
            aux[auxIndex++] = array[firstHalfIndex++];
        } else {
            // Perform inversion
            aux[auxIndex++] = array[secondHalfIndex++];
            inversions += (middle + 1 - firstHalfIndex); 
        }
    }

    // Copy the remaining elements from left subarray
    while (firstHalfIndex <= middle) {
        aux[auxIndex++] = array[firstHalfIndex++];
    }

    // Copy the remaining elements from right subarray
    while (secondHalfIndex <= end) {
        aux[auxIndex++] = array[secondHalfIndex++];
    }

    // Copy all elements back to the original array
    for (int i = start; i <= end; i++) {
        array[i] = aux[i];
    }
}

void mergeSort(int *array, int start, int end, int *aux) {
    if (start < end) {
        int middle = (start + end) / 2;

        // Calls sort for each one of the halves
        mergeSort(array, start, middle, aux);

        // Merge the halves together
        mergeSort(array, middle + 1, end, aux);
        merge(array, start, end, middle, aux);
    }
}

int main(int argc, char* argv[]) {
    inversions = 0; // Initialize counter as 0

    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return EXIT_FAILURE;
    }

    ifstream file(argv[1]);

    // Check if the input file has been opened successfully
    if (!file.is_open()) {
        cout << "Error reading the file!" << endl;
        return EXIT_FAILURE;
    }

    int n; // Number of items in the array
    file >> n;

    // Allocate the array and auxiliary array
    int *aux = new int[n];
    int *array = new int[n];

    // Read the array items from the input file
    for (int i = 0; i < n; i++) {
        file >> array[i];
    }

    file.close(); 

    // Sort and count the number of inversions
    mergeSort(array, 0, n - 1, aux);

    cout << "[+] Number of inversions: " << inversions << endl;
  
    delete[] aux;
    delete[] array;

    return 0;
}
