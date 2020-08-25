#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
bool compare(pair<int, int> &a, pair<int, int> &b) {
	return (a.second < b.second);
}
int main() {
	int N, a, b, c = 1, m;
	vector<pair <int, int> > v;
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	sort(v.begin(), v.end(), compare);
	m = v[0].second;
	for (int i = 1; i < N; i++) {
		if (v[i].first >= m) {
			m = v[i].second;
			c++;
		}
	}
	cout << c;
	return 0;
}