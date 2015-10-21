// Backpack - DP

#include <iostream>
#include <vector>
using namespace std;

int backPack(int m, vector<int> A) {
    const int sizeA = A.size();

    if (sizeA == 0 || m == 0) {
        return 0;
    }

    vector<bool> canPack(m + 1, false);
    canPack[0] = true;

    for (int i = 0; i < sizeA; ++i) {
        for (int j = m; j >= A[i]; j--) {
            if (canPack[j - A[i]]) {
                canPack[j] = true;
            }
        }
    }

    for (size_t i = m; i > 0; i--) {
        if (canPack[i]) {
            return i;
        }
    }

    return 0;
}

int main() {
    cout << backPack(11, vector<int>({2, 3, 5, 7})) << endl;
    cout << backPack(12, vector<int>({2, 3, 5, 7})) << endl;
    return 0;
}
