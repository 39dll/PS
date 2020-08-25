#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
long long cur;
bool neg, fl = 1;
deque<long long> n;
deque<char> o;
bool comp(char l, char r) {
	int lw = 1, rw = 1, sz = n.size();
	if (l == '+' || l == '-') lw = 0;
	if (r == '+' || r == '-') rw = 0;
	if (lw != rw) return lw > rw;
	long long p = 0, q = 0;
	switch (l) {
	case '+': p = n[0] + n[1]; break;
	case '-': p = n[0] - n[1]; break;
	case '*': p = n[0] * n[1]; break;
	case '/': p = n[0] / n[1]; break;
	}
	switch (r) {
	case '+': q = n[sz - 2] + n[sz - 1]; break;
	case '-': q = n[sz - 2] - n[sz - 1]; break;
	case '*': q = n[sz - 2] * n[sz - 1]; break;
	case '/': q = n[sz - 2] / n[sz - 1]; break;
	}
	return p >= q;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	char in;
	while (cin >> in) {
		if (fl && in == '-') {
			neg = 1;
			fl = 0;
			continue;
		}
		fl = 0;
		if ('0' <= in && in <= '9') {
			cur *= 10;
			cur += (long long)in - '0';
		}
		else {
			n.push_back(cur);
			cur = 0;
			o.push_back(in);
		}
	}n.push_back(cur);
	if (neg) {
		long long temp = n.front();
		n.pop_front();
		temp *= -1;
		n.push_front(temp);
	}
	while (!o.empty()) {
		if (comp(o.front(), o.back())) {
			char curOp = o.front(); o.pop_front();
			long long cur = n.front(); n.pop_front();
			switch (curOp) {
			case '+':cur += n.front(); break;
			case '-':cur -= n.front(); break;
			case '*':cur *= n.front(); break;
			case '/':cur /= n.front(); break;
			}
			n.pop_front();
			n.push_front(cur);
		}
		else {
			char curOp = o.back(); o.pop_back();
			long long cur = n.back(); n.pop_back();
			switch (curOp) {
			case '+':cur += n.back(); break;
			case '-':cur = n.back() - cur; break;
			case '*':cur *= n.back(); break;
			case '/':cur = n.back() / cur; break;
			}
			n.pop_back();
			n.push_back(cur);
		}
	}
	cout << n.front();
}