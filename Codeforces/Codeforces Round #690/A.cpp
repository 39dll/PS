#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		long long N; cin >> N;
		vector<long long>v(N);
		for (auto &i : v)cin >> i;
		int ptr1 = 0, ptr2 = N - 1;
		bool turn = 0;
		while (1) {
			if(turn==0)cout << v[ptr1] << ' ';
			else cout << v[ptr2] << ' ';
			if (ptr1 == ptr2)break;
			if (turn == 0)ptr1++;
			else ptr2--;
			turn ^= 1;
		}cout << '\n';
	}
}
