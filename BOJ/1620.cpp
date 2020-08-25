#include <iostream>
#include <map>
#include <string>
using namespace std;
int N, M;
map<string, int> m;
map<int, string> m2;
string in;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> in;
		m[in] = i;
		m2[i] = in;
	}
	for (int i = 1; i <= M; i++) {
		cin >> in;
		if (in[0] >= '0' && in[0] <= '9') {
			cout << m2[stoi(in)] << "\n";
		}
		else {
			cout << m[in] << "\n";
		}
	}
}