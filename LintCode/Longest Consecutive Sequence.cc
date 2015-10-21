// Longest Consecutive Sequence

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int longestConsecutive(vector<int> &num) {
    unordered_set<int> s;

    for (const auto item : num) {
        s.insert(item);
    }

    int longest = 0;

    while (!s.empty()) {
        auto it = s.begin();
        int count = 1;

        for (int tmp = *it + 1; true; tmp++) {
            auto found = s.find(tmp);
            if (found != s.end()) {
                count++;
                s.erase(found);
            } else {
                break;
            }
        }

        for (int tmp = *it - 1; true; tmp--) {
            auto found = s.find(tmp);
            if (found != s.end()) {
                count++;
                s.erase(found);
            } else {
                break;
            }
        }

        s.erase(it);
        longest = max(longest, count);
    }

    return longest;
}

int main() {
    vector<int> v = {100, 4, 200, 1, 3, 2};

    cout << longestConsecutive(v) << endl;
    return 0;
}
