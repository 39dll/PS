#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K, iter, arr[501];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	if (M + K - 1 <= N && N <= M * K) {
		for (int i = 0; i < N; i++)arr[i] = i + 1;
		for (int i = 1; i <= M; i++) {
			reverse(arr + iter, arr + min(iter + K, N - M + i));
			iter = min(iter + K, N - M + i);
		}
		for (int i = 0; i < N; i++)cout << arr[i] << ' ';
	}
	else cout << -1;
}