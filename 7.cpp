#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/* This method does 2(n-2)+1 Operations */
void solve(int arr[], int n) {
	int mini;
	int maxi;
	if (n == 1) {
		mini = arr[0];
		maxi = arr[0];
	}
	else {
		if (arr[0] < arr[1]) {
			maxi = arr[1];
			mini = arr[0];
		} else {
			mini = arr[1];
			maxi = arr[0];
		}
		for (int i = 2; i < n; i++) {
			if (arr[i] > maxi) maxi = arr[i];
			if (arr[i] < mini) mini = arr[i];
		}
	}
	cout << "The max element is " << maxi << "\n";
	cout << "The min element is " << mini << "\n";
}

/* Method 2 Optimised low number of comparision*/
void solve2(int arr[], int n) {
	int mini, maxi;
	int i;

	if (n % 2 == 0) {
		if (arr[0] > arr[1]) {
			maxi = arr[0];
			mini = arr[1];
		}
		else {
			maxi = arr[1];
			mini = arr[0];
		}
		i = 2;
	}
	else {
		maxi = arr[0];
		mini = arr[0];
		i = 1;
	}
	while (i < n - 1) {
		if (arr[i] > arr[i + 1]) {    // odd -> 3*(n-1)/2   even -> 1+3*(n-2)/2
			if (arr[i] > maxi) maxi = arr[i];
			if (arr[i + 1] < mini) mini = arr[i + 1];
		}
		else {
			if (arr[i + 1] > maxi) maxi = arr[i + 1];
			if (arr[i] < mini) mini = arr[i];
		}
		i += 2;
	}

	cout << "The max element is " << maxi << "\n";
	cout << "The min element is " << mini << "\n";
}
int main() {
	fastio();
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	solve2(arr, n);
	return 0;
}