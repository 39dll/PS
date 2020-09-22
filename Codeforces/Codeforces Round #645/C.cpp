#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << (c - a)*(d - b) + 1 << '\n';
	}
}
