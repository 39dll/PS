#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> t;
typedef unsigned long long ull;
vector<int> temp[300001];
int par[300001];
vector<int> child[300001];
t depsib[300001];
int N, u, v, root;
ull D, G;
ull nCthree(ull n) {
	n -= 2;
	return n*(n + 1)*(n + 2) / 6;
}
void find(int ind) { //ind의 자식을 찾아 ind를 부모로 설정
	for (int i = 0; i < temp[ind].size(); i++) {
		if (par[temp[ind][i]] == 0) {
			par[temp[ind][i]] = ind;
			find(temp[ind][i]);
		}
	}
}
void search(int a) {
	if (child[a].size() == 0) {
		depsib[a] = { 0,0,0 };
		return;
	}
	for (int i = 0; i < child[a].size(); i++) {
		search(child[a][i]);
	}
	int sum1, sum2 = 0, sum3 = 0;
	sum1 = child[a].size();
	for (int i = 0; i < child[a].size(); i++) {
		int ch = child[a][i];
		sum2 += get<0>(depsib[ch]);
		sum3 += get<1>(depsib[ch]);
	}
	depsib[a] = { sum1, sum2, sum3 };
	if (sum2 != 0) {
		D += sum2 * (sum1 - 1);
		D += sum3;
	}
	if (sum1 >= 2) {
		if (a == root) {
			if (sum1 >= 3)G += nCthree(sum1);
		}
		else {
			G += nCthree(sum1 + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		if (root == 0)root = u;
		temp[u].push_back(v);
		temp[v].push_back(u);
	}
	find(root);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < temp[i].size(); j++) {
			if (i == root || temp[i][j] != par[i])child[i].push_back(temp[i][j]);
		}
	}
	search(root);
	//cout << D << " " << G << "\n";
	if (D > 3 * G) cout << "D";
	if (D < 3 * G) cout << "G";
	if (D == 3 * G) cout << "DUDUDUNGA";
}