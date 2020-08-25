#include <iostream>
using namespace std;
long long N, B, A[3][3], C[3][3], ans[3][3], temp = 0;
void multiply(long long a[3][3], long long b[3][3]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				temp += a[i][k] * b[k][j];
				temp %= 1000000;
			}
			C[i][j] = temp; temp = 0;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			a[i][j] = C[i][j];
		}
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(0);
	cin >> N;
	A[0][0] = 1; A[0][1] = 1; A[1][0] = 1; A[1][1] = 0;
	ans[0][0] = 1; ans[0][1] = 1; ans[1][0] = 1; ans[1][1] = 0;
	while (N > 0) {
		if (N % 2 == 1) {
			multiply(ans, A);
		}
		multiply(A, A);
		N /= 2;
	}
	cout << ans[1][1];
}