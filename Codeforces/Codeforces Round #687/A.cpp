#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		long long m, n, r, c;
		cin >> m >> n >> r >> c;
		long long mx = 0;
		mx = max({ r + c - 2, m - r + c - 1,n - c + r - 1,m - r + n - c });
		cout << mx << '\n';
	}
}
