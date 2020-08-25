#include <iostream>
using namespace std;
int N, M, K, A[101][101], B[101][101], C[101][101], temp = 0;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> B[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				temp += A[i][k] * B[k][j];
			}
			C[i][j] = temp; temp = 0;
			cout << C[i][j] << " ";
		}
		cout << "\n";
	}
}