#include <iostream>
#include <cmath>
using namespace std;
int n, d;
double ans;
int main() {
	cout.precision(1);
	cin >> n >> d;
	ans = (n / 2.0) - d;
	ans *= 10;
	ans = round(ans);
	ans /= 10;
	cout << fixed << ans;
}