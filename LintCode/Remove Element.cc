#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &A, int elem) {
  int i;

  for (i = 0; i < A.size();) {
    if (A[i] == elem) {
      A.erase(A.begin() + i);
    } else {
      ++i;
    }
  }
  return A.size();
}

int main(int argc, char const* argv[])
{
  int a[] = {0,4,4,0,0,2,4,4};
  vector<int> v(a, a + 8);
  cout << removeElement(v, 4) << endl;
  return 0;
}
