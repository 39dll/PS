#include <iostream>
using namespace std;
int r1, r2, r3;
double ans;
int main() {
	cout.precision(8);
	cin >> r1 >> r2 >> r3;
	ans = (1.0 * r1 * r2 * r3) / (r1 * r2 + r2 * r3 + r3 * r1);
	cout << fixed << ans;
}