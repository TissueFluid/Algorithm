// Permutation Sequence

#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    int fact(int n) {
        int result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

public:
    string getPermutation(int n, int k) {
        k--;
        int factor = fact(n - 1);
        vector<char> tmp;
        string result("");

        for (int i = 1; i <= n; ++i) {
            tmp.push_back(i + '0');
        }

        for (int i = n-1; i >= 0; --i) {
            int candidate = k / factor;
            result.push_back(tmp[candidate]);
            tmp.erase(tmp.begin() + candidate);
            k = k % factor;
            if (i > 0) {
                factor /= i;
            }
        }

        return result;
    }
};
