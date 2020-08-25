#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int N, M, dist[401][401];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = INF;
		}
	}
	for (int i = 1; i <= M; i++) {
		int in1, in2, in3;
		cin >> in1 >> in2 >> in3;
		dist[in1][in2] = min(dist[in1][in2], in3);
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = INF, ansind;
	for (int i = 1; i <= N; i++) {
		if (dist[i][i] < ans) {
			ans = dist[i][i];
			ansind = i;
		}
	}
	if (ans != INF) cout << ans;
	else cout << -1;
}