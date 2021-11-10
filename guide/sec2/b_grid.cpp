#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int h, w;
    cin >> h >> w;

    vector< vector<char> > data(h, vector<char>(w));
    rep(i, h) {
        rep(j, w) {
            cin >> data[i][j];
        }
    }

    vector<int> tate(0), yoko(0);

    rep(i, h) {
        int c = 0;
        rep(j, w) {
            if (data[i][j] == '#') c++;
        }
        if (c == 0) tate.push_back(i);
    }

    rep(j, w) {
        int c = 0;
        rep(i, h) {
            if (data[i][j] == '#') c++;
        }
        if (c == 0) yoko.push_back(j);
    }

    rep(i, h) {
        rep(j, w) {
            if (find(tate.begin(), tate.end(), i) == tate.end() && find(yoko.begin(), yoko.end(), j) == yoko.end()) {
                cout << data[i][j];
            }
        }
        if (find(tate.begin(), tate.end(), i) == tate.end()) cout << endl;
    }

}