#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int k[3];
	cout.precision(1);
	double a, b, c;
	cin >> k[0] >> k[1] >> k[2];
	a = (k[0] + k[1] - k[2]) / 2.0;
	b = (k[0] + k[2] - k[1]) / 2.0;
	c = (k[1] + k[2] - k[0]) / 2.0;
	if (a > 0 && b > 0 && c > 0) {
		cout << 1 << '\n';
		cout << fixed << round(a * 10) / 10 << ' ' << round(b * 10) / 10 << ' ' << round(c * 10) / 10;
	}
	else {
		cout << -1;
	}
}