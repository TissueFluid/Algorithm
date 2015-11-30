#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        const int size = A.size();

        int count = 0;
        for (const auto &item : A) {
            if (item >= 0) {
                count++;
            } else {
                count--;
            }
        }

        int a = 0;
        int b = 1;

        if (count > 0) {
            swap(a, b);
        }

        while (a < size && b < size) {
            if (A[a] < 0) {
                a += 2;
            } else {
                swap(A[a], A[b]);
                b += 2;
            }
        }

        return;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    vector<int> A = {-1, -2, -3, 4, 5, 6};

    s.rerange(A);

    for (auto item : A) {
        cout << item << endl;
    }
    return 0;
}
