#include<iostream>
using namespace std;

int partition( int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;
    
    for(int i = start + 1; i <= end; i++) {
        if(arr[i] <= pivot) {
            count++;
        }

    }

    int pivotIndex = start + count;

    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
    if(start >= end)return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);

    quickSort(arr, p + 1, end);
}

int main() {
    int arr[5] = {2, 4, 1, 6, 9};
    int n = 5;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

// USECASE : Quicksort is the fastest algorithm so it is widely used as a better way of searching. It is used everywhere where a stable sort is not needed. Quicksort is a cache-friendly algorithm as it has a good locality of reference when used for arrays.
// TIME COMPLEXITY : O(N log(n))
// SPACE COMPLEXITY : O(1)

// GFG : https://practice.geeksforgeeks.org/problems/quick-sort/1