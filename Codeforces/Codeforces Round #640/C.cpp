#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while (T--) {
		long long N, K;
		cin >> N >> K;
		cout << (long long)floor((K - 1) / (N - 1)) + K << '\n';
	}
}
