#include <iostream>
#include <vector>
using namespace std;
vector<int> v[1001];
bool visited[1001];
int N, M, in, in2, cnt;
void search(int a) {
	if (visited[a]) return;
	visited[a] = 1;
	for (int i = 0; i < v[a].size(); i++) {
		search(v[a][i]);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> in >> in2;
		v[in].push_back(in2);
		v[in2].push_back(in);
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;
		search(i);
		cnt++;
	}
	cout << cnt;
}