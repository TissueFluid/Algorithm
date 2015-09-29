/*
 * Binary Representation
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

string binaryRepresentation(string n) {
  string err("ERROR");
  string result("");

  auto len = n.length();
  int i;
  for (i = 0; i < len; ++i) {
    if (n[i] == '.') {
      break;
    } else if (!isdigit(n[i])) {
      return err;
    }
  }
  int dot = i;
  i++;
  for ( ; i < len; ++i ) {
    if (!isdigit(n[i])) {
      return err;
    }
  }

  string fraction_s(n.substr(dot + 1, len - 1 - dot));

  unsigned long long int fraction = stoull(fraction_s);
  unsigned long long tmp = 1;
  for (i = 0; i < fraction_s.length(); i++) {
    tmp *= 10;
  }

  int most = 32;
  while (fraction && most > 0) {
    fraction <<= 1;
    if (fraction / tmp) {
      result += "1";
      fraction %= tmp;
    } else {
      result += "0";
    }
    most--;
  }
  if (fraction) {
    return err;
  }

  result = "." + result;

  unsigned long long int intpart = stoull(n.substr(0, dot));

  while (intpart) {
    if (intpart % 2) {
      result = "1" + result;
    } else {
      result = "0" + result;
    }
    intpart /= 2;
  }

  for (i = result.length()-1; result[i] != '.'; i--) {
    if (result[i] != '0') {
      break;
    }
  }

  if (result[i] == '.') {
    i--;
  }

  result = result.substr(0, i+1);
  if (result[0] == '.') {
    result = "0" + result;
  }

  if (result == "") {
    return string("0");
  }

  return result;
}

int main(int argc, char const* argv[])
{
  cout << binaryRepresentation("3.72") << endl;
  cout << binaryRepresentation("3.5") << endl;
  cout << binaryRepresentation("0.0625") << endl;
  cout << binaryRepresentation("4096.6435546875") << endl;
  cout << binaryRepresentation("17817287.6418609619140625") << endl;
  return 0;
}
