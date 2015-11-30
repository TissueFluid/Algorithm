// Longest Increasing Continuous subsequence

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int result = 1;

        int start = 1;
        const int size = A.size();

        if (size <= 2) {
            return size;
        }

        while (start < size) {
            int count = 1;
            while (start < size && A[start] > A[start - 1]) {
                start++;
                count++;
            }
            result = max(result, count);

            count = 1;
            while (start < size && A[start] < A[start - 1]) {
                start++;
                count++;
            }

            result = max(result, count);
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> v1({5, 4, 2, 1, 3});
    vector<int> v2({5, 1, 2, 3, 4});

    cout << s.longestIncreasingContinuousSubsequence(v1) << endl;
    cout << s.longestIncreasingContinuousSubsequence(v2) << endl;

    return 0;
}
