#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> origin_arr;
vector<vector<vector<char>>> arr_set;
vector<vector<int>> visited;
int drow[4] = {0, 1, 0, -1};
int dcol[4] = {1, 0, -1, 0};
int width, height;
int S_row, S_col;
int E_row, E_col;

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
	visited = vector<vector<int>>(height, vector<int>(width, 0));
}

void init_arrs() {
	for (int row = 1; row + 1 < height; row++) {
		for (int col = 1; col + 1 < width; col++) {
			if (origin_arr[row][col] == '#') {
				origin_arr[row][col] = '.';
				arr_set.push_back(origin_arr);
				origin_arr[row][col] = '#';
			}
		}
	}
}

void dfs(int row, int col, int cheating, int pico, vector<vector<char>> &arr) {
	if (row == E_row && col == E_col) {
		if (origin_pico == 0) {
			origin_pico = pico;
		} else {
			diff_pico[origin_pico - pico]++;
		}
		return ;
	}
	for (int i = 0; i < 4; i++) {
		int next_row = row + drow[i];
		int next_col = col + dcol[i];
		
		if (!(0 <= next_row && next_row < height && 0 <= next_col && next_col < width)) continue;
		if (visited[next_row][next_col]) continue;
		if (arr[next_row][next_col] == '#') continue;
		visited[next_row][next_col] = 1;
		dfs(next_row, next_col, cheating, pico + 1, arr);
		visited[next_row][next_col] = 0;
	}
}

struct queue_data {
	int row;
	int col;
	int pico;
};

void bfs(int start_row, int start_col, vector<vector<char>> &arr) {
	queue<queue_data> q;
	visited[start_row][start_col] = 1;
	q.push({start_row, start_col, 0});

	while (!q.empty()) {
		queue_data curr = q.front();
		q.pop();


		if (curr.row == E_row && curr.col == E_col) {
			if (origin_pico == 0) {
				origin_pico = curr.pico;
			} else {
				diff_pico[origin_pico - curr.pico]++;
			}
			return ;
		}

		for (int i = 0; i < 4; i++) {
			int next_row = curr.row + drow[i];
			int next_col = curr.col + dcol[i];
			
			if (!(0 <= next_row && next_row < height && 0 <= next_col && next_col < width)) continue;
			if (visited[next_row][next_col]) continue;
			if (arr[next_row][next_col] == '#') continue;
			visited[next_row][next_col] = 1;
			q.push({next_row, next_col, curr.pico + 1});
		}
	}
}

int main() {
	init_arr();
	set_pos();
	init_arrs();
	visited = vector<vector<int>>(height, vector<int>(width, 0));
	// dfs(S_row, S_col, 1, 0, origin_arr);
	bfs(S_row, S_col, origin_arr);
	for (int i = 0; i < arr_set.size(); i++) {
		visited = vector<vector<int>>(height, vector<int>(width, 0));
		bfs(S_row, S_col, arr_set[i]);
		// dfs(S_row, S_col, 1, 0, arr_set[i]);
	}

	int res = 0;
	for (map<int, int>::iterator it = diff_pico.begin(); it != diff_pico.end(); it++) {
		if (it->first >= 100) {
			cout << "save " << it->first << " pico" << ' ' << it->second << " sets" << '\n';
			res += it->second;
		}
	}
	cout << res;
	return 0;
}