#include <iostream>
using namespace std;
int parent[1000001];
int N, M, root;
int input;
int find(int a) {
	if (a == parent[a]) return a;
	int k = find(parent[a]);
	parent[a] = k;
	return k;
}
void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		parent[b] = a;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input;
			if (input == 1) {
				unite(i, j);
			}
		}
	}
	cin >> input;
	root = find(input);
	for (int i = 2; i <= M; i++) {
		cin >> input;
		if (find(input) != root) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}