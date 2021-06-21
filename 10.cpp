#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Using two pointerss
void solve(int arr[], int n) {
	int i = 0;
	int j = n - 1;
	while (i <= j) {
		if (arr[i] < 0 && arr[j] < 0) {
			i++;
		}
		else if (arr[i] > 0 && arr[j] < 0) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		else if (arr[i] > 0 && arr[j] > 0) {
			j--;
		}
		else {
			i++;
			j--;
		}
	}
}

// Using partition process of quicksort
void solve2(int arr[], int n) {

	int j = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			if (i != j)
				swap(arr[i], arr[j]);
			j++;
		}
	}
}

int main() {
	fastio();
	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	solve2(arr, N);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}