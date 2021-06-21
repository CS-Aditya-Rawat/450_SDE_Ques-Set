#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void DNF(int arr[], int n) {
	int low = 0, mid = 0, high = n - 1;

	while (mid <= high) {
		switch (arr[mid])
		{
		case 0:
			swap(arr[low], arr[mid]);
			low++;
			mid++;
			break;

		case 1:
			mid++;
			break;

		case 2:
			swap(arr[mid], arr[high]);
			high--;
			break;
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
	DNF(arr, N);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}