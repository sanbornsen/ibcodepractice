/**

Merge Intervals

Link - https://www.interviewbit.com/problems/merge-intervals/

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	vector<Interval> ans;
	int i = 0;

	if (!intervals.size()) { // When there is no element
		ans.push_back(newInterval);
	}
	else if (newInterval.end < intervals[0].start) { // If new interval comes first
		ans.push_back(newInterval);
		for (int i=0; i<intervals.size(); i++){
			ans.push_back(intervals[i]);
		}
	} else if (newInterval.start > intervals[intervals.size()-1].end) { // If new interval comes first
		for (int i=0; i<intervals.size(); i++){
			ans.push_back(intervals[i]);
		}
		ans.push_back(newInterval);
	} else {
		int overlapStarted = 0;
		for (int i=0; i<intervals.size(); i++){
			if (max(intervals[i].start, newInterval.start) > min(intervals[i].end, newInterval.end)){ // do not overlap
				if (overlapStarted) {
					ans.push_back(newInterval);
					overlapStarted = 0;
				} else if (i > 0 && intervals[i-1].end < newInterval.start && intervals[i].start > newInterval.end) {
					ans.push_back(newInterval);
				}
				ans.push_back(intervals[i]);
			} else { // overlap found
				overlapStarted = 1;
				newInterval.start = min(intervals[i].start, newInterval.start);
				newInterval.end = max(intervals[i].end, newInterval.end);
			}
		}
		if (overlapStarted) {
			ans.push_back(newInterval);
		}
	}
	return ans;
}

int main() {
	Interval f[4], x;

	 f[0].start = 1;
	 f[0].end = 2;

	f[1].start = 3;
	f[1].end = 5;

	f[2].start = 6;
	f[2].end = 7;

	f[3].start = 8;
	f[3].end = 10;

	// f[4].start = 12;
	// f[4].end = 16;

	vector<Interval> intervals(f, f + sizeof(f) / sizeof(f[0]));
	x.start = 4;
	x.end = 9;

	vector<Interval> ans = insert(intervals, x);

	for (int i=0; i<ans.size(); i++){
		cout << ans[i].start << " , " << ans[i].end << endl;
	}

	return 0;
}
