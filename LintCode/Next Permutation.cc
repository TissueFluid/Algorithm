/*
 * Next Permutation
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nextPermutation(vector<int> &nums) {
  vector<int> ret(nums);

  int size = nums.size();

  if (size == 0) {
    return ret;
  }

  int i, min;

  for (i = size - 1; i > 0 && ret[i-1] >= ret[i] ; i--);

  if (i > 0) {
    for (min = size - 1; ret[min] <= ret[i-1]; min--);
    swap(ret[i-1], ret[min]);
  }
  reverse(ret.begin() + i, ret.end());

  return ret;
}

int main(int argc, char const* argv[])
{
  int a[] = {2, 1, 1};
  vector<int> v(a, a + sizeof(a) / sizeof(int));

  vector<int> result = nextPermutation(v);

  for (size_t i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;
}
