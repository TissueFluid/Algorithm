/*
 * Search for a Range
 *   Binary Search
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int> &A, int target) {
  vector<int> result;
  vector<int> err;
  err.push_back(-1);
  err.push_back(-1);

  int left = 0;
  int right = A.size() - 1;
  int mid = (left + right) / 2;
  int tmp;

  if (right < 0) {
    return err;
  }

  while (left <= right) {
    if (A[mid] == target) {
      tmp = mid;
      while (tmp-1 >= 0 && A[tmp-1] == A[tmp]) {
        tmp--;
      }
      result.push_back(tmp);
      tmp = mid;
      while (tmp+1 < A.size() && A[tmp+1] == A[tmp]) {
        tmp++;
      }
      result.push_back(tmp);

      return result;

    } else if (A[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }

    mid = (left + right) / 2;
  }

  return err;
}

int main(int argc, char const* argv[])
{
  int a[] = {5, 7, 7, 8, 8, 10};
  vector<int> v(a, a + sizeof(a)/sizeof(int));

  vector<int> result = searchRange(v, 8);
  cout << result[0] << " " << result[1] << endl;
  return 0;
}
