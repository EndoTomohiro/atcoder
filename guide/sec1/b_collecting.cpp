#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main() {
    int n, k, a = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a += min(abs(x), abs(x - k)) * 2;
    }
    cout << a << endl;
}