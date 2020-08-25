#include <iostream>
using namespace std;
long long mul(long long x, long long y, long long p) {
	long long ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	long long n, r, p;
	p = 1000000007LL;
	while (t--) {
		cin >> n >> r;
		long long ans = 1;
		long long t1 = 1;
		long long t2 = 1;
		for (long long i = 1; i <= n; i++) {
			t1 *= i;
			t1 %= p;
		}
		for (long long i = 1; i <= r; i++) {
			t2 *= i;
			t2 %= p;
		}
		for (long long i = 1; i <= n - r; i++) {
			t2 *= i;
			t2 %= p;
		}
		long long t3 = mul(t2, p - 2, p);
		t3 %= p;
		ans = t1*t3;
		ans %= p;
		cout << ans << '\n';
	}
}