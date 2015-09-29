/*
 * Search in Rotated Sorted Array II
 *   Binary Search
 */

#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int> &A, int target) {
  auto size = A.size();
  int left = 0;
  int right = size - 1;

  if (right < 0) {
    return false;
  }

  int pivot;

  while (left < right) {
    int mid = (left + right) / 2;
    if (A[mid] > A[right]) {
      left = mid + 1;
    } else if (A[mid] < A[right]) {
      right = mid;
    } else {
      right--;
    }
  }

  pivot = left;

  if (target == A[pivot]) {
    return true;
  } else if (target < A[pivot]) {
    left = 0;
    right = pivot - 1;
  } else {
    right = size - 1;
    left = pivot + 1;
  }

  while (left <= right) {
    int mid = (left + right) / 2;
    if (A[mid] == target) {
      return true;
    } else if (A[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return false;
}

int main(int argc, char const* argv[])
{
  int a[] = {4, 5, 1, 2, 3};
  vector<int> v(a, a + sizeof(a) / sizeof(int));

  cout << search(v, 1) << endl;
  cout << search(v, 0) << endl;
  return 0;
}
