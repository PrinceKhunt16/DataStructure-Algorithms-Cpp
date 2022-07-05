#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

class Solution{
    public:
        int select(int arr[], int i, int n){
            int minNumber = i;

            for (int j = i + 1; j < n; j++){
                if (arr[j] < arr[minNumber]){
                    minNumber = j;
                }
            }

            return minNumber;
        }

        void selectionSort(int arr[], int n){
            int sizeOfArr = n;

            for (int i = 0; i < n - 1; i++){
                int getMin = select(arr, i, sizeOfArr);

                if (getMin != i){
                    int temp = arr[getMin];
                    arr[getMin] = arr[i];
                    arr[i] = temp;
                }

            }

        }
};

void printArray(int arr[], int size){
    int i;
    
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    
}

int main(){
    int arr[1000], n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    Solution obj;
    obj.selectionSort(arr, n);
    
    printArray(arr, n);

    return 0;
}

// USECASE : This sorting algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from the unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array, the subarray which is already sorted and remaining subarray which is unsorted.
// TIME COMPLEXITY : O(N^2)
// SPACE COMPLEXITY : O(1)

// GFG : https://practice.geeksforgeeks.org/problems/selection-sort/1#