#include <bits/stdc++.h>
using namespace std;

int maximumSubarray(vector<int> &nums){
    int sum = 0;
    int subarraySum = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum > subarraySum)
            subarraySum = sum;
        if (sum < 0)
            sum = 0;
    }
    return subarraySum;
}

int main(){
    vector<int> arr({-2, 1, -3, 4, -1, 2, 1, -5, 4});

    int answer = maximumSubarray(arr);
    cout << answer << endl;

    return 0;
}

// INPUT  : nums({-2,1,-3,4,-1,2,1,-5,4})
// OUTPUT : 6

// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(1)

// LEETCODE : https://leetcode.com/problems/maximum-subarray/