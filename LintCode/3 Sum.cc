/*
 * Two pointers
 *   i: [0, size-2), ++
 *     j: [i+1, k), ++
 *     k: [size-1, j), --
 *
 * Notes:
 *   Remove duplicates by increase/decrease i,j,k
 *   when the neighbour elements equal.
 */
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > threeSum(vector<int> &nums) {
  vector<vector<int> > ret;
  vector<int>::size_type size = nums.size();

  sort(nums.begin(), nums.end());

  for (int i = 0; i < size-2; ) {
    for (int j=i+1, k=size-1; j < k; ) {
      int tmp = nums[i] + nums[j] + nums[k];
      if (tmp == 0) {
        vector<int> triple;
        triple.push_back(nums[i]);
        triple.push_back(nums[j]);
        triple.push_back(nums[k]);
        ret.push_back(triple);
        do {
          j++;
        } while (j < k && nums[j] == nums[j-1]);
        do {
          k--;
        } while (k > j && nums[k] == nums[k+1]);
      } else if (tmp > 0) {
        k--;
      } else {
        j++;
      }
    }
    do {
      i++;
    } while(i < size-2 && nums[i] == nums[i-1]);
  }

  return ret;
}

int main(int argc, char const* argv[])
{
  int a[] = {-1, 0, 1, 2, -1, -4};
  vector<int> v(a, a + sizeof(a)/sizeof(int));
  vector<vector<int> > result = threeSum(v);

  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
