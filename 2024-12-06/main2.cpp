#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> arr;
vector<vector<int>> visited_arr;
int player_y, player_x;
int origin_y, origin_x;
int width, height;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int dir = 0;
int ans = 0;


void init_arr() {
	string s;

	while (!cin.eof()) {
		getline(cin, s);

		vector<char> temp;
		for (char c: s) {
			if (c != '\n')
				temp.push_back(c);
		}
		arr.push_back(temp);
	}
}

void init_parameter() {
	height = arr.size();
	width = arr[0].size();
	cout << "height: " << height << '\n';
	cout << "width : " << width  << '\n';
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (arr[i][j] == '^') {
				origin_y = player_y = i;
				origin_x = player_x = j;
			}
		}
	}
	visited_arr = vector<vector<int>>(height, vector<int>(width, 0));
}

bool run() {
	int cnt = 0;

	while (cnt < 100000) {
		cnt++;
		visited_arr[player_y][player_x] = 1;
		if (!(0 <= player_y + dy[dir] && player_y + dy[dir] < height && 0 <= player_x + dx[dir] && player_x + dx[dir] < width)) break;
		if (arr[player_y + dy[dir]][player_x + dx[dir]] == '#') {
			dir = (dir + 1) % 4;
		} else {
			player_y += dy[dir];
			player_x += dx[dir];
		}
	}

	// for (int i = 0; i < height; i++) {
	// 	for (int j = 0; j < width; j++) {
	// 		cout << visited_arr[i][j];
	// 	}
	// 	cout << '\n';
	// }
	// cout << '\n';
	return cnt >= 100000;
}

int main() {
	init_arr();
	init_parameter();

	bool is_wall = true;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			// if (arr[i][j] == '#') is_wall = true;
			if (arr[i][j] == '#' || arr[i][j] == '^') continue;
			// cout << "i: " << i << " j: " << j << '\n';
			player_y = origin_y;
			player_x = origin_x;
			// visited_arr = vector<vector<int>>(height, vector<int>(width, 0));
			dir = 0;
			arr[i][j] = '#';
			if(run()) {
				cout << "i: " << i << " j: " << j << '\n';
				ans++;
			}
			arr[i][j] = '.';
			// if (is_wall) {
			// 	is_wall = false;
			// } else  {
			// 	arr[i][j] = '.';
			// }
		}
	}
	cout << ans;
	return 0;
}