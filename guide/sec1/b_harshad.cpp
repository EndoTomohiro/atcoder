#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x = 0;
    cin >> n;
    int m = n;
    while (n > 0) {
        x += n % 10;
        n = n / 10;
    }
    if (m % x == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}