// Given an array of size n and a number k, fin all elements that appear more than " n/k " times.

#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int solve(int arr[], int n, int k) {
	int x = n / k;
	int count = 0;
	unordered_map<int, int> freq;

	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}
	for (auto i : freq)
	{
		if (i.second > x) {
			cout << i.first << " ";
			count += 1;
		}
	}
	return count;
}

int main() {
	int n, k;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> k;
	solve(a, n, k);
	return 0;
}