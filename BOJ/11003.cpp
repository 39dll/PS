#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int N, L, in;
typedef pair<int, int> p;
priority_queue < p, vector<p>, greater<p> > pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> in;
		pq.push({ in,i });
		while (pq.top().second <= i - L) pq.pop();
		cout << pq.top().first << " ";
	}
}