#include <iostream>
#include <algorithm>
using namespace std;
long long twocount(int a) {
	long long mul2 = 0;
	for (long long i = 2; i <= a; i *= 2) {
		mul2 += a / i;
		}
	return mul2;
}
long long fivecount(int a) {
	long long mul5 = 0;
	for (long long i = 5; i <= a; i *= 5) {
		mul5 += a / i;
	}
	return mul5;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long k, n, m;
	cin >> n >> m;
	k = min(twocount(n) - twocount(m) - twocount(n - m), fivecount(n) - fivecount(m) - fivecount(n - m));
	cout << k;
	return 0;
}