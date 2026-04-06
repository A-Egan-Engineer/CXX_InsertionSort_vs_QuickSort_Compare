#include <iostream>
#include "Headers/InsertionSort.h"
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
    auto insertionTime = chrono::duration_cast<ms>(end1 - start1);
    cout << endl;
    for (int i = 0; i < count; i++) {
        cout << arr1[i] << endl;
    }
    cout << endl;
    cout << "Insertion Sort Execution Time: " << insertionTime.count() << " ms" << endl;

    delete [] arr1;

    ifstream file2("Input Data/a2_task2_input1.txt");
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

    int* arr2 = new int[count];

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

    auto start2 = Clock::now();

    return 0;
};
