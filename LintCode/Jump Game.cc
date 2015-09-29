/*
 * Jump Game
 *   Greedy / dp
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canJump(vector<int> A) {
  int fastest = 0;
  int size = A.size();

  for (int i = 0; i < size; ++i) {
    fastest = max(fastest, i + A[i]);
    if (fastest == i) {
      return false;
    }
  }

  return true;
}

int main(int argc, char const* argv[])
{
  int a[] = {2, 3, 1, 1, 4};
  int b[] = {3, 2, 1, 0, 4};
  vector<int> v(a, a + 5);
  vector<int> w(b, b + 5);

  cout << canJump(v) << endl;
  cout << canJump(w) << endl;

  return 0;
}
