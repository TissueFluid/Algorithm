// Permutation Index

// 1 2 4
// 1 4 2
// 2 1 4
// 2 4 1
// 4 1 2
// 4 2 1

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        const int size = A.size();

        if (size == 0) {
            return 0;
        }

        long long result = 1;
        long long base = 1;

        for (int i = size - 2; i >= 0; --i) {
            int count = 0;
            for (int j = i + 1; j < size; ++j) {
                if (A[j] < A[i]) {
                    count++;
                }
            }
            result += base * count;
            base *= (size - i);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> v({1, 2, 4});

    cout << s.permutationIndex(v) << endl;
    return 0;
}
