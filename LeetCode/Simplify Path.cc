// Simplify Path

#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string item;
        vector<string> result;

        while (getline(ss, item, '/')) {
            if (item == "" || item == ".") {
                continue;
            }

            if (item == "..") {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(item);
            }
        }

        string ret("");

        for (const auto &str : result) {
            ret += "/" + str;
        }

        if (ret == "") {
            ret = "/";
        }

        return ret;
    }
};
