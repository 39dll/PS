#include <iostream>
#include <map>
using namespace std;
map<pair<long long, long long>, long double> dp;
long long N, M, K;
long double go(long long N, long long K) {
	if (N == 0) return 0;
	if (K == 1) { if (N >= 2) return 1; else return (double)(M - N) / M; }
	long double p = 0;
	if (dp[{N, K}] != 0) return dp[{N, K}];
	p += (double)(M - N % M) / (double)M * go(N - N / M, K - 1);
	p += (double)(N % M) / (double)M * go(N - N / M - 1, K - 1);
	return dp[{N, K}] = p;
}
int main() {
	cin >> N >> M >> K;
	cout.precision(9);
	cout << fixed << go(N, K);
}