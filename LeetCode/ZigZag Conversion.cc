#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        const int len = s.length();

        vector<string> rows(numRows, "");
        int row_id = 0;
        int row_vary = numRows > 1 ? 1 : 0;

        for (int i = 0; i < len; ++i) {
            rows[row_id] += s[i];

            if (row_vary == 1 && row_id == numRows - 1) {
                row_vary = -1;
            } else if (row_vary == -1 && row_id == 0) {
                row_vary = 1;
            }
            row_id += row_vary;
        }

        return accumulate(rows.begin(), rows.end(), string(""));
    }
};
