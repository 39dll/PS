#include <bits/stdc++.h>
using namespace std;
const long long MAX = 40001;
int notPrime[100003];
vector<long long> prime;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 2; i <= 100000; i++) {
		if (notPrime[i]) continue;
		for (int j = 2 * i; j <= 100000; j += i) {
			notPrime[j] = 1;
		}
	}
	for (int i = 2; i <= 100000; i++) {
		if (!notPrime[i]) prime.push_back(i);
	}
	int T; cin >> T; while (T--) {

		long long N, oriN; cin >> N; oriN = N;
		map<long long, int> m;
		long long mx = 0, mxcnt = 0;

		int ind = 0;
		while (N > 1) {
			if (N%prime[ind] == 0) {
				N /= prime[ind];
				m[prime[ind]]++;
			}
			else {
				ind++;
			}
			if (ind == prime.size()) {
				N = 1;
				m[N]++;
			}
		}

		for (auto &i : m) {
			if (mxcnt < i.second) {
				mxcnt = i.second;
				mx = i.first;
			}
		}
		long long k = 1;
		cout << mxcnt << '\n';
		for (int i = 0; i < mxcnt - 1; i++) {
			cout << mx << ' ';
			k *= mx;
		}
		cout << oriN / k << '\n';
	}
}
