#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, M;
		int zcnt = 0, ocnt = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int in;
			cin >> in;
			if (in % 2 == 0)zcnt++;
			else ocnt++;
		}
		if (ocnt == 0) {
			cout << "No\n";
			continue;
		}
		if (zcnt == 0) {
			if (M % 2 == 1)cout << "Yes\n";
			else cout << "No\n";
			continue;
		}
		if (ocnt % 2 == 0) {
			if (M == ocnt + zcnt) {
				cout << "No\n";
			}
			else cout << "Yes\n";
			continue;
		}
		else {
			cout << "Yes\n";
			continue;
		}
	}
}
