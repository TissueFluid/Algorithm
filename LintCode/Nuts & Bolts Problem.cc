// Nuts & Bolts Problem

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Comparator {
    public:
     int cmp(string a, string b);
};

class Solution {
private:
    int partition(int start, int end,
                  vector<string> &strs,
                  string &pivot,
                  Comparator &compare) {
        int pos;

        while (start <= end) {
            if (compare.cmp(strs[start], pivot) == 0
                || compare.cmp(pivot, strs[start]) == 0) {
                pos = start;
                start++;
            } else if (compare.cmp(strs[start], pivot) == -1
                       || compare.cmp(pivot, strs[start]) == 1) {
                start++;
            } else {
                swap(strs[start], strs[end]);
                end--;
            }
        }
        swap(strs[pos], strs[end]);

        return end;
    }

    void quickSort(int start, int end,
              vector<string> &nuts,
              vector<string> &bolts,
              Comparator &compare) {
        if (start >= end) {
            return;
        }

        int pivot_index = partition(start, end, nuts, bolts[start], compare);
        partition(start, end, bolts, nuts[pivot_index], compare);

        quickSort(start, pivot_index - 1, nuts, bolts, compare);
        quickSort(pivot_index + 1, end, nuts, bolts, compare);
    }
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        const int size = nuts.size();
        if (bolts.size() != size) {
            return;
        }

        quickSort(0, size - 1, nuts, bolts, compare);
    }
};
