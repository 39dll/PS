#include <iostream>
#include <functional>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N, temp, temp2;
		priority_queue<int, vector<int>, less<int> > maxheap;
		priority_queue<int, vector<int>, greater<int> > minheap;
		cin >> N;
		cout << (N + 1) / 2 << '\n';
		while (N--) {
			cin >> temp;
			maxheap.push(temp);
			if (maxheap.size() - 2 == minheap.size()) {
				minheap.push(maxheap.top());
				maxheap.pop();
			}
			if (!minheap.empty()) {
				if (maxheap.top() > minheap.top()) {
					temp = maxheap.top();
					temp2 = minheap.top();
					maxheap.pop(); minheap.pop();
					maxheap.push(temp2); minheap.push(temp);
				}
			}
			if(N%2==0)cout << maxheap.top() << " ";
		}
		cout << '\n';
	}
}