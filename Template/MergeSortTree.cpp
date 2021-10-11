struct MergeSortTree {
	ll sz, st, dep;
	vector<vector<ll>> v;
	vector<ll> pw2;
	MergeSortTree(ll size) {
		ll k = 1;
		for (int i = 0; i < 30; i++)pw2.push_back(k), k <<= 1;
		sz = size; v.resize(sz * 4); dep = 1;
		while (1) {
			if (sz <= pw2[dep - 1])break;
			dep++;
		}
		st = pw2[dep - 1] - 1;
	}
	void make(vector<ll> in) {
		for (int i = 0; i < sz; i++) {
			v[st + i].push_back(in[i]);
		}
		int ind = st, cnt = sz;
		while (ind > 0) {
			ind = (ind + 1) / 2; cnt = (cnt + 1) / 2;
			for (int i = 0; i < cnt; i++) {
				v[ind + i].resize(v[(ind + i) * 2].size() + v[(ind + i) * 2 + 1].size());
				merge(v[(ind + i) * 2].begin(), v[(ind + i) * 2].end(),
				v[(ind + i) * 2 + 1].begin(), v[(ind + i) * 2 + 1].end(),
				v[ind + i].begin()
				);
			}
			if (ind == 1)break;
		}
	}
	ll query(ll start, ll end, ll val) {
		ll ret = 0;
		start += st; end += st;
		while (start <= end) {
			if (start % 2 == 1) {
				auto k = upper_bound(v[start].begin(), v[start].end(), val) - v[start].begin();
				ret += v[start].size() - k;
			}
			if (end % 2 == 0) {
				auto k = upper_bound(v[end].begin(), v[end].end(), val) - v[end].begin();
				ret += v[end].size() - k;
			}
			start = (start + 1) / 2;
			end = (end - 1) / 2;
		}
		return ret;
	}
};
