#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// Hashing Time: O(n) | Space: O(n)

void solve(int arr[], int n) {
	int count = 0;
	int freq[n];
	for (int i = 0; i < n; i++) freq[i] = 0;

	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (freq[i] > 1) count++;
	}
	cout << count;
}

// Hare and tortise method Time: O(n) | Space: O(1)
void solve2(int arr[]) {
	int slow = arr[0];
	int fast = arr[0];
	do {
		slow = arr[slow];
		fast = arr[arr[fast]];
	} while (slow != fast);

	fast = arr[0];
	while (slow != fast) {
		slow = arr[slow];
		fast = arr[fast];
	}
	cout << slow;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	solve2(arr);
	return 0;
}