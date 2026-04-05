#include <iostream>
#include "Headers/InsertionSort.h"
#include <fstream>
#include <chrono>
#include <unistd.h>

using namespace std;

typedef chrono::high_resolution_clock Clock;
typedef chrono::milliseconds ms;

int main() {

    ifstream file("Input Data/a2_task1_input1.txt");
    if (file.is_open()) {
        cout << "File opened correctly" << endl;
    }
    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return 0;
    }

    int count;

    cout << endl;
    file >> count;
    cout << endl;
    cout << "Total count of intergers in .txt: " << count << endl;
    cout << endl;

    int* arr1 = new int[count];

    for (int i = 0; i < count; i++) {
        file >> arr1[i];
    }
    file.close();

    for (int i = 0; i < count; i++) {
        cout << arr1[i] << endl;
    }

    cout << endl;

    auto start1 = Clock::now();
    insertionSort(arr1, count);
    auto end1 = Clock::now();
    auto executionTime1 = chrono::duration_cast<ms>(end1 - start1);
    cout << "Execution Time: " << executionTime1.count() << " ms" << endl;

    delete [] arr1;

    return 0;
}
