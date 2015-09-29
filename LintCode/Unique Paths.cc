/*
 * Unique Paths
 *     a[i][j] = a[i-1][j] + a[i][j-1];
 */

#include <iostream>

using namespace std;

/* unsigned long long gcd(unsigned long long a, unsigned long long b) { */
/*   unsigned long long r = a % b; */

/*   if (a < b) { */
/*     swap(a, b); */
/*   } */

/*   while (r) { */
/*     a = b; */
/*     b = r; */
/*     r = a % b; */
/*   } */

/*   return b; */
/* } */

/* unsigned long long C(int a, int b) { */
/*   unsigned long long numerator = 1; */
/*   unsigned long long demoninator = 1; */

/*   int i, j; */

/*   for (i = 0, j = 2; i < b; i++) { */
/*     numerator *= (a-i); */
/*     unsigned long long common; */
/*     common = gcd(numerator, demoninator); */
/*     numerator /= common; */
/*     demoninator /= common; */
/*     while (j <= b && (common = gcd(numerator, j)) != 1) { */
/*       numerator /= common; */
/*       demoninator *= (j / common); */
/*       j++; */
/*     } */
/*   } */

/*   while (j <= b) { */
/*     numerator /= j; */
/*     j++; */
/*   } */

/*   return (int)numerator; */
/* } */

/* int uniquePaths(int m, int n) { */
/*   m--; */
/*   n--; */
/*   return (int)C(m+n, min(m, n)); */
/* } */

int uniquePaths(int m, int n) {
  int a[101][101] = {0};

  for (int i = 0; i < m; i++) {
    a[i][0] = 1;
  }
  for (int i = 0; i < n; i++) {
    a[0][i] = 1;
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      a[i][j] = a[i-1][j] + a[i][j-1];
    }
  }

  return a[m-1][n-1];
}

int main(int argc, char const* argv[])
{
  cout << uniquePaths(1, 3) << endl;
  cout << uniquePaths(2, 2) << endl;
  cout << uniquePaths(8, 68) << endl;
  cout << uniquePaths(68, 8) << endl;
  cout << uniquePaths(66, 8) << endl;
  cout << uniquePaths(17, 18) << endl;
  return 0;
}
