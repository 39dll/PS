#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int T; cin >> T; while(T--) {

		ll N, M; cin >> N >> M;
		string str; cin >> str;
		vector<ll> cnt(4);
		for (auto i : str) {
			if (i == 'U')cnt[0]++;
			if (i == 'D')cnt[1]++;
			if (i == 'R')cnt[2]++;
			if (i == 'L')cnt[3]++;
		}
		bool pos = 1;
		if (N >= 0) {
			if (N > cnt[2])pos = 0;
		}
		else {
			if (-N > cnt[3])pos = 0;
		}
		if (M >= 0) {
			if (M > cnt[0])pos = 0;
		}
		else {
			if (-M > cnt[1])pos = 0;
		}
		cout << (pos ? "YES\n" : "NO\n");
	}
}
