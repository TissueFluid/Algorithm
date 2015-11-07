// Search in a Big Sorted Array

#include <iostream>
using namespace std;


class ArrayReader {
public:
    int get(int index) {
         // return the number on given index,
         // return -1 if index does not exist.
    }
};

class Solution {
public:
    /**
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader *reader, int target) {
        if (reader == NULL || reader->get(0) == -1) {
            return -1;
        }

        int end = 0;

        while (1) {
            int value = reader->get(end);
            if (value >= target || value == -1) {
                break;
            }
            end = (end << 1) + 1;
        }

        if (reader->get(end) == target) {
            return end;
        }

        int start = (end >> 1);

        while (start + 1 < end) {
            int mid = (start + end) / 2;
            int value = reader->get(mid);
            if (value == target) {
                while (mid - 1 > start && reader->get(mid - 1) == target) {
                    mid--;
                }
                return mid;
            } else if (value != -1 && value < target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        return -1;
    }
};
