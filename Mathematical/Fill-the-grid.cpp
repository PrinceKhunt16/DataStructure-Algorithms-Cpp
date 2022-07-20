#include <iostream>
using namespace std;

int remainTiles(int N, int M){
    if(N % 2 == 0){
        if(M % 2 == 0){
            return 0;
        } else {
            return N;
        }
    } else if(M % 2 == 0){
        return M;
    } else {
        int ans = (N * M) - (N - 1) * (M - 1);
        return ans;
    }
}

int main() {
	int N, M;
	cin >> N >> M;
	
	int ans = remainTiles(N, M);
	
	cout << ans << endl;
		
	return 0;
}

// Testcase : 1 1
// Result   : 1

// Testcase : 4 5
// Result   : 4 

// Testcase : 6 8
// Result   : 0

// Testcase : 3 2
// Result   : 2

// Time Complexity : O(1)
// Space Complexity : O(1)

// Link : https://www.codechef.com/START48D/problems/GRIDBL