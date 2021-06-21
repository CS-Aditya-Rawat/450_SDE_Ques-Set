#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Time: O(n1 + n2) | Space: O(n1+n2)
void solve(int arr1[], int arr2[], int n, int m) {
	int arr3[n + m];
	int i = 0, j = 0, k = 0;

	while (i < n && j < m) {
		if (arr1[i] < arr2[j]) {
			arr3[k++] = arr1[i++];
		}
		else {
			arr3[k++] = arr2[j++];
		}
	}
	while (i < n) {
		arr3[k++] = arr1[i++];
	}
	while (j < m) {
		arr3[k++] = arr2[j++];
	}
	for (auto it : arr3) cout << it << " ";
}

// Insertion sort like approach Time: O(n*m) | Space: O(1)
void solve2(int arr1[], int arr2[], int n, int m) {
	int i = 0, j = 0;
	while (i < n) {
		if (arr1[i] > arr2[j]) {
			swap(arr1[i], arr2[j]);
			sort(arr2, arr2 + m);
		}
		i++;
	}
	for (int i = 0; i < n; i++) cout << arr1[i] << " ";
	cout << "\n";
	for (int i = 0; i < m; i++) cout << arr2[i] << " ";
}

// GAP Algorithm (Shell Short) Time: O((n+m)*log(n+m)) | Space: O(1)
int nextGap(int gap) {
	if (gap <= 1) {
		return 0;
	}
	return (gap / 2) + (gap % 2);
}

void solve3(int* arr1, int* arr2, int n, int m) {
	int i, j, gap = n + m;
	for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
	{
		// Comparing the elements of 1st array
		for (i = 0; i + gap < n; i++) {
			if (arr1[i] > arr1[i + gap])
				swap(arr1[i], arr1[i + gap]);
		}

		// comparing elements in both arrays.
		for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++) {
			if (arr1[i] > arr2[j])
				swap(arr1[i], arr2[j]);
		}

		// comparing the elements in the second aray
		if (j < m) {
			for (j = 0; j + gap < m; j++) {
				if (arr2[j] > arr2[j + gap])
					swap(arr2[j], arr2[j + gap]);
			}
		}

	}
}
int main() {
	int N, M;
	cin >> N >> M;
	int arr1[N];
	int arr2[M];
	for (int i = 0; i < N; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> arr2[i];
	}
	solve3(arr1, arr2, N, M);
	for (int i = 0; i < N; i++) {
		cout << arr1[i] << " ";
	}

	cout << "\n";

	for (int i = 0; i < M; i++) {
		cout << arr2[i] << " ";
	}
	return 0;
}