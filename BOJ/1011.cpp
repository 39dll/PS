#include <iostream>
#include <cmath>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	long long int x, y ,t, k = 0;
	int T;
	cin >> T;
	while (T--) {
		cin >> x >> y;
		t = y - x;
		if (t == 1) {
			k = 1;
		}
		else if (t == 2) {
			k = 2;
		}
		else {
			for (int i = 2; i <= pow(2,32); i++) {
				if (t <= pow(i, 2)) {
					k = i + (i - 1);
					if (t < (pow(i - 1, 2) + 1 + pow(i, 2)) / 2) {
						k--;
					} break;
				}
			}
		}
		cout << k << "\n";
	}
	return 0;
}