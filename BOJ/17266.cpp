#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, M, x[100003], mx = 0;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> x[i];
	}
	for (int i = 2; i <= M; i++) {
		mx = max(mx, (x[i] - x[i - 1] + 1) / 2);
	}
	mx = max(mx, x[1]);
	mx = max(mx, N - x[M]);
	cout << mx;
}