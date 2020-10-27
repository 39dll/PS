#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		long long a, b, q, l, r;
		cin >> a >> b >> q;
		vector<long long> v(a*b + 1);
		for (int i = 1; i <= a*b; i++) {
			if ((i%a) % b != (i%b) % a)v[i] = v[i - 1] + 1;
			else v[i] = v[i - 1];
		}
		auto k = [&](long long p)->long long {
			long long res = 0;
			res += p / (a*b) * v[a*b];
			p %= (a*b);
			res += v[p];
			return res;
		};
		for (int i = 0; i < q; i++) {
			cin >> l >> r;
			cout << k(r) - k(l - 1) << ' ';
		}cout << '\n';
	}
}
