#include <iostream>
#include <algorithm>
using namespace std;
long long N, M, in, mx1, mx2;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> in;
		mx1 = max(mx1, in);
	}
	for (int i = 0; i < M; i++) {
		cin >> in;
		mx2 = max(mx2, in);
	}
	cout << mx1 + mx2;
}