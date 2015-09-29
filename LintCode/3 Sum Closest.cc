/*
 * Two pointers
 *   i: [0, size-2), ++
 *     j: [i+1, k), ++
 *     k: [size-1, j), --
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int threeSumClosest(vector<int> nums, int target) {
  long long ret, tmp_sum, tmp_dist;
  int i, j, k;
  vector<int>::size_type size = nums.size();
  unsigned long long dist = ULLONG_MAX;

  sort(nums.begin(), nums.end());

  for (i = 0; i < size - 2; ++i) {
    for (j = i+1, k = size - 1; j < k; ) {
      tmp_sum = nums[i] + nums[j] + nums[k];
      tmp_dist = llabs(tmp_sum - target);
      if (tmp_dist == 0) {
        return target;
      }
      if (dist > tmp_dist) {
        ret = tmp_sum;
        dist = tmp_dist;
      }
      if (tmp_sum > target) {
        k--;
      } else {
        j++;
      }
    }
  }

  return (int)ret;
}

int main(int argc, char const* argv[])
{
  int a[] = {-1, 2, 1, -4};
  vector<int> v(a, a+4);

  cout << threeSumClosest(v, 1) << endl;
  return 0;
}
