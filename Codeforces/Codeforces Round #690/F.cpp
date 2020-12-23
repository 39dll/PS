#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<pair<long long, long long>>v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i].first >> v[i].second;
		}
		vector<long long> v1(N), v2(N);
		for (int i = 0; i < N; i++)tie(v1[i], v2[i]) = v[i];
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		long long mn = 2100000000;
		for (int i = 0; i < N; i++) {
			long long fs = v[i].first, sc = v[i].second;
			long long it1 = lower_bound(v2.begin(), v2.end(), fs) - v2.begin();
			long long it2 = lower_bound(v1.begin(), v1.end(), sc + 1) - v1.begin();
			mn = min(mn, it1 + N - 1 - it2);
		}
		cout << mn + 1 << '\n';
	}
}
