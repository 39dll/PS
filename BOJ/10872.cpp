#include <iostream>
using namespace std;
int fac(int a) {
	if (a > 2) {
		a *= fac(a - 1);
	}
	return a;
}
int main() {
	int N, a = 1;
	cin >> N;
	if (N != 0) a = fac(N);
	cout << a;
	return 0;
}