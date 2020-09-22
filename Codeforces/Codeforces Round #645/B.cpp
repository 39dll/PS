#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		long long N;
		vector<int> v;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int in;
			cin >> in;
			v.push_back(in);
		}
		sort(v.begin(), v.end());
		int cnt = N;
		for (int i = N - 1; i >= 0; i--) {
			if (v[i] > i + 1)cnt--;
			else break;
		}
		cout << cnt + 1 << '\n';
	}
}
