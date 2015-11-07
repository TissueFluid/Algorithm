// Reverse Words in a String

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string result("");

        while (ss >> word) {
            result = word + " " + result;
        }

        result = result.substr(0, result.length() - 1);

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.reverseWords("the sky is blue") << endl;
    return 0;
}
