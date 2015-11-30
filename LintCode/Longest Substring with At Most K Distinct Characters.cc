// Longest Substring with At Most K Distinct Characters

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        const int length = s.length();
        int slow = 0;
        int fast;
        int result = 0;
        int count = 0;
        vector<int> hash(256, 0);

        for (fast = 0; fast < length; ++fast) {
            int ch = s[fast];

            if (hash[ch] == 0) {
                count++;
            }
            hash[ch]++;

            if (count > k) {
                result = max(result, fast - slow);

                for (; slow <= fast && count > k; slow++) {
                    hash[s[slow]]--;
                    if (hash[s[slow]] == 0) {
                        count--;
                    }
                }
            }
        }

        return max(result, fast - slow);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.lengthOfLongestSubstringKDistinct("eceba", 3) << endl;
    cout << s.lengthOfLongestSubstringKDistinct("eqgkcwGFvjjmxutystqdfhuMblWbylgjxsxgnoh", 16) << endl;
    return 0;
}
