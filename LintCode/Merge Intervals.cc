// Merge Intervals

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        struct {
            bool operator() (Interval a, Interval b) {
                return a.start < b.start;
            }
        } cmp;

        sort(intervals.begin(), intervals.end(), cmp);

        vector<Interval> result;

        const int size = intervals.size();

        if (size == 0) {
            return result;
        }

        Interval itv(intervals[0].start, intervals[0].end);

        for (int i = 1; i < size; ++i) {
            if (itv.end >= intervals[i].start) {
                itv.end = max(itv.end, intervals[i].end);
            } else {
                result.push_back(itv);
                itv.start = intervals[i].start;
                itv.end = intervals[i].end;
            }
        }

        result.push_back(itv);

        return result;
    }
};
