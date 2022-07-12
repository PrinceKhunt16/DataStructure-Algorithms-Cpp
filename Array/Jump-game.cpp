#include <bits/stdc++.h>
using namespace std;

class JumpGame
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int reachable = 0;

        for (int i = 0; i < n; i++)
        {
            if (reachable < i)
            {
                return false;
            }
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }
};

int main()
{
    vector<int> nums({2,3,1,1,4});

    JumpGame object;
    
    if(object.canJump(nums)){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}

// Input  : arr[] = {2, 3, 1, 1, 4}
// Output : true

// Time Complexity : O(N)
// Space Complexity : O(1)

// LEETCODE : https://leetcode.com/problems/jump-game/submissions/