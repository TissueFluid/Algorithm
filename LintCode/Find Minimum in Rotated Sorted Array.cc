/*
 * Find Minimum in Rotated Sorted Array
 *   Binary Search
 */

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int> &num) {
  int left = 0;
  int right = num.size() - 1;
  int mid = (left + right) / 2;

  if (num[left] < num[right]) {
    return num[left];
  }

  while (left + 1 < right) {
    if (num[mid] >= num[left]) {
      left = mid;
    } else {
      right = mid;
    }
    mid = (left + right) / 2;
  }

  return num[right];
}

int main(int argc, char const* argv[])
{
  int a[] = {4, 5, 6, 7, 0, 1, 2};
  vector<int> v(a, a + sizeof(a)/sizeof(int));

  cout << findMin(v) << endl;

  return 0;
}
