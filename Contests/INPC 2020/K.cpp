#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
unordered_map<long long, pair<long long, long long>> m;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long N, M, X;
	cin >> N >> M >> X;
	while (X--) {
		long long in1, in2, in3;
		cin >> in1 >> in2 >> in3;
		if (in3 == 1) {
			if (in1 + in2 - 1 <= M) {
				m[in1 + in2 - 1].first++;
				m[in1 + in2 - 1].second = max(m[in1 + in2 - 1].second, in1 - 1);
			}
			else {
				long long oriiin = in1;
				in1 -= M - in2 + 1;
				in2 = M;
				if (in2 >= in1) {
					m[in2 - in1 + 1].first++;
					m[in2 - in1 + 1].second = max(m[in2 - in1 + 1].second, oriiin - 1);
				}
				else {
					long long oriin = in1;
					in1 -= in2;
					in1 %= 2 * M;
					if (in1 <= M) {
						if (in1 == 0)in1 = 1;
						m[in1].first++;
						m[in1].second = max(m[in1].second, oriiin - 1);
					}
					else {
						in1 %= M;
						m[M - in1 + 1].first++;
						m[M - in1 + 1].second = max(m[M - in1 + 1].second, oriiin - 1);
					}
				}
			}
		}
		else {
			if (in2 >= in1) {
				m[in2 - in1 + 1].first++;
				m[in2 - in1 + 1].second = max(m[in2 - in1 + 1].second, in1 - 1);
			}
			else {
				long long oriin = in1;
				in1 -= in2;
				in1 %= 2 * M;
				if (in1 <= M) {
					if (in1 == 0)in1 = 1;
					m[in1].first++;
					m[in1].second = max(m[in1].second, oriin - 1);
				}
				else {
					in1 %= M;
					m[M - in1 + 1].first++;
					m[M - in1 + 1].second = max(m[M - in1 + 1].second, oriin - 1);
				}
			}
		}
	}
	pair<long long, long long> ans = { -1,-1 };
	for (auto i : m) {
		if (i.second.first > ans.first) {
			ans = i.second;
		}
		else if (i.second.first == ans.first) {
			if (i.second.second < ans.second) {
				ans = i.second;
			}
		}
	}
	cout << ans.first << ' ' << ans.second;
}
