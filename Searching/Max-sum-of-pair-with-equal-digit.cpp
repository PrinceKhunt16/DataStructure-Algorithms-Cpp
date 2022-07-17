#include <bits/stdc++.h>
using namespace std;

int getNumber(int n){
    int answer = 0;
        
    while(n){
        answer += (n % 10);
        n /= 10;
    }
        
    return answer;       
}
    
int maximumSum(vector<int>& nums) {
    int n = nums.size();
    sort(begin(nums), end(nums), greater<int>());
    map<int, vector<int>> store;
        
    for(int i = 0; i < n; i++){
        int temp = getNumber(nums[i]);
        store[temp].push_back(nums[i]);
    }
        
    int maxi = -1;
        
    for(auto i: store){
        if(i.second.size() <= 1){
        continue;
    }
            
        vector<int> it = i.second;
        maxi = max(maxi, it[0] + it[1]);
    }
        
    return maxi;
}

int main(){
    vector<int> nums = {18, 43, 36, 13 ,7};

    int answer = maximumSum(nums);
    cout << answer;

    return 0;
}

// Input  : nums = {18, 43, 36, 13 ,7};
// Output : 54

// Time Complexity : O(n)
// Space Complexity : O(n)

// LEETCODE : https://leetcode.com/contest/weekly-contest-302/problems/max-sum-of-a-pair-with-equal-sum-of-digits/