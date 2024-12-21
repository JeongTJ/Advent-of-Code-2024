#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> origin_arr;
vector<vector<int>> visited;
vector<vector<int>> new_visited;
int drow[4] = {0, 1, 0, -1};
int dcol[4] = {1, 0, -1, 0};
int width, height;
int S_row, S_col;
int E_row, E_col;

set<pair<int, int>> start_walls;
map<int, int> diff_pico;

int origin_pico;

void init_arr() {
	string s;
	vector<char> temp;

	while (!cin.eof()) {
		getline(cin, s);
		temp.clear();
		for (char c: s) {
			temp.push_back(c);
		}
		origin_arr.push_back(temp);
	}
}

void set_pos() {
	width = origin_arr[0].size();
	height = origin_arr.size();
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (origin_arr[row][col] == 'S') {
				S_row = row;
				S_col = col;
			}
			if (origin_arr[row][col] == 'E') {
				E_row = row;
				E_col = col;
			}
		}
	}
}

struct queue_data {
	int row;
	int col;
	int pico;
};

void bfs(int start_row, int start_col, int end_row, int end_col, vector<vector<char>> &arr) {
	queue<queue_data> q;
	visited[start_row][start_col] = 1;
	q.push({start_row, start_col, 0});

	while (!q.empty()) {
		queue_data curr = q.front();
		q.pop();

		if (curr.row == end_row && curr.col == end_col) {
			return ;
		}

		for (int i = 0; i < 4; i++) {
			int next_row = curr.row + drow[i];
			int next_col = curr.col + dcol[i];
			
			if (!(0 <= next_row && next_row < height && 0 <= next_col && next_col < width)) continue;
			if (visited[next_row][next_col]) continue;
			if (arr[next_row][next_col] == '#') continue;
			visited[next_row][next_col] = curr.pico + 1;
			q.push({next_row, next_col, curr.pico + 1});
		}
	}
}

void print_visited() {
	cout << "== == == == " << '\n';
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			cout << visited[row][col] << "\t";
		}
		cout << '\n';
	}
}

void cheating_bfs(int start_row, int start_col, vector<vector<char>> &arr) {
	queue<queue_data> q;
	new_visited[start_row][start_col] = 1;
	q.push({start_row, start_col, 0});
	int res = 0;


	while (!q.empty()) {
		queue_data curr = q.front();
		q.pop();

		if ((visited[curr.row][curr.col] > 0 || curr.row == E_row && curr.col == E_col) && visited[start_row][start_col] - visited[curr.row][curr.col] - curr.pico > 0) {
			diff_pico[visited[start_row][start_col] - visited[curr.row][curr.col] - curr.pico]++;
		}

		if (curr.pico == 20) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int next_row = curr.row + drow[i];
			int next_col = curr.col + dcol[i];
			
			if (!(0 <= next_row && next_row < height && 0 <= next_col && next_col < width)) continue;
			if (new_visited[next_row][next_col] == 1) continue;
			new_visited[next_row][next_col] = 1;
			q.push({next_row, next_col, curr.pico + 1});
		}
	}
}

int main() {
	init_arr();
	set_pos();
	visited = vector<vector<int>>(height, vector<int>(width, 0));
	visited = vector<vector<int>>(height, vector<int>(width, 0));
	bfs(E_row, E_col, S_row, S_col, origin_arr);
	visited[E_row][E_col] = 0;
	// print_visited();

	
	new_visited = vector<vector<int>>(height, vector<int>(width, 0));
	// cheating_bfs(S_row, S_col, origin_arr);
	new_visited = vector<vector<int>>(height, vector<int>(width, 0));
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (visited[row][col] != 0) {
				new_visited = vector<vector<int>>(height, vector<int>(width, 0));
				cheating_bfs(row, col, origin_arr);
			}
		}
	}

	int res = 0;
	for (map<int, int>::iterator it = diff_pico.begin(); it != diff_pico.end(); it++) {
		if (it->first >= 100) {
			cout << "save " << it->first << " pico" << ' ' << it->second << " sets" << '\n';
			res += it->second;
		}
	}
	cout << res << '\n';
	return 0;
}