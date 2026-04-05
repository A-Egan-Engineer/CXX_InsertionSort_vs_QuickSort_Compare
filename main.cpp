#include <iostream>
#include "Headers/InsertionSort.h"

using namespace std;

int main() {

    int arr[] = {12,11,13,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << endl;
    printArray(arr, n);
    cout << endl;
    insertionSort(arr, n);
    cout << endl;
    printArray(arr, n);
    cout << endl;

    return 0;
}
