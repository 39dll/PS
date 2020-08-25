#include <iostream>
#include <map>
using namespace std;
int T, N, point[1001];
map<int, int> m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		m.clear();
		for (int i = 0; i < N; i++) {
			cin >> point[i];
			m[point[i]] = 1;
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if ((point[i] + point[j]) % 2)continue;
				if (m.find((point[i] + point[j]) / 2) != m.end())ans++;
			}
		}
		cout << ans << '\n';
	}
}