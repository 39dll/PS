typedef pair<ll, int> p;
const ll INF = 10000000000000000;

auto dijkstra = [&](int start, vector<p> e[]) -> vector<ll>{
		vector<ll> v(N + 1);
		for (auto &i : v)i = INF;
		priority_queue<p, vector<p>, greater<p>> pq;
		v[start] = 0; pq.push({ 0, start });
		while (!pq.empty()) {
			ll cost, des, next, there;
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
	};
