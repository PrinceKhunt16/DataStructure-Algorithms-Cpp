#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
	int i, j;

	for (i = 0; i < n - 1; i++){
        bool swapped = false;

        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }

        }

        if(swapped == false){
            break;
        }
    }

}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
		cout << arr[i] << " ";
    }

	cout << endl;

}

int main(){
	int arr[] = { 5, 1, 4, 2, 8};
	int n = sizeof(arr) / sizeof(arr[0]);

	bubbleSort(arr, n);
	
	printArray(arr, n);
	
    return 0;
}

// When use : Bubble sort is a simple sorting algorithm used to rearrange a set of elements in ascending or descending order. It's useful for smaller sets of elements but is inefficient for larger sets.
// Time Complexity : O(N^2)
// Space Complexity : O(1)

// GFG : https://practice.geeksforgeeks.org/problems/bubble-sort/1