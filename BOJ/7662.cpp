#include <iostream>
#include <map>
using namespace std;
map<long long, int> m;
int T, k, in2;
char in;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> k;
		while (k--) {
			cin >> in;
			if (in == 'I') {
				cin >> in2;
				m[in2]++;
			}
			else {
				cin >> in2; 
				if (m.empty()) {
					continue;
				}
				if (in2 == 1) {
					auto ind = m.rbegin();
					if (m[ind->first] == 1) {
						m.erase(ind->first);
					}
					else {
						m[ind->first]--;
					}
				}
				else {
					auto ind = m.begin();
					if (m[ind->first] == 1) {
						m.erase(ind->first);
					}
					else {
						m[ind->first]--;
					}
				}
			}
		}
		if (m.empty()) {
			cout << "EMPTY\n";
		}
		else {
			auto ind = m.rbegin();
			cout << ind->first << " ";
			auto ind2 = m.begin();
			cout << ind2->first << "\n";
		}
		m.clear();
	}
}