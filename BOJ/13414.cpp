#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
map <string, int> m;
int K, L, cnt = 1, ind;
string input;
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> K >> L;
	for (int i = 1; i <= L; i++) {
		cin >> input;
		m[input] = i;
	}
	vector<pair<int, string> > v;
	for (pair<string, int> a : m) {
		v.push_back({ a.second, a.first });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < min((int)v.size(), K); i++) {
		cout << v[i].second << "\n";
	}
}