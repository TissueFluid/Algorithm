// A + B Problem

#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        return (int)(long)&(((char *)a)[b]);
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << s.aplusb(1, 2) << endl;
    return 0;
}
