/*
 * Single Number III
 *   Math
 */

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> singleNumberIII(vector<int> &A) {
  int size = A.size();
  vector<int> result;

  if (size < 2) {
    return result;
  }

  int a_xor_b = 0;
  for (int i = 0; i < size; ++i) {
    a_xor_b ^= A[i];
  }

  int lowest_one = a_xor_b & (-a_xor_b);

  int a = 0;
  for (int i = 0; i < size; ++i) {
    if (A[i] & lowest_one) {
      a ^= A[i];
    }
  }

  result.push_back(a);
  result.push_back(a ^ a_xor_b);

  sort(result.begin(), result.end());

  return result;
}

int main(int argc, char const* argv[])
{
  /* int a[] = {1, 2, 2, 3, 4, 4, 5, 3}; */
  int a[] = {-1, -2, -2, numeric_limits<int>::max()};
  vector<int> v(a, a + sizeof(a) / sizeof(int));

  auto result = singleNumberIII(v);
  cout << result[0] << " " << result[1] << endl;

  return 0;
}
