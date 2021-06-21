// Find whether an array is a subset of another array

#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Sorting + binary_search Time:O(nLogn + mLogm) | Space: O(1)
bool solve(int a[], int b[], int n, int m) {
	sort(a, a + n);
	for (int i = 0; i < m; i++) {
		if (!binary_search(a, a + n, b[i])) {
			return false;
		}
	}
	return true;
}

// HashTable
string solve2(int a[], int b[], int n, int m) {
	unordered_set<int>s;
	for (int i = 0; i < n; i++) {
		s.insert(a[i]);
	}
	for (int i = 0; i < m; i++) {
		if (s.find(b[i]) == s.end()) return "No";
	}
	return "Yes";
	// unordered_set<int> :: iterator itr;
	// for (itr = s.begin(); itr != s.end(); itr++)
	// 	cout << (*itr) << endl;
}

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	int b[k];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < k; i++) cin >> b[i];
	cout << solve2(a, b, n, k);
	return 0;
}