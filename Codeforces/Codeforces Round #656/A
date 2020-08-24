#include <iostream>
#include <algorithm>
using namespace std;
int t, x, y, z, a, b, c;
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> x >> y >> z;
		if (x == y && y == z) {
			cout << "YES\n";
			cout << x << " " << x << " " << x << "\n";
		}
		else if (x == y) {//a가 가장 큼
			a = x;
			if (z > x) {
				cout << "NO\n";
				a = b = c = 0;
				continue;
			}
			else {
				cout << "YES\n";
				cout << a << " " << z << " " << 1 << "\n";
				a = b = c = 0;
				continue;
			}
		}
		else if (x == z) {
			a = x;
			if (y > x) {
				cout << "NO\n";
				a = b = c = 0;
				continue;
			}
			else {
				cout << "YES\n";
				cout << a << " " << y << " " << 1 << "\n";
				a = b = c = 0;
				continue;
			}
		}
		else if (y == z) {
			a = y;
			if (x > y) {
				cout << "NO\n";
				a = b = c = 0;
				continue;
			}
			else {
				cout << "YES\n";
				cout << a << " " << x << " " << 1 << "\n";
				a = b = c = 0;
				continue;
			}
		}
		else {
			cout << "NO\n";
			a = b = c = 0;
			continue;
		}
	}
}
