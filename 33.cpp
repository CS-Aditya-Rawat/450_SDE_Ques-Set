// Find the triplet that sum to a given value

#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Naive approach Time: O(n^3) | Space: O(1)
void solve(int a[], int n, int key) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n ; k++) {
				if (a[i] + a[j] + a[k] == key) cout << "Found";
			}
		}
	}
	cout << "Not Found";
}

bool solve2(int a[], int n, int key) {
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		int l = i + 1;
		int r = n - 1;

		while (l < r) {
			if (a[i] + a[l] + a[r] == key) return true;
			else if ( a[i] + a[l] + a[r] < key) l++;
			else r--;
		}
	}
	return false;
}

int main() {
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	solve2(arr, n, k);
	return 0;
}