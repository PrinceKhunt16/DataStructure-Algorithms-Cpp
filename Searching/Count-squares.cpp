#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSquares(int N) {
        int num = sqrt(N);
        
        if(num * num == N){
            return num -1;
        } else {
            return num;
        }

    }
};

int main() {
    int N = 9; 

    Solution ob;
    cout << ob.countSquares(N) << endl;
 
    return 0;
}

// Time Complexity : O(1)
// Space Complexity : O(1)

// GFG : https://practice.geeksforgeeks.org/problems/count-squares3649/1