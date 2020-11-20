#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) {
		int N, M; cin >> N >> M;
		bool arr[101][101] = { 0 };
		vector<tuple<int, int, int, int, int, int>>ans;
		for (int i = 0; i < N; i++) {
			string in; cin >> in;
			for (int j = 0; j < M; j++) {
				arr[i][j] = in[j] - '0';
			}
		}
		auto p = [&](int a1, int a2, int a3, int a4, int a5, int a6) {
			ans.push_back({ a1,a2,a3,a4,a5,a6 });
		};
		auto f = [&](int x, int y) {
			arr[x][y] = arr[x + 1][y] = arr[x][y + 1] = arr[x + 1][y + 1] = 0;
		};
		auto fix = [&](int x, int y)->void {
			int p1 = arr[x][y];
			int p2 = arr[x][y + 1];
			int p3 = arr[x + 1][y];
			int p4 = arr[x + 1][y + 1];
			if (p1 == 0) {
				if (p2 == 0) {
					if (p3 == 0) {
						if (p4 == 0) {//00 00
						}
						else {
							//00 01
							p(x, y, x + 1, y, x + 1, y + 1);
							p(x, y, x, y + 1, x + 1, y + 1);
							p(x, y + 1, x + 1, y + 1, x + 1, y);
							f(x,y);
						}
					}
					else {
						if (p4 == 0) {//00 10
							p(x, y, x + 1, y, x, y + 1);
							p(x, y, x + 1, y, x + 1, y + 1);
							p(x + 1, y, x + 1, y + 1, x, y + 1);
							f(x, y);
						}
						else {//00 11
							p(x, y, x + 1, y, x, y + 1);
							p(x, y, x, y + 1, x + 1, y + 1);
							f(x, y);
						}

					}
				}
				else {
					if (p3 == 0) {
						if (p4 == 0) {//01 00
							p(x, y, x + 1, y, x, y + 1);
							p(x, y, x, y + 1, x + 1, y + 1);
							p(x + 1, y, x + 1, y + 1, x, y + 1);
							f(x, y);
						}
						else {
							//01 01
							p(x, y, x + 1, y, x, y + 1);
							p(x, y, x + 1, y, x + 1, y + 1);
							f(x, y);
						}
					}
					else {
						if (p4 == 0) {//01 10
							p(x, y, x + 1, y, x + 1, y + 1);
							p(x, y, x, y + 1, x + 1, y + 1);
							f(x, y);
						}
						else {//01 11
							p(x, y + 1, x + 1, y, x + 1, y + 1);
							f(x, y);
						}

					}
				}
			}
			else {
				if (p2 == 0) {
					if (p3 == 0) {
						if (p4 == 0) {//10 00
							p(x, y, x + 1, y, x, y + 1);
							p(x, y, x + 1, y, x + 1, y + 1);
							p(x, y, x, y + 1, x + 1, y + 1);
							f(x, y);
						}
						else {
							//10 01
							p(x, y, x + 1, y, x, y + 1);
							p(x + 1, y + 1, x, y + 1, x + 1, y);
							f(x, y);
						}
					}
					else {
						if (p4 == 0) {//10 10
							p(x, y, x, y + 1, x + 1, y + 1);
							p(x + 1, y, x + 1, y + 1, x, y + 1);
							f(x, y);
						}
						else {//10 11
							p(x, y, x + 1, y, x + 1, y + 1);
							f(x, y);
						}

					}
				}
				else {
					if (p3 == 0) {
						if (p4 == 0) {//11 00
							p(x, y, x + 1, y, x + 1, y + 1);
							p(x + 1, y, x + 1, y + 1, x, y + 1);
							f(x, y);
						}
						else {//11 01
							p(x, y, x, y + 1, x + 1, y + 1);
							f(x, y);
						}
					}
					else {
						if (p4 == 0) {//11 10
							p(x, y, x, y + 1, x + 1, y);
							f(x, y);
						}
						else {//11 11
							p(x, y, x, y + 1, x + 1, y + 1);
							p(x + 1, y, x + 1, y + 1, x, y + 1);
							p(x, y, x + 1, y, x, y + 1);
							p(x, y, x + 1, y, x + 1, y + 1);
							f(x, y);
						}

					}
				}
			}
		};
		for (int i = 0; i < N - 1; i++) {
			for (int j = 0; j < M - 1; j++) {
				fix(i, j);
			}
		}
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++) {
			int a1, a2, a3, a4, a5, a6;
			tie(a1, a2, a3, a4, a5, a6) = ans[i];
			cout << a1 + 1 << ' ' << a2 + 1 << ' ' << a3 + 1 << ' ' << a4 + 1 << ' ' << a5 + 1 << ' ' << a6 + 1 << '\n';
		}
	}
}
