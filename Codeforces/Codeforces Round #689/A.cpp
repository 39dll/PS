#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		long long n, k; cin >> n >> k;
		for (int i = 0; i < n; i++) {
			if (i % 3 == 0)cout << "a";
			if (i % 3 == 1)cout << "b";
			if (i % 3 == 2)cout << "c";
		}cout << '\n';
	}
}
