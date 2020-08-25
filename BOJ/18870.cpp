#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, in;
vector<int> v1, v2;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> in;
		v1.push_back(in);
		v2.push_back(in);
	}
	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());
	for (auto& i : v1) {
		auto ind = lower_bound(v2.begin(), v2.end(), i) - v2.begin();
		cout << ind << " ";
	}
}