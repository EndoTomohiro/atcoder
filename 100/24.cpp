#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (int)(s); i < (int)(n); i++)

bool allt(vector<bool> tf) {
    rep(i, tf.size()) {
        if (!tf[i]) return false;
    }
    return true;
}

void dfs(vector< vector<int> > v, vector<bool> tf, vector<int> vec, vector< vector<int> > ans, int tim) {
    int x = vec[vec.size()-1];
    bool ok = true;
    rep(i, v[x].size()) {
        if (!tf[v[x][i]]) {
            vec.push_back(v[x][i]);
            ans[v[x][i]][0] = tim;
            ok = false;
            break;
        }
    }

    if (ok) {
        tf[x] = true;
        vec.pop_back();
        ans[x][1] = tim;
    }

    tim++;

    if (allt(tf)) {
        rep2(i, 1, tf.size()) {
            cout << i << ' ' << ans[i][0] << ' ' << ans[i][1] << endl;
        }
        return;
    }

    return dfs(v, tf, vec, ans, tim);
}

int main() {
    int n;
    cin >> n;

    vector< vector<int> > v(n+1);
    rep2(i, 1, n+1) {
        cin >> i;
        int k;
        cin >> k;

        vector<int> vi(k);
        rep(j, k) cin >> vi[j];
        v[i] = vi;
    }

    vector<bool> tf(n+1, false);
    tf[0] = true;

    vector<int> vec(1, 1);

    int tim = 2;

    vector< vector<int> > ans(n+1, vector<int>(2));
    ans[1][0] = 1;

    dfs(v, tf, vec, ans, tim);
}