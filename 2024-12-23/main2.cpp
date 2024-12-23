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
	cout << 'z' - 'a' << '\n';
	// for (int k = 0; k < 26 * 26; k++) {
		vector<int> tmp;
		for (int i = 0; i < 26 * 26; i++) {
			conn[i][i] = 1;
			if (conn[_hash("uy")][i])
				tmp.push_back(i);
		
		}

		for (int i: tmp) {
			cout << _rhash(i) << ',';
		}
		// for (int i: tmp) {
		// 	for (int j: tmp) {
		// 		cout << conn[i][j];
		// 	}
		// 	cout << '\n';
		// }
		// cout << '\n';
	// }
	// for (int i = 0; i < 26 * 26; i++) {
	// 	for (int j = 0; j < 26 * 26; j++) {
	// 		cout << conn[i][j];
	// 	}
	// 	cout << '\n';
	// }
	return 0;
}

/*


 */