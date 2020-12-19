typedef pair<long long, long long> line;
struct LiChao {
	long long f(line l, long long x) {
		return l.first * x + l.second;
	}
	struct Node {
		int lnode, rnode;
		long long xl, xr;
		line l;
	};
	vector<Node> nodes;
	LiChao() { init(-1e9, 1e9); }
	void init(long long xmin, long long xmax) {
		nodes.push_back({ -1,-1,xmin,xmax,{0,-1e18} });
	}
	void insert(line newline) { insert(0, newline); }
	long long get(long long xq) { get(0, xq); }
	void insert(int n, line newline) {
		long long xl = nodes[n].xl, xr = nodes[n].xr;
		long long xm = (xl + xr) / 2;
		line llow = nodes[n].l, lhigh = newline;
		if (f(llow, xl) >= f(lhigh, xl))swap(llow, lhigh);
		if (f(llow, xr) <= f(lhigh, xr)) {
			nodes[n].l = lhigh; return;
		}
		else if (f(llow, xm) <= f(lhigh, xm)) {
			nodes[n].l = lhigh;
			if (nodes[n].rnode == -1) {
				nodes[n].rnode = nodes.size();
				nodes.push_back({ -1,-1,xm + 1,xr,{0,-1e18} });
			}
			insert(nodes[n].rnode, llow);
		}
		else {
			nodes[n].l = llow;
			if (nodes[n].lnode == -1) {
				nodes[n].lnode = nodes.size();
				nodes.push_back({ -1,-1,xl,xm,{0,-1e18} });
			}
			insert(nodes[n].lnode, lhigh);
		}
	}
	long long get(int n, long long xq) {
		if (n == -1)return -1e18;
		long long xl = nodes[n].xl, xr = nodes[n].xr;
		long long xm = (xl + xr) / 2;
		if (xq <= xm)return max(f(nodes[n].l, xq), get(nodes[n].lnode, xq));
		else return max(f(nodes[n].l, xq), get(nodes[n].rnode, xq));
	}
};
