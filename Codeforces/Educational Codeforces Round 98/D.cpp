#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long arr[200001] = { 0 };
long long n, a;
tuple<long long, long long, long long> euclid(long long x, long long y) {
	if (x < y) swap(x, y);
	if (y == 0) return { x,1,0 };
	long long g, x1, y1; tie(g, x1, y1) = euclid(y, x%y);
	return { g, y1, x1 - (x / y) * y1 };
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	arr[0] = 0; arr[1] = 1;
	for (int i = 2; i <= N; i++)arr[i] = arr[i - 1] + arr[i - 2], arr[i] %= MOD;
	long long base = 1;
	for (int i = 0; i < N; i++) {
		base *= 2;
		base %= MOD;
	}
	tuple<long long, long long, long long> ret = euclid(base, MOD);
	long long inv = (get<2>(ret) + MOD) % MOD;
	cout << (inv * arr[N]) % MOD;
}
