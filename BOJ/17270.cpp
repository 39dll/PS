#include <iostream>
#include <utility>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> p; //가중치, 도착점
const int INF = 10000001;
int V, E, K, K0, K1;
int temp1, temp2, temp3;
int v[101], sum[101] = { 0 }, mn = 2100000000, mx = 0;
bool hubo[101] = { 0 };
vector<p> e[101];
priority_queue<p, vector<p>, greater<p> > pq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;
	for (int i = 1; i <= E; i++) {
		cin >> temp1 >> temp2 >> temp3;
		e[min(temp1, temp2)].push_back({ temp3, max(temp2,temp1) });
		e[max(temp1, temp2)].push_back({ temp3, min(temp2,temp1) });
	}
	for (int ii = 0; ii < 2; ii++) {
		cin >> K;
		if (ii == 0) K0 = K;
		else K1 = K;
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
			sum[i] += v[i];
			if (i == K) sum[i] = 99999999;
		}
	}
	for (int i = 1; i <= V; i++) {
		mn = min(mn, sum[i]);
	}
	for (int i = 1; i <= V; i++) {
		if(sum[i] == mn) mx = max(mx, v[i]);
		if (sum[i] == mn && sum[i] != INF && sum[i] <= v[i] * 2) {
			hubo[i] = 1;
		}
		if (i == K0 || i == K1) hubo[i] = 0;
	}
	for (int i = 1; i <= V; i++) {
		if (hubo[i] == 1) {
			if (mx == v[i]) {
				cout << i; return 0;
			}
		}
	}
	cout << "-1"; return 0;
}