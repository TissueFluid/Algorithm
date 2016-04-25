//  Unique Binary Search Trees

#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> v(n + 1, 0);

        v[0] = v[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                v[i] += v[j] * v[i - j - 1];
            }
        }

        return v[n];
    }
};
