#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * For each element nums[i], calculate sum from nums[0] to nums[i],
 * If the current sum has been seen before, then there is a zero sum
 * array.
 */

vector<int> subarraySum(vector<int> nums) {
  map<int, int> m_sum;
  int sum = 0;
  map<int, int>::iterator imap;
  vector<int> ret;

  m_sum[0] = -1;
  for (int i = 0; i != nums.size(); ++i) {
    sum += nums[i];
    imap = m_sum.find(sum);
    if (imap == m_sum.end()) {
      m_sum[sum] = i;
    } else {
      ret.push_back(imap->second + 1);
      ret.push_back(i);
      break;
    }
  }
  return ret;
}

int main(int argc, char const* argv[])
{
  int a[] = {-3,1,2,-3,4};
  vector<int> v(a, a + sizeof(a) / sizeof(int));
  vector<int> ret = subarraySum(v);
  cout << ret[0] << ',' << ret[1] << endl;
  return 0;
}
