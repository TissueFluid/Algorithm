/*
 * Binary Search
 */

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &array, int target) {
  long long left = 0;
  long long right = array.size() - 1;
  long long mid = (left + right) / 2;

  if (right < 0) {
    return -1;
  }

  while (left <= right) {
    if (array[mid] == target) {
      while (mid >= 0 && array[mid] == array[mid-1]) {
        mid--;
      }
      return (int)mid;
    } else if (array[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
    mid = (left + right) >> 1;
  }

  return -1;
}

int main(int argc, char const* argv[])
{
  int a[] = {1, 2, 3, 3, 4, 5, 10};
  vector<int> v(a, a + sizeof(a)/sizeof(int));
  cout << binarySearch(v, 3) << endl;
  return 0;
}
