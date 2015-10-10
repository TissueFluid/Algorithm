// Combination Sum II

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinationSum2(vector<int> &num, int target, size_t start,
                     vector<vector<int> > &result) {
    static vector<int> tmp;
    static const auto size = num.size();
    static int sum = 0;

    if (sum == target) {
        result.push_back(tmp);
    } else if (sum > target) {
        return;
    }

    for (size_t i = start; i < size; ++i) {
        if (i > start && num[i] == num[i-1]) {
            continue;
        }
        tmp.push_back(num[i]);
        sum += num[i];
        combinationSum2(num, target, i + 1, result);
        sum -= num[i];
        tmp.pop_back();
    }

    return;
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    auto size = num.size();

    vector<vector<int> > result;

    if (size == 0) {
        return result;
    }

    sort(num.begin(), num.end());
    combinationSum2(num, target, 0, result);

    return result;
}

int main() {
    vector<int> num = {10,1,6,7,2,1,5};

    auto result = combinationSum2(num, 8);

    for (auto &item : result) {
        cout << "[ ";
        for (auto &i : item) {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
