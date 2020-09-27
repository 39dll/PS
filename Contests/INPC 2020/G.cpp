#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long a1, b1, c1, a2, b2, c2;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	long long d = (a1 - a2)*(a1 - a2) + (b1 - b2)*(b1 - b2) + (c1 - c2)*(c1 - c2);
	long long N, K[101];
	cin >> N;
	long long mx = 0, sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> K[i];
		mx = max(mx, K[i]);
		sum += K[i];
	}
	if (mx*mx >= d) {
		sum -= mx;
		sum += sqrt(d);
		if (sum >= mx) {
			cout << "YES";
			return 0;
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	else {
		if (sum >= sqrt(d)) {
			cout << "YES";
			return 0;
		}
		else {
			cout << "NO";
			return 0;
		}
	}
}
