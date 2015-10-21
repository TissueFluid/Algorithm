// Space Replacement

#include <iostream>
using namespace std;

int replaceBlank(char string[], int length) {
    for (int i = 0; i < length; ) {
        if (string[i] == ' ') {
            length += 2;
            for (int j = length - 1; j > i + 2; j--) {
                string[j] = string[j - 2];
            }
            string[i] = '%';
            string[i + 1] = '2';
            string[i + 2] = '0';
            i += 3;
        } else {
            i++;
        }
    }

    return length;
}
