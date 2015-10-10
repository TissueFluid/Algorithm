// Word Ladder II

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

void dfs(unordered_map<string, vector<string> > &pre,
         vector<vector<string> > &result,
         string &start, string &end, const size_t count) {
    static vector<string> tmp = {end};

    if (start == end) {
        result.push_back(tmp);
        return;
    } else if (tmp.size() >= count) {
        return;
    }

    for (auto &item : pre[end]) {
        tmp.push_back(item);
        dfs(pre, result, start, item, count);
        tmp.pop_back();
    }

    return;
}

vector<vector<string> > findLadders(
    string start, string end, unordered_set<string> &dict) {

    vector<vector<string> > result;
    size_t count = 1;

    auto len = start.length();

    if (len <= 0 || len != end.length()) {
        return result;
    }

    swap(start, end);

    queue<string> q;
    unordered_map<string, vector<string> > pre;

    q.push(start);
    dict.erase(start);

    bool found = false;

    while (!q.empty()) {
        count++;
        unordered_set<string> s;

        auto qsize = q.size();
        for (size_t i = 0; i < qsize; ++i) {
            string front = q.front(); q.pop();
            string origin_str(front);

            for (size_t j = 0; j < len; ++j) {
                char origin_ch = front[j];

                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if (ch != origin_ch) {
                        front[j] = ch;

                        if (front == end) {
                            pre[end].push_back(origin_str);
                            found = true;
                            goto NEXT_STRING;
                        }

                        if (!found && dict.find(front) != dict.end()) {
                            pre[front].push_back(origin_str);

                            if (s.find(front) == s.end()) {
                                q.push(front);
                                s.insert(front);
                            }
                        }
                    }
                }

                front[j] = origin_ch;
            }
        NEXT_STRING:;
        }

        if (found) {
            break;
        }

        for (auto &item : s) {
            dict.erase(item);
        }
    }

    if (found) {
        dfs(pre, result, start, end, count);
    }

    return result;
}

int main() {
    unordered_set<string> dict = {"hot","cog","dog","tot","hog","hop","pot","dot"};

    auto result = findLadders("hot", "dog", dict);

    for (auto &item : result) {
        cout << "[ ";
        for (auto &i : item) {
            cout << i << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
