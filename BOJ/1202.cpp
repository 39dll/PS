#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, K, i1, i2, ind;
long long cnt;
vector<pair<int, int> > v;
vector<int> v2;
priority_queue<int> pq;
bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) {
		return a.first < b.first;
	}
	else {
		return a.second > b.second;
	}
}
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> i1 >> i2;
		v.push_back({ i1,i2 });
	}
	for (int i = 0; i < K; i++) {
		cin >> i1;
		v2.push_back(i1);
	}
	sort(v.begin(), v.end(), comp);
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v2.size(); i++) {
		while (ind < v.size() && v[ind].first <= v2[i]) {
			pq.push(v[ind].second);
			ind++;
		}
		if (!pq.empty()) {
			cnt += pq.top();
			pq.pop();
		}
	}
	cout << cnt;
}