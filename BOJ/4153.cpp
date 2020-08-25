#include <iostream>
using namespace std;
int max(int a, int b) { if (a > b) return a; else return b; }
int min(int a, int b) { if (a < b) return a; else return b; }
int main() {
	ios_base::sync_with_stdio(0);
	int d1, d2, d3, a, b, c;
	cin >> d1 >> d2 >> d3;
	while (!(d1 == 0 && d2 == 0 && d3 == 0)) {
		a = min(d1, min(d2, d3));
		c = max(d1, max(d2, d3));
		b = d1 + d2 + d3 - a - c;
		if (a*a + b*b == c*c) cout << "right\n";
		else cout << "wrong\n";
		cin >> d1 >> d2 >> d3;
	}
	return 0;
}