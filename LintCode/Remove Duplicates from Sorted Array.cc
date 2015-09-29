#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums) {
  vector<int>::iterator i;
  for (i = nums.begin(); (i+1) < nums.end();) {
    if (*(i+1) == *i) {
      nums.erase(i+1);
    } else {
      ++i;
    }
  }
  return nums.size();
}

int main(int argc, char const* argv[])
{
  int a[] = {1, 1, 2};
  vector<int> v(a, a + sizeof(a) / sizeof(int));
  cout << removeDuplicates(v) << endl;
  return 0;
}
