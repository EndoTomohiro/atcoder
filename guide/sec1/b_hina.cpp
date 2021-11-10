#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x = 3;
    cin >> n;
    string a = "A", b = "A", c = "A", d = "A";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (a == "A") {
            a = s;
        }
        else if (a != s) {
            if (b == "A") {
                b = s;
            }
            else if (b != s) {
                if (c == "A") {
                    c = s;
                }
                else if (c != s) {
                    x = 4;
                }
            }
        }
    }
    if (x == 4) cout << "Four" << endl;
    else cout << "Three" << endl;
}