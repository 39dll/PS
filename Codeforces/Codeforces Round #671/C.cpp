#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, kill;
		cin >> N >> kill;
		int cnt = 0;
		long long cha = 0;
		vector<int> v;
		for (int i = 0; i < N; i++) {
			int in;
			cin >> in;
			v.push_back(in);
			if (in == kill)cnt++;
			else cha += (in - kill);
		}
		if (cnt == N) {
			cout << 0 << '\n';
			continue;
		}
		if (cha == 0 || cnt != 0) {
			cout << 1 << '\n';
			continue;
		}
		cout << 2 << '\n';
		continue;
	}
}
