#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> p; //가중치, 도착점
const long long INF = 10000000000000;
int V, E, K;
long long v[20001];
vector<p> e[20001];
void init() {
	for (int i = 1; i <= V; i++) {
		v[i] = INF;
	}
}
void dijkstra(int start) {
	init();
	priority_queue<p, vector<p>, greater<p> > pq;
	v[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int des = pq.top().second;
		pq.pop();
		if (v[des] < cost) continue;
		for (int i = 0; i < e[des].size(); i++) {
			int there = e[des][i].second;
			int next = cost + e[des][i].first;
			if (v[there] > next) {
				v[there] = next;
				pq.push({ next,there });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E >> K;
	for (int i = 1; i <= E; i++) {
		long long in1, in2, in3;
		cin >> in1 >> in2 >> in3;
		e[in1].push_back({ in3, in2 });
	}
	dijkstra(K);
	for (int i = 1; i <= V; i++) {
		if (v[i] == INF) cout << "INF\n";
		else cout << v[i] << "\n";
	}
}