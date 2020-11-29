#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		long long n, p, k, x, y;
		cin >> n >> p >> k;
		string s; cin >> s;
		cin >> x >> y;
		long long mn = 21000000000000000;
		for (int i = 0; i < k; i++) {
			long long init = i * y;
			vector<int> psum0;
			psum0.push_back(0);
			for (int q = p + i - 1; q < n; q += k) {
				psum0.push_back(psum0.back() + (s[q] == '0'));
			}
			for (int ind = 1; ind < psum0.size(); ind++) {
				long long cost = init + (psum0.back() - psum0[ind - 1]) * x + y*k*(ind - 1);
				mn = min(mn, cost);
			}
		}
		cout << mn << '\n';
	}
}
