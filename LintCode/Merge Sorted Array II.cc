#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
  vector<int> ret;
  int i, j;

  for (i = j = 0; i < A.size() && j < B.size(); ) {
    if (A[i] < B[j]) {
      ret.push_back(A[i++]);
    } else {
      ret.push_back(B[j++]);
    }
  }

  while (i < A.size()) {
    ret.push_back(A[i++]);
  }

  while (j < B.size()) {
    ret.push_back(B[j++]);
  }

  return ret;
}

int main(int argc, char const* argv[])
{

  return 0;
}
