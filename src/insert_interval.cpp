/*
https://leetcode.com/problems/insert-interval/

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

#include "std_headers.h"


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval>  res;
		Interval cur;
		Interval* data = intervals.data();
		int size = intervals.size();
		int i = 0;

		if (intervals.empty()) {
			res.push_back(newInterval);
			return res;
		}

		while (i < size && newInterval.start > data[i].start) {
			i++;
		}

		for (int j = 0; j < i - 1; j++)
			res.push_back(data[j]);

		if (i) {
			if (data[i - 1].end >= newInterval.start) {
				cur.start = data[i - 1].start;
				cur.end = max(data[i - 1].end, newInterval.end);
			}
			else {
				res.push_back(data[i-1]);
				cur = newInterval;
			}
		}
		else {
			cur = newInterval;
		}
		

		for (int j = i; j <= size; j++) {
			if (j == size) {
				res.push_back(cur);
				break;
			}

			if (cur.end >= data[j].start) {
				cur.end = (cur.end > data[j].end) ? cur.end : data[j].end;
			}
			else {
				res.push_back(cur);
				cur = data[j];
			}
		}

		return res;
	}
};