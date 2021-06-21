// Spiral traversal on a Matrix

#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MAX 1000
int A[MAX][MAX];

vector<int> solve(int A[MAX][MAX], int n, int m) {
	int T, B, L, R, dir;
	T = 0;
	B = n - 1;
	L = 0;
	R = m - 1;
	dir = 0;
	int i;
	vector<int> ans;

	while (T <= B && L <= R)
	{
		if (dir == 0)
		{
			for (i = L; i <= R; i++)
				ans.push_back(A[T][i]);
			T++;
		}
		else if (dir == 1)
		{
			for (i = T; i <= B; i++)
				ans.push_back(A[i][R]);
			R--;
		}
		else if (dir == 2)
		{
			for (i = R; i >= L; i--)
				ans.push_back(A[B][i]);
			B--;
		}
		else if (dir == 3)
		{
			for (i = B; i >= T; i--)
				ans.push_back(A[i][L]);
			L++;
		}
		dir = (dir + 1) % 4;
	}
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];

	vector<int> ans = solve(A, n, m);
	for (auto it : ans) cout << it << " ";
	return 0;
}

