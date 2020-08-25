#include <iostream>
#include <string>
#include <stack>
using namespace std;
int n, temp, cnt = 1, popped, arr[100001], it = 1;
string s;
stack<int> st;
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	while (popped != n) {
		temp = arr[it];
		while (1) {
			if (st.empty()) {
				st.push(cnt);
				cnt++;
				s += "+\n";
				continue;
			}
			if (st.top() == temp) {
				st.pop();
				popped++;
				s += "-\n";
				//cout << s << "\n";
				break;
			}
			else {
				st.push(cnt);
				cnt++;
				s += "+\n";
			}
			if (s.length() >= 4 * n + 2) {
				cout << "NO";
				return 0;
			}
			//cout << s << "\n";
		}
		it++;
	}
	cout << s;
}