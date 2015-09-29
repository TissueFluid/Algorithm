#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums) {

  for (int i = 0; i < nums.size();) {
    if (i < 2 || nums[i] != nums[i-2]) {
      i++;
    } else {
      nums.erase(nums.begin() + i);
    }
  }

  return nums.size();
}

int main(int argc, char const* argv[])
{
  int a[] = {1, 1, 1, 2, 2, 3};
  vector<int> v(a, a+sizeof(a)/sizeof(int));
  cout << removeDuplicates(v) << endl;
  return 0;
}
