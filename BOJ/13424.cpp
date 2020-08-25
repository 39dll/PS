#include <iostream>
#include <utility>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> p; //가중치, 도착점
const int INF = 1000000;
int T, V, E, K, start;
int temp1, temp2, temp3;
int v[101];
vector<p> e[5501];
int sum[5501] = { 0 }, mn = INF, index;
priority_queue<p, vector<p>, greater<p> > pq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> V >> E;
		for (int i = 1; i <= E; i++) {
			cin >> temp1 >> temp2 >> temp3;
			e[min(temp1, temp2)].push_back({ temp3, max(temp1, temp2) });
			e[max(temp1, temp2)].push_back({ temp3, min(temp1, temp2) });
		}
		cin >> K;
		while (K--) {
			cin >> start;
			for (int i = 1; i <= V; i++) {
				v[i] = INF;
			}
			v[start] = 0;
			pq.push({ 0, start });
			while (!pq.empty()) {
				int gj = pq.top().first;
				int des = pq.top().second;
				pq.pop();
				if (v[des] < gj) continue;
				for (int i = 0; i < e[des].size(); i++) {
					int there = e[des][i].second;
					int next = gj + e[des][i].first;
					if (v[there] > next) {
						v[there] = next;
						pq.push({ next,there });
					}
				}
			}
			for (int i = 1; i <= V; i++) {
				sum[i] += v[i];
			}
		}
		for (int i = 1; i <= V; i++) {
			if (sum[i] != INF) {
				if (sum[i] < mn) index = i;
				mn = min(mn, sum[i]);
				e[i].clear();
			}
		}
		cout << index << "\n";
		mn = INF; index = 0;
		for (int i = 0; i <= V; i++) {
			sum[i] = 0;
		}
	}
}