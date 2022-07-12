#include <bits/stdc++.h>
using namespace std;

void shellSort(int arr[], int n) {
    for(int interval = n / 2; interval > 0; interval /= 2){
        for(int i = interval; i < n; i += 1){
            for(int j = i - interval; i >= 0; i - interval){
                if(arr[j + interval] > arr[j]){
                    break;
                } else {
                    swap(arr[j + interval], arr[j]);
                }
            }
        }
    }
}

int main(){
    int arr[] = {9, 8, 3, 7, 5, 6, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;
    
    shellSort(arr, size);
    
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// When use : Shell sort is a highly efficient sorting algorithm and is based on insertion sort algorithm. This algorithm avoids large shifts as in case of insertion sort, if the smaller value is to the far right and has to be moved to the far left.
// Time Complexity : O(N log(n))
// Space Complexity : O(1)

// GFG : https://www.geeksforgeeks.org/shellsort/