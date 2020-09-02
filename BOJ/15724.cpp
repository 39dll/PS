#include <bits/stdc++.h>
using namespace std;
int N, M, Q, arr[1025][1025], psum[1025][1025];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		//psum[i][1] = arr[i][1] + psum[i - 1][1];
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			psum[i][j] = arr[i][j] + psum[i][j - 1] + psum[i - 1][j] - psum[i - 1][j - 1];
		}
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int in1, in2, in3, in4;
		cin >> in1 >> in2 >> in3 >> in4;
		cout << psum[in3][in4] - psum[in1 - 1][in4] - psum[in3][in2 - 1] + psum[in1 - 1][in2 - 1] << '\n';
	}
}