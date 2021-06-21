#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int main() {
	fastio();
	int N;
	cin >> N ;
	int arr[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int last = arr[N - 1];
	for (int i = N; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = last;

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}