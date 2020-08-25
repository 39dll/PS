#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq, pq2;
vector<int> v;
int N, d, ind, last, in, cnt;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> in;
		v.push_back(in);
	}
	sort(v.begin(), v.end());
	d = v[1] - v[0]; ind = v[0];
	for (int i = 1; i < N; i++) {
		if (ind + d == v[i]) {
			ind = v[i];
			last = v[i];
			continue;
		}
		else {
			cnt++;
		}
		pq.push(v[i]);
	}
	if (cnt == 0 || d == 0) {
		cout << "No";
		return 0;
	}
	pq2 = pq;
	pq.push(last);
	d = -1; ind = v[0];
	if (pq2.empty()) {
		cout << "Yes";
		return 0;
	}
	while (!pq2.empty()) {
		int a = pq2.top();
		//cout << a << " ";
		pq2.pop();
		if (d == -1) {
			d = a - v[0];
			ind = a;
			if (pq2.empty()) {
				cout << "Yes";
				return 0;
			}
			continue;
		}
		else {
			if (ind + d == a) {
				ind = a;
				if (pq2.empty()) {
					cout << "Yes";
					return 0;
				}
				continue;
			}
			else {
				break;
			}
		}
		if (pq2.empty()) {
			cout << "Yes";
			return 0;
		}
	}
	//cout << "\n";
	d = -1; ind = v[0];
	while (!pq.empty()) {
		int a = pq.top();
		//cout << a << " ";
		pq.pop();
		if (d == -1) {
			d = a - v[0];
			ind = a;
			continue;
		}
		else {
			if (ind + d == a) {
				ind = a;
				continue;
			}
			else {
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
}