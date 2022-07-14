#include <bits/stdc++.h>
using namespace std;

int interpolationSearch(int arr[], int n, int x){
    int low = 0, high = ( n - 1 );

    while(low <= high && x <= arr[high] && x >= arr[low]){
        if(low == high){
            if(arr[low] == x){
                return 1;
            }

            return -1;
        }

        int position = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));
        
        if(arr[position] == x){
            return 1;
        }

        if(arr[position] < x){
            low = position + 1;
        } else {
            high = position - 1;
        }

    }
    
    return -1;
}

int main(){
    int arr[] = { 10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 11;

    int isAvilable = interpolationSearch(arr, n, x);
  
    cout << isAvilable;

    return 0;
}

// Input  : arr[] = { 10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47 }, n = 15, x = 11
// Output : 1

// Time Complexity : O(log2(log2 n))
// Space Complexity : O(1)

// GFG : https://www.geeksforgeeks.org/interpolation-search/