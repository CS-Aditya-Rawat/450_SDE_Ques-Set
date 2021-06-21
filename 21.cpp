#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


// Brutefore Time: O(n^2) | Space: O(1)
int solve(int arr[], int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] > arr[j]) count += 1;
		}
	}
	cout << count;
}

// using Merge Sort Algorithm Time: O(nlogn) | Space: O(n)
int merge(int arr[], int temp[], int left, int mid, int right) {
	int i, j, k, inv_count = 0;
	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i );
		}
	}

	while (i <= mid - 1) {
		temp[k++] = arr[i++];
	}

	while (j <= right) {
		temp[k++] = arr[j++];
	}

	for (i = left; i <= right; i++) {
		arr[i] = temp[i];
	}

	return inv_count;
}

int mergeSort(int arr[], int temp[], int left, int right) {
	int inv_count = 0;
	if (left < right) {
		int mid = (right + left) / 2;

		inv_count += mergeSort(arr,  temp, left, mid);
		inv_count += mergeSort(arr, temp, mid + 1, right);

		inv_count += merge(arr, temp, left, mid + 1, right);
	}

	return inv_count;
}

int main() {
	fastio();
	int N;
	cin >> N;
	int arr[N];
	int temp[N];
	for (int i = 0; i < N; i++) cin >> arr[i];

	cout << mergeSort(arr, temp, 0,  N - 1);
	return 0;
}