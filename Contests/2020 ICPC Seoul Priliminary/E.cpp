#include <bits/stdc++.h>
using namespace std;
int uf[500002];
int find(int a) {
	if (uf[a] == a) return a;
	return uf[a] = find(uf[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) uf[b] = a;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M; cin >> N >> M;
	for (int i = 0; i <= N; i++)uf[i] = i;
	for (int i = 0; i < M; i++) {
		int in1, in2;
		cin >> in1 >> in2;
		in1++; in2++;
		if (find(in1) == find(in2)) {
			cout << i + 1;
			return 0;
		}
		merge(in1, in2);
	}
	cout << 0;
}
