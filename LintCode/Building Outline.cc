// Building Outline

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define X1 0
#define X2 1
#define HEIGHT 2
class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        vector<vector<int> > result;
        const int size = buildings.size();

        if (size == 0) {
            return result;
        }

        map<int, vector<int> > map_x_to_height;

        for (const auto &building : buildings) {
            if (building[HEIGHT] != 0) {
                map_x_to_height[building[X1]].push_back(-building[HEIGHT]);
                map_x_to_height[building[X2]].push_back(building[HEIGHT]);
            }
        }

        map<int, int> map_height_to_count;
        int curr_start = -1;
        int curr_max = 0;

        for (const auto &item : map_x_to_height) {
            const auto &x = item.first;
            const auto &heights = item.second;

            for (const auto &height : heights) {
                if (height < 0) {
                    if (map_height_to_count.find(-height) ==
                        map_height_to_count.end()) {
                        map_height_to_count[-height] = 1;
                    } else {
                        map_height_to_count[-height]++;
                    }
                } else {
                    map_height_to_count[height]--;
                    if (map_height_to_count[height] == 0) {
                        map_height_to_count.erase(height);
                    }
                }
            }

            if (map_height_to_count.empty()
                || curr_max != map_height_to_count.crbegin()->first) {

                if (curr_max > 0) {
                    result.push_back({curr_start, x, curr_max});
                }
                curr_start = x;
                curr_max = map_height_to_count.empty() ?
                    0 : map_height_to_count.crbegin()->first;
            }
        }

        return result;
    }
};
