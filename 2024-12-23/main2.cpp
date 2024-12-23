#include <bits/stdc++.h>
using namespace std;

/*
  0 1 2 3
0 0 1 1 1
1 1 0 1 1
2 1 1 0 1
3 1 1 1 0

*/
int conn[676][676];



int _hash(string s) {
	return (s[0] - 'a') * 26 + (s[1] - 'a');
}

string _rhash(int x) {
	string s = "abcdefghijklmnopqrstuvwxyz";
	return s.substr((x / 26), 1) + s.substr((x % 26), 1);
}

void init() {
	string s;
	
	while (!cin.eof()) {
		getline(cin, s);
		// cout << s.substr(0, 2) << ' ' << s.substr(3, 2) << '\n';
		conn[_hash(s.substr(0, 2))][_hash(s.substr(3, 2))] = 1;
		conn[_hash(s.substr(3, 2))][_hash(s.substr(0, 2))] = 1;
	}
}

int main(int argc, char *argv[]) {
	init();
	int max_size = 0;
	set<int> max_group;
	for (int i = 0; i < 26 * 26; i++) {
		conn[i][i] = 1;
	}

	for (int k = 0; k < 26 * 26; k++) {
		set<int> conn_set;
		set<int> remove_set;
		for (int i = 0; i < 26 * 26; i++) {
			if (conn[k][i])
				conn_set.insert(i);
		}

		for (set<int>::iterator it1 = conn_set.begin(); it1 != conn_set.end(); it1++) {
			int cnt = 0;
			for (set<int>::iterator it2 = conn_set.begin(); it2 != conn_set.end(); it2++) {
				if (conn[*it1][*it2] == 0) {
					cnt++;
				}
			}
			if (cnt > 1) {
				remove_set.insert(*it1);
			}
		}

		for (set<int>::iterator it = remove_set.begin(); it != remove_set.end(); it++) {
			conn_set.erase(*it);
		}
		if (max_size < conn_set.size()) {
			max_size = conn_set.size();
			max_group = conn_set;
		}
	}
	for (set<int>::iterator it = max_group.begin(); it != max_group.end(); it++) {
		cout << _rhash(*it) << ',';
	}
	cout << '\n';
	return 0;
}

/*


 */