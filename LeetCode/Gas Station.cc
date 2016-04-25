// Gas Station

#include <vector>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    const int LEN = gas.size();
    int total = 0;
    int amountOfGas = 0;
    int ret = 0;

    for (int i = 0; i < LEN; ++i) {
      int diff = gas[i] - cost[i];
      total += diff;
      amountOfGas += diff;

      if (amountOfGas < 0) {
        amountOfGas = 0;
        ret = i + 1;
      }
    }

    if (total < 0) {
      return - 1;
    }

    return ret;
  }
};
