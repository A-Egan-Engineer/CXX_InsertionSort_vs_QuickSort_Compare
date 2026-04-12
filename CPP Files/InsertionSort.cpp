#include <iostream>
#include "../Headers/InsertionSort.h"

using namespace std;
// Insertion sort function which sorts a data set
// by iteratively inserting the unordered into the
// correct position within the array.
void insertionSort(int arr[], int n) {
    for (int i = 1 ; i < n ; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to iterate through the array, and
// call out the data stored in the array.
void printArray(int arr[], int n) {
    for (int i = 0 ; i < n ; i++) {
        cout << arr[i] << " ";
        cout << endl;
    }
}