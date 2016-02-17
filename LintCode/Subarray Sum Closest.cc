/*
 * Sybarray Sum Closest
 *
 *   for i: [0, size)
 *     sum[i] = sum[i-1] + a[i]
 *   sort(sum[])
 *   ...
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;

struct Sum{
  int sum;
  int index;
  Sum(){}
  Sum(int sum, int index) {
    this->sum = sum;
    this->index = index;
  }
  bool operator () (Sum &a, Sum &b) {
    return a.sum < b.sum;
  }
  /* static bool cmp(Sum a, Sum b) { */
  /*   return a.sum < b.sum; */
  /* } */
};

vector<int> subarraySumClosest(vector<int> nums){
  auto size = nums.size();

  vector<int> result;
  vector<Sum> sum;

  if (size == 0) {
    return result;
  } else if (size == 1) {
    result.push_back(0);
    result.push_back(0);
    return result;
  }

  sum.push_back(Sum(0, -1));
  for (auto i = 0; i < size; ++i) {
    sum.push_back(Sum(nums[i] + sum.back().sum, i));
  }

  /* sort(sum.begin(), sum.end(), Sum::cmp); */
  sort(sum.begin(), sum.end(), Sum());

  auto closest = numeric_limits<unsigned>::max();
  auto index = 0;

  for (auto i = 0; i < sum.size() - 1; i++) {
    auto tmp = abs(sum[i+1].sum - sum[i].sum);
    if (tmp == 0) {
      index = i;
      break;
    } else if (tmp < closest) {
      index = i;
      closest = tmp;
    }
  }

  result.push_back(sum[index+1].index);
  result.push_back(sum[index].index);
  if (result[0] > result[1]) {
    swap(result[0], result[1]);
  }
  result[0] += 1;

  return result;
}

int main(int argc, char const* argv[])
{
  int a[] = {-3, 1, 1, -3, 5};
  vector<int> v(a, a+5);

  vector<int> result = subarraySumClosest(v);
  cout << result[0] << ", " << result[1] << endl;

  return 0;
}
