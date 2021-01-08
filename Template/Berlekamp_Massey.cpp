ll ipow(ll x, ll p) {
	ll ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % MOD;
		piv = piv * piv % MOD;
		p >>= 1;
	}
	return ret;
}

vector<ll> berlekamp_massey(vector<ll> x) {
	vector<ll> ls, cur;
	ll lf, ld;
	for(int i = 0; i < x.size(); i++) {
		ll t = 0;
		for(int j = 0; j < cur.size(); j++) {
			t = (t + 1ll * x[i - j - 1] * cur[j]) % MOD;
		}
		if((t - x[i]) % MOD == 0) continue;
		if(cur.empty()) {
			cur.resize(i + 1);
			lf = i;
			ld = (t - x[i]) % MOD;
			continue;
		}
		ll k = -(x[i] - t) * ipow(ld, MOD - 2) % MOD;
		vector<ll> c(i - lf - 1);
		c.push_back(k);
		for(auto &j : ls) c.push_back(-j * k % MOD);
		if(c.size() < cur.size()) c.resize(cur.size());
		for(int j = 0; j < cur.size(); j++) {
			c[j] = (c[j] + cur[j]) % MOD;
		}
		if(i - lf + (ll)ls.size() >= (ll)cur.size()) {
			tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % MOD);
		}
		cur = c;
	}
	for(auto &i : cur) i = (i % MOD + MOD) % MOD;
	return cur;
}
ll get_nth(vector<ll> rec, vector<ll> dp, ll n) {
	ll m = rec.size();
	vector<ll> s(m), t(m);
	s[0] = 1;
	if(m != 1) t[1] = 1;
	else t[0] = rec[0];
	auto mul = [&rec](vector<ll> v, vector<ll> w) {
		int m = v.size();
		vector<ll> t(2 * m);
		for(int j = 0; j < m; j++) {
			for(int k = 0; k < m; k++) {
				t[j + k] += 1ll * v[j] * w[k] % MOD;
				if(t[j + k] >= MOD) t[j + k] -= MOD;
			}
		}
		for(int j = 2 * m - 1; j >= m; j--) {
			for(int k = 1; k <= m; k++) {
				t[j - k] += 1ll * t[j] * rec[k - 1] % MOD;
				if(t[j - k] >= MOD) t[j - k] -= MOD;
			}
		}
		t.resize(m);
		return t;
	};
	while(n) {
		if(n & 1) s = mul(s, t);
		t = mul(t, t);
		n >>= 1;
	}
	ll ret = 0;
	for(int i = 0; i < m; i++) ret += 1ll * s[i] * dp[i] % MOD;
	return ret % MOD;
}
ll guess_nth_term(vector<ll> x, ll n){
	if(n < x.size()) return x[n];
	vector<ll> v = berlekamp_massey(x);
	if(v.empty()) return 0;
	return get_nth(v, x, n);
}
