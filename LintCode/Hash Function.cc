// Hash Function

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        const int len = key.length();

        if (len == 0) {
            return 0;
        }

        long long int result = 0;
        long long int base = 1 % HASH_SIZE;
        for (int i = len - 1; i >= 0; i--) {
            result += (base * key[i]) % HASH_SIZE;
            result %= HASH_SIZE;
            base = (base * 33) % HASH_SIZE;
        }

        return (int)result;
    }
};

int main() {
    Solution s;

    cout << s.hashCode("abcd", 100) << endl;
    cout << s.hashCode("Wrong answer or accepted?", 1000000007) << endl;
    return 0;
}
