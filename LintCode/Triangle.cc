// Triangle - DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumTotal(vector<vector<int> > &triangle) {
    auto size = triangle.size();

    if (size == 0) {
        return 0;
    }

    for (auto i = size - 1; i > 0; i--) {
        for (auto j = 0; j < i; ++j) {
            triangle[i-1][j] += min(triangle[i][j], triangle[i][j+1]);
        }
    }

    return triangle[0][0];
}
