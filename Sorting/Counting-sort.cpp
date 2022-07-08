#include <bits/stdc++.h>
using namespace std;
  
int getMax(int a[], int n) {  
    int max = a[0];  
    
    for(int i = 1; i < n; i++) {  
        if(a[i] > max){
            max = a[i];  
        }
    }  
    
    return max; 
}  
  
void countSort(int a[], int n){  
    int output[n + 1];  
    int max = getMax(a, n);  
    int count[max + 1]; 
  
    // Store all index in 0 of count array
    for (int i = 0; i <= max; ++i)   {  
        count[i] = 0;  
    }  

    // Store the count of each element    
    for (int i = 0; i < n; i++){
        count[a[i]]++;  
    }  

    // find cumulative frequency  
    for(int i = 1; i <= max; i++){
        count[i] += count[i - 1]; 
    }   
  
    // This loop will find the index of each element of the original array in count array and place the elements in output array
    for (int i = n - 1; i >= 0; i--) {  
        output[count[a[i]] - 1] = a[i];  
        count[a[i]]--;
    }  
  
    // Copy result in final array
    for(int i = 0; i<n; i++) {  
        a[i] = output[i]; 
    }  
}  
  
int main() {  
    int a[] = { 31, 11, 42, 7, 30, 11 };  
    int n = sizeof(a)/sizeof(a[0]);  
    
    countSort(a, n);  
    
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";   
    }
    
    return 0;  
}  


// USECASE : Counting sort works by determining the positions of each key value in the output sequence by counting the number of objects with distinct key values and applying prefix sum to those counts.
// TIME COMPLEXITY : O(n + k)
// SPACE COMPLEXITY : O(n + k)

// GFG : https://practice.geeksforgeeks.org/problems/heap-sort/0/?category[]=Sorting&category[]=Sorting&page=1&query=category[]Sortingpage1category[]Sorting#