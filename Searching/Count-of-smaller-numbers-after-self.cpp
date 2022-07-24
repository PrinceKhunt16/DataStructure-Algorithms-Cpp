#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right){
        vector<pair<int, int>> temp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;
        
        while(i <= mid && j <= right){
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            } else {
                count[v[i].second] += right - j + 1;
                temp[k++] = v[i++];
            }
            
        } 
        
        while(i <= mid){
            temp[k++] = v[i++];
        }
        
        while(j <= right){
            temp[k++] = v[j++];
        }
        
        for(int i = left; i <= right; i++){
            v[i] = temp[i - left];
        }
              
    }
    
    void mergeSort(vector<int> &count, vector<pair<int,int>> &v, int left, int right){
        if(left < right){
            int mid = left + (right - left) / 2;
            mergeSort(count, v, left, mid);
            mergeSort(count, v, mid + 1, right);
            merge(count, v, left, mid, right);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        vector<int> count(n, 0);
        
        for(int i = 0; i < n; i++){
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            v[i] = p;
        }
        
        mergeSort(count, v, 0, n - 1);
        
        return count;
    }
};

int main() {    
    vector<int> nums = {5, 2, 6, 1};
    vector<int> ans;
    
    Solution obj;
    ans = obj.countSmaller(nums);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}

// Time Complexity : O(n(log n))
// Space Complexity : O(n)

// Link : https://leetcode.com/problems/count-of-smaller-numbers-after-self/