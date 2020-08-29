#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> child[100001];
vector<int> edge[100001];
int par[100001];
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
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	treeInput(N, 1);
	for (int i = 2; i <= N; i++) cout << par[i] << "\n";
}