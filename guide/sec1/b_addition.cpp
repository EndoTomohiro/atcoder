#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, x = 1;
    cin >> n >> k;
    for (int i; i < n; i++) {
        if (x < k) x *= 2;
        else x += k;
    }
    cout << x << endl;
}