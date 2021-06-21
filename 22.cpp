#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// BruteForce Time : O(n^2) | Space: O(1)
void solve(int arr[], int n) {
	int profit = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				profit = max(profit, arr[j] - arr[i]);
			}
		}
	}
	cout << profit;
}

// Time : O(n) | Space: O(1)
void solve2(int arr[], int n) {
	int profit = 0;
	int mini = INT_MAX;
	for (int i = 0; i < n; i++) {
		mini = min(arr[i], mini);
		profit = max(profit, arr[i] - mini);
	}
	cout << profit;
}

int main() {
	fastio();
	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];

	solve2(arr, N);
	return 0;
}