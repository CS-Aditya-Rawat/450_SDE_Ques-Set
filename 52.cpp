//

#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MAX 1000
int mat[MAX][MAX];

// Time: O(n^2Logn^2) | Space: O(1)
int solve(int mat[MAX][MAX], int n, int k)
{
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v.push_back(mat[i][j]);
		}
	}
	sort(v.begin(), v.end());
	return v[k - 1];
}



int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> mat[i][j];

		int r;
		cin >> r;
		cout << solve2(mat, n, r);
	}
	return 0;
}