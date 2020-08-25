#include <iostream>
using namespace std;
long long f[4000001];
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
	long long n, r, p;
	p = 1000000007LL;
	cin >> t;
	f[0] = 1; f[1] = 1;
	for (int i = 2; i <= 4000000; i++) {
		f[i] = f[i - 1] * i;
		f[i] %= p;
	}
	while (t--) {
		cin >> n >> r;
		cout << (f[n] * mul((f[r] * f[n - r]) % p, p - 2, p)) % p << "\n";
	}
}