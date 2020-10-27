#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		long long x, y, a, b;
		cin >> x >> y >> a >> b;
		long long ans = 0;
		if (a * 2 <= b) {
			ans += a * llabs(x);
			ans += a * llabs(y);
		}
		else {
			if (x > 0 && y > 0) {
				long long temp = llabs(min(x, y));
				ans += b * temp;
				x -= temp;
				y -= temp;
				ans += a * llabs(x);
				ans += a * llabs(y);
			}
			else if (x < 0 && y < 0) {
				long long temp = llabs(max(x, y));
				ans += b * temp;
				x += temp;
				y += temp;
				ans += a * llabs(x);
				ans += a * llabs(y);
			}
			else {
				ans += a * llabs(x);
				ans += a * llabs(y);
			}
		}
		cout << ans << '\n';
	}
}
