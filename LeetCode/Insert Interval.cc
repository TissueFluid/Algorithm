// Insert Interval

#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        const int N = intervals.size();

        int i = 0;
        for (; i < N && intervals[i].end < newInterval.start; ++i) {
            result.push_back(intervals[i]);
        }

        for (; i < N && intervals[i].start <= newInterval.end; ++i) {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }

        result.push_back(newInterval);

        for (; i < N; ++i) {
            result.push_back(intervals[i]);
        }

        return result;
    }
};
