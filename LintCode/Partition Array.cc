/*
 * Partition Array
 *   Two pointers;
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int partitionArray(vector<int> &nums, int k) {
  vector<int>::size_type size = nums.size();
  int i, j;

  for (i = 0, j = size - 1; i <= j; ) {
    while (i <= j && nums[i] < k) i++;
    while (i <= j && nums[j] >= k) j--;
    if (i < j) {
      swap(nums[i], nums[j]);
      i++;
      j--;
    }
  }

  return i;
}

int main(int argc, char const* argv[])
{
  int a[] = {3, 2, 2, 1};
  vector<int> v(a, a+4);

  cout << partitionArray(v, 2) << endl;

  return 0;
}
