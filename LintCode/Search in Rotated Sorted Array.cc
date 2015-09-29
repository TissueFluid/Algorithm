/*
 * Search in Rotated Sorted Array
 *   Binary Search
 */

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &A, int target) {
  auto size = A.size();

  if (size < 1) {
    return -1;
  }

  int pivot = 0;

  if (A[0] > A[size - 1]) {
    int left = 0;
    int right = size - 1;
    int mid = (left + right) / 2;

    while (left < mid) {
      if (A[mid] < A[left]) {
        right = mid;
      } else {
        left = mid;
      }
      mid = (left + right) / 2;
    }

    pivot = right;
  }

  int left, right, mid;

  if (A[0] > A[size - 1]) {
    if (target >= A[0]) {
      left = 0;
      right = pivot - 1;
    } else {
      left = pivot;
      right = size - 1;
    }
  } else {
    left = 0;
    right = size - 1;
  }

  mid = (left + right) / 2;
  while (left <= right) {
    if (A[mid] == target) {
      return mid;
    } else if (A[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
    mid = (left + right) / 2;
  }

  return -1;
}

int main(int argc, char const* argv[])
{
  int a[] = {4, 5, 1, 2, 3};
  vector<int> v(a, a + sizeof(a) / sizeof(int));

  cout << search(v, 1) << endl;
  cout << search(v, 0) << endl;
  return 0;
}
