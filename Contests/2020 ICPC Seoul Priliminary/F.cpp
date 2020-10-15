#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[500001];
pair<int, int> d;
bool ps[4] = { 1,1,1,1 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i].second >> p[i].first;
	}
	cin >> d.second >> d.first;
	for (int i = 0; i < N; i++) {
		if (ps[0] == 1) {
			if (p[i].first <= d.first) {
				if (p[i].second == d.second)ps[0] = 0;
				else if (p[i].second > d.second) {
					if (p[i].second - d.second <= d.first - p[i].first)ps[0] = 0;
				}
				else {
					if (d.second - p[i].second <= d.first - p[i].first)ps[0] = 0;
				}
			}
		}
		if (ps[1] == 1) {
			if (p[i].first >= d.first) {
				if (p[i].second == d.second)ps[1] = 0;
				else if (p[i].second > d.second) {
					if (p[i].second - d.second <= -d.first + p[i].first)ps[1] = 0;
				}
				else {
					if (d.second - p[i].second <= -d.first + p[i].first)ps[1] = 0;
				}
			}
		}
		if (ps[2] == 1) {
			if (p[i].second <= d.second) {
				if (p[i].first == d.first)ps[2] = 0;
				else if (p[i].first > d.first) {
					if (p[i].first - d.first <= d.second - p[i].second)ps[2] = 0;
				}
				else {
					if (d.first - p[i].first <= d.second - p[i].second)ps[2] = 0;
				}
			}
		}
		if (ps[3] == 1) {
			if (p[i].second >= d.second) {
				if (p[i].first == d.first)ps[3] = 0;
				else if (p[i].first > d.first) {
					if (p[i].first - d.first <= -d.second + p[i].second)ps[3] = 0;
				}
				else {
					if (d.first - p[i].first <= -d.second + p[i].second)ps[3] = 0;
				}
			}
		}
	}
	cout << ((ps[0] + ps[1] + ps[2] + ps[3] == 0) ? "NO" : "YES");
}
