#include <iostream>
using namespace std;
int T, N;
int cnt = 0;
int gcd(int a, int b) {
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
bool is_seoroso(int a, int b) {
	if (gcd(a, b) == 1) return 1;
	else return 0;
}
int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i*i <= N; i++) {
			if (N%i == 0) {
				cnt += is_seoroso(i, N / i);
			}
		}
		cout << cnt << "\n";
		cnt = 0;
	}
}