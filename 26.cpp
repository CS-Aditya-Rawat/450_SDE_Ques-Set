#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// BruteForce
bool solve(int arr[], int n) {
	int sum;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			if (sum == 0) return true;
		}
	}
	return false;
}

bool solve2(int arr[], int n) {
	int prefix[n];
	map<int, int> m;  // I can also use sets here
	prefix[0] = arr[0];
	for (int i = 1; i < n ; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}
	for (int it : prefix) {
		if (it == 0) return true;

		if (m[it]) {
			return true;
		}
		else {
			m[it] = 1;
		}
	}
	return false;
}
int main() {
	fastio();
	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];
	cout << solve2(arr, N);
	return 0;
}