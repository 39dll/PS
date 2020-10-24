#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, c, up, dw, n;
	cin >> a >> b >> c;
	dw = b - 1;
	up = a - dw - 1;
	int useddw = 0;
	int usedup = 0;
	long long base = 1;

	int start = 0, end = a;
	while (start < end) {
		int mid = (start + end) / 2;
		if (mid == c)break;
		if (mid < c) {
			base = (dw * base) % MOD;
			dw--;
			useddw++;
			start = mid + 1;
			continue;
		}
		if (mid > c) {
			base = (up * base) % MOD;
			up--;
			usedup++;
			end = mid;
			continue;
		}
	}
	n = up + dw;
	if (up < 0 || dw < 0) {
		cout << 0;
		return 0;
	}
	long long newbase = 1;
	for (int i = 2; i <= n; i++) {
		newbase *= i;
		newbase %= MOD;
	}
	cout << (base * newbase) % MOD;
}
