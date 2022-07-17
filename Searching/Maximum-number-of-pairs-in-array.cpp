#include <bits/stdc++.h>
using namespace std;

vector<int> numberOfPairs(vector<int> &nums){
    map<int, int> store;

    for (auto element : nums){
        store[element] += 1;
    }

    int pair = 0, remain = 0;

    for (auto element : store){
        pair += (element.second) / 2;
        remain += (element.second) % 2;
    }

    return {pair, remain};
}

int main(){
    vector<int> nums = {2, 1, 1, 3, 2, 3, 3};
    vector<int> answer;

    answer = numberOfPairs(nums);

    cout << answer[0] << " " << answer[1];

    return 0;
}

// Input  : nums = {2, 1, 1, 3, 2, 3, 3};
// Output : { 3, 1 }

// Time Complexity : O(n)
// Space Complexity : O(n)

// GFG : https://leetcode.com/contest/weekly-contest-302/problems/maximum-number-of-pairs-in-array/