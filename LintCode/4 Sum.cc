/*
 * 4 sum
 *   Two pointers
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > fourSum(vector<int> nums, int target) {
  vector<vector<int> > result;
  auto nums_size = nums.size();

  if (nums_size < 4) {
    return result;
  }

  sort(nums.begin(), nums.end());

  for (auto i = 0; i < nums_size - 3; ) {
    for (auto j = i+1; j < nums_size - 2; ) {
      for (int m = j+1, n = nums_size - 1; m < n; ) {
        auto sum = nums[i] + nums[m] + nums[n] + nums[j];
        if (sum == target) {
          vector<int> tmp(4, 0);
          tmp[0] = nums[i];
          tmp[1] = nums[j];
          tmp[2] = nums[m];
          tmp[3] = nums[n];
          result.push_back(tmp);
        }
        if (sum <= target) {
          do {
            m++;
          } while(m < n && nums[m] == nums[m-1]);
        }
        if (sum >= target) {
          do {
            n--;
          } while(m < n && nums[n] == nums[n+1]);
        }
      }
      do {
        j++;
      } while(j < nums_size - 2 && nums[j] == nums[j-1]);
    }
    do {
      i++;
    } while(i < nums_size-3 && nums[i] == nums[i-1]);
  }

  return result;
}


int main(int argc, char const* argv[])
{
  int a[] = {1, 0, -1, 0, -2, 2};
  vector<int> v(a, a + 6);

  auto result = fourSum(v, 0);
  for (auto i = 0; i < result.size(); ++i) {
    cout << "("
      << result[i][0] << ", "
      << result[i][1] << ", "
      << result[i][2] << ", "
      << result[i][3] << ")";
  }

  return 0;
}
