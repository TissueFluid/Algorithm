// Combination Sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinationSum(vector<int> &candidates, int target,
                    size_t start, size_t end,
                    vector<vector<int> > &result) {
    static vector<int> tmp;
    static int sum = 0;

    if (sum == target) {
        result.push_back(tmp);
        return;
    } else if (sum > target) {
        return;
    }

    for (size_t i = start; i <= end; ++i) {
        tmp.push_back(candidates[i]);
        sum += candidates[i];
        combinationSum(candidates, target, i, end, result);
        sum -= candidates[i];
        tmp.pop_back();
    }

    return;
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > result;

    sort(candidates.begin(), candidates.end());
    size_t size = candidates.size();

    if (size == 0) {
        return result;
    }

    combinationSum(candidates, target, 0, size - 1, result);

    return result;
}


int main() {
    int a[] = {2, 3, 6, 7};
    vector<int> v(a, a + sizeof(a) / sizeof(int));

    auto result = combinationSum(v, 7);

    for (auto &i : result) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
