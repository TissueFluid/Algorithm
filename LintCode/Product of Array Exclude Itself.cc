/*
 * Forward-Backward Traversal
 */

#include <iostream>
#include <vector>

using namespace std;

vector<long long> productExcludeItself(vector<int> &nums) {
  vector<long long> ret;
  int size = nums.size();
  long long left_to_i = 1;
  long long right_to_i = 1;

  ret.push_back(left_to_i);
  for (int i = 0; i < size - 1; i++) {
    left_to_i *= nums[i];
    ret.push_back(left_to_i);
  }

  for (int i = size - 1; i > 0; i--) {
    right_to_i *= nums[i];
    ret[i-1] *= right_to_i;
  }

  return ret;
}

int main(int argc, char const* argv[])
{
  int a[] = {1, 2, 3};
  vector<int> v(a, a+3);
  vector<long long> result = productExcludeItself(v);
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << endl;
  }
  return 0;
}
