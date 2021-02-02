#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define DEBUG 0
#define lld93 if(DEBUG)cout.flush(),system("pause"); return 0
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T; while(T--) {
		ll N, K; cin >> N >> K;
		vector<ll> v(N);
		for (auto &i : v)cin >> i;
		ll st = 0, en = 100000000000;
		ll ans = 100000000000;
		while (st <= en) {
			ll mid = (st + en) / 2;
			bool pos = 1;
			ll cur = v[0] + mid;
			for (int i = 1; i < N; i++) {
				if (v[i] * 100 > K * cur) {
					pos = 0;
					break;
				}
				cur += v[i];
			}
			if (pos) {
				en = mid - 1;
				ans = min(ans, mid);
			}
			else {
				st = mid + 1;
			}
		}
		cout << ans << '\n';
	}
	lld93;
}
