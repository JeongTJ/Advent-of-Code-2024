#include <bits/stdc++.h>
using namespace std;

map<char, vector<pair<int, int>>> m;
vector<vector<char>> arr;
vector<vector<char>> arr_antena;

void init_arr() {
	string s;

	while (!cin.eof()) {
		getline(cin, s);

		vector<char> temp;

		for (char c: s) {
			temp.push_back(c);
		}
		arr.push_back(temp);
	}
}

void init_map() {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (arr[i][j] != '.') {
				m[arr[i][j]].push_back({i, j});
			}
		}
	}
}

void make_antena() {
	arr_antena = vector<vector<char>>(arr.size(), vector<char>(arr[0].size(), '.'));
	for (auto it = m.begin(); it != m.end(); it++) {
		vector<pair<int, int>> &coors = it->second;
		for (int i = 0; i < coors.size(); i++) {
			for (int j = 0; j < coors.size(); j++) {
				if (i == j) continue;
				int new_y, new_x;
				new_y = coors[j].first * 2 - coors[i].first;
				new_x = coors[j].second * 2 - coors[i].second;
				if (!(0 <= new_y && new_y < arr.size() && 0 <= new_x && new_x < arr[0].size())) continue;
				arr_antena[new_y][new_x] = '#';
			}
		}
	}
}

int cnt_antena() {
	int res = 0;

	for (int i = 0; i < arr_antena.size(); i++) {
		for (int j = 0; j < arr_antena[0].size(); j++) {
			if (arr_antena[i][j] == '#') {
				res++;
			}
		}
	}
	return res;
}

void print_map() {
	for (int i = 0; i < arr_antena.size(); i++) {
		for (int j = 0; j < arr_antena[0].size(); j++) {
			cout << arr_antena[i][j];
		}
		cout << '\n';
	}
}

int main() {
	init_arr();
	init_map();
	make_antena();
	cout << cnt_antena() << '\n';
	print_map();
	return 0;
}