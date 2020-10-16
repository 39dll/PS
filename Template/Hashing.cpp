#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
const int EXP = 127;
const long long MOD = 1000000007;
unordered_set<long long> um;
long long fnpow;
//get initial hash for str
long long getHash(string str) {
	long long exp = 1;
	long long curHash = str[(int)str.length() - 1];
	for (int i = (int)str.length() - 2; i >= 0; i--) {
		exp *= EXP;
		exp %= MOD;
		curHash += exp * str[i];
		curHash %= MOD;
	}
	fnpow = exp;
	return curHash;
}
//remove oldChar and add newChar
long long updateHash(long long hash, char oldChar, char newChar, int len) {
	hash -= fnpow * oldChar;
	hash += fnpow * MOD;
	hash %= MOD;
	hash *= EXP;
	hash += newChar;
	hash %= MOD;
	return hash;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	if (str1.length() < str2.length()) {
		cout << 0;
		return 0;
	}
	int len = str2.length();
	um.insert(getHash(str2));
	string temp = str1.substr(0, len);
	long long hash = getHash(temp);
	vector<int> ans;
	for (int i = 0; i < (int)str1.length() - len + 1; i++) {
		if (um.find(hash) != um.end())ans.push_back(i + 1);
		if (i != str1.length() - len)hash = updateHash(hash, str1[i], str1[i + len], len);
	}
	cout << ans.size() << '\n';
	for (int i : ans)cout << i << ' ';
}
