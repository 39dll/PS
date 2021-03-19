#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int T; cin >> T; while(T--) {
    
		ll N, M; cin >> N >> M;
		vector<ll> a(N), b(N);
		vector<ll> c(M);
		vector<ll> d(N + 1, -1), e(N + 1);
		for (int i = 0; i < N; i++)cin >> a[i];
		for (int i = 0; i < N; i++)cin >> b[i];
		for (int i = 0; i < M; i++)cin >> c[i];

		map<ll, vector<ll>> m;
		bool pos = 1;
		vector<ll> ans;
		ll k = -1;
		
		for (int i = 0; i < N; i++) {
			if (a[i] != b[i]) {
				if (m.find(b[i]) == m.end()) {
					m[b[i]] = { i + 1 };
				}
				else {
					m[b[i]].push_back(i + 1);
				}
				e[b[i]] = 1;
			}
			d[b[i]] = i + 1;
		}

		if (d[c[M - 1]] == -1 && e[c[M - 1]] == 0) {
			cout << "NO\n";
			continue;
		}

		if (m.find(c[M - 1]) != m.end()) {
			k = m[c[M - 1]][0];
		}
		else {
			k = d[c[M - 1]];
		}

		for (int i = 0; i < M; i++) {
			ll t = -1;
			if (m.find(c[i]) != m.end() && m[c[i]].size()) {
				t = m[c[i]].back();
				m[c[i]].pop_back();
			}
			if (t == -1) {
				ans.push_back(k);
				a[k - 1] = c[i];
			}
			else {
				ans.push_back(t);
				a[t - 1] = c[i];
			}
		}
		for (int i = 0; i < N; i++) {
			if (a[i] != b[i]) {
				pos = 0;
				break;
			}
		}
		if (pos) {
			cout << "YES\n";
			for (auto i : ans)cout << i << ' ';
			cout << '\n';
		}
		else cout << "NO\n";
	}
}
