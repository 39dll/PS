#include <iostream>
#include <vector>
using namespace std;
const int MAX_DEPTH = 10;
int T, in1;
char in[MAX_DEPTH + 1];
struct Node {
	Node* child[MAX_DEPTH];
	bool last; //이 노드를 마지막으로 하는 자료가 존재하는가?
	bool hasChild;
	Node() {
		fill(child, child + MAX_DEPTH, nullptr);
		last = hasChild = 0;
	}
	~Node() {
		for (int i = 0; i < MAX_DEPTH; i++) {
			if (child[i]) delete child[i];
		}
	}
	void insert(const char* key) {
		if (*key == NULL) last = 1;
		else {
			int next = *key - '0';
			if (!child[next])child[next] = new Node;
			hasChild = 1;
			child[next]->insert(key + 1);
		}
	}
	bool check() {
		if (hasChild && last) return 0;
		for (int i = 0; i < MAX_DEPTH; i++) {
			if (child[i] && !child[i]->check()) return 0;
		}
		return 1;
	}
};
int main() {
	cin >> T;
	while (T--) {
		cin >> in1;
		Node *root = new Node;
		for (int i = 0; i < in1; i++) {
			cin >> in;
			root->insert(in);
		}
		if (root->check()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		delete root;
	}
}