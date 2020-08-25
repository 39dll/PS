#include <iostream>
using namespace std;
long long a[3][3], a2[3][3], ans[3][3], temp[3][3], N;
void mult(long long a[3][3], long long b[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				temp[i][j] += a[i][k] * b[k][j];
				temp[i][j] %= 1000000007;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = temp[i][j];
			temp[i][j] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N; N--;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[i][j] = 1;
			if (i == j)a2[i][i] = 1;
		}
	}
	a[0][0] = a[1][1] = 0;
	ans[0][0] = ans[0][1] = ans[0][2] = 1;
	while (N > 0) {
		if (N % 2 == 1) {
			mult(a2, a);
		}
		mult(a, a);
		N /= 2;
	}
	mult(ans, a2);
	cout << (ans[0][0] + ans[0][1] + ans[0][2]) % 1000000007;
}