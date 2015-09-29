/*
 * Fast Power
 */

#include <iostream>

using namespace std;

int fastPower(int a, int b, int n) {
  long long int ret = 1;
  if (n == 1) {
    return a % b;
  }
  if (n == 0) {
    return 1 % b;
  }

  if (n % 2) {
    ret *= a % b;
    ret %= b;
  }
  long long int tmp = fastPower(a, b, n/2);
  ret *= tmp;
  ret %= b;
  ret *= tmp;
  ret %= b;

  return (int)ret;
}

int main(int argc, char const* argv[])
{
  cout << fastPower(2, 3, 31) << endl;
  cout << fastPower(100, 1000, 1000) << endl;
  cout << fastPower(109, 10000007, 1000001) << endl;
  return 0;
}
