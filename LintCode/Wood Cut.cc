/*
 * Wood Cut
 *   Binary Search
 */

#include <iostream>
#include <vector>

using namespace std;

int woodCut(vector<int> L, int k) {
  int L_size = L.size();

  if (L_size < 1) {
    return 0;
  }

  long long max = L[0];
  for (auto i = 1; i < L_size; ++i) {
    if (L[i] > max) {
      max = L[i];
    }
  }

  long long left = 0;
  long long right = max + 1;
  long long mid = (left + right) / 2;

  while (left < mid) {
    auto tmp = 0;
    for (auto i = 0; i < L_size; ++i) {
      tmp += L[i] / mid;
    }
    if (tmp >= k) {
      left = mid;
    } else {
      right = mid;
    }
    mid = (left + right) / 2;
  }

  return (int)left;
}

int main(int argc, char const* argv[])
{
  int a[] = {232, 114, 456};
  vector<int> v(a, a + 3);

  cout << woodCut(v, 7) << endl;

  int b[] = {2147483644,2147483645,2147483646,2147483647};
  vector<int> v2(b, b + 4);

  cout << woodCut(v2, 4) << endl;

  return 0;
}
