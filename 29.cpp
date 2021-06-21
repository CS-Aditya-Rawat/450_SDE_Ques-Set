// Find longest coinsecutive subsequence

#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// BruteForce Time: O(nLogn) | Space: O(1)
void solve(int arr[], int n) {
	if (n == 0) cout << "0";

	sort(arr, arr + n);

	int longestStreak = 1;
	int currentStreak = 1;

	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[i - 1]) {
			if (arr[i] == arr[i - 1] + 1) {
				currentStreak += 1;
			}
			else {
				longestStreak = max(longestStreak, currentStreak);
				currentStreak = 1;
			}
		}
	}
	cout << max(longestStreak, currentStreak);
}

// Using hashset Time: T(3n) | Space: O(n)
int longestConsecutive(vector<int> nums) {
	set<int> hashSet;
	for (int num : nums) {
		hashSet.insert(num);
	}

	int longestStreak = 0;

	for (int num : nums) {
		if (!hashSet.count(num - 1)) {
			int currentNum = num;
			int currentStreak = 1;

			while (hashSet.count(currentNum + 1)) {
				currentNum += 1;
				currentStreak += 1;
			}

			longestStreak = max(longestStreak, currentStreak);
		}
	}
	return longestStreak;
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