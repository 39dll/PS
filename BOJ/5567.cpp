#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, input1, input2, cnt;
vector<int> v[501];
queue<int> q;
bool visited[501];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> input1 >> input2;
		v[input1].push_back(input2);
		v[input2].push_back(input1);
	}
	visited[1] = 1;
	for (int i = 0; i < v[1].size(); i++) {
		q.push(v[1][i]);
		visited[v[1][i]] = 1;
		cnt++;
	}
	while (!q.empty()) {
		int ind = q.front();
		q.pop();
		for (int i = 0; i < v[ind].size(); i++) {
			if (visited[v[ind][i]] == 0) {
				visited[v[ind][i]] = 1;
				cnt++;
			}
		}
	}
	cout << cnt;
}