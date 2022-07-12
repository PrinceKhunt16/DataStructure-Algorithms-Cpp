#include <bits/stdc++.h>
using namespace std;

void mergeIntevals(vector<vector<int>> &intervals, vector<vector<int>> &result){

    if (intervals.size() == 0){
        return;
    }

    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
        return a[0] < b[0]; 
    });

    vector<int> current = intervals[0];

    for (int i = 1; i < intervals.size(); i++){
        if (current[1] < intervals[i][0]){
            result.push_back(current);
            current = intervals[i];
        } else {
            current[1] = max(current[1], intervals[i][1]);
        }
    }

    result.push_back(current);
}

int main()
{
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result;

    mergeIntevals(intervals, result);

    for (int i = 0; i < result.size(); i++){
        cout << "[ ";
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }    
        cout << "] ";
    }

    return 0;
}

// Input  : intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}}
// Output : {{1,6},{8,10},{15,18}}

// Time Complexity : O(N*logN)
// Space Complexity : O(N)

// LEETCODE : https://leetcode.com/problems/maximum-subarray/