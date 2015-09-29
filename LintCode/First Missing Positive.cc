/*
 * Swap
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int firstMissingPositive(vector<int> A) {
  vector<int>::size_type size = A.size();

  int i;

  for (i = 0; i < size;) {
    if (A[i] > 0 && A[i] <= size && A[A[i] - 1] != A[i]) {
      swap(A[i], A[A[i] - 1]);
    } else {
      i++;
    }
  }

  for (i = 0; i < size; i++) {
    if (A[i] != i + 1) {
      break;
    }
  }
  return i + 1;
}

int main(int argc, char const* argv[])
{
  int a1[] = {1,2,0};
  int a2[] = {3,4,-1,1};
  int a3[] = {1};
  vector<int> v1(a1, a1 + sizeof(a1)/sizeof(int));
  vector<int> v2(a2, a2 + sizeof(a2)/sizeof(int));
  vector<int> v3(a3, a3 + sizeof(a3)/sizeof(int));

  cout << firstMissingPositive(v1) << endl;
  cout << firstMissingPositive(v2) << endl;
  cout << firstMissingPositive(v3) << endl;
  return 0;
}
