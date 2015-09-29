#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int longestCommonSubstring(string &A, string &B) {
  int ret = 0;
  int i, j;
  int lenA = A.length();
  int lenB = B.length();

  int **table = new int*[lenA + 1];

  // malloc
  for (i = 0; i < lenA + 1; ++i) {
    table[i] = new int[lenB + 1];
  }

  // init
  for (i = 0; i < lenB + 1; ++i) {
    table[0][i] = 0;
  }
  for (i = 1; i < lenA + 1; ++i) {
    table[i][0] = 0;
  }

  // main
  for (i = 1; i < lenA + 1; ++i) {
    for (j = 1; j < lenB + 1; ++j) {
      if (A[i-1] == B[j-1]) {
        table[i][j] = table[i-1][j-1] + 1;
        ret = max(ret, table[i][j]);
      } else {
        table[i][j] = 0;
      }
    }
  }

  // free
  if (table) {
    for (i = 0; i < lenA + 1; ++i) {
      if (table[i]) {
        delete[] table[i];
      }
    }
    delete[] table;
  }

  return ret;
}

int main(int argc, char const* argv[])
{
  string a("www.lintcode.com code");
  string b("www.ninechapter.com code");
  cout << longestCommonSubstring(a, b) << endl;
  return 0;
}
