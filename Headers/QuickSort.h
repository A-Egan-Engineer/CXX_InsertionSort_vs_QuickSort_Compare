#ifndef CXX_INSERTIONSORT_VS_QUICKSORT_COMPARE_QUICKSORT_H
#define CXX_INSERTIONSORT_VS_QUICKSORT_COMPARE_QUICKSORT_H
#include <vector>

using namespace std;

// Header file to intialise partition
// function and quicksort function.
int partition(vector<int>& arr, int low, int high);

void quicksort(vector<int>& arr, int low, int high);
#endif //CXX_INSERTIONSORT_VS_QUICKSORT_COMPARE_QUICKSORT_H