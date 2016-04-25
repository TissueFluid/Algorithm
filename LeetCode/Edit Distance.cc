// Edit Distance

#include <string>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int len1 = word1.length();
        const int len2 = word2.length();

        if (word1 == word2) {
            return 0;
        }

        if (len1 == 0) {
            return len2;
        }

        if (len2 == 0) {
            return len1;
        }

        vector<vector<int> > v(2, vector<int>(len1 + 1));
        int m = 0;
        int n = 1;

        iota(v[m].begin(), v[m].end(), 0);

        for (int i = 1; i <= len2; ++i) {
            v[n][0] = i;
            for (int j = 1; j <= len1; ++j) {
                if (word1[j - 1] == word2[i - 1]) {
                    v[n][j] = v[m][j - 1];
                } else {
                    v[n][j] = 1 + min(v[m][j-1], min(v[m][j], v[n][j-1]));
                }
            }
            swap(m, n);
        }

        return v[m][len1];
    }
};
