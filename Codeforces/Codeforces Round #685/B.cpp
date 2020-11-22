#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) {

		int N, Q; cin >> N >> Q;
		string str; cin >> str;

		vector<int> p1(N + 1), p0(N + 1);
		p1[0] = p0[0] = 0;
		for (int i = 0; i < N; i++) {
			p1[i + 1] = p1[i] + (str[i] == '1');
			p0[i + 1] = p0[i] + (str[i] == '0');
		}
		while (Q--) {
			bool good = 0;
			int L, R; cin >> L >> R;
			if (str[L - 1] == '0') {
				if (p0[L - 1] != 0)good = 1;
			}
			if (str[L - 1] == '1') {
				if (p1[L - 1] != 0)good = 1;
			}
			if (str[R - 1] == '0') {
				if (p0[N] != p0[R])good = 1;
			}
			if (str[R - 1] == '1') {
				if (p1[N] != p1[R])good = 1;
			}
			cout << (good ? "YES\n" : "NO\n");
		}

	}
}
