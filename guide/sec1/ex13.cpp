#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x += a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << abs(x / n - a[i]) << endl;
    }
}