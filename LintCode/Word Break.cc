// Word Break - DP

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
    const auto lenS = s.length();

    if (lenS == 0) {
        return true;
    }

    vector<bool> canBreak(lenS + 1, false);

    canBreak[0] = true;

    size_t maxlen = 0;
    for (const auto &item : dict) {
        maxlen = max(maxlen, item.length());
    }

    for (size_t i = 1; i < lenS + 1; ++i) {
        for (size_t j = 1; j <= i && j <= maxlen; ++j) {
            if (canBreak[i - j]) {
                if (dict.find(s.substr(i - j, j)) != dict.end()) {
                    canBreak[i] = true;
                    break;
                }
            }
        }
    }

    return canBreak[lenS];
}

int main() {
    unordered_set<string> dict = {"lint", "code"};
    cout << wordBreak(string("lintcode"), dict) << endl;
    return 0;
}
