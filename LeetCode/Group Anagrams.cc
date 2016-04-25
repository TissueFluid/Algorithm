// Group Anagrams

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > result;
        unordered_map<string, vector<string> > m;

        for (const auto &str : strs) {
            string key = string(str);
            sort(key.begin(), key.end());
            m[key].push_back(str);
        }

        for (auto &item : m) {
            sort(item.second.begin(), item.second.end());
            result.push_back(item.second);
        }

        return result;
    }
};
