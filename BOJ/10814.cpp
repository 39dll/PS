#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
int N, temp;
string str;
typedef tuple<int, string, int> t;
t v[100002];
bool comp(t v1, t v2) {
	if (get<0>(v1) != get<0>(v2)) {
		return get<0>(v1) < get<0>(v2);
	}
	else {
		return get<2>(v1) < get<2>(v2);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp >> str;
		v[i] = make_tuple(temp, str, i);
	}
	sort(v, v + N, comp);
	for (int i = 0; i < N; i++) {
		cout << get<0>(v[i]) << " " << get<1>(v[i]) << "\n";
	}
}