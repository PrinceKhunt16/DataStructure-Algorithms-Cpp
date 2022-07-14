#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x){
    if(r >= l){
        int mid = l + (r - l) / 2;

        if(arr[mid] == x){
            return 1;
        }

        if(arr[mid] > x){
            return binarySearch(arr, l, mid - 1, x);
        }

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int exponentialSearch(int arr[], int n, int x){
    if(arr[0] == x){
        return 1;
    }    

    int i = 1;
    while(i < n && arr[i] <= x){
        i = i * 2;
    }

    return binarySearch(arr, i / 2, min(i, n - 1), x);
}

int main(){
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
   
    int isAvilable = exponentialSearch(arr, n, x);
  
    cout << isAvilable;

    return 0;
}

// Input  : arr[] = {2, 3, 4, 10, 40}, n = 5, x = 10
// Output : 1

// Time Complexity : O(log n)
// Space Complexity : O(1)

// GFG : https://www.geeksforgeeks.org/exponential-search/