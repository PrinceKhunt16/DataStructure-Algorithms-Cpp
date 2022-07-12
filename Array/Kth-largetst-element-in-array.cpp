#include <bits/stdc++.h>
using namespace std;

class FindLargest {
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        return pq.top();
    }
};

int main() {
    int arr[] = {100, 121, 12, 30, 300};
    int arr_element = 5;
    vector<int> element;

    for (int i = 0; i < arr_element; i++)
    {
        element.push_back(arr[i]);
    }

    FindLargest object;
    int answer = object.findKthLargest(element, 2);

    cout << answer;

    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)

// LEETCODE : https://leetcode.com/problems/kth-largest-element-in-an-array