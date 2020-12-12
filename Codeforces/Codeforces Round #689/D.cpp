#include <bits/stdc++.h>
using namespace std;

const long long INF = 2100000000000000;

struct SegTree {
	int sz, st, dep;
	vector<long long> pw2, v;
	SegTree(int size) {
		long long k = 1;
		for (int i = 0; i < 30; i++) pw2.push_back(k), k <<= 1;
		sz = size; v.resize(sz * 4, 0); dep = 1;
		while (1) {
			if (sz <= pw2[dep - 1])break;
			dep++;
		}
		st = pw2[dep - 1] - 1;
	}
	void init(long long val) {
		for (int i = 1; i < 4 * sz; i++) v[i] = val;
	}
	long long val(int ind) {
		ind++;
		return v[st + ind];
	}
	void update(int ind, long long val) {
		ind++;
		v[st + ind] = val; ind = (ind + 1) / 2;
		for (int i = dep - 1; i >= 1; i--) {
			int cur = pw2[i - 1] - 1 + ind;
			v[cur] = v[cur * 2] + v[cur * 2 + 1];
			ind = (ind + 1) / 2;
		}
	}
	long long query(int start, int end) {
		start++; end++;
		long long ret = 0;
		start += st; end += st;
		while (start <= end) {
			if (start % 2 == 1)ret += v[start];
			if (end % 2 == 0)ret += v[end];
			start = (start + 1) / 2;
			end = (end - 1) / 2;
		}
		return ret;
	}
};

struct SegTree2 {
	int sz, st, dep;
	vector<long long> pw2, v;
	SegTree2(int size) {
		long long k = 1;
		for (int i = 0; i < 30; i++) pw2.push_back(k), k <<= 1;
		sz = size; v.resize(sz * 4, -INF); dep = 1;
		while (1) {
			if (sz <= pw2[dep - 1])break;
			dep++;
		}
		st = pw2[dep - 1] - 1;
	}
	void init(long long val) {
		for (int i = 1; i < 4 * sz; i++) v[i] = val;
	}
	long long val(int ind) {
		ind++;
		return v[st + ind];
	}
	void update(int ind, long long val) {
		ind++;
		v[st + ind] = val; ind = (ind + 1) / 2;
		for (int i = dep - 1; i >= 1; i--) {
			int cur = pw2[i - 1] - 1 + ind;
			v[cur] = max(v[cur * 2], v[cur * 2 + 1]);
			ind = (ind + 1) / 2;
		}
	}
	long long query(int start, int end) {
		start++; end++;
		long long ret = 0;
		start += st; end += st;
		while (start <= end) {
			if (start % 2 == 1)ret = max(ret, v[start]);
			if (end % 2 == 0)ret = max(ret, v[end]);
			start = (start + 1) / 2;
			end = (end - 1) / 2;
		}
		return ret;
	}
};

struct SegTree3 {
	int sz, st, dep;
	vector<long long> pw2, v;
	SegTree3(int size) {
		long long k = 1;
		for (int i = 0; i < 30; i++) pw2.push_back(k), k <<= 1;
		sz = size; v.resize(sz * 4, INF); dep = 1;
		while (1) {
			if (sz <= pw2[dep - 1])break;
			dep++;
		}
		st = pw2[dep - 1] - 1;
	}
	void init(long long val) {
		for (int i = 1; i < 4 * sz; i++) v[i] = val;
	}
	long long val(int ind) {
		ind++;
		return v[st + ind];
	}
	void update(int ind, long long val) {
		ind++;
		v[st + ind] = val; ind = (ind + 1) / 2;
		for (int i = dep - 1; i >= 1; i--) {
			int cur = pw2[i - 1] - 1 + ind;
			v[cur] = min(v[cur * 2], v[cur * 2 + 1]);
			ind = (ind + 1) / 2;
		}
	}
	long long query(int start, int end) {
		start++; end++;
		long long ret = INF;
		start += st; end += st;
		while (start <= end) {
			if (start % 2 == 1)ret = min(ret, v[start]);
			if (end % 2 == 0)ret = min(ret, v[end]);
			start = (start + 1) / 2;
			end = (end - 1) / 2;
		}
		return ret;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {

		int N, Q; cin >> N >> Q;
		SegTree *sg = new SegTree(N + 1);
		SegTree2 *mxsg = new SegTree2(N + 1);
		SegTree3 *mnsg = new SegTree3(N + 1);
		vector<long long> v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < N; i++) {
			sg->update(i, v[i]);
			mxsg->update(i, v[i]);
			mnsg->update(i, v[i]);
		}
		set<long long> s;
		queue<pair<int, int>> q;
		q.push({ 0,N - 1 });
		while (!q.empty()) {
			int lf, rg;
			tie(lf, rg) = q.front(); q.pop();
			if (lf > rg)continue;
			s.insert(sg->query(lf, rg));
			if (lf == rg)continue;
			long long mn, mx;
			mn = mnsg->query(lf, rg);
			mx = mxsg->query(lf, rg);
			long long mid = (mn + mx) / 2;

			auto it = upper_bound(v.begin() + lf, v.begin() + rg + 1, mid) - v.begin();
			//cout << it << '\n';
			if (it > rg)continue;
			q.push({ lf,it-1 }); q.push({ it,rg });
		}

		while (Q--) {
			long long in; cin >> in;
			if (s.find(in) != s.end()) {
				cout << "Yes\n";
			}
			else {
				cout << "No\n";
			}
		}
	}
}
