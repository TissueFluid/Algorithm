// Insert Interval

#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        const int size = intervals.size();

        if (size == 0) {
            return {newInterval};
        }

        vector<Interval> result;

        bool canInsert = true;

        for (int i = 0; i < size; ++i) {
            if (newInterval.start > intervals[i].end) {
                result.push_back(intervals[i]);
            } else if (newInterval.end < intervals[i].start) {
                if (canInsert) {
                    result.push_back(newInterval);
                    canInsert = false;
                }
                result.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }

        if (canInsert) {
            result.push_back(newInterval);
        }

        return result;
    }
};
