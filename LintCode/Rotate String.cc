// Rotate String

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        if (str == "") {
            return;
        }

        const int len = str.length();

        offset %= len;

        if (offset != 0) {
            str = str.substr(len - offset, offset)
                + str.substr(0, len - offset);
        }
    }
};
