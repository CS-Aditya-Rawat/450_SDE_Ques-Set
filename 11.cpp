#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int main() {
	fastio();
	int N, M;
	cin >> N >> M;
	set<int, greater<int> > s1;
	int arr[N];
	int arr1[M];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		s1.insert(arr[i]);
	}
	for (int i = 0; i < M; i++) {
		cin >> arr1[i];
		s1.insert(arr[i]);
	}
	cout << s1.size();
	return 0;
}