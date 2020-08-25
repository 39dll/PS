#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, in1, in2, in3;
int ind[1001];
vector<int> e[1001];
queue<int> q, ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> in1;
		cin >> in2;
		in1--;
		while (in1--) {
			cin >> in3;
			e[in2].push_back(in3);
			ind[in3]++;
			in2 = in3;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 0; i < N; i++) {
		if (q.empty()) {
			cout << "0";
			return 0;
		}
		int a = q.front();
		q.pop();
		ans.push(a);
		for (int j = 0; j < e[a].size(); j++) {
			ind[e[a][j]]--;
			if (ind[e[a][j]] == 0)q.push(e[a][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		int a = ans.front();
		cout << a << "\n";
		ans.pop();
	}
}