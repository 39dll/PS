#include <iostream>
#include <cmath>
int max(int a, int b) { if (a > b) return a; else return b; }
int min(int a, int b) { if (a < b) return a; else return b; }
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int T, x, y, r, xx, yy, rr;
	double d;
	cin >> T;
	while (T--) {
		cin >> x >> y >> r >> xx >> yy >> rr;
		d = sqrt(pow(x - xx, 2) + pow(y - yy, 2));
		if (d == 0) {
			if (r == rr) cout << "-1\n";
			else cout << "0\n";
		}
		else {
			if (d > r + rr) cout << "0\n";
			else if (d == r + rr) cout << "1\n";
			else if (d < max(rr, r) - min(rr, r)) cout << "0\n";
			else if (d == max(rr, r) - min(rr, r)) cout << "1\n";
			else cout << "2\n";
		}
	}
	return 0;
}