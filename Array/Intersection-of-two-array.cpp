#include <bits/stdc++.h>
using namespace std;

class IntersectionTwoArray
{
public:
    vector<int> intersectionTwoArray(vector<int> &nums1, vector<int> &nums2, vector<int> &result)
    {
        // Sort two vector 
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // Two vectors starting pointer nums1 for i and nums2 for j.
        int i = 0;
        int j = 0;
        int last = -1;

        while (i != nums1.size() and j != nums2.size())
        {
            if (nums1[i] == nums2[j] and last != nums1[i])
            {
                result.push_back(nums1[i]);
                last = nums1[i];
                i++;
                j++;
            }
            else if (nums1[i] == nums2[j] and last == nums1[i])
            {
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j])
            {
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
        }
        
        return result;
    }
};

int main()
{
    vector<int> arr1({1, 2, 3, 4, 5});
    vector<int> arr2({2, 3, 5, 6});
    vector<int> result({});

    IntersectionTwoArray object;
    result = object.intersectionTwoArray(arr1, arr2, result);

    for (auto item : result)
    {
        cout << item << endl;
    }

    return 0;
}

// Input  : vector<int> arr1({1, 2, 3, 4, 5});
//          vector<int> arr2({2, 3, 5, 6});

// Output : vector<int> result = ({2, 3, 5});

// Time Complexity : O(N*logN)
// Space Complexity : O(N)

// LEETCODE : https://leetcode.com/problems/intersection-of-two-arrays/