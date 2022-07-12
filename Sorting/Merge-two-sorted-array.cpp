#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void mergeBySwap(int arr1[], int arr2[], int n, int m) {
	    int i = 0;
	    int j = 0;
	    
	    while(i < n){
	        if(arr1[i] > arr2[j]){
	            swap(arr1[i], arr2[j]);
	            
	            for (int k = 1; k < m; k++){
	                if(arr2[k] < arr2[k - 1]){
	                    swap(arr2[k], arr2[k - 1]);
	                }   
	            }
	        }
	        
	        i++;   
	    }
	}

    void mergeByGap(int arr1[], int arr2[], int n, int m) {
	    int gap = ceil((float)(m+n)/2);
	    
	    while(gap > 0){
	        int i = 0;
	        int j = gap;
	        
	        while(j < (m + n)){
                if(j < n && arr1[i] > arr1[j]){
	                swap(arr1[i], arr1[j]);
	            } else if(j >= n && i < n && arr1[i] > arr2[j - n]){
                    swap(arr1[i],arr2[j-n]);
	            } else if(j >= n && i >= n && arr2[i - n] > arr2[j - n]){
                    swap(arr2[i-n],arr2[j-n]);
                }
                    
                j++; i++;
	        }
	        
	        if(gap == 1)
               gap = 0;
            else 
               gap = ceil((float) gap/2);
	    }
	}
};

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    int n = 4, m = 5, i;

    Solution ob;

    ob.mergeBySwap(arr1, arr2, n, m);

    for (i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }

    for (i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
  
    return 0;
} 

// Input  : arr1[] = {1, 3, 5, 7} arr2[] = {0, 2, 6, 8, 9} n = 4 m = 5
// Output : 0 1 2 3 5 6 7 8 9 

// Time Complexity : O(N log(n))
// Space Complexity : O(1)

// GFG : https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1