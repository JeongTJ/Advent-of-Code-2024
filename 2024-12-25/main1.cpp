#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> keys;
vector<vector<int>> locks;


void init() {
	string s;
	bool is_key = false;
	bool is_check = true;
	vector<int> temp = {0, 0, 0, 0, 0};

	while (!cin.eof()) {
		getline(cin, s);
		// cout << "s: " << s << '\n';
		if (s == "") {
			if (is_key) {
				keys.push_back(temp);
			} else {
				locks.push_back(temp);
			}
			for (int i = 0; i < 5; i++) {
				temp[i] = 0;
			}
			is_check = true;
			continue;
		}
		if (is_check) {
			if (s == "#####") {
				is_key = false;
			} else {
				is_key = true;
			}
			is_check = false;
		}
		for (int i = 0; i < 5; i++) {
			if (s[i] == '#') {
				temp[i]++;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	init();
	int cnt = 0;
	bool is_right = true;

	for (int lock_idx = 0; lock_idx < locks.size(); lock_idx++) {
		for (int key_idx = 0; key_idx < keys.size(); key_idx++) {
			is_right = true;
			for (int i = 0; i < 5; i++) {
				if (locks[lock_idx][i] + keys[key_idx][i] > 7) {
					is_right = false;
				}
			}
			if (is_right) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}