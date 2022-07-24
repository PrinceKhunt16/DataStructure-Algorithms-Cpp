#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void merge(long long* arr, long long int i, long long int mid, long long int j, long long int& count){
        long long ptr1 = i, ptr2 = mid + 1;
        long long newArr[j + 1];
        long long k = i;
       
        while(ptr1 <= mid && ptr2 <= j){
            if(arr[ptr1] > arr[ptr2]){
                count += mid - ptr1 + 1;
                newArr[k] = arr[ptr2];
                k++, ptr2++;
            } else {
                newArr[k] = arr[ptr1];
                k++, ptr1++;
            }  
        }
       
        while(ptr1 <= mid){
            newArr[k] = arr[ptr1];
            ptr1++, k++;
        }
       
        while(ptr2 <= j){
            newArr[k] = arr[ptr2];
            ptr2++, k++;
        }
       
        for(long long t = i; t <= j; t++){
            arr[t] = newArr[t];
        }

    }
    
    void mergeSort(long long* arr,long long int i, long long int j, long long int& count){
        if(i >= j){
            return;
        }
        
        long long int mid = (i + j) / 2;
        
        mergeSort(arr, i, mid, count);
        
        mergeSort(arr, mid + 1, j, count);
        
        merge(arr, i, mid, j, count);
    }
    
    long long int inversionCount(long long arr[], long long N){
        if(N == 1){
            return 0;
        }
       
        long long int count = 0;
        long long int i = 0, j = N - 1;
       
        mergeSort(arr, i, j, count);
       
        return count;
    }
};

int main() {
    long long N = 5;    
    long long A[] = {2, 4, 1, 3, 5};
 
    Solution obj;
    
    cout << obj.inversionCount(A, N) << endl;

    return 0;
}

// Input  : N = 5, A[] = {2, 4, 1, 3, 5}
// Output : 3

// Time Complexity : O(n(log n))
// Space Complexity : O(n)

// Link : https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1