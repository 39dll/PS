#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> p;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<int> v(N);
		long long sum = 0;
		bool haszero = 0;
		for (int i = 0; i < N; i++) {
			cin >> v[i];
			sum += v[i];
			if (v[i] == 0)haszero = 1;
		}
		if (sum == M)cout << "YES\n";
		else cout << "NO\n";
	}
}
