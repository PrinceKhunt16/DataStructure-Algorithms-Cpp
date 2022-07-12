#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main()
{
    vector<int> arr({1, 2, 3, 4, 5});
    int k = 2;
    
    rotate(arr, k);

    for (auto item : arr)
    {
        cout << item << " ";
    }
}

// Input :  arr[] = {1, 2, 3, 4, 5} k = 2
// Output : arr[] = {4, 5, 1, 2, 3}

// Time Complexity : O(N)
// Space Complexity : O(1)

// GFG : https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
// LEETCODE : https://leetcode.com/problems/rotate-array/