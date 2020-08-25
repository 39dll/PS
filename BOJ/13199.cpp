#include <iostream>
#include <cmath>
using namespace std;
int T, P, M, F, C, c1, c2;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> P >> M >> F >> C;
		c1 = M / P + (M / P)*C / F;
		c2 = M / P;
		if (M / P * C >= F) c2 += (M / P * C - F) / (F - C) + 1;
		cout << c2 - c1 << "\n";
	}
}