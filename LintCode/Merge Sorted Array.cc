#include <iostream>

using namespace std;

void mergeSortedArray(int A[], int m, int B[], int n) {
  int *tmp = new int[m];
  int i, j, k;

  for (i = 0; i < m; i++) {
    tmp[i] = A[i];
  }

  for (i = j = k = 0; i < m && j < n;) {
    if (tmp[i] < B[j]) {
      A[k++] = tmp[i++];
    } else {
      A[k++] = B[j++];
    }
  }

  while (i < m) {
    A[k++] = tmp[i++];
  }

  while (j < n) {
    A[k++] = B[j++];
  }

  if (tmp) {
    delete[] tmp;
  }
}

int main(int argc, char const* argv[])
{
  int a[5] = {1,2,3};
  int b[2] = {4,5};
  mergeSortedArray(a, 3, b, 2);
  for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
    cout << a[i] << endl;
  }
  return 0;
}
