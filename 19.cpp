#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// APPROACH 1 Time: O(nlogn)+O(n) | space: O(n)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> mergedIntervals;

	if (intervals.size() == 0) return mergedIntervals;
	sort(intervals.begin(), intervals.end());

	vector<int> tempInterval = intervals[0];
	for (auto it : intervals) {
		if (it[0] <= tempInterval[1]) {
			tempInterval[1] = max(it[1], tempInterval[1]);
		} else {
			mergedIntervals.push_back(tempInterval);
			tempInterval = it;
		}
	}
	mergedIntervals.push_back(tempInterval);
	return mergedIntervals;
}

// A O(n Log n) and O(1) Extra Space Solution
class Interval {
public:
	int s, e;
};

bool mycomp(Interval a, Interval b)
{
	return a.s < b.s;
}

void mergeIntervals(Interval arr[], int n)
{
	// Sort Intervals in increasing order of
	// start time
	sort(arr, arr + n, mycomp);

	int index = 0; // Stores index of last element
	// in output array (modified arr[])

	// Traverse all input Intervals
	for (int i = 1; i < n; i++)
	{
		// If this is not first Interval and overlaps
		// with the previous one
		if (arr[index].e >= arr[i].s)
		{
			// Merge previous and current Intervals
			arr[index].e = max(arr[index].e, arr[i].e);
			arr[index].s = min(arr[index].s, arr[i].s);
		}
		else {
			index++;
			arr[index] = arr[i];
		}
	}

	// Now arr[0..index-1] stores the merged Intervals
	cout << "\n The Merged Intervals are: ";
	for (int i = 0; i <= index; i++)
		cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}


int main() {
	fastio();
	vector<vector<int>> arr =  { {1, 4}, {0, 4} };
	vector<vector<int>> ans;
	ans = merge(arr);
	for (int i = 0 ; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	Interval arr1[] = { {1, 3}, {5, 6}, {7, 9}, {1, 4}, {5, 7} };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	mergeIntervals(arr1, n);
	return 0;
}

