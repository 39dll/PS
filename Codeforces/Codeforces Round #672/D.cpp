#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<long long> st, en, all;
long long f[300301];
long long mypow(long long base, long long exp) {
	if (exp == 0) return 1;
	if (exp == 1) return base;
	if (exp % 2 == 1) return base * mypow(base, exp - 1) % 998244353;
	long long temp = mypow(base, exp / 2);
	return (temp * temp) % 998244353;
}
long long nCr(long long n, long long k) {
	int num = f[n];
	int denom = f[k] * f[n - k] % 998244353;
	return (num)*mypow(denom, 998244353 - 2) % 998244353;
}
int getind(int x) {
	return lower_bound(all.begin(), all.end(), x) - all.begin();
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= 300300; ++i) {
		f[i] = f[i - 1] * i;
		f[i] %= 998244353;
	}

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		long long in1, in2;
		cin >> in1 >> in2;
		st.push_back(in1);
		en.push_back(in2 + 1);
		all.push_back(in1);
		all.push_back(in2 + 1);
	}
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	sort(st.begin(), st.end());
	sort(en.begin(), en.end());
	long long cur = 0;
	long long ans = 0;
	int ptr1 = 0, ptr2 = 0;
	for (int i = 0; i < all.size(); i++) {
		long long oldcur = cur;
		int pl = 0;
		int mi = 0;
		while (ptr1 < st.size() && getind(st[ptr1]) == i) {
			cur++;
			ptr1++;
			pl++;
		}
		while (ptr2 < en.size() && getind(en[ptr2]) == i) {
			cur--;
			ptr2++;
			mi++;
		}
		oldcur -= mi;
		if (pl == 0) continue;
		if (cur < K) continue;
		ans += nCr(cur, K);
		if (oldcur >= K) {
			ans -= nCr(oldcur, K);
		}
		ans = (ans + 998244353) % 998244353;
	}
	cout << ans;
}
