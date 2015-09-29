/*
 * Find Peak Element
 *   Binary Search
 */
#include <iostream>
#include <vector>

using namespace std;

int findPeak(vector<int> A) {
  int left = 0;
  int right = A.size() - 1;
  int mid = (left + right) / 2;

  if (right == 0) {
    return 0;
  }

  while (left < right) {
    int tmp = 0;

    if (A[mid+1] < A[mid]) {
      tmp |= 1;
    }
    if (A[mid-1] < A[mid]) {
      tmp |= (1<<1);
    }

    switch (tmp) {
      case 0:
        left = mid;
        break;
      case 1:
        right = mid - 1;
        break;
      case 2:
        left = mid + 1;
        break;
      case 3:
        return mid;
    }

    mid = (left + right) / 2;
  }

  return mid;
}

int main(int argc, char const* argv[])
{
  /* int a[] = {1, 2, 1, 3, 4, 5, 7, 6}; */
  int a[] = {100, 102, 104, 7, 9, 11, 4, 3};
  vector<int> v(a, a + sizeof(a) / sizeof(int));

  cout << findPeak(v) << endl;

  return 0;
}
