// Candy - Greedy

#include <vector>
using namespace std;

class Solution {
public:
  int candy(vector<int>& ratings) {
    const int N = ratings.size();
    vector<int> candies(N, 1);

    for (int i = 1; i < N; ++i) {
      if (ratings[i] > ratings[i-1]) {
        candies[i] = candies[i-1] + 1;
      }
    }

    int result = 0;

    for (int i = N - 1; i > 0; --i) {
      result += candies[i];
      if (ratings[i-1] > ratings[i] && candies[i-1] <= candies[i]) {
        candies[i-1] = candies[i] + 1;
      }
    }

    result += candies[0];

    return result;
  }
};
