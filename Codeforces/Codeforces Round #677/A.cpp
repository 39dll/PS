#include <bits/stdc++.h>
using namespace std;

int go(int n) {
	if (n < 10) return 1;
	else if (n < 100) return 3;
	else if (n < 1000) return 6;
	return 10;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << go(N) + ((N % 10) - 1) * 10 << '\n';
	}
}
