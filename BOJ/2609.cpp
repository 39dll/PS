#include <iostream>
using namespace std;
int gcd(int a, int b) {
	int k;
	while (b != 0) {
		k = a%b;
		a = b;
		b = k;
	}
	return a;
}
int lcm(int a, int b) {
	return a*b / gcd(a, b);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N1, N2;
	cin >> N1 >> N2;
	cout << gcd(N1, N2) << "\n" << lcm(N1, N2);
	return 0;
}