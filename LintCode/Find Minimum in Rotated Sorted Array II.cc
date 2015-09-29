/*
 * Find Minimum in Rotated Sorted Array II
 *   Binary Search, Divide and Conquer
 */

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int> &num) {
  auto size = num.size();

  int left = 0;
  int right = size - 1;

  while (left < right) {
    int mid = (left + right) / 2;

    if (num[right] < num[mid]) {
      left = mid + 1;
    } else if (num[mid] < num[right]) {
      right = mid;
    } else {
      right--;
    }
  }

  return num[left];
}

int main(int argc, char const* argv[])
{
  int a[] = {4, 4, 5, 6, 7, 0, 1, 2};
  vector<int> v(a, a + sizeof(a) / sizeof(int));
  cout << findMin(v) << endl;
  return 0;
}
