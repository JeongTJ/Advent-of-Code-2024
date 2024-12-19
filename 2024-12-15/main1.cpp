#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> arr;
int player_x, player_y;

void init_arr() {
	string s;
	int coor = 0;

	while (1) {
		getline(cin, s);
		if (s == "")
			break;
		vector<char> tmp;
		for (char c: s) {
			tmp.push_back(c);
			coor++;
		}
		arr.push_back(tmp);
	}
}

void find_player() {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == '@') {
				player_y = i;
				player_x = j;
			}
		}
	}
}

pair<int, int> find_up_empty() {
	int diff_y = 0, diff_x = 0;
	int next_y, next_x;

	while (1) {
		next_y = player_y + diff_y;
		next_x = player_x + diff_x;
		if (!(0 <= next_y && next_y < arr.size() && 0 <= next_x && next_x <= arr[0].size()))
			break;
		if (arr[next_y][next_x] == '.')
			return {next_y, next_x};
		if (arr[next_y][next_x] == '#')
			return {-1, -1};
		diff_y--;
	}
	return {-1, -1};
}

pair<int, int> find_down_empty() {
	int diff_y = 0, diff_x = 0;
	int next_y, next_x;

	while (1) {
		next_y = player_y + diff_y;
		next_x = player_x + diff_x;
		if (!(0 <= next_y && next_y < arr.size() && 0 <= next_x && next_x <= arr[0].size()))
			break;
		if (arr[next_y][next_x] == '.')
			return {next_y, next_x};
		if (arr[next_y][next_x] == '#')
			return {-1, -1};
		diff_y++;
	}
	return {-1, -1};

}

pair<int, int> find_left_empty() {
	int diff_y = 0, diff_x = 0;
	int next_y, next_x;

	while (1) {
		next_y = player_y + diff_y;
		next_x = player_x + diff_x;
		if (!(0 <= next_y && next_y < arr.size() && 0 <= next_x && next_x <= arr[0].size()))
			break;
		if (arr[next_y][next_x] == '.')
			return {next_y, next_x};
		if (arr[next_y][next_x] == '#')
			return {-1, -1};
		diff_x--;
	}
	return {-1, -1};
}

pair<int, int> find_right_empty() {
	int diff_y = 0, diff_x = 0;
	int next_y, next_x;

	while (1) {
		next_y = player_y + diff_y;
		next_x = player_x + diff_x;
		if (!(0 <= next_y && next_y < arr.size() && 0 <= next_x && next_x <= arr[0].size()))
			break;
		if (arr[next_y][next_x] == '.')
			return {next_y, next_x};
		if (arr[next_y][next_x] == '#')
			return {-1, -1};
		diff_x++;
	}
	return {-1, -1};
}

void print_arr() {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
}

long long get_res() {
	long long res = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == 'O')
				res += i * 100 + j;
		}
	}
	return res;
}

void run() {
	char command;
	pair<int, int> next_coor;
	while (1) {
		cin >> command;
		if (cin.eof())
			break;
		switch (command) {
		case '^':
			next_coor = find_up_empty();
			if (next_coor.first == -1)
				break;
			arr[player_y--][player_x] = '.';
			arr[next_coor.first][next_coor.second] = 'O';
			arr[player_y][player_x] = '@';
			break;
		case '>':
			next_coor = find_right_empty();
			if (next_coor.first == -1)
				break;
			arr[player_y][player_x++] = '.';
			arr[next_coor.first][next_coor.second] = 'O';
			arr[player_y][player_x] = '@';
			break;
		case 'v':
			next_coor = find_down_empty();
			if (next_coor.first == -1)
				break;
			arr[player_y++][player_x] = '.';
			arr[next_coor.first][next_coor.second] = 'O';
			arr[player_y][player_x] = '@';
			break;
		case '<':
			next_coor = find_left_empty();
			if (next_coor.first == -1)
				break;
			arr[player_y][player_x--] = '.';
			arr[next_coor.first][next_coor.second] = 'O';
			arr[player_y][player_x] = '@';
			break;
		default:
			break;
		}
	}
}


int main() {
	init_arr();
	find_player();
	run();
	print_arr();
	cout << get_res();
	return 0;
}