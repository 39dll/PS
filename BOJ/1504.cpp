#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> p; //가중치, 도착점
int N, E, a, b, c, v1, v2;
int des;
long long D[5];
int v[801] = { 0 };
vector<p> e[801];
priority_queue<p, vector<p>, greater<p> > pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> E;
	for (int i = 1; i <= E; i++) {
		cin >> a >> b >> c;
		e[max(a, b)].push_back({ c, min(a, b) });
		e[min(a, b)].push_back({ c, max(a, b) });
	}
	cin >> v1 >> v2;
	for (int ii = 0; ii < 5; ii++) {
		for (int i = 1; i <= N; i++) {
			v[i] = 2100000000;
		}
		switch (ii) {
		case 0:
			v[1] = 0;
			pq.push({ 0,1 });
			des = v1;
			break;
		case 1:
			v[1] = 0;
			pq.push({ 0,1 });
			des = v2;
			break;
		case 2:
			v[v1] = 0;
			pq.push({ 0, v1 });
			des = v2;
			break;
		case 3:
			v[v1] = 0;
			pq.push({ 0, v1 });
			des = N;
			break;
		case 4:
			v[v2] = 0;
			pq.push({ 0, v2 });
			des = N;
			break;
		}
		while (!pq.empty()) {
			int cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (v[cur] < cost) continue;
			for (int i = 0; i < e[cur].size(); i++) {
				int newcost = e[cur][i].first + cost;
				int next = e[cur][i].second;
				if (v[next] > newcost) {
					v[next] = newcost;
					pq.push({ newcost, next });
				}
			}
		}
		D[ii] = v[des];
	}
	if (D[2] + min(D[0] + D[4], D[1] + D[3]) >= 2100000000) cout << -1;
	else cout << D[2] + min(D[0] + D[4], D[1] + D[3]);
}