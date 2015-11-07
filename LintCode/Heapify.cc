// Heapify

// left + 1 = 2 * (i + 1) = 2i + 1
// right + 1 = 2 * (i + 1) + 1 = 2i + 2


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
#define LEFT(i)  (2*(i) + 1)
#define RIGHT(i) (2*(i) + 2)
    void heapify(vector<int> &A) {
        const int size = A.size();

        for (int i = size / 2 - 1; i >=0; --i) {
            for (int j = i; j < size;) {
                int smallest = j;

                if (LEFT(j) < size && A[LEFT(j)] < A[smallest]) {
                    smallest = LEFT(j);
                }

                if (RIGHT(j) < size && A[RIGHT(j)] < A[smallest]) {
                    smallest = RIGHT(j);
                }

                if (smallest == j) {
                    break;
                }

                swap(A[j], A[smallest]);

                j = smallest;
            }
        }
    }
};

int main() {
    Solution s;

    vector<int> v({3, 2, 1, 4, 5});
    s.heapify(v);

    for (const auto &item : v) {
        cout << item << endl;
    }
    return 0;
}
