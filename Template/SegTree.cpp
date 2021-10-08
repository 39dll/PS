struct SegTree {
	ll sz, st, dep;
	vector<ll> pw2, v;
	SegTree(ll size) {
    	long long k = 1;
    	for (int i = 0; i < 30; i++)pw2.push_back(k), k <<= 1;
    	sz = size; v.resize(sz * 4, 0); dep = 1;
    	while(1) {
        	if (sz <= pw2[dep - 1])break;
        	dep++;
    	}
    	st = pw2[dep - 1] - 1;
	}
	void init(ll val) {
		for (int i = 1; i < 4 * sz; i++)v[i] = val;
	}
	ll val(ll ind) {
    	return v[st + ind];
	}
	void update(ll ind, ll val) {
		v[st + ind] = val; ind = (ind + 1) / 2;
    	for (int i = dep - 1; i >= 1; i--) {
        	ll cur = pw2[i - 1] - 1 + ind;
        	v[cur] = v[cur * 2] + v[cur * 2 + 1];
        	ind = (ind + 1) / 2;
	}
   	ll query(ll start, ll end) {
    	ll ret = 0;
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
