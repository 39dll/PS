#include <iostream>
using namespace std;
typedef pair<int, int> p; //왼쪽 자식, 오른쪽 자식
p node[10000001];
int key[100001], temp, iter = 1, head = 0;
void search(int start, int end) {
	if (start == end) {
		node[key[start]] = make_pair(0, 0);
		return;
	}
	int ind = start;
	int root = key[start];
	bool left_exist = (key[start] > key[start + 1]);
	bool right_exist = 0;
	for (int i = start + 1; i <= end; i++) {
		if (key[i] > key[start]) {
			right_exist = 1;
			ind = i;
			break;
		}
	}
	if (left_exist && right_exist) {
		node[key[start]] = make_pair(key[start + 1], key[ind]);
		search(start + 1, ind - 1);
		search(ind, end);
	}
	else if (left_exist) {
		node[key[start]] = make_pair(key[start + 1], 0);
		search(start + 1, end);
	}
	else if (right_exist) {
		node[key[start]] = make_pair(0, key[ind]);
		search(start + 1, end);
	}
}
void huwi(int root) {
	if (node[root].first != 0) huwi(node[root].first);
	if (node[root].second != 0) huwi(node[root].second);
	cout << root << "\n";
}
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	while (cin >> temp) {
		key[iter] = temp; iter++;
		if (head == 0) head = temp;
	}
	search(1, iter);
	huwi(head);
}