#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, bool> p;
queue<p> q;
int T, C, P, in1, in2;
vector<int> child[100001];
vector<int> temp[100001];
int par[100001];
bool flag;
long long pop[100001], hap[100001], stackpop[100001];
void find(int ind) {
	for (int i = 0; i < temp[ind].size(); i++) {
		if (par[temp[ind][i]] == 0) {
			par[temp[ind][i]] = ind;
			find(temp[ind][i]);
		}
	}
}
long long calcpop(int ind) {
	stackpop[ind] = pop[ind];
	for (int i = 0; i < child[ind].size(); i++) {
		int newind = child[ind][i];
		stackpop[ind] += calcpop(newind);
	}
	return stackpop[ind];
}
void search() {
	while (!q.empty())q.pop();
	flag = 1;
	if (stackpop[1] == hap[1]) {
		for (int i = 0; i < child[1].size(); i++) {
			if (stackpop[child[1][i]] == -hap[child[1][i]]) {
				q.push({child[1][i], 0});
			}
			else {
				q.push({ child[1][i],1 });
			}
		}
	}
	else {
		for (int i = 0; i < child[1].size(); i++) {
			if (stackpop[child[1][i]] == hap[child[1][i]]) {
				flag = 0;
			}
			else if (stackpop[child[1][i]] != hap[child[1][i]]) {
				q.push({ child[1][i],0 });
			}
			else flag = 0;
		}
	}
	if (flag == 0)return;
	while (!q.empty()) {
		int cur = q.front().first;
		bool happy = q.front().second;
		//cout << "cur = " << cur << "\n";
		//cout << "happy = " << happy << "\n";
		q.pop();
		if (child[cur].size() == 0) {
			if (stackpop[cur] == 0) continue;
			if (stackpop[cur] == hap[cur] && happy == 1) continue;
			if (stackpop[cur] == -hap[cur] && happy == 0) continue;
			flag = 0;
			return;
		}

		if (happy == 1) {
			for (int i = 0; i < child[cur].size(); i++) {
				if (stackpop[child[cur][i]] == -hap[child[cur][i]]) {
					q.push({ child[cur][i], 0 });
				}
				else {
					q.push({ child[cur][i],1 });
				}
			}
		}
		else {
			for (int i = 0; i < child[cur].size(); i++) {
				if (stackpop[child[cur][i]] == hap[child[cur][i]]) {
					flag = 0;
				}
				else if (stackpop[child[cur][i]] != hap[child[cur][i]]) {
					q.push({ child[cur][i],0 });
				}
				else flag = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		for (int i = 0; i <= 100000; i++) {
			pop[i] = hap[i] = stackpop[i] = par[i] = 0;
			temp[i].clear(); child[i].clear();
		}
		cin >> C >> P;
		for (int i = 1; i <= C; i++) {
			cin >> pop[i];
		}
		for (int i = 1; i <= C; i++) {
			cin >> hap[i];
		}
		for (int i = 0; i < C - 1; i++) {
			cin >> in1 >> in2;
			temp[in1].push_back(in2);
			temp[in2].push_back(in1);
		}
		find(1);
		for (int i = 1; i <= C; i++) {
			for (int j = 0; j < temp[i].size(); j++) {
				if (i == 1 || temp[i][j] != par[i])child[i].push_back(temp[i][j]);
			}
		}
		for (int i = 1; i <= C; i++) {
			calcpop(i);
			//cout << "stackpop[" << i << "] = " << stackpop[i] << "\n";
		}
		search();
		if (flag == 1) cout << "YES\n";
		else cout << "NO\n";
	}
}
