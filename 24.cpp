#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Method 1 Time: O(n1+n2+n3) | Space: O(n1+n2+n3)
void solve(int a[], int b[], int c[], int n1, int n2, int n3) {
	unordered_map<int, int> m1, m2, m3;
	vector<int> ans;

	for (int i = 0; i < n1; i++) m1[a[i]]++;
	for (int i = 0; i < n2; i++) m2[b[i]]++;
	for (int i = 0; i < n3; i++) m3[c[i]]++;

	for (int i = 0; i < n1; i++) {
		if (m1[a[i]] and m2[a[i]] and m3[a[i]]) {
			ans.push_back(a[i]);
			m1[a[i]] = 0;
		}
	}
	for (auto it : ans) cout << it;
}

// Method 2 Time: O(n1+n2+n3) | Space: O(1)
void solve2(int a[], int b[], int c[], int n1, int n2, int n3) {
	int i = 0, j = 0, k = 0;
	vector<int> ans;
	while (i < n1 and j < n2 and k < n3) {
		if (a[i] == b[j] and b[j] == c[k]) {
			ans.push_back(a[i]);
			i++; j++; k++;
		}
		else if (a[i] < b[j]) i++;
		else if (b[j] < c[k]) j++;
		else k++;
		// To handlle the duplicates case
		int x = a[i - 1];
		while (a[i] == x) i++;

		int y = b[j - 1];
		while (b[j] == y) j++;

		int z = c[k - 1];
		while (c[k] == z) k++;
	}

	if (ans.size() == 0) cout << -1;
	return ans;
}
int main() {
	fastio();
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	int a[n1];
	int b[n2];
	int c[n3];
	for (int i = 0; i < n1; i++) cin >> a[i];
	for (int i = 0; i < n2; i++) cin >> b[i];
	for (int i = 0; i < n3; i++) cin >> c[i];
	solve2(a, b, c, n1, n2, n3);
	return 0;
}