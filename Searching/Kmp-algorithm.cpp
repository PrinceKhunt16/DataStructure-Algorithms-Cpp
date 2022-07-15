#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string s){
    int n = s.size();
    vector<int> pi(n, 0);

    for(int i = 1; i < n; i++){
        int j = pi[i - 1];

        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }

        if(s[i] == s[j]){
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

int main(){
    string t = "princeishero";
    string s = "is";
    vector<int> res = prefix(s);
    int pos = -1;
    int i(0), j(0);

    while (i < t.size()){
        if(t[i] == s[j]){
            j++;
            i++;
        } else {
            if(j != 0){
                j = res[j - 1];
            } else {
                i++;
            }
        }

        if(j == s.size()){
            pos = i - s.size();
            break;
        }

    }

    cout << pos;

    return 0;    
}

// Input  : t = "princeishero", s = "is"
// Output : 6

// Time Complexity : O(s + t)
// Space Complexity : O(1)

// GFG : https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/