#include <iostream>
using namespace std;
int N, M, arr[100001], psum[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	cin >> M;
	while (M--) {
		int in1, in2;
		cin >> in1 >> in2;
		cout << psum[in2] - psum[in1 - 1] << '\n';
	}
}