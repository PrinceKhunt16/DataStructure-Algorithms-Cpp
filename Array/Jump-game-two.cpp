#include <bits/stdc++.h>
using namespace std;

class JumpGameTwo
{
public:
    int canJump(vector<int> &nums)
    {
        int jump = 0;
        int position = 0;
        int destination = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            destination = max(destination, nums[i] + i);

            if (position == i) {
                position = destination;
                jump++;
            }

        }

        return jump;
    }
};

int main()
{
    vector<int> nums({2, 3, 1, 1, 4});

    JumpGameTwo object;
    int result = object.canJump(nums);
    cout << result;

    return 0;
}

// INPUT  : arr[] = {2, 3, 1, 1, 4}
// OUTPUT : 2

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

// LEETCODE : https://leetcode.com/problems/jump-game-ii/