#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;
vector<int> v[202];
unordered_map<string, int> um;
bool good[202];
int uf[202];
int find(int a) {
	if (a == uf[a]) return a;
	int k = find(uf[a]);
	return uf[a] = k;
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		uf[b] = a;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int t = 1; t <= N; t++) {
		int M;
		cin >> M;
		um.clear();
		for (int i = 0; i < 202; i++) {
			v[i].clear();
			uf[i] = i;
		}
		memset(good, 0, sizeof(good));
		string in1, in2;
		int cnt = 1;
		for (int i = 0; i < M; i++) {
			cin >> in1 >> in2;
			if (um[in1] == 0) {
				um[in1] = cnt;
				cnt++;
			}
			if (um[in2] == 0) {
				um[in2] = cnt;
				cnt++;
			}
			v[um[in1]].push_back(um[in2]);
			v[um[in2]].push_back(um[in1]);
		}
		for (int i = 1; i < cnt; i++) {
			for (int j = 0; j < v[i].size() - 1; j++) {
				merge(v[i][j], v[i][j + 1]);
			}
		}
		for (int i = 1; i < cnt; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (find(i) == find(v[i][j])) {
					goto no;
				}
			}
		}


		cout << "Case #" << t << ": Yes\n";
		continue;
	no:
		cout << "Case #" << t << ": No\n";
	}
}