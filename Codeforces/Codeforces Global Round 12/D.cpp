#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int getnum() {
	int num = 0, ch;
	while ((ch = getchar()) != ' ') {
		if (ch == '\n')break;
		else num = num * 10 + ch - '0';
	}
	return num;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; T = getnum();
	while (T--) {

		int N; N = getnum();
		vector<int> v(N);
		for (auto &i : v)i = getnum();

		auto good = [&](vector<int> v) -> bool {
			bool gd = 1;
			int tot = 0;
			int sz = v.size();
			if (sz == 1 && v[0] == 1)return 1;
			set<int> cnt;
			for (int i = 0; i < sz; i++) {
				cnt.insert(v[i]);
			}
			return (cnt.size() == sz && *cnt.begin() == 1 && *--cnt.end() == sz);
		};
		auto bsearch = [&](int mid) -> vector<int> {
			deque<pair<int, int>>dq;
			vector<int> ans;
			for (int i = 0; i < N; i++) {
				if (!dq.empty() && dq.front().second <= i - mid)dq.pop_front();
				while (!dq.empty() && dq.back().first > v[i])dq.pop_back();
				dq.push_back({ v[i],i });
				if (i >= mid - 1) ans.push_back(dq.front().first);
			}
			return ans;
		};

		int ans = 300001;
		bool fs = good(bsearch(1));
		int st = 2, en = N;
		while (st <= en) {
			int mid = (st + en) / 2;
			bool gd = good(bsearch(mid));
			if (gd) {
				ans = mid;
				en = mid - 1;
			}
			else {
				st = mid + 1;
			}
		}
		if (ans == 300001) {
			if (fs) {
				cout << '1';
				for (int i = 1; i < N; i++) {
					cout << '0';
				}cout << '\n';
			}
			else {
				for (int i = 0; i < N; i++) {
					cout << '0';
				}cout << '\n';
			}
		}
		else {
			if (fs) {
				cout << '1';
				for (int i = 1; i < ans - 1; i++) {
					cout << '0';
				}
				for (int i = ans - 1; i < N; i++) {
					cout << '1';
				}cout << '\n';
			}
			else {
				cout << '0';
				for (int i = 1; i < ans - 1; i++) {
					cout << '0';
				}
				for (int i = ans - 1; i < N; i++) {
					cout << '1';
				}cout << '\n';
			}
		}
	}
}
