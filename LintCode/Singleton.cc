// Singleton

#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        static Solution *sol = new Solution();
        return sol;
    }
};
