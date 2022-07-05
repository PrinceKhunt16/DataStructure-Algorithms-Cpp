#include <bits/stdc++.h>
using namespace std;

class MaxSubarray
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maximum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > maximum)
                maximum = sum;
            if (sum < 0)
                sum = 0;
        }
        return maximum;
    }
};

int main()
{
    vector<int> arr({-2, 1, -3, 4, -1, 2, 1, -5, 4});

    MaxSubarray object;
    int answer = object.maxSubArray(arr);

    cout << answer;
}

// INPUT :  arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4} 
// OUTPUT : 6

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

// LEETCODE : https://leetcode.com/problems/maximummum-subarray/