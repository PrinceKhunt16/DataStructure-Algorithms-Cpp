#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i){

    // root
    int largest = i;

    // Left element for formula
    int left = 2 * i + 1;

    // Right element for formula
    int right = 2 * i + 2;

    // Left child if it is bigger than root
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    // Right child if it is bigger than root
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    // Largest variable is not root
    if(largest != i){
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }

}

void heapSort(int arr[], int n){
    
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for(int i = n - 1; i > 0; i--){
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on reduced heap
        heapify(arr, i, 0);

    }
    
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    heapSort(arr, n);
  
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}

// USECASE : Heap Sort in Data Structure is used when the smallest (shortest) or highest (longest) value is needed instantly. Other usages include finding the order in statistics, dealing with priority queues in Prim's algorithm (also called the minimum spanning tree) and Huffman encoding or data compression.
// TIME COMPLEXITY : O(N log(n))
// SPACE COMPLEXITY : O(1)

// GFG : https://practice.geeksforgeeks.org/problems/heap-sort/0/?category[]=Sorting&category[]=Sorting&page=1&query=category[]Sortingpage1category[]Sorting#