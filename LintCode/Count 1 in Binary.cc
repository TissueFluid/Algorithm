// Count 1 in Binary

#include <iostream>
using namespace std;

int countOnes(int num) {
    int count = 0;

    while (num) {
        count++;
        num ^= (num & (~num + 1));
    }

    return count;
}

int main() {
    cout << countOnes(32) << endl;
    cout << countOnes(5) << endl;
    cout << countOnes(1023) << endl;
    return 0;
}
