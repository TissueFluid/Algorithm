// Combinations
//     Backtracking


#include <iostream>
#include <vector>
using namespace std;

void combine(int n, int k, int start,
             vector<vector<int> > &result) {
    static vector<int> tmp;
    if (tmp.size() == (unsigned)k) {
        result.push_back(tmp);
        return;
    }

    if (start > n) {
        return;
    }

    for (unsigned i = start; i <= n - k + tmp.size() + 1; ++i) {
        tmp.push_back(i);
        combine(n, k, i + 1, result);
        tmp.pop_back();
    }
    return;
}

vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > result;

    if (k > n || k <= 0 || n <= 0) {
        return result;
    }

    combine(n, k, 1, result);

    return result;
}
