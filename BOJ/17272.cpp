#include <iostream>
using namespace std;
long long a[101][101] = { { 0, }, }, a2[101][101] = { { 0, }, }, ans[101][101] = { { 0, }, }, temp[101][101] = { {0, }, }, N;
int M;
void mult(long long a[101][101], long long b[101][101]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < M; k++) {
				temp[i][j] += a[i][k] * b[k][j];
				temp[i][j] %= 1000000007;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			a[i][j] = temp[i][j];
			temp[i][j] = 0;
		}
	}
}
int main() {
	cin >> N >> M;
	a[0][0] = 1; a[M - 1][0] = 1; a2[0][0] = 1;
	for (int i = 1; i < M; i++) {
		a[i - 1][i] = 1;
		a2[i][i] = 1;
	}
	ans[0][0] = 2;
	for (int i = 1; i < M; i++) {
		ans[0][i] = 1;
	}
	if (N < M) { cout << 1; return 0; }
	N -= M;
	while (N > 0) {
		if (N % 2 == 1) {
			mult(a2, a);
		}
		mult(a, a);
		N /= 2;
	}
	mult(ans, a2);
	cout << ans[0][0];
	return 0;
}