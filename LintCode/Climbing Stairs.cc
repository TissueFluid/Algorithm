// Climbing Stairs - DP

#include <vector>
#include <iostream>
using namespace std;

int climbStairs(int n) {
    int a1 = 1;
    int a2 = 2;
    int tmp;

    if (n == 1) {
        return a1;
    }

    if (n == 2) {
        return a2;
    }

    for (int i = 3; i <= n; ++i) {
        tmp = a1 + a2;
        a1 = a2;
        a2 = tmp;
    }

    return tmp;
}

int main() {
    cout << climbStairs(3) << endl;
}
