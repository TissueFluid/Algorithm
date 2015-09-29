#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) {
  auto m = matrix.size();

  if (m < 1) {
    return false;
  }

  auto n = matrix[0].size();

  if (n < 1) {
    return false;
  }

  int left = 0;
  int right = m * n - 1;
  int mid = (left + right) / 2;

  while (left <= right) {
    auto tmp = matrix[mid / n][mid % n];
    if (tmp == target) {
      return true;
    } else if (tmp > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
    mid = (left + right) / 2;
  }

  return false;
}

int main(int argc, char const* argv[])
{
  int a[][4] = {
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
  };
  vector<vector<int> > v;

  for (auto i = 0; i < 3; i++) {
    vector<int> tmp(4, 0);
    for (auto j = 0; j < 4; j++) {
      tmp[j] = a[i][j];
    }
    v.push_back(tmp);
  }

  cout << searchMatrix(v, 3) << endl;

  vector<int> x(1, 5);
  vector<vector<int> > xx;
  xx.push_back(x);
  cout << searchMatrix(xx, 2) << endl;
  return 0;
}
