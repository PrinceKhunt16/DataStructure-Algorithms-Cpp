#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int middle(int A, int B, int C){
        if((A > C && A < B) || (A > B && A < C)){
            return A;
        } else if((C > A && C < B) || (C > B && C < A)){
            return C;
        } else {
            return B;
        }

    }

};

int main(){
    int A = 10, B = 20, C = 30;

    Solution obj;
    cout<<obj.middle(A, B, C) << endl;
    
    return 0;
}

// Time Complexity : O(1)
// Space Complexity : O(1)

// GFG : https://practice.geeksforgeeks.org/problems/middle-of-three2926/1