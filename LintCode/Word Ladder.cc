// Word Ladder
//    BFS

#include <iostream>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;

int ladderLength(string start, string end, unordered_set<string> &dict) {
    if (start == end) {
        return 1;
    }

    auto len = start.length();

    if (len == 0 || len != end.length()) {
        return 0;
    }

    int result = 1;
    queue<string> q;

    q.push(start);
    dict.erase(start);

    while (!q.empty()) {
        result++;

        auto size = q.size();

        for (unsigned i = 0; i < size; ++i) {
            auto front = q.front();
            q.pop();

            for (unsigned j = 0; j < len; j++) {
                char origin_ch = front[j];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch != origin_ch) {
                        front[j] = ch;
                        if (front == end) {
                            return result;
                        }
                        if (dict.find(front) != dict.end()) {
                            q.push(front);
                            dict.erase(front);
                        }
                    }
                }
                front[j] = origin_ch;
            }
        }
    }

    return 0;
}

int main() {
    unordered_set<string> dict = {"hot", "dot", "dog", "lot", "log"};
    cout << ladderLength("hit", "cog", dict) << endl;
}
