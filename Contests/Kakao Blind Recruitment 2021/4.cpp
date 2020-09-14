#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> p;
const long long INF = 10000000000000;
int V, E, K;
long long v[201];
vector<p> e[201];

void init() {
	for (int i = 1; i <= V; i++) {
		v[i] = INF;
	}
}

long long dijkstra(int start, int end) {
	init();
	priority_queue<p, vector<p>, greater<p> > pq;
	v[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		long long cost = pq.top().first;
		int des = pq.top().second;
        if(des==end)return v[end];
		pq.pop();
		if (v[des] < cost) continue;
		for (int i = 0; i < e[des].size(); i++) {
			int there = e[des][i].second;
			long long next = cost + e[des][i].first;
			if (v[there] > next) {
				v[there] = next;
				pq.push({ next,there });
			}
		}
	}
	return v[end];
}



int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    V = n;
    for(int i=0;i<fares.size();i++){
        long long in1, in2, in3;
        in1 = fares[i][0];
        in2 = fares[i][1];
        in3 = fares[i][2];
        e[in1].push_back({in3,in2});
        e[in2].push_back({in3,in1});
    }
    long long answer = INF;
    
    for(int i=1;i<=n;i++){
        answer = min(answer, dijkstra(s,i)+dijkstra(i,a)+dijkstra(i,b));
    }
    
    return answer;
}