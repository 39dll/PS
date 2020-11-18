#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		int arr[101][101];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
				if ((i + j) % 2 == 0) {
					if (arr[i][j] % 2 == 0) {
						arr[i][j]++;
					}
				}
				else {
					if (arr[i][j] % 2 == 1) {
						arr[i][j]++;
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << arr[i][j] << ' ';
			}cout << '\n';
		}
	}
}
