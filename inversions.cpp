#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

long int inversions = 0; // long int should be enough for arrays with around 100000 items

int merge(int *array, int start, int end, int middle, int *aux){
  int auxIndex = start; // Temporary array index
  int firstHalfIndex = start; // First subarray index
  int secondHalfIndex = middle + 1; // Second subarray index

  while(firstHalfIndex <= middle && secondHalfIndex <= end){
    // While the index of the first subarray is not at the middle or the index of
    // the second subarray is not at the end, continue
    if (array[secondHalfIndex] >= array[firstHalfIndex]){
      // The value at the current position on the second subarray is greater than the value
      // at the current position of the first subarray, therefore, there are no inversions
      aux[auxIndex] = array[firstHalfIndex]; // Moves the smallest value to the sorted array
      firstHalfIndex++;
    }
    else{
      // The value at the current position on the first subarray is greater than the value
      // at the current position of the second subarray, therefore, there are inversions.
      // Knowing that the first subarray is sorted, all the items that come after the current
      // position are also greater than the current item in the second subarray, so we add
      // the number of items from the current position until the end of the first subarray to the
      // inversions counter
      aux[auxIndex] = array[secondHalfIndex]; // Inserts the smallest value in the sorted array
      secondHalfIndex++;
      inversions += (middle + 1 - firstHalfIndex);
    }
    auxIndex++;
  }

  if(secondHalfIndex > end){
    // If the second subarray reaches the end first, copy the remaining items from the
    // first subarray to the sorted array
    for(int i = firstHalfIndex; i <= middle; i++){
      aux[auxIndex] = array[i];
      auxIndex++;
    }
  }

  else if(firstHalfIndex > middle){
    // If the first subarray reaches the end first, copy the remaining items from the
    // second subarray to the sorted array
    for(int i = secondHalfIndex; i <= end; i++){
      aux[auxIndex] = array[i];
      auxIndex++;
    }
  }

  // Copies the values from the temporary array to the original array
  for(int i = 0; i <= end; i++){
    array[i] = aux[i];
  }
}


int mergeSort(int *array, int start, int end, int *aux){
  if (end > start){
    int middle = floor((start + end)/2);

    // Calls sort for each one of the halves
    mergeSort(array, start, middle, aux);
    mergeSort(array, middle+1, end, aux);

    // Merges the halves together
    merge(array, start, end, middle, aux);
  }
}


int main(int argc, char* argv[]){
  int n; // Number of itens in the array

  ifstream file(argv[1]);

  if(file == NULL){
    cout << "Error reading the file!" << endl;
    exit(EXIT_FAILURE);
  }

  file >> n;

  int *aux = new int[n];
  int *array = new int[n];

  for(int i = 0; i <= n; i++){
    file >> array[i];
  }

  file.close();

  mergeSort(array, 0, n-1, aux);

  cout << "[+] Number of inversions: " << inversions << endl;
  
  delete(aux, array);
}
