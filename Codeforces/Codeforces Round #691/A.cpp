#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		long long N; cin >> N;
		string s1, s2; cin >> s1 >> s2;
		int sc = 0;
		for (int i = 0; i < N; i++) {
			if (s1[i] > s2[i])sc++;
			if (s1[i] < s2[i])sc--;
		}
		if (sc > 0)cout << "RED\n";
		else if (sc < 0)cout << "BLUE\n";
		else cout << "EQUAL\n";
	}
}
