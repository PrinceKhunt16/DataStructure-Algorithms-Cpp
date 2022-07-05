#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int i = m - 1, j = n - 1, k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
            k--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }

    while (i >= 0)
    {
        nums1[k--] = nums1[i--];
    }

    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

int main()
{
    vector<int> nums1({1, 2, 3, 0, 0, 0});
    vector<int> nums2({2, 5, 6});
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    for (auto item : nums1){
        cout << item << " ";
    }

    return 0;
}

// INPUT  : nums1({1, 2, 3, 0, 0, 0}) nums2({2, 5, 6})
// OUTPUT : 1 2 2 3 5 6

// TIME COMPLEXITY : O(M + N)
// SPACE COMPLEXITY : O(1)

// LEETCODE : https://leetcode.com/problems/merge-sorted-array/