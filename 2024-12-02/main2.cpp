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
		vector<int> &origin_data = datas[i];
		vector<vector<int>> sub_data(origin_data.size());
		for (int seq = 0; seq < origin_data.size(); seq++) {
			for (int j = 0; j < sub_data.size(); j++) {
				if (seq != j) {
					sub_data[j].push_back(origin_data[seq]);
				}
			}
		}

		int sub_safe = 0;
		for (int j = 0; j < sub_data.size(); j++) {
			bool is_inc = false;
			bool is_safe = true;

			if (sub_data[j].size() < 2 || sub_data[j][1] - sub_data[j][0] > 0) {
				is_inc = true;
			}
			for (int k = 0; k < sub_data[j].size(); k++) {
				if (k == 0) continue;
				if (is_inc) {
					if (sub_data[j][k] - sub_data[j][k - 1] > 3 || sub_data[j][k] - sub_data[j][k - 1] <= 0) {
						is_safe = false;
					}
				} else {
					if (sub_data[j][k] - sub_data[j][k - 1] < -3 || sub_data[j][k] - sub_data[j][k - 1] >= 0) {
						is_safe = false;
					}
				}
			}
			if (is_safe) {
				sub_safe++;
			}
		}
		if (sub_safe > 0) {
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