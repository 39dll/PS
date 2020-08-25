#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> m;
int parent[100001] = { 0 };
int cnt[100001] = { 0 };
int T, F;
int key = 1;
string input1, input2;
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
		cnt[a] += cnt[b];
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> F;
		for (int i = 1; i <= F; i++) {
			cin >> input1 >> input2;
			if (m[input1] == 0) {
				m[input1] = key;
				parent[key] = key;
				cnt[key] = 1;
				key++;
			}
			if (m[input2] == 0) {
				m[input2] = key;
				parent[key] = key;
				cnt[key] = 1;
				key++;
			}
			unite(m[input1], m[input2]);
			cout << cnt[find(m[input1])] << "\n";
		}
		key = 1;
		m.clear();
	}
}