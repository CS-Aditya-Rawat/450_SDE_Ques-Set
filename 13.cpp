#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Basic approach Time: O(n^3)
void solve(int arr[], int n) {
	int maxSum = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += arr[k];
			}
			maxSum = max(maxSum, sum);
		}
	}
	cout << "The Max Sum is " << maxSum;
}

// Using Prefix sum array Time: O(n^2) Space: O(n)
void solve2(int arr[], int n) {
	int maxSum = INT_MIN;

	int pSum[n + 1];      // 0-based Indexing of pSum
	pSum[0] = 0;
	for (int i = 1; i <= n; i++) {
		pSum[i] = pSum[i - 1] + arr[i - 1];
	}

	for (int it : pSum) cout << it << " ";

	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = i; j <= n; j++) {
			maxSum = max(maxSum, pSum[j] - pSum[i]);
		}
	}
	cout << maxSum;
}

// Using kadane algorithm Time: O(n) space: O(1)
void solve3(int arr[], int n) {
	int maxSum = INT_MIN;
	int max_th = 0;          //max till here
	for (int i = 0; i < n; i++) {
		max_th += arr[i];
		if (max_th < 0) {
			max_th = 0;
		}
		maxSum = max(maxSum, max_th);
	}
	cout << maxSum;
}

int main() {
	fastio();
	int N;
	cin >> N ;
	int arr[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	solve3(arr, N);
	return 0;
}