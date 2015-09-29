/*
 * Update Bits
 */

#include <iostream>
using namespace std;

int updateBits(int n, int m, int i, int j) {
  for (int k = i; k <= j; ++k) {
    if (m & (1 << (k-i))) {
      n |= (1 << k);
    } else {
      n &= (0xffffffff ^ (1 << k));
    }
  }
  return n;
}
