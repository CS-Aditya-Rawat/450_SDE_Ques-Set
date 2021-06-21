#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// BruteFore Time: O(n^2) | Space: O(1)
void solve(int arr[], int n, int key) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] + arr[j] == key) {
				count++;
			}
		}
	}
	cout << count;
}

// Time: O(n) | Space: O(n)
void solve2(int arr[], int n, int k) {
	int count = 0;
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		int x = k - arr[i];
		if (m[x] ) {
			count += m[x];
		}
		m[arr[i]]++;
	}
	cout << count;
}

int main() {
	fastio();
	int N, key;
	cin >> N >> key;
	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];

	solve2(arr, N, key);
	return 0;
}