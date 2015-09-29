/*
 * Majority Number
 *   Greedy
 */

#include <iostream>
#include <vector>

using namespace std;

int majorityNumber(vector<int> nums) {
  int ret = 0;
  int size = nums.size();
  int count = 1;

  for (int i = 1; i < size; ++i) {
    if (nums[i] == nums[ret]) {
      count++;
    } else {
      count--;
    }

    if (count == 0) {
      ret = i;
      count = 1;
    }
  }

  return nums[ret];
}

int main(int argc, char const* argv[])
{
  int a[] = {1, 1, 1, 1, 2, 2, 2};

  vector<int> v(a, a + sizeof(a) / sizeof(int));
  cout << majorityNumber(v) << endl;

  return 0;
}
