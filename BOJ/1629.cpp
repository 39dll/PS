#include <iostream>
#include <cmath>
using namespace std;
long long A, B, C, res = 0;
long long calc(long long A, long long B) {
	if (B == 1) { return (A % C); }
	long long temp = calc(A, B / 2) % C;
	if (B % 2 == 0) {
		return temp * temp % C;
	}
	else {
		return ((temp * temp) % C * (calc(A, 1))) % C;
	}
}
int main() {
	cin >> A >> B >> C;
	res = calc(A, B);
	cout << res;
}