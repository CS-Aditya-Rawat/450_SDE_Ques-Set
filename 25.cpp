#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


// Bruteforce Time: | Space: O(n)
void solve(int a[], int n) {
	vector<int> positive;
	vector<int> negative;
	vector<int> ans;
	for (int i = 0 ; i < n; i++) {
		if (a[i] >= 0)
			positive.push_back(a[i]);
		else
			negative.push_back(a[i]);
	}
	int i = 0, j = 0;
	while (i < positive.size() && j < negative.size()) {
		ans.push_back(negative[j]);
		ans.push_back(positive[i]);
		i++; j++;
	}
	while (i < positive.size()) {
		ans.push_back(positive[i]);
		i++;
	}
	while (j < negative.size()) {
		ans.push_back(negative[j]);
		j++;
	}
	for (auto it : ans) cout << it << " ";
}
// Optimised Time: | Space: O(1)
// int rightRotate(int arr[], int from , int to) {
// 	int temp = arr[to];
// 	for (int i = to; i > from; i++) {
// 		arr[i] = arr[i - 1];
// 	}
// 	arr[from] = temp;

// }

// void solve2(int a[], int n) {
// 	int wrongIndex = -1;
// 	for (int i = 0; i < n; i++) {
// 		if (wrongIndex != -1) {
// 			if ((a[wrongIndex] >= 0 && a[i] < 0) || (a[wrongIndex] < 0 && a[i] >= 0)) {
// 				rightRotate(a, wrongIndex, i);
// 				if (i - wrongIndex  >= 2) // To check the wrongIndex present between the rotation
// 					wrongIndex += 2;
// 				else
// 					wrongIndex = -1;
// 			}
// 		}
// 		else {
// 			if ((a[i] < 0 && i % 2 == 1) || (a[i] >= 0 && i % 2 == 0))
// 				wrongIndex = i;
// 		}
// 	}
// 	for (int i = 0; i < n; i++) cout << a[i] << " ";

// }
int main() {
	fastio();
	int N;
	cin >> N;
	int arr[N];
	for (int i = 0; i < N; i++) cin >> arr[i];
	solve2(arr, N);
	return 0;
}