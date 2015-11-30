// Permutation Sequence

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int fact(int x) {
        int result = 1;
        for (int i = 2; i <= x; ++i) {
            result *= i;
        }
        return result;
    }
public:
    /**
     * @param n: n
     * @param k: the kth permutation
     * @return: return the k-th permutation
     */
    string getPermutation(int n, int k) {
        vector<int> result;
        vector<int> nums(n);

        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }
        auto factor = fact(n - 1);

        k--;
        int j = n - 1;
        for (int i = 0; i < n; ++i) {
            int candidate = k / factor;
            result.push_back(nums[candidate]);
            nums.erase(nums.begin() + candidate);
            k = k % factor;
            if (j) {
                factor /= j;
                j--;
            }
        }

        string ret("");
        for (const auto &item : result) {
            ret += to_string(item);
        }

        return ret;
    }
};
