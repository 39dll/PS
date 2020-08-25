#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> child[1000001];
vector<int> edge[1000001];
int par[1000001];
bool early[1000001];
int dep[1000001];
int ans;
void findPar(int ind, vector<int> edge[]) {
	for (int i = 0; i < edge[ind].size(); i++) {
		if (par[edge[ind][i]] == 0) {
			par[edge[ind][i]] = ind;
			findPar(edge[ind][i], edge);
		}
	}
}
void treeInput(int N, int root) {
	int in1, in2;
	for (int i = 1; i < N; i++) {
		cin >> in1 >> in2;
		edge[in1].push_back(in2);
		edge[in2].push_back(in1);
	}
	findPar(root, edge);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < edge[i].size(); j++) {
			if (i == root || edge[i][j] != par[i])child[i].push_back(edge[i][j]);
		}
	}
}
void search(int ind) {
	bool k = 1;
	int childCnt = child[ind].size();
	if (childCnt == 0) return;
	for (int i = 0; i < childCnt; i++) {
		int next = child[ind][i];
		search(next);
	}
	for (int i = 0; i < childCnt; i++) {
		int next = child[ind][i];
		k *= early[next];
		if (k == 0) break;
	}
	if (k == 0) {
		early[ind] = 1;
		ans++;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	treeInput(N, 1);
	search(1);
	cout << ans;
}