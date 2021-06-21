#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main() {
	fastio();
	int N, k;
	cin >> N >> k;
	int arr[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	priority_queue<int, vector<int>, greater<int>> p;

	for (int i = 0; i < N; i++) {
		p.push(arr[i]);
	}

	int ans, i = 1;
	while (!p.empty()) {
		if (i == k) {
			ans = p.top();
			break;
		}
		i++;
		p.pop();
	}
	cout << ans;
	return 0;
}