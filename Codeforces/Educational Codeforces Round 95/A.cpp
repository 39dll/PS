#include <bits/stdc++.h>
using namespace std;
long long myabs(long long a) {
	return a >= 0 ? a : -a;
}
int main() {
	int T; cin >> T;
	while (T--) {
		long long x, y, k;
		cin >> x >> y >> k;
		long long a;
		if ((k*y + k - 1) % (x - 1) == 0)a = (k*y + k - 1) / (x - 1);
		else {
			a = (k*y + k - 1) / (x - 1) + 1;
		}
		long long b = k;
		cout << b + a << '\n';
	}
}
