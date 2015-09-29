#include <iostream>
#include <ctype.h>
using namespace std;

int myatoi(string str) {
  if (str.length() == 0) {
    return 0;
  }

  int i;
  int positive = 1;
  int start = 0;
  int write = 1;
  string res("");

  for (;start < str.length(); ++start) {
    if (str[start] != ' ') {
      break;
    }
  }

  if (str[start] == '-') {
    positive = 0;
    start += 1;
  } else if (str[start] == '+') {
    start += 1;
  }

  for (i = start; i < str.length(); ++i) {
    if (str[i] == '.') {
      write = 0;
    } else if (str[i] != ' ') {
      if (!isdigit(str[i])) {
        break;
      }
      if (write) {
        res += str[i];
      }
    }
  }

  if (res.length() < 10) {
    res = string(10 - res.length(), '0') + res;
  }

  if (positive) {
    if (res.length() > 10 || res.compare("2147483647") > 0) {
      return 2147483647;
    }
  } else {
    if (res.length() > 10 || res.compare("2147483648") > 0) {
      return -2147483648;
    }
  }

  int ret = 0;
  for (i = 0; i < res.length(); ++i) {
    ret *= 10;
    ret += (res[i] - '0');
  }
  if (!positive) {
    ret = 0 - ret;
  }
  return ret;
}

int main(int argc, char const* argv[])
{
  cout << myatoi("10") << endl;
  cout << myatoi("-1") << endl;
  cout << myatoi("    -5211314") << endl;
  cout << myatoi("1.0") << endl;
  cout << myatoi("    52lintcode   ") << endl;

  return 0;
}
