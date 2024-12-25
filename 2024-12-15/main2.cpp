#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> arr;
int player_x, player_y;

void init_arr() {
	string s;

	while (1) {
		getline(cin, s);
		if (s == "")
			break;
		vector<char> tmp;
		for (char c: s) {
			if (c == '@') {
				tmp.push_back(c);
				tmp.push_back('.');
			} else if (c == 'O') {
				tmp.push_back('[');
				tmp.push_back(']');
			} else {
				tmp.push_back(c);
				tmp.push_back(c);
			}
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

bool move_check_updown(int y, int x, char dir) {
	bool res = true;

	if (dir == 'U') {
		if (arr[y - 1][x] == '[') {
			res &= move_check_updown(y - 1, x, dir);
			res &= move_check_updown(y - 1, x + 1, dir);
		} else if (arr[y - 1][x] == ']') {
			res &= move_check_updown(y - 1, x, dir);
			res &= move_check_updown(y - 1, x - 1, dir);
		} else if (arr[y - 1][x] == '#') {
			res = false;
		} else if (arr[y - 1][x] == '.') {
			res = true;
		}
	} else if (dir == 'D') {
		if (arr[y + 1][x] == '[') {
			res &= move_check_updown(y + 1, x, dir);
			res &= move_check_updown(y + 1, x + 1, dir);
		} else if (arr[y + 1][x] == ']') {
			res &= move_check_updown(y + 1, x, dir);
			res &= move_check_updown(y + 1, x - 1, dir);
		} else if (arr[y + 1][x] == '#') {
			res = false;
		} else if (arr[y + 1][x] == '.') {
			res = true;
		}
	}
	return res;
}

void move_updown(int y, int x, char dir) {
	if (dir == 'U') {
		if (arr[y - 1][x] == '[') {
			move_updown(y - 1, x, dir);
			move_updown(y - 1, x + 1, dir);
		} else if (arr[y - 1][x] == ']') {
			move_updown(y - 1, x, dir);
			move_updown(y - 1, x - 1, dir);
		}
		arr[y - 1][x] = arr[y][x];
		arr[y][x] = '.';
	} else if (dir == 'D') {
		if (arr[y + 1][x] == '[') {
			move_updown(y + 1, x, dir);
			move_updown(y + 1, x + 1, dir);
		} else if (arr[y + 1][x] == ']') {
			move_updown(y + 1, x, dir);
			move_updown(y + 1, x - 1, dir);
		}
		arr[y + 1][x] = arr[y][x];
		arr[y][x] = '.';
	}
}

bool move_check_lr(int y, int x, char dir) {
	bool res = true;

	if (dir == 'L') {
		cout << "y: " << y << " x - 1: " << x - 1 << " [" << arr[y][x - 1] << "]" << '\n';
		if (arr[y][x - 1] == '[' || arr[y][x - 1] == ']') {
			res &= move_check_lr(y, x - 1, dir);
		} else if (arr[y][x - 1] == '#') {
			res = false;
		} else if (arr[y][x - 1] == '.') {
			res = true;
		}
	} else if (dir == 'R') {
		if (arr[y][x + 1] == '[' || arr[y][x + 1] == ']') {
			res &= move_check_lr(y, x + 1, dir);
		} else if (arr[y][x + 1] == '#') {
			res = false;
		} else if (arr[y][x + 1] == '.') {
			res = true;
		}
	}
	return res;
}

void move_lr(int y, int x, char dir) {
	if (dir == 'L') {
		if (arr[y][x - 1] == '[' || arr[y][x - 1] == ']') {
			move_lr(y, x - 1, dir);
		}
		arr[y][x - 1] = arr[y][x];
		arr[y][x] = '.';
	} else if (dir == 'R') {
		if (arr[y][x + 1] == '[' || arr[y][x + 1] == ']') {
			move_lr(y, x + 1, dir);
		}
		arr[y][x + 1] = arr[y][x];
		arr[y][x] = '.';
	}
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
			if (arr[i][j] == '[')
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
			if (move_check_updown(player_y, player_x, 'U')) {
				move_updown(player_y, player_x, 'U');
				player_y--;
			}
			break;
		case '>':
			if (move_check_lr(player_y, player_x, 'R')) {
				move_lr(player_y, player_x, 'R');
				player_x++;
			}
			break;
		case 'v':
			if (move_check_updown(player_y, player_x, 'D')) {
				move_updown(player_y, player_x, 'D');
				player_y++;
			}
			break;
		case '<':
			if (move_check_lr(player_y, player_x, 'L')) {
				move_lr(player_y, player_x, 'L');
				player_x--;
			}
			break;
		default:
			break;
		}
		system("clear");
		print_arr();
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