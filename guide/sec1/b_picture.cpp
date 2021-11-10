#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (int i = 0; i < h; i++) {
        cin >> a[i];
        a[i].insert(a[i].begin(), '#');
        a[i].push_back('#');
    }

    string x;
    for (int i = 0; i < w + 2; i++) x += '#';

    cout << x << endl;
    for (int i = 0; i < h; i++) cout << a[i] << endl;
    cout << x << endl;
}