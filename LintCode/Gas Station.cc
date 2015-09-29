/*
 * Gas Station
 *   Greedy
 */

#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  int size = gas.size();
  int ret = 0;
  int sum = 0;
  int total = 0;

  for (int i = 0; i < size; ++i) {
    int diff = gas[i] - cost[i];
    total += diff;
    sum += diff;
    if (sum < 0) {
      sum = 0;
      ret = i + 1;
    }
  }

  if (total < 0) {
    return -1;
  }

  return ret;
}

int main(int argc, char const* argv[])
{
  int arr_gas[] = {1, 1, 3, 1};
  int arr_cost[] = {2, 2, 1, 1};
  vector<int> v_gas(arr_gas, arr_gas + 3);
  vector<int> v_cost(arr_cost, arr_cost + 3);

  cout << canCompleteCircuit(v_gas, v_cost) << endl;

  return 0;
}
