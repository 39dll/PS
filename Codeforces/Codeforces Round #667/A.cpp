#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		long long a, b;
		cin >> a >> b;
		cout << (long long)ceil(abs(b - a) / 10.0) << '\n';
	}
}
