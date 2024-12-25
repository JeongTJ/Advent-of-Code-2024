#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> arr;
vector<vector<int>> visited;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int edge_dx[4][4] = {
	{-1, 0, -1, 0}, // 왼위
	{0, 1, 0, 1},   // 오위
	{-1, 0, -1, 0}, // 왼아
	{0, 1, 0, 1}    // 오아
};
int edge_dy[4][4] = {
	{-1, -1, 0, 0}, // 왼위
	{-1, -1, 0, 0}, // 오위
	{0, 0, 1, 1},   // 왼아
	{0, 0, 1, 1}    // 오아
};
char edge_case[3][4][4] = {
	{
		{'.', '#', '#', '#'},
		{'#', '.', '#', '#'},
		{'#', '#', '.', '#'},
		{'#', '#', '#', '.'}
	},
	{
		{'.', '.', '.', '#'},
		{'.', '.', '#', '.'},
		{'.', '#', '.', '.'},
		{'#', '.', '.', '.'}
	},
	{
		{'#', '.', '.', '#'},
		{'.', '#', '#', '.'},
		{'.', '#', '#', '.'},
		{'#', '.', '.', '#'}
	},
};

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
	arr.insert(arr.begin(), vector<char>(arr.size(), '.'));
	arr.push_back(vector<char>(arr.size(), '.'));
	for (int i = 0; i < arr.size(); i++) {
		arr[i].insert(arr[i].begin(), '.');
		arr[i].push_back('.');
	}
}

struct queue_data {
	int y;
	int x;
	char c;
};
/*
####
# ##
## #
####

*/

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({y, x});
	int edges = 0;
	int cnt = 1;

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int k = 0; k < 3; k++) {
			for (int i = 0; i < 4; i++) {
				bool flag = true;
				for (int j = 0; j < 4; j++) {
					int Y, X;
					Y = cur_y + edge_dy[i][j];
					X = cur_x + edge_dx[i][j];
					if (!((edge_case[k][i][j] == '#' && arr[Y][X] == arr[cur_y][cur_x]) || (edge_case[k][i][j] == '.' && arr[Y][X] != arr[cur_y][cur_x]))) {
						// cout << "edge: " << edge_case[k][i][j] << '\n';
						// cout << "cur_y: " << cur_y << " cur_x: " << cur_x << '\n';
						// cout << "Y: " << Y << " X: " << X << '\n';
						// cout << "arr[Y][X]: " << arr[Y][X] << " arr[cur_y][cur_x]: " << arr[cur_y][cur_x] << '\n';
						// cout << '\n';
						flag = false;
					}
				}
				if (flag) {
					cout << "cur_y: " << cur_y << " cur_x: " << cur_x << '\n';
					cout << "i: " << i << '\n';
					cout << edge_case[k][i][0] << edge_case[k][i][1] << '\n';
					cout << edge_case[k][i][2] << edge_case[k][i][3] << '\n';
					cout << arr[cur_y + edge_dy[i][0]][cur_x + edge_dx[i][0]] << arr[cur_y + edge_dy[i][1]][cur_x + edge_dx[i][1]] << '\n';
					cout << arr[cur_y + edge_dy[i][2]][cur_x + edge_dx[i][2]] << arr[cur_y + edge_dy[i][3]][cur_x + edge_dx[i][3]] << '\n';
					cout << '\n';
					edges++;
				}
			}
		}
		

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];
			if (visited[next_y][next_x]) continue;
			if (arr[next_y][next_x] == arr[cur_y][cur_x]) {
				visited[next_y][next_x] = 1;
				q.push({next_y, next_x});
				cnt++;
			}
		}
	}
	cout << arr[y][x] << ": " << edges << '\n';
	return cnt * edges;
}

int main() {
	init_arr();
	visited = vector<vector<int>>(arr.size(), vector<int>(arr[0].size(), 0));
	int res = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (arr[i][j] == '.') continue;
			if (visited[i][j]) continue;
			int tmp = bfs(i, j);
			cout << tmp << '\n';
			res += tmp;
		}
	}
	cout << res << '\n';
	return 0;
}