#include <iostream>
#include <cmath>
using namespace std;
int a, b, c, d, e;
double ans;
int main() {
	cout.precision(8);
	cin >> a >> b >> c >> d >> e;
	ans = 1.0 * b * (c - d) * (a - e) / (d * e + (c - d) * (a - e));
	cout << fixed << ans;
}