#include<bits/stdc++.h>
using namespace std;

vector<int> find(int arr[], int n , int x){
    int start, end;
    bool checkFirst = true;
    vector<int> answer;
    bool checkX = false;
   
    for(int i = 0; i < n; i++){
        if(arr[i] == x && checkFirst){
            start = i;
            end = i; 
            checkFirst = false;
        }
        
        if(arr[i] == x){
            end = i;
        }

        if(arr[i] == x){
            checkX = true;
        }
        
    }

    if(checkX == false){
        start = -1, end = -1;
        answer.push_back(start);
        answer.push_back(end);
        return answer;
    }
    
    answer.push_back(start);
    answer.push_back(end);
    
    return answer;
}

int main(){
    int arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 };
    int n = 9;
    int x = 5;

    vector<int> ans;
    
    ans = find(arr, n, x);

    cout << ans[0] << " " << ans[1] << endl;
   
    return 0;
}

// Input  : arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }, n = 9, x = 5
// Output : 2 5

// Time Complexity : O(n)
// Space Complexity : O(1)

// GFG : https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1#