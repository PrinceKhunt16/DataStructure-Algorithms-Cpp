#include <bits/stdc++.h>
using namespace std;

struct Result
{
    int max_element = INT_MIN;
    int min_element = INT_MAX;
};

Result getMinMax(int arr[], int n){

    struct Result value;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > value.max_element)
        {
            value.max_element = arr[i];
        }
        else if (arr[i] < value.min_element)
        {
            value.min_element = arr[i];
        }
    }

    cout << "Minimum is " << value.min_element << endl;
    cout << "Maximum is " << value.max_element;
}

int main()
{
    int arr[] = {100, 121, 12, 30, 300};
    int arr_element = 6;

    getMinMax(arr, arr_element);

    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(1)