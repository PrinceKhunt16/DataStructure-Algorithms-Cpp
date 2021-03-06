#include <bits/stdc++.h>
using namespace std;

void cyclicSort(int arr[], int n){
    int i = 0;

    while(i < n){
        int correctindex = arr[i] - 1;

        if(arr[i] != arr[correctindex]){
            swap(arr[i], arr[correctindex]);
        } else {
            i++;
        }

    }    
}

int main(){
    int arr[] = {3, 2, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    cyclicSort(arr, n);

    for (i = 0; i < n; i++)
    cout << arr[i] << " ";

    return 0;
}

// When use : This sorting algorithm is best suited for situations where memory write or swap operations are costly.
// Time Complexity : O(n2)
// Space Complexity : O(1)

// GFG : https://www.geeksforgeeks.org/cycle-sort/