/*
https://leetcode.com/problems/merge-intervals/

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

#include "std_headers.h"


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareIterval(Interval& l, Interval& r) {
	return (l.start < r.start);
}

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		Interval cur;
		Interval* data;
		int size = intervals.size();
		vector<Interval> res;
		if (size <= 1)
			return intervals;

		std::sort(intervals.begin(), intervals.end(), compareIterval);
		data = intervals.data();
		cur = data[0];
		for (int i = 1; i < size; i++) {
			if (cur.end >= data[i].start) {
				cur.end = (cur.end > data[i].end) ? cur.end : data[i].end;
			}
			else {
				res.push_back(cur);
				cur = data[i];
			}

			if (i == size - 1)
				res.push_back(cur);
		}

		return res;
	}
};