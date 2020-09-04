#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
vector<int> edge[MAX];

//Variables
int sccCnt; //How many SCCs?
vector<vector<int>> SCC; //Stores Vertices of each SCCs

//Operation
int dfscnt;
int dfsn[MAX];
bool finished[MAX];
int sccInd[MAX];
stack<int> s;

int makeSCC(int cur) { //return index cur's SCC number
	dfsn[cur] = ++dfscnt;
	s.push(cur);

	int res = dfsn[cur];
	for (int next : edge[cur]) {
		if (dfsn[next] == 0)res = min(res, makeSCC(next));
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
		//sort(curSCC.begin(), curSCC.end());
		SCC.push_back(curSCC);
		sccCnt++;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int V, E;
		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			int in1, in2;
			cin >> in1 >> in2;
			in1++; in2++;
			edge[in1].push_back(in2);
		}
		for (int i = 1; i <= V; i++)if (dfsn[i] == 0) makeSCC(i);
		//sort(SCC.begin(), SCC.end());
		//cout << sccCnt << '\n';
		/*
		for (auto& curSCC : SCC) {
			for (int cur : curSCC) {
				cout << cur << ' ';
			}
			cout << "\n";
		}
		*/
		int outdegree[MAX] = { 0 };
		for (int i = 1; i <= V; i++) {
			for (int j : edge[i]) {
				if (sccInd[i] != sccInd[j]) {
					outdegree[sccInd[j]]++;
				}
			}
		}
		int ans = 0, ind = 0;
		for (int i = 0; i < sccCnt; i++) {
			if (outdegree[i] == 0) {
				ans++; ind = i;
			}
		}
		if (ans != 1)cout << "Confused\n";
		else {
			for (int i = 1; i <= V; i++) {
				if (sccInd[i] == ind) {
					cout << i - 1 << '\n';
				}
			}
		}
		cout << '\n';
		//Initialize
		while (!s.empty())s.pop();
		dfscnt = 0;
		sccCnt = 0;
		for (int i = 0; i <= V; i++) {
			dfsn[i] = 0;
			finished[i] = 0;
			sccInd[i] = 0;
			edge[i].clear();
		}
	}
}