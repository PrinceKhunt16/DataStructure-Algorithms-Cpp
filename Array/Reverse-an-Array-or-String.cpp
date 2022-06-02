#include <bits/stdc++.h>
using namespace std;

void rvereseArray(int arr[], int start, int end)
{
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}	

void printArray(int arr[], int size)
{
for (int i = 0; i < size; i++)
cout << arr[i] << " ";

cout << endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, n);
	rvereseArray(arr, 0, n-1);
	cout << "Reversed array is" << endl;
	printArray(arr, n);
	return 0;
}

// INPUT  : arr[] = {1, 2, 3}
// OUTPUT : arr[] = {3, 2, 1}

// INPUT :  arr[] = {4, 5, 1, 2}
// OUTPUT : arr[] = {2, 1, 5, 4}

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(n)

// GFG : https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
// LEETCODE : https://leetcode.com/problems/reverse-string/