#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve2(int arr[], int n) {
	int result = arr[0];
	for (int i = 0; i < n; i++) {
		int mul = arr[i];

		for (int j = i + 1 ; j < n ; j++) {
			result = max(result, mul);
			mul *= arr[j];
			cout << mul;
		}
		result = max(result, mul);
	}
	cout << result;
}

void solve(int arr[], int n) {
	int curr_max_product = arr[0];
	int prev_max_product = arr[0];
	int prev_min_product = arr[0];
	int ans = arr[0];
	for (int i = 1; i < n; i++) {
		curr_max_product = max(prev_max_product * arr[i] , max(prev_min_product * arr[i], arr[i]));
		int curr_min_product = min(prev_max_product * arr[i] , min(prev_min_product * arr[i], arr[i]));
		ans = max(ans, curr_max_product);
		prev_max_product = curr_max_product;
		prev_min_product = curr_min_product;
	}
	cout << ans;
}

int main() {
	fastio();
	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];
	solve(arr, N);
	return 0;
}