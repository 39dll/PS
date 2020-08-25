#include <iostream>
using namespace std;
int p[100001], G, P, g, cnt = 0;
int find(int a) {
	if (p[a] == a) return a;
	int k = find(p[a]);
	p[a] = k;
	return k;
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		p[b] = a;
	}
}
int main() {
	cin >> G >> P;
	for (int i = 1; i <= G; i++) {
		p[i] = i;
	}
	for (int i = 1; i <= P; i++) {
		cin >> g;
		if (!find(g)) break;
		cnt++;
		g = find(g);
		merge(g - 1, g);
	}
	cout << cnt;
}