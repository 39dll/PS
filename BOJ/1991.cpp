#include <iostream>
using namespace std;
typedef pair<int, int> p; //왼쪽 자식, 오른쪽 자식
p node[27];
int N;
char in1, in2, in3;
void pre(int root) {
	cout << char(root + 'A' - 1);
	if (node[root].first != int('.' - 'A' + 1)) pre(node[root].first);
	if (node[root].second != int('.' - 'A' + 1)) pre(node[root].second);
}
void in(int root) {
	if (node[root].first != int('.' - 'A' + 1)) in(node[root].first);
	cout << char(root + 'A' - 1);
	if (node[root].second != int('.' - 'A' + 1)) in(node[root].second);
}
void post(int root) {
	if (node[root].first != int('.' - 'A' + 1)) post(node[root].first);
	if (node[root].second != int('.' - 'A' + 1)) post(node[root].second);
	cout << char(root + 'A' - 1);
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> in1 >> in2 >> in3;
		node[in1 - 'A' + 1] = (make_pair(in2 - 'A' + 1, in3 - 'A' + 1));
	}
	pre(1);
	cout << "\n";
	in(1);
	cout << "\n";
	post(1);
}