/*
 * Unique Binary Search Trees
 *   dp
 */

#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n) {
  vector<int> count(n + 1, 0);

  count[0] = 1;
  count[1] = 1;

  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      count[i] += count[j-1] * count[i-j];
    }
  }

  return count[n];
}

int main(int argc, char const* argv[])
{
  cout << numTrees(3) << endl;
  return 0;
}
