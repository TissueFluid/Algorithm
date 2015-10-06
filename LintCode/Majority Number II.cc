/*
 * Majority Number II
 *   Greedy
 */

#include <iostream>
#include <vector>

using namespace std;

int majorityNumber(vector<int> nums) {
  int size = nums.size();
  int a = 0;
  int b = 0;
  int count_a = 0;
  int count_b = 0;

  for (int i = 0; i < size; ++i) {
    if (count_a && nums[i] == a) {
      count_a++;
    } else if (count_b && nums[i] == b) {
      count_b++;
    } else if (count_a == 0) {
      a = nums[i];
      count_a++;
    } else if (count_b == 0) {
      b = nums[i];
      count_b++;
    } else {
      if (count_a) {
        count_a--;
      }
      if (count_b) {
        count_b--;
      }
      if (count_a == 0) {
        a = nums[i];
        count_a++;
      } else if (count_b == 0) {
        b = nums[i];
        count_b++;
      }
    }
  }

  int count = 0;
  for (int x : nums) {
    if (x == a) {
      count++;
    }
  }

  return (count > size / 3 ? a : b);
}

int main(int argc, char const* argv[])
{
  int a[] = {1, 2, 1, 2, 1, 3, 3};
  vector<int> v(a, a + sizeof(a) / sizeof(int));

  cout << majorityNumber(v) << endl;

  return 0;
}
