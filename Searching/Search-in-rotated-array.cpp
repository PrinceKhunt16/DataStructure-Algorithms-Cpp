#include <bits/stdc++.h>
using namespace std;

class SearchInRotatedArray {
    public:
    int search(int A[], int l, int h, int key){
        while(l <= h){
            int mid = (l + h) / 2;
            
            if(A[mid] == key){
                return mid;
            }
            
            if(A[l] <= A[mid]){
                if(key >= A[l] && key < A[mid]){
                    h = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if(key > A[mid] && key <= A[h]){
                    l = mid + 1;
                } else {
                    h = mid - 1; 
                }
            }
        }
            
        return -1;
    }
};
    
int main() {
    int A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 10;
    int size = sizeof(A) / sizeof(A[0]);

    SearchInRotatedArray obj;
    
    cout << obj.search(A, 0, size, key) << endl;
   
    return 0;
}


// Input  : A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
// Output : 5

// Time Complexity : O(log n)
// Space Complexity : O(1)

// Link : https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1