#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while (T--) {
		deque<int> dq;
		long long a = 0, b = 0;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int in;
			cin >> in;
			dq.push_back(in);
		}
		long long last = 0, eaten, move = 0;
		bool turn = 0;
		while (!dq.empty()) {
			eaten = 0;
			if (turn == 0) {
				while (1) {
					if (eaten > last)break;
					if (dq.empty())break;
					int cur = dq.front();
					dq.pop_front();
					a += cur;
					eaten += cur;
				}
				last = eaten;
				turn = 1;
				move++;
			}
			else if (turn == 1) {
				while (1) {
					if (eaten > last)break;
					if (dq.empty())break;
					int cur = dq.back();
					dq.pop_back();
					b += cur;
					eaten += cur;
				}
				last = eaten;
				turn = 0;
				move++;
			}
		}
		cout << move << ' ' << a << ' ' << b << '\n';
	}
}
