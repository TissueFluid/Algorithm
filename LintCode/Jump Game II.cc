/*
 * Jump Game II
 *   Greedy
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int jump(vector<int> A) {
  int size = A.size();

  if (size == 0) {
    return -1;
  }

  if (size == 1) {
    return 0;
  }

  int ret = 0;
  int fastest = 0;
  int pre_fastest = -1;
  while (fastest < size - 1) {
    int start = pre_fastest + 1;
    int end = fastest;
    pre_fastest = fastest;
    for (int i = start; i <= end; ++i) {
      fastest = max(fastest, A[i] + i);
    }
    ret++;
  }

  return ret;
}

int main(int argc, char const* argv[])
{
  int a[] = {2, 3, 1, 1, 4};
  vector<int> v(a, a + sizeof(a) / sizeof(int));

  cout << jump(v) << endl;

  return 0;
}
