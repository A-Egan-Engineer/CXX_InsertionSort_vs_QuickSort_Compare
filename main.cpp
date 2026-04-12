#include <iostream>
#include "Headers/InsertionSort.h"
#include "Headers/QuickSort.h"
#include <fstream>
#include <chrono>
#include <unistd.h>

using namespace std;

// Creates clock to time execution time of sorts.
typedef chrono::high_resolution_clock Clock;
typedef chrono::milliseconds ms;

int main() {

    // Opens txt file that contains unsorted data set.
    ifstream file1("Input Data/a2_task1_input1.txt");
    if (file1.is_open()) {
        cout << "File opened correctly" << endl;
    }
    if (!file1.is_open()) {
        cout << "Error opening file" << endl;
        return 0;
    }

    // Integer to store count of data in file.
    int count;
    file1 >> count;

    cout << endl;
    cout << "Testing execution time of insertion sort vs quick sort using the same unsorted data set..." << endl;
    sleep(5);
    cout << endl;
    cout << "Total count of integers in .txt: " << count << endl;
    cout << endl;

    // Initialises a dynamic array to store data equal to file count.
    int* arr1 = new int[count];

    // Stores data from file into dynamic array & closes file.
    for (int i = 0; i < count; i++) {
        file1 >> arr1[i];
    }
    file1.close();

    cout << "The data is arranged as follows: " << endl;
    sleep(3);

    // Prints array contents .
    for (int i = 0; i < count; i++) {
        cout << arr1[i] << endl;
    }

    cout << endl;

    cout << "Insertion Sort Executing in 3..." << endl;
    sleep(1);
    cout << endl;
    cout << "2..." << endl;
    sleep(1);
    cout << endl;
    cout << "1..." << endl;
    sleep(1);
    cout << endl;
    cout << "Insertion Sort Executing!" << endl;
    cout << endl;

    // Starts clock, calls insertion sort function and prints sorted array
    // with execution time.
    auto start1 = Clock::now();
    insertionSort(arr1, count);
    auto end1 = Clock::now();
    auto insertionSortTime = chrono::duration_cast<ms>(end1 - start1);
    cout << endl;
    for (int i = 0; i < count; i++) {
        cout << arr1[i] << endl;
    }
    cout << endl;
    cout << "Insertion Sort Execution Time: " << insertionSortTime << endl;

    sleep(3);

    // Deletes array data from heap manually to avoid leak
    delete [] arr1;

    cout << endl;

    ifstream file2("Input Data/a2_task1_input1.txt");
    if (file2.is_open()) {
        cout << "File opened correctly" << endl;
    }
    if (!file2.is_open()) {
        cout << "Error opening file" << endl;
        return 0;
    }

    file2 >> count;

    cout << endl;
    cout << "Total count of integers in .txt: " << count << endl;
    cout << endl;
    sleep(3);

    // An STL vector is used to store file data. Safer as once the
    // vector is out of scope it automatically clears data from
    // the heap, avoiding accidental memory leakage.
    vector<int> arr2(count);

    for (int i = 0; i < count; i++) {
        file2 >> arr2[i];
    }
    file2.close();

    cout << "The data is arranged as follows: " << endl;
    sleep(3);

    for (int i = 0; i < count; i++) {
        cout << arr2[i] << endl;
    }

    cout << endl;

    cout << "Quick Sort Executing in 3..." << endl;
    sleep(1);
    cout << endl;
    cout << "2..." << endl;
    sleep(1);
    cout << endl;
    cout << "1..." << endl;
    sleep(1);
    cout << endl;
    cout << "Quick Sort Executing!" << endl;
    cout << endl;

    // Sets n to size of array
    int n = count;

    // Clock starts, calls quicksort algorithm, stops timer and prints
    // the ordered array.
    auto start2 = Clock::now();
    quicksort(arr2, 0, n - 1);
    auto end2 = Clock::now();
    auto quickSortTime = chrono::duration_cast<ms>(end2 - start2);
    cout << endl;
    for (int i = 0; i < count; i++) {
        cout << arr2[i] << endl;
    }

    // Calls out quicksort execution time, compares the insertion sort time vs quicksort time and prints
    // out which algorithm sorted the data faster based on the times using an if else statement.
    cout << endl;
    cout << "Quick Sort Execution Time: " << quickSortTime << endl;
    cout << endl;

    cout << "Insertion Sort Time: " << insertionSortTime << " vs" << " Quick Sort Time: " << quickSortTime << endl;
    cout << endl;
    if (insertionSortTime < quickSortTime) {
        cout << "Insertion sort algorithm executes faster with unsorted data set!" << endl;
    }
    else {
        cout << "Quick sort algorithm executes faster with unsorted data set!" << endl;
    }
    sleep(5);

    // No need to delete vector array from heap as it is handled automatically

    cout << endl;

    // Opens the nearly sorted txt file for use.
    ifstream file3("Input Data/a2_task1_input2.txt");
    if (file3.is_open()) {
        cout << "File opened correctly" << endl;
    }
    if (!file3.is_open()) {
        cout << "Error opening file" << endl;
    }

    // Uses original count int to store total number
    // of data in file using line one.
    file3 >> count;

    cout << endl;
    cout << "Testing execution time of insertion sort vs quick sort using the same nearly sorted data set..." << endl;
    sleep(5);
    cout << endl;
    cout << "Total number of integers in .txt " << count << endl;

    // A third dynamic array created to hold
    // data from nearly sorted data set.
    int* arr3 = new int[count];

    for (int i = 0; i < count; i++) {
        file3 >> arr3[i];
    }
    file3.close();

    cout << endl;
    cout << "The data is arranged as follows: " << endl;
    sleep(3);

    for (int i = 0; i < count; i++) {
        cout << arr3[i] << endl;
    }

    cout << endl;
    cout << "Insertion Sort Executing in 3..." << endl;
    sleep(1);
    cout << endl;
    cout << "2..." << endl;
    sleep(1);
    cout << endl;
    cout << "1..." << endl;
    sleep(1);
    cout << endl;
    cout << "Insertion Sort Executing!" << endl;
    cout << endl;

    // Clock starts, insertion sort is called on third array storing nearly
    // sorted data, clock ends, ordered array is printed and execution time
    // is printed.
    auto start3 = Clock::now();
    insertionSort(arr3, count);
    auto end3 = Clock::now();
    auto insertionSortTime2 = chrono::duration_cast<ms>(end3 - start3);
    cout << endl;
    for (int i = 0; i < count; i++) {
        cout << arr3[i] << endl;
    }
    cout << endl;
    cout << "Insertion Sort Execution Time: " << insertionSortTime2 << endl;

    sleep(3);

    // Deletes array data from heap manually to avoid leak
    delete [] arr3;

    cout << endl;

    ifstream file4("Input Data/a2_task1_input2.txt");
    if (file4.is_open()) {
        cout << "File opened correctly" << endl;
    }
    if (!file4.is_open()) {
        cout << "Error opening file" << endl;
    }

    file4 >> count;

    cout << endl;
    cout << "Total count of integers in .txt " << count << endl;
    cout << endl;
    sleep(3);

    // Using vector again for final array
    vector<int> arr4(count);

    for (int i = 0; i < count; i++) {
        file4 >> arr4[i];
    }
    file4.close();

    cout << "The data is arranged as follows: " << endl;
    sleep(3);

    for (int i = 0; i < count; i++) {
        cout << arr4[i] << endl;
    }

    cout << endl;

    cout << "Quick Sort Executing in 3..." << endl;
    sleep(1);
    cout << endl;
    cout << "2..." << endl;
    sleep(1);
    cout << endl;
    cout << "1..." << endl;
    sleep(1);
    cout << endl;
    cout << "Quick Sort Executing!" << endl;
    cout << endl;

    // Reusing int n for array size
    n = count;

    // Starts clock, calls quicksort function, ends timer and prints ordered array.
    auto start4 = Clock::now();
    quicksort(arr4, 0, n - 1);
    auto end4 = Clock::now();
    auto quickSortTime2 = chrono::duration_cast<ms>(end2 - start2);
    cout << endl;
    for (int i = 0; i < count; i++) {
        cout << arr4[i] << endl;
    }

    // Calls out quicksort execution time, compares insertion sort vs quicksort time and prints
    // sorting algorith that has faster execution time based on time using if else statement.
    cout << endl;
    cout << "Quick Sort Execution Time: " << quickSortTime2 << endl;
    cout << endl;

    cout << "Insertion Sort Time: " << insertionSortTime2 << " vs" << " Quick Sort Time: " << quickSortTime2 << endl;
    cout << endl;
    if (insertionSortTime2 < quickSortTime2) {
        cout << "Insertion sort algorithm executes faster with unsorted data set!" << endl;
    }
    else {
        cout << "Quick sort algorithm executes faster with unsorted data set!" << endl;
    }
    sleep(5);

    return 0;
};
