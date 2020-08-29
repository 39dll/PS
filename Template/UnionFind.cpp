#include <iostream>
using namespace std;
int uf[10001];
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
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 10000; i++) { //초기화
		uf[i] = i;
	}
}