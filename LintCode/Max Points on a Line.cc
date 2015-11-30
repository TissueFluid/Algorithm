// Max Points on a Line

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        const int size = points.size();
        int result = 1;

        if (size == 0) {
            return 0;
        }

        for (int i = 0; i < size - 1; ++i) {
            int dup = 0;
            unordered_map<double, int> m;

            for (int j = i + 1; j < size; ++j) {
                if (points[i].x == points[j].x
                    && points[i].y == points[j].y) {
                    dup++;
                    continue;
                }

                double dx = (double)(points[i].x - points[j].x);
                double slop;

                if (dx == 0) {
                    slop = numeric_limits<double>::max();
                } else {
                    slop = (double)(points[i].y - points[j].y) / dx;
                }

                if (m.find(slop) == m.end()) {
                    m[slop] = 2;
                } else {
                    m[slop]++;
                }
            }

            if (!m.empty()) {
                for (const auto &item : m) {
                    result = max(result, item.second + dup);
                }
            } else {
                result = max(result, dup + 1);
            }

        }

        return result;
    }
};
