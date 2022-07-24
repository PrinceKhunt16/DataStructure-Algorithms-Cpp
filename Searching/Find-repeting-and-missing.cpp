#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    int *findTwoElement(int *arr, int n) {
        int repeting, missing;
        
        for(int i = 0; i < n; i++){
            if(arr[abs(arr[i]) - 1] > 0){
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            } else {
                repeting = abs(arr[i]);
            }
        }
        
        for(int i = 0; i < n; i++) {
            if (arr[i] > 0){
                missing = (i + 1);
            }
        }
        
        int *ans = new int[2];
        ans[0] = repeting;
        ans[1] = missing;
        
        return ans;
    }

};

int main() {
    int n = 3;
    int a[n] = {1, 3, 3};
    
    Solution ob;
    auto ans = ob.findTwoElement(a, n);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

// GFG : https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1