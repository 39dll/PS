#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define DEBUG 0
#define lld93 if(DEBUG)cout.flush(),system("pause"); return 0
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T; while(T--) {
		ll N, K; cin >> N >> K;
		if (N == K)cout << 1 << '\n';
		else if (N > K)cout << 1 + (N % K != 0) << '\n';
		else cout << (K + N - 1) / N << '\n';
	}
	lld93;
}
