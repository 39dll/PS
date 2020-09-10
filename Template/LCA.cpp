#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
const int MAXDEP = 18;//more than log(2, 100000)
int N, M;
int par[MAX][MAXDEP];//par[i][k] : i의 2^k번째 부모
int dep[MAX];
vector<int> edge[MAX];
void makeTree(int cur) {
	for (int next : edge[cur]) {
		if (dep[next] == -1) {
			par[next][0] = cur;
			dep[next] = dep[cur] + 1;
			makeTree(next);
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int in1, in2;
		cin >> in1 >> in2;
		in1--; in2--;
		edge[in1].push_back(in2);
		edge[in2].push_back(in1);
	}
	memset(par, -1, sizeof(par));
	fill(dep, dep + N, -1);
	dep[0] = 0;
	makeTree(0);
	for (int j = 0; j < MAXDEP - 1; j++) {
		for (int i = 1; i < N; i++) {
			if (par[i][j] != -1) {
				par[i][j + 1] = par[par[i][j]][j];
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int in1, in2;
		cin >> in1 >> in2;
		in1--; in2--;
		if (dep[in1] < dep[in2])swap(in1, in2);
		int dif = dep[in1] - dep[in2];

		for (int j = 0; dif; j++) {
			if (dif % 2)in1 = par[in1][j];
			dif /= 2;
		}
		if (in1 != in2) {
			for (int j = MAXDEP - 1; j >= 0; j--) {
				if (par[in1][j] != -1 && par[in1][j] != par[in2][j]) {
					in1 = par[in1][j];
					in2 = par[in2][j];
				}
			}
			in1 = par[in1][0];
		}
		cout << in1 + 1 << '\n';
	}
}
