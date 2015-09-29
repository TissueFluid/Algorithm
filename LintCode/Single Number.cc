/*
 * Single Number
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> &A) {
  int tmp = 0;
  for (int i = 0; i < A.size(); ++i) {
    tmp ^= A[i];
  }
  return tmp;
}

int main(int argc, char const* argv[])
{
  int a[] = {1, 2, 2, 1, 3, 4, 4};
  vector<int> v(a, a + sizeof(a) / sizeof(int));

  cout << singleNumber(v) << endl;

  return 0;
}
