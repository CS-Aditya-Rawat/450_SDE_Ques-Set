// Search an element in a matriix

#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main() {
	int n, m, key;
	cin >> n >> m >> key;
	int arr[n][m];
	arr = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 24, 60}};
	int r = 0;
	int c = m - 1;
	while (r<n and c >= 0) {
		if (arr[r][c] == key) return 1;
		if (arr[r][c] > key) c--;
		else r++;
	}
	return 0;
}