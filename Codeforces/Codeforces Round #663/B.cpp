#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N, M, cnt = 0;
		char in;
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> in;
				if (i != N) {
					if (j == M && in == 'R')cnt++;
				}
				else {
					if (j != M && in == 'D')cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}
