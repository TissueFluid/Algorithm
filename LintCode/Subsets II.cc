// Subsets II

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void subsetsWithDup(vector<int> &v, size_t start, const size_t size,
                    vector<vector<int> > &result) {
    static vector<int> tmp;

    result.push_back(tmp);

    for (size_t i = start; i < size; ++i) {
        if (i > start && v[i - 1] == v[i]) {
            continue;
        }
        tmp.push_back(v[i]);
        subsetsWithDup(v, i + 1, size, result);
        tmp.pop_back();
    }
    return;
}

vector<vector<int> > subsetsWithDup(const vector<int> &S) {
    vector<vector<int> > result;

    vector<int> v(S);

    sort(v.begin(), v.end());
    subsetsWithDup(v, 0, v.size(), result);

    return result;
}

int main() {
    vector<int> v = {1, 2, 2};

    auto result = subsetsWithDup(v);

    for (auto i : result) {
        cout << "[ ";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
