#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 10001;
int V, E;
vector<int> edge[MAX];

//Operation
int cnt, dfsn[MAX], sccCnt, sccInd[MAX];
bool finished[MAX];
stack<int> s;
vector<vector<int>> SCC;

int dfs(int cur) { //return index cur's SCC number
	dfsn[cur] = ++cnt;
	s.push(cur);

	int res = dfsn[cur];
	for (int next : edge[cur]) {
		if (dfsn[next] == 0)res = min(res, dfs(next));
		else if (finished[next] == 0) res = min(res, dfsn[next]);
	}

	if (res == dfsn[cur]) {
		vector<int> curSCC;
		while (1) {
			int t = s.top();
			s.pop();
			curSCC.push_back(t);
			finished[t] = true;
			sccInd[t] = sccCnt;
			if (t == cur) break;
		}
		sort(curSCC.begin(), curSCC.end());
		SCC.push_back(curSCC);
		sccCnt++;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int in1, in2;
		cin >> in1 >> in2;
		edge[in1 - 1].push_back(in2 - 1);
	}
	for (int i = 0; i < V; i++)if (dfsn[i] == 0) dfs(i);
	sort(SCC.begin(), SCC.end());
	cout << sccCnt << '\n';
	for (auto& curSCC : SCC) {
		for (int cur : curSCC) {
			cout << cur + 1 << ' ';
		}
		cout << "-1\n";
	}
}