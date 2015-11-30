// Permutation Index II

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    long long fact(long long n) {
        if (n == 0) {
            return 1;
        }

        long long result = n;

        while (--n) {
            result *= n;
        }

        return result;
    }

    long long dups(const unordered_map<int, int> &m) {
        long long result = 1;
        for (const auto &item : m) {
            result *= fact(item.second);
        }
        return result;
    }
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        const int size = A.size();

        if (size == 0) {
            return 0;
        }

        unordered_map<int, int> m;
        long long base = 1;
        long long result = 1;

        m[A[size - 1]] = 1;
        for (int i = size - 2; i >= 0; --i) {
            long long count = 0;
            if (m.find(A[i]) == m.end()) {
                m[A[i]] = 1;
            } else {
                m[A[i]]++;
            }
            for (int j = i + 1; j < size; ++j) {
                if (A[j] < A[i]) {
                    count++;
                }
            }

            result += (base * count / dups(m));
            base *= (size - i);
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> v = {10,10,10,10,9,8,7,6,5,4,3,2,1};

    cout << s.permutationIndexII(v) << endl;
    return 0;
}
