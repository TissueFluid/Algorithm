/*
 * Trailing Zeros
 *   The number of factor 5
 */

#include <iostream>

using namespace std;

long long trailingZeros(long long n) {
  long long count = 0;
  for (long long i = 5; i <= n; i *= 5) {
    count += n / i;
  }

  return count;
}

int main(int argc, char const* argv[])
{
  cout << trailingZeros(11) << endl;
  cout << trailingZeros(105) << endl;
  return 0;
}
