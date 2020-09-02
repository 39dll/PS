#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, root, qcnt;
vector<int> child[100001];
vector<int> edge[100001];
int par[100001];
int dp[100001];
void findPar(int ind) {
	for (int next : edge[ind]) {
		if (!par[next]) {
			par[next] = ind;
			findPar(next);
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
	findPar(root);
	for (int i = 1; i <= N; i++) {
		if (i == root) {
			for (int next : edge[i]) {
				child[i].push_back(next);
			}
		}
		else for (int next : edge[i]) {
			if (next != par[i]) {
				child[i].push_back(next);
			}
		}
	}
}
void search(int ind) {
	int sum = 1;
	for (int i = 0; i < child[ind].size(); i++) {
		int next = child[ind][i];
		search(next);
		sum += dp[next];
	}
	dp[ind] = sum;
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> root >> qcnt;
	treeInput(N, root);
	search(root);
	while (qcnt--) {
		int in;
		cin >> in;
		cout << dp[in] << '\n';
	}
}