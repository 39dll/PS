#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
int N, cnt, p1 = -1000000001, p2 = -1000000001, i1, i2;
vector<p> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> i1 >> i2;
		v.push_back({ min(i1, i2), max(i1, i2) });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		if (v[i].first > p2) {
			cnt += p2 - p1;
			p1 = v[i].first;
			p2 = v[i].second;
		}
		else {
			p2 = max(p2, v[i].second);
		}
	}
	cnt += p2 - p1;
	cout << cnt;
}