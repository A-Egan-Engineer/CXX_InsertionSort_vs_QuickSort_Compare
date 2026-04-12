#include "../Headers/QuickSort.h"

using namespace std;

// Partition function that chooses the pivot, and indicates the
// right position of pivot. It then divides the data based on whether
// it is lower or higher than the pivot and swaps as required.
int partition(vector<int>& arr, int low, int high) {

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quicksort function the uses recursion to create sub-arrays
// and chooses a picot using the partition function, sorting
// smaller numbers before the pivot and larger numbers after.
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}