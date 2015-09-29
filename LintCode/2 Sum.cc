/*
 * Two pointers
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  vector<int> ret;
  vector<int> triple;
  vector<int> copy(nums);
  vector<int>::size_type size = nums.size();
  int i, j;

  sort(copy.begin(), copy.end());

  for (i = 0, j = size-1; i < j; ) {
    int tmp = copy[i] + copy[j];
    if (tmp == target) {
      triple.push_back(copy[i]);
      triple.push_back(copy[j]);
      break;
    } else if (tmp > target) {
      j--;
    } else {
      i++;
    }
  }

  for (int k = 0; k < triple.size(); ++k) {
    ret.push_back(1 + distance(nums.begin(), find(nums.begin(), nums.end(), triple[k])));
  }

  if (ret[0] > ret[1]) {
    swap(ret[0], ret[1]);
  }

  return ret;
}

int main(int argc, char const* argv[])
{
  int a[] = {2, 7, 11, 15};
  vector<int> v(a, a+4);
  vector<int> result = twoSum(v, 9);
  cout << result[0] << ", " << result[1] << endl;
  return 0;
}
