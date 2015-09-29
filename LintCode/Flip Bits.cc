/*
 * Flip bits
 */

#include <iostream>

using namespace std;

int bitSwapRequired(int a, int b) {
  int count = 0;
  int tmp = a ^ b;

  for (auto i = 0; i < 32; i++) {
    if (tmp & (1 << i)) {
      count++;
    }
  }

  return count;
}

int main(int argc, char const* argv[])
{
  cout << bitSwapRequired(31, 14);
  return 0;
}
