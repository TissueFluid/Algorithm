// Sort Colors II

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        const int size = colors.size();

        int start = 1;
        int end = k;

        int left = 0;
        int right = size - 1;

        while (start < end) {
            for (int i = left; i <= right; ) {
                if (colors[i] == start) {
                    swap(colors[i], colors[left]);
                    left++;
                    i++;
                } else if (colors[i] == end) {
                    swap(colors[i], colors[right]);
                    right--;
                } else {
                    i++;
                }
            }
            start++;
            end--;
        }
    }
};

int main() {
    vector<int> v({3, 2, 2, 1, 4});
    Solution s;

    s.sortColors2(v, 4);

    for (const auto &item : v) {
        cout << item << endl;
    }
    return 0;
}
