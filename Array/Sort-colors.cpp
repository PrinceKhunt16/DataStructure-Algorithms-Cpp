#include <bits/stdc++.h>
using namespace std;

class SortColors
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = (int)nums.size();
        int l = 0;
        int m = 0;
        int h = n - 1;
        while (m <= h)
        {
            int x = nums[m];
            if (x == 0)
            {
                swap(nums[l], nums[m]);
                l++;
                m++;
            }
            else if (x == 1)
            {
                m++;
            }
            else
            {
                swap(nums[h], nums[m]);
                h--;
            }
        }
    }
};

int main()
{
    int arr[] = {1, 0, 2, 1, 2, 0, 0, 1, 1};
    int arr_element = sizeof(arr) / sizeof(arr[0]);

    vector<int> element;

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        element.push_back(arr[i]);
    }

    SortColors object;
    object.sortColors(element);

     for (auto iterator : element) {
        cout << iterator << " ";
    }

    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)

// LEETCODE : https://leetcode.com/problems/sort-colors/