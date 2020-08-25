#include <iostream>
#include <cmath>
using namespace std;
int j(int a, int b) {//a의 10^b자리수 반환
	return (a % int(pow(10, b + 1))) / pow(10, b);
}
bool is_666(int a) {
	int k = 0;
	for (int i = 6; i >= 0; i--) {
		if (a >= pow(10, i)) k = i;
		if (k != 0) break;
	}
	for (int i = 0; i <= k - 2; i++) {
		if (j(a, i) == 6) {
			if (j(a, i + 1) == 6) {
				if (j(a, i + 2) == 6) return 1;
			}
		}
	}
	return 0;
}
int main() {
	int ind = 0, N, M = 0;;
	cin >> N;
	while (1) {
		for (int i = 666; i <= 2700000; i++) {
			if (is_666(i))ind++;
			if (ind == N) { M = i; break; }
		}
		if (M != 0) break;
	}
	cout << M;
	return 0;
}