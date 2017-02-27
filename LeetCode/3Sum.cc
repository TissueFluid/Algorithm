class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> copyNums = nums;
        vector<vector<int>> result;
        const int size = copyNums.size();

        sort(begin(copyNums), end(copyNums));

        for (int i = 0; i < size - 2;) {
            int start = i + 1;
            int end = size - 1;

            while (start < end) {
                int sum = copyNums[i] + copyNums[start] + copyNums[end];
                if (sum == 0) {
                    result.push_back({copyNums[i], copyNums[start], copyNums[end]});
                }
                
                if (sum <= 0) {
                    do {
                        ++start;
                    } while (start < end && copyNums[start] == copyNums[start - 1]);
                }
                
                if (sum >= 0) {
                    do {
                        --end;
                    } while (start < end && copyNums[end] == copyNums[end + 1]);
                }
            }

            do {
                ++i;
            } while (i < size - 2 && copyNums[i] == copyNums[i-1]);
        }
        
        return result;
    }
};
