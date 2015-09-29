/*
 * Largest Number
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp_func {
  bool operator() (int a, int b) {
    string s_a = to_string(a);
    string s_b = to_string(b);
    return ((s_a + s_b) > (s_b + s_a));
  }
} cmp;

string largestNumber(vector<int> &num) {

  sort(num.begin(), num.end(), cmp);

  auto size = num.size();
  string result("");

  bool allzero = true;
  for (size_t i = 0; i < size; ++i) {
    if (num[i] != 0) {
      allzero = false;
    }
    result += to_string(num[i]);
  }

  if (allzero) {
    return string("0");
  }

  return result;
}

int main(int argc, char const* argv[])
{
  int a[] = {1, 20, 23, 4, 8};
  vector<int> v(a, a + sizeof(a) / sizeof(int));

  cout << largestNumber(v) << endl;

  return 0;
}
