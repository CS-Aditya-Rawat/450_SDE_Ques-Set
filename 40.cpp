// Median of 2 sorted arrays of equal size

#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// naive approach Time: O(n+m) | Space: O(n+m)
void solve(int a[], int b[], int n, int m) {
	int i = 0, j = 0, k = 0;
	int c[n + m];
	while (i < n && j < m) {
		if (a[i] < b[j]) c[k++] = a[i++];
		else c[k++] = b[j++];
	}
	while (i < n) c[k++] = a[i++];
	while (j < m) c[k++] = b[j++];

	if ((m + n) % 2 == 0) {
		cout << (c[(m + n) / 2] + c[((m + n) / 2) - 1]) / 2;
	} else {
		cout << c[(m + n) / 2];
	}
}

// naive optimised Time: O(n+m) | Space: O(1)
void solve2(int a[], int b[], int n, int m) {
	int i = 0;
	int j = 0;
	int count = 0;
	int m1 = -1, m2 = -1;

	if ((m + n) % 2 == 1)
	{
		for (count = 0; count <= (n + m) / 2; count++) {
			if (i != n && j != m)
				m1 = (a[i] > b[j]) ? b[j++] : a[i++];
			else if (i < n)
				m1 = a[i++];
			else
				m1 = b[j++];
		}
		cout << m1;
	}
	else
	{
		for (count = 0; count <= (n + m) / 2; count++) {
			m2 = m1;
			if (i != n && j != m)
				m1 = (a[i] > b[j]) ? b[j++] : a[i++];
			else if (i < n)
				m1 = a[i++];
			else
				m1 = b[j++];
		}
		cout << (m1 + m2) / 2;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int arr1[n], arr2[m];
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	solve2(arr1, arr2, n, m);
	return 0;
}