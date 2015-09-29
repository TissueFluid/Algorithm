#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MARGIN 21

int main(int argc, char const* argv[])
{
  int T;
  int m, n, k;
  int i, j, r;
  char a[101][101];
  char b[21];
  char ch;

  scanf("%2d", &T);
  while (T--) {
    memset(a, '#', sizeof(a));
    getchar();
    scanf("%2d %2d", &m, &n);
    getchar();

    for (i = MARGIN; i < m + MARGIN; i++) {
      for (j = MARGIN; j < n + MARGIN; j++) {
        a[i][j] = toupper(getchar());
      }
      getchar();
      a[i][j] = '\0';
    }

    scanf("%2d", &k);
    getchar();
    while (k--) {
      for (i = 0; (ch = getchar()) != '\n'; i++) {
        b[i] = toupper(ch);
      }
      b[i] = '\0';
      unsigned len = strlen(b);

      for (i = MARGIN; i < m + MARGIN; i++) {
        for (j = MARGIN; j < n + MARGIN; j++) {
          for (r = 0; r < len && b[r] == a[i][j - r]; r++);
          if (r == len) goto found;

          for (r = 0; r < len && b[r] == a[i][j + r]; r++);
          if (r == len) goto found;

          for (r = 0; r < len && b[r] == a[i - r][j]; r++);
          if (r == len) goto found;

          for (r = 0; r < len && b[r] == a[i + r][j]; r++);
          if (r == len) goto found;

          for (r = 0; r < len && b[r] == a[i + r][j + r]; r++);
          if (r == len) goto found;

          for (r = 0; r < len && b[r] == a[i - r][j + r]; r++);
          if (r == len) goto found;

          for (r = 0; r < len && b[r] == a[i + r][j - r]; r++);
          if (r == len) goto found;

          for (r = 0; r < len && b[r] == a[i - r][j - r]; r++);
          if (r == len) goto found;
        }
      }

found:
      printf("%d %d\n", i+1-MARGIN, j+1-MARGIN);
    }
    if (T) printf("\n");
  }
  return 0;
}
