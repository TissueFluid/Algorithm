#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> &A, int target) {
  if (A.size() < 1) {
    return 0;
  }

  int left = 0;
  int right = A.size() - 1;
  int mid = (left + right) / 2;

  if (target <= A[left]) {
    return 0;
  }
  if (target > A[right]) {
    return A.size();
  }

  while (left < mid) {
    if (target == A[mid]) {
      return mid;
    } else if (target > A[mid]) {
      left = mid;
    } else {
      right = mid;
    }
    mid = (left + right) / 2;
  }

  return right;
}

int main(int argc, char const* argv[])
{
  int a[] = {1, 3, 5, 6};
  vector<int> v(a, a + 4);

  cout << searchInsert(v, 5) << endl;
  cout << searchInsert(v, 2) << endl;
  cout << searchInsert(v, 7) << endl;
  cout << searchInsert(v, 0) << endl;
  return 0;
}
