#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> datas;

void init_arr() {
	string s;

	while (1) {
		getline(cin, s);
		istringstream iss;
		iss.str(s);

		int x;
		vector<int> tmp;
		while (iss >> x) {
			tmp.push_back(x);
		}
		datas.push_back(tmp);
		if (cin.eof()) {
			break ;
		}
	}
}

int sol() {
	int res = 0;

	for (int i = 0; i < datas.size(); i++) {
		bool is_inc = false;
		bool is_safe = true;

		if (datas[i].size() < 2 || datas[i][1] - datas[i][0] > 0) {
			is_inc = true;
		}

		if (is_inc) {
			for (int j = 1; j < datas[i].size(); j++) {
				if (datas[i][j] - datas[i][j - 1] > 3 || datas[i][j] - datas[i][j - 1] <= 0) {
					is_safe = false;
				}
			}
		} else {
			for (int j = 1; j < datas[i].size(); j++) {
				if (datas[i][j] - datas[i][j - 1] < -3 || datas[i][j] - datas[i][j - 1] >= 0) {
					is_safe = false;
				}
			}
		}
		if (is_safe) {
			res++;
		}
	}
	return res;
}

int main() {
	init_arr();
	cout << sol();
	return 0;
}