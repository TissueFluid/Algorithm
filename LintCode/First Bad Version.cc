/*
 * First Bad Version
 *   Binary Search
 */

#include <iostream>
#include <vector>

using namespace std;

class VersionControl {
  public:
    static bool isBadVersion(int k);
};

int findFirstBadVersion(int n) {
  if (VersionControl::isBadVersion(1)) {
    return 1;
  }

  int left = 0;
  int right = n - 1;
  int mid = (left + right) / 2;

  while (left + 1 < right) {
    if (VersionControl::isBadVersion(mid + 1)) {
      right = mid;
    } else {
      left = mid;
    }
    mid = (left + right) / 2;
  }

  return right + 1;
}
