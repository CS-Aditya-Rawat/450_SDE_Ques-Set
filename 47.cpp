// Find row with maximum no. of 1's

#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int main() {
	int N, M;
	cin >> N >> M;
	int arr[N][M];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	// Time: O(n*m) | Space: O(1)
	int row = 0;
	int prev_one = INT_MIN;
	for (int i = 0; i < N; i++) {
		int one = 0;
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) one++;
		}
		if (prev_one < one) {
			row = i;
			prev_one = one;
		}
	}
	cout << row;

	// Time: O(n+m) | Space: O(1)
	int ans = -1;
	int i = 0; int j = M - 1;
	while ((i < N) && (j >= 0)) {
		if (arr[i][j] == 1) {
			ans = i;
			j--;
		}
		if (arr[i][j] == 0) {
			i++;
		}
	}
	cout << ans;
	return 0;
}