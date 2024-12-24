#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> arr;
vector<vector<int>> visited_arr;
int player_y, player_x;
int width, height;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int dir = 0;

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

void init_parameter() {
	height = arr.size();
	width = arr[0].size();
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (arr[i][j] == '^') {
				player_y = i;
				player_x = j;
			}
		}
	}
	visited_arr = vector<vector<int>>(height, vector<int>(width, 0));
}

void run() {
	while (1) {
		visited_arr[player_y][player_x] = 1;
		if (!(0 <= player_y + dy[dir] && player_y + dy[dir] < height && 0 <= player_x + dx[dir] && player_x + dx[dir] < width)) break;
		if (arr[player_y + dy[dir]][player_x + dx[dir]] == '#') {
			dir = (dir + 1) % 4;
		}
		player_y += dy[dir];
		player_x += dx[dir];
	}
}

int get_visited() {
	int res = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			res += visited_arr[i][j];
		}
	}
	return res;
}

int main() {
	init_arr();
	init_parameter();
	run();
	cout << get_visited();
	return 0;
}