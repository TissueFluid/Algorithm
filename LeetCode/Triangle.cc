// Triangle

#include <vector>
using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    const int height = triangle.size();

    if (height == 0) {
      return 0;
    }

    for (int i = height - 2; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
      }
    }

    return triangle[0][0];
  }
};
