#include <bits/stdc++.h>
using namespace std;

class NegetiveRightSide {
public:
    void nagetiveRightSide(int arr[], int n) {

        // Initialize an empty arr for store result.
        int result[n];

        // Starting pointer.
        int start = 0;

        // Consider only positive number and store in result array.
        for(int i = 0; i < n; i++)
        {
            if(arr[i] >= 0){
                result[start++] = arr[i];
            }
        }
        
        // Consider only nagetive number and store in result array right side to negetive number.
        for(int i = 0; i < n; i++)
        {
            if(arr[i] < 0){
                result[start++] = arr[i];
            }
        }

        // Now result array assigned in argument array which is our final answer.      
        for(int i = 0; i < n; i++)
        {
            arr[i] = result[i];
        }

        // Print output.
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " " ;
        }
    }
};

int main() {
    int arr[] = {1, -1, 3, 2, -7, -5, 11, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    NegetiveRightSide object;
    object.nagetiveRightSide(arr, n);

    return 0;
}

// INPUT  : arr[] = {-5, 7, -3, -4, 9, 10, -1, 11}
// OUTPUT : arr[] = {7  9  10  11  -5  -3  -4  -1}

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N)

// GFG : https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1#