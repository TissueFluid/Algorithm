#include <iostream>

using namespace std;

int strStr(const char *source, const char *target) {
  if (source == NULL || target == NULL) {
    return -1;
  }

  int len_source = strlen(source);
  int len_target = strlen(target);

  if (len_target > len_source) {
    return -1;
  }

  if (len_target == 0) {
    return 0;
  }

  int *next = new int[len_target];
  int i, j;

  next[0] = 0;
  for (i = 1; i < len_target; ++i) {
    if (target[i] == target[next[i-1]]) {
      next[i] = next[i-1] + 1;
    } else {
      next[i] = 0;
    }
  }

  int ret = -1;
  int step = 1;

  for (i = 0; i < len_source - len_target; i += step) {
    for (j = 0; j < len_target; ++j) {
      if (target[j] != source[i+j]) {
        break;
      }
    }
    if (j == len_target) {
      ret = i;
      break;
    } else {
      step = j - next[j];
      if (step == 0) {
        step = 1;
      }
    }
  }

  if (next) {
    delete []next;
  }

  return ret;
}

int main(int argc, char const* argv[])
{
  cout << strStr("abcdabcdefg", "bcd") << endl;
  return 0;
}
