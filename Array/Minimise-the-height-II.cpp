#include <bits/stdc++.h>
using namespace std;

class MinimiseTheHeight
{
public:
    int getMindifference(int arr[], int n, int k)
    {
        if (n == 1){
            return 0;
        }

        sort(arr, arr + n);

        int minimum = arr[0];
        int maximum = arr[n - 1];

        int difference = maximum - minimum;

        for (int i = 1; i < n; i++)
        {

            if (arr[i] - k < 0)
                continue;

            minimum = min(arr[0] + k, arr[i] - k);
            maximum = max(arr[i - 1] + k, arr[n - 1] - k);

            difference = min(difference, maximum - minimum);
        }

        return difference;
    }
};

int main()
{
    int arr[] = {3, 9, 12, 16, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    MinimiseTheHeight object;
    int result = object.getMindifference(arr, n, k);
    cout << result << endl;

    return 0;
}

// Input  : K = 3, N = 5 Arr[] = {3, 9, 12, 16, 20}
// Output : 11

// Time Complexity : O(N*logN)
// Space Complexity : O(N)

// GFG : https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1