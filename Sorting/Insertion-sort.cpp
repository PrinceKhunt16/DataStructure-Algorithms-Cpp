#include <stdio.h>
#include <math.h>

void printArray(int arr[], int size){
    int i;
    
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");

}

class Solution{
    public:
        void insertionSort(int arr[], int n){
            int i, key, j;

            for (int i = 1; i < n; i++){
                key = arr[i];
                j = i - 1;

                while (j >= 0 && arr[j] > key){
                    arr[j + 1] = arr[j];
                    j--;
                }

                arr[j + 1] = key;
            }
        }
};

int main(){
    int arr[1000], n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Solution ob;
    ob.insertionSort(arr, n);
    
    printArray(arr, n);

    return 0;
}

// When use : Insertion sort has a fast best-case running time and is a good sorting algorithm to use if the input list is already mostly sorted. For larger or more unordered lists, an algorithm with a faster worst and average-case running time, such as mergesort, would be a better choice.
// Time Complexity : O(N^2)
// Space Complexity : O(1)

// GFG : https://practice.geeksforgeeks.org/problems/insertion-sort/1#