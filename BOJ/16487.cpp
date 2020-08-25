#include <iostream>
#include <cmath>
using namespace std;
int a, b, c, m, n;
double ans;
int main() {
	cout.precision(8);
	cin >> a >> b >> c >> m;
	n = b - m;
	ans = (1.0 * n * a * a + m * c * c) / b - m * n;
	cout << fixed << ans;
}