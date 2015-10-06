/*
 * Majority Number III
 *   Greedy, hashmap
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int majorityNumber(vector<int> nums, int k) {
    unordered_map<int, unsigned> m;
    unsigned size = nums.size();

    for (unsigned i = 0; i < size; ++i) {
        auto found = m.find(nums[i]);
        if (found == m.end()) {
            if (m.size() < (unsigned)k) {
                m[nums[i]] = 1;
            } else {
                for (auto it = m.begin(); it != m.end(); ) {
                    it->second--;
                    if (it->second == 0) {
                        m.erase(it++);
                        if (m.size() < (unsigned)k) {
                            m[nums[i]] = 1;
                        }
                    } else {
                        ++it;
                    }
                }
            }
        } else {
            found->second++;
        }
    }

    unsigned max = 0;
    int ret = 0;

    for (auto &item : m) {
        if (item.second >= max) {
            max = item.second;
            ret = item.first;
        }
    }

    return ret;
}

int main()
{
    int a[] = {3, 1, 2, 3, 2, 3, 3, 4, 4, 4};
    vector<int> v(a, a + sizeof(a) / sizeof(int));

    cout << majorityNumber(v, 3) << endl;

    return 0;
}
