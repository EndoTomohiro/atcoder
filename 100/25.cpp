#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i <= (int)(n); i++)

int find(pair<int, int> p, vector< pair<int, int> > vec) {
    rep(i, vec.size()) {
        if (p == vec[i]) return i;
    }
    return 0;
}

void island(int ans, int num, int count, vector< pair<int, int> > list, vector<bool> tf, vector< vector< vector< pair<int, int> > > > co, vector< pair<int, int> > vec) {
    if (num == list.size() || count == list.size()) {
        cout << ans << endl;
        return;
    }

    if (vec.size() == 0) {
        if (!tf[num]) num++;
        else {
            vec.push_back(list[num]);
            tf[num] = false;
            count++;
            ans++;
        }
    }

    else {
        int i = vec[vec.size()-1].first;
        int j = vec[vec.size()-1].second;

        bool ok = false;
        for (pair<int, int> pa : co[i][j]) {
            int n = find(pa, list);
            if (tf[n]) {
                ok = true;
                vec.push_back(pa);
                tf[n] = false;
                count++;
                break;
            }
        }

        if (!ok) vec.pop_back();
    }

    return island(ans, num, count, list, tf, co, vec);
}

int main() {
    int w, h;
    cin >> w >> h;

    vector< vector< vector<int> > > c;

    while (w != 0 || h != 0) {
        vector< vector<int> > vv(h, vector<int>(w));
        rep(i, h) rep(j, w) cin >> vv[i][j];
        c.push_back(vv);
        cin >> w >> h;
    }

    rep(i, c.size()) {
        int hi = c[i].size();
        int wi = c[i][0].size();

        vector< pair<int, int> > list;
        rep(j, hi) rep(k, wi) {
            if (c[i][j][k]) list.push_back({j, k});
        }

        vector<bool> tf(list.size(), true);

        vector< vector< vector< pair<int, int> > > > co(hi, vector< vector< pair<int, int> > >(wi));
        rep(j, hi) rep(k, wi) {
            if (c[i][j][k] == 0) continue;
            rep2(x, -1, 1) rep2(y, -1, 1) {
                if (x == 0 && y == 0) continue;
                int jx = j + x;
                int ky = k + y;
                if (jx < 0 || jx >= hi || ky < 0 || ky >= wi) continue;
                if (c[i][jx][ky]) co[j][k].push_back({jx, ky});
            }
        }

        int ans = 0, num = 0, count = 0;
        vector< pair<int, int> > vec;

        island(ans, num, count, list, tf, co, vec);
    }
}