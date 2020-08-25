#include <iostream>
#include <utility>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> p; //가중치, 도착점
const int INF = 2100000000;
int V, E, K;
int temp1, temp2, temp3;
int v[20001];
vector<p> e[20001];
priority_queue<p, vector<p>, greater<p> > pq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E >> K;
	for (int i = 1; i <= E; i++) {
		cin >> temp1 >> temp2 >> temp3;
		e[temp1].push_back({ temp3, temp2 });
	}
	for (int i = 1; i <= V; i++) {
		v[i] = INF;
	}
	v[K] = 0;
	pq.push({ 0, K });
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
		if (v[i] == INF) cout << "INF\n";
		else cout << v[i] << "\n";
	}
}