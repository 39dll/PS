#include <iostream>
using namespace std;
long long N, B, A[6][6], C[6][6], ans[6][6], temp = 0;
void multiply(long long a[6][6], long long b[6][6]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				temp += a[i][k] * b[k][j];
				temp %= 1000;
			}
			C[i][j] = temp; temp = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = C[i][j];
		}
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(0);
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
		ans[i][i] = 1;
	}
	while (B > 0) {
		if (B % 2 == 1) {
			multiply(ans, A);
		}
		multiply(A, A);
		B /= 2;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << "\n";
	}
}