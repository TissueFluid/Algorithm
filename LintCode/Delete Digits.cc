/*
 * Delete Digits
 *   Greedy
 */

#include <iostream>
#include <string>

using namespace std;

string DeleteDigits(string A, int k) {
  size_t len = A.length();
  string result("");

  size_t i;
  for (i = 0; (i < len - k) && (k > 0); ++i) {
    bool deleteOrNot = false;

    for (size_t j = 1; j <= k; ++j) {
      if (A[i] > A[i + j]) {
        deleteOrNot = true;
        break;
      }
    }

    if (deleteOrNot) {
      k--;
    } else {
      result += A[i];
    }
  }

  if (k == 0) {
    result += A.substr(i);
  }

  auto len_result = result.length();
  for (i = 0; i < len_result; ++i) {
    if (result[i] != '0') {
      break;
    }
  }

  if (i == len_result) {
    return string("0");
  } else {
    return result.substr(i);
  }
}

int main(int argc, char const* argv[])
{
  cout << DeleteDigits("178542", 4) << endl;
  cout << DeleteDigits("90249", 2) << endl;
  return 0;
}

