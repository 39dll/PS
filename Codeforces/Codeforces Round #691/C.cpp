#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;
long long gcd(long long a, long long b) { for (; b; a %= b, swap(a, b)); return a; }
ll f(ll a, ll b) {
	if (a == 0) return b;
	if (b == 0) return a;
	return gcd(a, b);
}

struct LazySeg {
	ll tree[804040];
	ll lazy[804040];
	void pro(int node, int s, int e) {
		if (!lazy[node]) return;
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	void update(int node, int s, int e, int l, int r, ll v) {
		pro(node, s, e);
		if (r < s || e < l) return;
		if (l <= s && e <= r) {
			tree[node] += (e - s + 1) * v;
			if (s ^ e) {
				lazy[node * 2] += v;
				lazy[node * 2 + 1] += v;
			}
			return;
		}
		int m = (s + e) >> 1;
		update(node * 2, s, m, l, r, v);
		update(node * 2 + 1, m + 1, e, l, r, v);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	ll query(int node, int s, int e, int x) {
		pro(node, s, e);
		if (x < s || e < x) return 0;
		if (s == e) return tree[node];
		int m = (s + e) >> 1;
		return query(node * 2, s, m, x) + query(node * 2 + 1, m + 1, e, x);
	}
	void update(ll a, ll b, ll c) {
		update(1, 1, 200000, a, b, c);
	}
	ll query(int x) {
		return query(1, 1, 200000, x);
	}
}bit;

struct Seg {
	int tree[804040];
	int bias;
	Seg() {
		for (bias = 1; bias<201010; bias <<= 1);
	}
	void update(int x, int v) {
		tree[x += bias] = v;
		while (x >>= 1) {
			tree[x] = f(tree[x << 1], tree[x << 1 | 1]);
		}
	}
	ll query(int l, int r) {
		l += bias, r += bias;
		int ret = 0;
		while (l < r) {
			if (l & 1) ret = f(ret, tree[l++]);
			if (~r & 1) ret = f(ret, tree[r--]);
			l >>= 1, r >>= 1;
		}
		if (l == r) ret = f(ret, tree[r]);
		return ret;
	}
}seg;

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int m; cin >> m;
	for (int i = 1; i <= n; i++) {
		ll t; cin >> t;
		bit.update(i, i, t);
	}
	for (int i = 1; i < n; i++) {
		ll now = bit.query(i) - bit.query(i + 1);
		seg.update(i, abs(now));
	}
	vector<long long>v(m);
	for (auto &i : v)cin >> i;
	for (int i = 0; i < m; i++) {
		bit.update(1, n, v[i]);
		ll now = bit.query(0) - bit.query(1);
		seg.update(0, llabs(now));
		now = bit.query(n) - bit.query(n + 1);
		seg.update(n, llabs(now));

		now = seg.query(1, n - 1);
		now = f(now, bit.query(1));
		cout << now << ' ';

		bit.update(1, n, -v[i]);
		now = bit.query(0) - bit.query(1);
		seg.update(0, llabs(now));
		now = bit.query(n) - bit.query(n + 1);
		seg.update(n, llabs(now));
	}
}
