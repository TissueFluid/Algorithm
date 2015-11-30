// Maximum Gap

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
    struct Bucket {
        int max;
        int min;
        Bucket() {
            max = numeric_limits<int>::min();
            min = numeric_limits<int>::max();
        }

        bool isValid() {
            return max >= min;
        }
    };
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        const int size = nums.size();

        if (size < 2) {
            return 0;
        }

        int minimum = nums[0];
        int maximum = nums[0];

        for (int i = 1; i < size; ++i) {
            minimum = min(minimum, nums[i]);
            maximum = max(maximum, nums[i]);
        }

        if (maximum == minimum) {
            return 0;
        }

        // ceiling (max - min) / (N - 1)
        const int bucket_size = (maximum - minimum - 1) / (size - 1) + 1;
        const int n_buckets = (maximum - minimum) / bucket_size + 1;

        vector<Bucket> buckets(n_buckets, Bucket());

        for (const auto &num : nums) {
            int bucket_id = (num - minimum) / bucket_size;

            buckets[bucket_id].max = max(buckets[bucket_id].max, num);
            buckets[bucket_id].min = min(buckets[bucket_id].min, num);
        }

        int i;
        int prev_max;
        int result = numeric_limits<int>::min();
        for (i = 0; i < n_buckets; ++i) {
            if (buckets[i].isValid()) {
                prev_max = buckets[i].max;
                break;
            }
        }
        i++;

        for (; i < n_buckets; ++i) {
            if (buckets[i].isValid()) {
                result = max(result, buckets[i].min - prev_max);
                prev_max = buckets[i].max;
            }
        }

        return result;
    }
};
