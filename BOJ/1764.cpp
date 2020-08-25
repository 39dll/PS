#include <iostream>
#include <map>
#include <string>
using namespace std;
int N, M;
map<string, int> m, m2;
string in;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> in;
		m[in] = 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> in;
		if (m[in])m2[in] = 1;
	}
	cout << m2.size() << "\n";
	for (auto i = m2.begin(); i != m2.end(); i++) {
		if (i->second) cout << i->first << "\n";
	}
}