// Fibonacci

#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    vector<int> v = {0, 1};

    for (int i = 2; i < n; ++i) {
        int tmp = v[i-1] + v[i-2];
        v.push_back(tmp);
    }

    return v[n - 1];
}

int main() {
    cout << fibonacci(1) << endl;
    cout << fibonacci(2) << endl;
    cout << fibonacci(10) << endl;
    return 0;
}
