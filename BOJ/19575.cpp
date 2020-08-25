#include <iostream>
using namespace std;
int A[1000002];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, x;
	cin >> N >> x;
	for (int i = N; i >= 0; i--) {
		int in;
		cin >> A[i] >> in;
	}
	long long ans = A[N];
	while (N >= 1) {
		ans *= x;
		ans += A[N - 1];
		ans %= 1000000007;
		N--;
	}
	cout << ans;
}