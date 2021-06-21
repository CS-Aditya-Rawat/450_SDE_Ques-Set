#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int solve(int arr[], int n, int k) {
	vector<pair<int, int>> v;
	vector<int> vis(n);

	for (int i = 0; i < n; i++) {
		if (arr[i] - k >= 0) {
			v.push_back({arr[i] - k, i});
		}
		v.push_back({arr[i] + k, i});
	}

	sort(v.begin(), v.end());
	int ele = 0;
	int left = 0;
	int right = 0;

	while (ele < n && right < v.size()) {
		if (vis[v[right].second] == 0) {
			ele++;
		}
		vis[v[right].second]++;
		right++;
	}

	return 0;
}
int main() {
	fastio();
	int K, N;
	cin >> K >> N;
	int arr[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	solve(arr, N, K);
	return 0;
}