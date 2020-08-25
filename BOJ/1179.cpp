#include <iostream>
using namespace std;
long long N, K, ans;
long long go(long long N, long long K) {
	if (N == 1) return 0;
	if (K == 1) return N - 1;
	if (K > N) return (go(N - 1, K) + K) % N;
	long long cnt = N / K;
	long long res = go(N - cnt, K);
	res -= N % K;
	if (res < 0) res += N;
	else res += res / (K - 1);
	return res;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	cout << go(N, K) + 1;
}