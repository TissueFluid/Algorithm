// Simplify Path

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        istringstream ss(path);

        vector<string> tokens;

        string token;
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!tokens.empty()) {
                    tokens.pop_back();
                }
            } else {
                tokens.push_back(token);
            }
        }

        if (tokens.empty()) {
            return string("/");
        }

        string result;

        for (const auto &item : tokens) {
            result += ("/" + item);
        }

        return result;
    }
};

int main() {
    Solution s;
    string path("/...");

    cout << s.simplifyPath(path) << endl;
    return 0;
}
