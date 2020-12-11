typedef pair<long long, int> p;
const long long INF = 10000000000000;
vector<long long> dijkstra(int start) {
	vector<long long> v(N + 1);
	for (auto &i : v)i = INF;
	priority_queue<p, vector<p>, greater<p>> pq;
	v[start] = 0; pq.push({ 0, start });
	while (!pq.empty()) {
		long long cost, des, next, there;
		tie(cost, des) = pq.top(); pq.pop();
		for (auto k : e[des]) {
			tie(next, there) = k; next += cost;
			if (v[there] > next) {
				v[there] = next;
				pq.push({ next,there });
			}
		}
	}
	return v;
}
