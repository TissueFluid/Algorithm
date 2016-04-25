// Merge Intervals

// sort by start

#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;

        if (intervals.empty()) {
            return result;
        }

        sort(intervals.begin(), intervals.end(),
             [](const Interval &a, const Interval &b) {
                 return a.start < b.start;
             });

        Interval tmp = intervals[0];
        for (const auto &interval : intervals) {
            if (interval.start > tmp.end) {
                result.push_back(tmp);
                tmp = interval;
            } else {
                tmp.end = max(tmp.end, interval.end);
            }
        }
        result.push_back(tmp);

        return result;
    }
};
