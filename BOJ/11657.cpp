#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> p;//가중치, 도착점
const int INF = 1000000000;
int N, M, a, b, c;
long long v[501];
bool cycle = 0;
vector<p> e[501];
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		e[a].push_back({ b, c });
	}
	for (int i = 1; i <= N; i++) {
		v[i] = INF;
	}
	v[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < e[j].size(); k++) {
				if (v[j] != INF && v[e[j][k].first] > e[j][k].second + v[j]) {
					v[e[j][k].first] = e[j][k].second + v[j];
					if (i == N) cycle = 1;
				}
			}
		}
	}
	if (cycle == 1) cout << "-1";
	else {
		for (int i = 2; i <= N; i++) {
			if (v[i] == INF) cout << "-1\n";
			else cout << v[i] << "\n";
		}
	}
}