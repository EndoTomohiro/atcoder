#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using pl = pair<ll, ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vp = vector< pair<ll, ll> >;
using vvl = vector<vl>;
using vvb = vector<vb>;
using vvp = vector<vp>;
using vs = vector<string>;
#define pi 3.14159265359;
const ll INF = 1000000000000000;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rep3(i, s, n) for (ll i = (ll)(n); i >= (ll)(s); i--)
#define all(v) v.begin(), v.end()
template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

// Union-Find
struct UnionFind {
    vl par;

	void init(int sz) {
		par.resize(sz, -1);
	}
    // 根を求める
    ll root(ll x) {
        if (par[x] == -1) return x; // x が根の場合は x を返す
        else return par[x] = root(par[x]);
    }

    // x と y が同じグループに属するかどうか（根が一致するかどうか）
    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループとを併合する
    void unite(ll x, ll y) {
        // x, y をそれぞれ根まで移動する
        x = root(x); y = root(y);

        // すでに同じグループの時は何もしない
        if (x == y) return;

        // y を x の子とする
        par[y] = x;
    }
};

// 入力
int H, W, Q;

// その他の変数
UnionFind UF;
bool used[2009][2009];

void query1(int px, int py) {
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	for (int i = 0; i < 4; i++) {
		int sx = px + dx[i], sy = py + dy[i];
		if (used[sx][sy] == false) continue;
		int hash1 = (px - 1) * W + (py - 1);
		int hash2 = (sx - 1) * W + (sy - 1);
		UF.unite(hash1, hash2);
	}
	used[px][py] = true;
}

bool query2(int px, int py, int qx, int qy) {
	if (used[px][py] == false || used[qx][qy] == false) {
		return false;
	}

	int hash1 = (px - 1) * W + (py - 1);
	int hash2 = (qx - 1) * W + (qy - 1);
	if (UF.issame(hash1, hash2) == true) return true;
	return false;
}

int main() {
	// Step #1. 入力
	cin >> H >> W >> Q;

    UF.init(H * W);

    vs ans;

	// Step #3. クエリ処理
	for (int i = 1; i <= Q; i++) {
		int ty; cin >> ty;
		if (ty == 1) {
			int x, y;
			cin >> x >> y;
			query1(x, y);
		}
		if (ty == 2) {
			int xa, xb, ya, yb;
			cin >> xa >> ya >> xb >> yb;
			bool Answer = query2(xa, ya, xb, yb);
			if (Answer == true) ans.push_back("Yes");
			else ans.push_back("No");
		}
	}
	
    rep(i, ans.size()) cout << ans[i] << endl;
}
