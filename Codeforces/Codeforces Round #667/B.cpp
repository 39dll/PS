#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		long long a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		long long am = max(x, a - n);
		long long bm = max(y, b - n);
		long long temp = 0;
		if (am < bm) {
			if (x > a - n) {
				temp = x - (a - n);
			}
			a = max(x, a - n);
			b -= temp;
		}
		else {
			if (y > b - n) {
				temp = y - (b - n);
			}
			b = max(y, b - n);
			a -= temp;
		}
		a = max(a, x);
		b = max(b, y);
		cout << a*b << '\n';
	}
}
