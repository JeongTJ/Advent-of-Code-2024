#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
vector<vector<int>> visited;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void init_arr() {
	string s;

	while (!cin.eof()) {
		getline(cin, s);

		vector<int> temp;
		for (char c: s) {
			temp.push_back(c - '0');
		}
		arr.push_back(temp);
	}
}

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({y, x});
	int cnt_tailhead = 0;
	visited[y][x] = 1;
	// visited.resize(arr.size(), vector<int>(arr[0].size(), 0));
	// visited = vector<vector<int>>(arr.size(), vector<int>(arr[0].size(), 0));
	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		if (arr[cur_y][cur_x] == 9) {
			// visited[cur_y][cur_x] = 1;
			cnt_tailhead++;
		}

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];
			if (!(0 <= next_y && next_y < arr.size() && 0 <= next_x && next_x < arr[0].size())) continue;
			// if (visited[next_y][next_x]) continue;
			if (arr[next_y][next_x] == arr[cur_y][cur_x] + 1) {
				visited[next_y][next_x] = 1;
				q.push({next_y, next_x});
			}
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (visited[i][j] == 1) {
				cout << arr[i][j];
			} else {
				cout << '.';
			}
		}
		cout << '\n';
	}
	cout << '\n';
	cout << '\n';

	return cnt_tailhead;
}

int main() {
	int res = 0;

	init_arr();
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			if (arr[i][j] == 0) {
				visited = vector<vector<int>>(arr.size(), vector<int>(arr[0].size(), 0));
				res += bfs(i, j);
			}
		}
	}
	cout << res << '\n';
	return 0;
}