// Number of Airplanes in the Sky

#include <vector>
#include <cstdlib>
#include <map>
using namespace std;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        map<int, int> m;

        for (const auto &plane : airplanes) {
            if (m.find(plane.start) == m.end()) {
                m[plane.start] = 1;
            } else {
                m[plane.start]++;
            }

            if (m.find(plane.end) == m.end()) {
                m[plane.end] = -1;
            } else {
                m[plane.end]--;
            }
        }

        int result = 0;
        int tmp = 0;

        for (const auto &item : m) {
            tmp += item.second;
            result = max(result, tmp);
        }

        return result;
    }
};

class Solution2 {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        vector<int> v;

        for (const auto &plane : airplanes) {
            v.push_back(plane.start);
            v.push_back(-plane.end);
        }

        sort(v.begin(), v.end(), [](const int a, const int b) {
                return abs(a) < abs(b) || (
                    a == -b && a < 0
                    );
            });

        int result = 0;
        int tmp = 0;
        for (const auto item : v) {
            if (item > 0) {
                tmp++;
                result = max(result, tmp);
            } else {
                tmp--;
            }
        }

        return result;
    }
};
