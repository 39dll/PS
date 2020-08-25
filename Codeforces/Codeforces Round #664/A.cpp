#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
long long r, g, b, w;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T; while (T--) {
		cin >> r >> g >> b >> w;
		
		int r2, g2, b2, w2;
		r2 = r % 2;
		g2 = g % 2;
		b2 = b % 2;
		w2 = w % 2;
		if (r == 0 || g == 0 || b == 0) {
			if (r2 + g2 + b2 + w2 == 3 || r2 + g2 + b2 + w2 == 2) {
				cout << "No\n";
			}
			else {
				cout << "Yes\n";
			}
			continue;
		}
		if (r2 + g2 + b2 + w2 != 2) {
			cout << "Yes\n";
		}
		else cout << "No\n";
	}
}
