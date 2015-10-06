/*
 * Single Number II
 *   math
 */

#include <iostream>
#include <vector>

using namespace std;

int singleNumberII(vector<int> &A) {
  int a[32] = {0};

  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < 32; ++j) {
      a[j] += !!(A[i] & (1 << j));
    }
  }

  int ret = 0;

  for (int i = 0; i < 32; ++i) {
    ret |= ((a[i] % 3) << i);
  }

  return ret;
}

int main(int argc, char const* argv[])
{
  int a[] = {1, 1, 2, 3, 3, 3, 2, 2, 4, 1};
  vector<int> v(a, a + sizeof(a) / sizeof(int));

  cout << singleNumberII(v) << endl;

  return 0;
}
