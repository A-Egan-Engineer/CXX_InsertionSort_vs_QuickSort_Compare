#include <iostream>
#include "Headers/InsertionSort.h"
#include "Headers/QuickSort.h"
#include <fstream>
#include <chrono>
#include <unistd.h>

using namespace std;

typedef chrono::high_resolution_clock Clock;
typedef chrono::milliseconds ms;

int main() {

    ifstream file1("Input Data/a2_task1_input1.txt");
    if (file1.is_open()) {
        cout << "File opened correctly" << endl;
    }
    if (!file1.is_open()) {
        cout << "Error opening file" << endl;
        return 0;
    }

    int count;

    cout << endl;
    file1 >> count;
    cout << endl;
    cout << "Total count of integers in .txt: " << count << endl;
    cout << endl;

    int* arr1 = new int[count];

    for (int i = 0; i < count; i++) {
        file1 >> arr1[i];
    }
    file1.close();

    cout << "The data is arranged as follows: " << endl;
    sleep(3);

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

    auto start1 = Clock::now();
    insertionSort(arr1, count);
    auto end1 = Clock::now();
    auto insertionSortTime = chrono::duration_cast<ms>(end1 - start1);
    cout << endl;
    for (int i = 0; i < count; i++) {
        cout << arr1[i] << endl;
    }
    cout << endl;
    cout << "Insertion Sort Execution Time: " << insertionSortTime.count() << " ms" << endl;

    sleep(3);

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

    cout << endl;
    file2 >> count;
    cout << endl;
    cout << "Total count of integers in .txt: " << count << endl;
    cout << endl;
    sleep(3);

    vector<int> arr2(count);

    for (int i = 0; i < count; i++) {
        file2 >> arr2[i];
    }
    file2.close();

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

    int n = arr2.size();

    auto start2 = Clock::now();
    quicksort(arr2, 0, n - 1);
    auto end2 = Clock::now();
    auto quickSortTime = chrono::duration_cast<ms>(end2 - start2);
    cout << endl;
    for (int i = 0; i < count; i++) {
        cout << arr2[i] << endl;
    }

    cout << endl;
    cout << "Quick Sort Execution Time: " << quickSortTime << endl;
    return 0;
};
