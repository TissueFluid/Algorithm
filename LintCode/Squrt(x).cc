/*
 * Sqrt(x)
 *
 *
 */

#include <iostream>

using namespace std;

int sqrt(int x) {
  int left = 1;
  int right = 46341;
  int mid = (left + right) / 2;

  while(left < mid) {
    int tmp = mid * mid;
    if (tmp == x) {
      return mid;
    } else if (tmp > x) {
      right = mid;
    } else {
      left = mid;
    }
    mid = (left + right) / 2;
  }

  return left;
}

int main(int argc, char const* argv[])
{
  cout << sqrt(3) << endl;
  cout << sqrt(4) << endl;
  cout << sqrt(5) << endl;
  cout << sqrt(10) << endl;
  cout << sqrt(999999999) << endl;

  return 0;
}
