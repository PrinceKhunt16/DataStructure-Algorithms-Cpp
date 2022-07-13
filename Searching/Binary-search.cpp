#include <bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int n, int k) {
        int low = 0;
        int high = n - 1;
        
        while(low <= high){
            int mid = (low + high) / 2;
            
            if(arr[mid] == k){
                return mid;    
            } 
                
            if(k > arr[mid]){
                low = mid + 1;
            }
            
            if(k < arr[mid]){
                high  = mid - 1;
            }
            
        }   
        return -1;
    }

int main(){
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = binarysearch(arr, n, x);
    cout << result;

    return 0;
}

// Input  : arr[] = { 2, 3, 4, 10, 40 }, x = 3, n = 5
// Output : 1

// Time Complexity : O(log n)
// Space Complexity : O(1)

// GFG : https://practice.geeksforgeeks.org/problems/binary-search/1#