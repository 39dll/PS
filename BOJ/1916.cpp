#include <iostream>
#include <utility>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> p; //가중치, 도착점
const long long INF = 2100000000000000;
long long V, E, K, K2;
long long temp1, temp2, temp3;
long long v[1001];
vector<p> e[1001];
priority_queue<p, vector<p>, greater<p> > pq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;
	for (int i = 1; i <= E; i++) {
		cin >> temp1 >> temp2 >> temp3;
		e[temp1].push_back({ temp3, temp2 });
	}
	for (int i = 1; i <= V; i++) {
		v[i] = INF;
	}
	cin >> K >> K2;
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
	cout << v[K2];
}