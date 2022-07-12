#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e) {

    int mid = ( s + e ) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // Copy values
    int mainArrayIndex = s;
    for(int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    // Merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;

}

void mergeSort(int *arr, int s, int e) {

    // Base case
    if(s >= e) {
        return;
    }
    
    int mid = ( s + e ) / 2;

    // Left part sort
    mergeSort(arr, s, mid);
    
    // Right part sort 
    mergeSort(arr, mid + 1, e);

    // Merge Left and Right both array
    merge(arr, s, e);

}

int main() {

    int arr[9] = {3, 7, 3, 2, 34, 66, 87, 23, 12};
    int n = 9;

    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}

// When use : Mergesort is used when we want a guaranteed running time of O(N log(n)), regardless of the state of the input. Mergesort is a stable sort with a Space Complexity of O(n).
// Time Complexity : O(N log(n))
// Space Complexity : O(n)

// GFG : https://practice.geeksforgeeks.org/problems/merge-sort/1