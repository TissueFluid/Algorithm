// Cosine Similarity

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        const int size = A.size();

        if (size != B.size() || size == 0) {
            return 2.0;
        }

        double denominator = 0;
        double numerator;

        double SumAiSquared = 1;
        double SumBiSquared = 1;
        for (int i = 0; i < size; ++i) {
            SumAiSquared += (A[i] * A[i]);
            SumBiSquared += (B[i] * B[i]);
            denominator += A[i] * B[i];
        }

        if (SumAiSquared == 0 || SumBiSquared == 0) {
            return 2.0;
        }

        numerator = sqrt(SumAiSquared) * sqrt(SumBiSquared);

        return denominator / numerator;
    }
};
