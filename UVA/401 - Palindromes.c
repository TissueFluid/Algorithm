#include <stdio.h>
#include <string.h>
#include <ctype.h>

char reverse[] = {
  'A','#','#','#','3','#','#','H','I','L','#','J','M','#','O','#','#','#','2','T','U','V','W','X','Y','5','1','S','E','#','Z','#','#','8','#'
};

int is_palindrome(char *str) {
  unsigned int len = strlen(str);
  unsigned int i;
  for (i = 0; i < len/2; i++) {
    if (str[i] != str[len - 1 - i]) {
      return 0;
    }
  }
  return 1;
}

int is_mirror(char *str) {
  unsigned int len = strlen(str);
  unsigned int i;
  for (i = 0; i <= len/2; i++) {
    if (isupper(str[i])) {
      if (reverse[str[i]-'A'] != str[len - 1 - i]) {
        return 0;
      }
    } else {
      if (reverse[str[i]-'1'+26] != str[len - 1 - i]) {
        return 0;
      }
    }
  }
  return 1;
}

int main(int argc, char const* argv[])
{
  char str[100 + 1];
  char *msg[] = {
    "is not a palindrome.",
    "is a mirrored string.",
    "is a regular palindrome.",
    "is a mirrored palindrome."
  };

  while (scanf("%100s", str) != EOF) {
    unsigned int result = 0;
    if (is_palindrome(str)) {
      result |= 2;
    }
    if (is_mirror(str)) {
      result |= 1;
    }
    printf("%s -- %s\n\n", str, msg[result]);
  }
  return 0;
}
