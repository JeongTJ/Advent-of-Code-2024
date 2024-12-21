#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> arr;
vector<vector<int>> find_arr;

int dx[4][5] = {
	{-1, -1, 0, 1, 1},
	{-1, 1, 0, -1, 1},
	{1, 1, 0, -1, -1},
	{-1, 1, 0, -1, 1}
};

int dy[4][5] = {
	{-1, 1, 0, -1, 1},
	{-1, -1, 0, 1, 1},
	{-1, 1, 0, -1, 1},
	{1, 1, 0, -1, -1}
};

void init_arr() {
	string s;
	arr.push_back({});
	arr.push_back({});
	arr.push_back({});
	while (!cin.eof()) {
		getline(cin, s);

		vector<char> temp;
		temp.push_back('.');
		temp.push_back('.');
		temp.push_back('.');
		for (char c: s) {
			temp.push_back(c);
		}
		temp.push_back('.');
		temp.push_back('.');
		temp.push_back('.');
		arr.push_back(temp);
	}
	arr[0] = arr[1] = arr[2] = vector<char>(arr[3].size(), '.');
	arr.push_back(arr[0]);
	arr.push_back(arr[0]);
	arr.push_back(arr[0]);
	find_arr = vector<vector<int>>(arr.size(), vector<int>(arr[0].size(), 0));
}

int count_XMAS(int y, int x) {
	string xmas = "MMASS";
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		bool is_xmas = true;
		for (int j = 0; j < 5; j++) {
			int YY, XX;
			YY = y + dy[i][j];
			XX = x + dx[i][j];
			if (arr[YY][XX] != xmas[j]) {
				is_xmas = false;
			}
		}
		if (is_xmas) {
			cnt++;
			for (int j = 0; j < 5; j++) {
				int YY, XX;
				YY = y + dy[i][j];
				XX = x + dx[i][j];
				find_arr[YY][XX] = 1;
			}
		}
	}
	return cnt;
}

void print_arr() {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (find_arr[i][j] == 1) {
				cout << arr[i][j];
			} else {
				cout << '.';
			}
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	int cnt = 0;
	init_arr();
	for (int i = 3; i < arr.size() - 3; i++) {
		for (int j = 3; j < arr[0].size() - 3; j++) {
			cnt += count_XMAS(i, j);
		}
	}
	print_arr();
	cout << cnt << '\n';
	return 0;
}