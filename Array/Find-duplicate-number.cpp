#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums){
    int slow = nums[0];
    int fast = nums[0];

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main(){
    vector<int> nums({3, 1, 3, 4, 2});
    int answer = findDuplicate(nums);
    cout << answer;

    return 0;
}

// Input  : arr[] = {3, 1, 3, 4, 2}
// Output : 3

// Time Complexity : O(N)
// Space Complexity : O(1)

// LEETCODE : https://leetcode.com/problems/find-the-duplicate-number/