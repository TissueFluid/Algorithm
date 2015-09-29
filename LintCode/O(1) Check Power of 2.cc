/*
 * O(1) Check Power of 2
 */

#include <iostream>

using namespace std;

bool checkPowerOf2(int n) {
  if (n < 0) {
    return false;
  }
  for (int i = 0; i < 32; i++) {
    if (n == 1 << i) {
      return true;
    }
  }
  return false;
}

int main(int argc, char const* argv[])
{
  cout << checkPowerOf2(4) << endl;
  cout << checkPowerOf2(5) << endl;
  return 0;
}
