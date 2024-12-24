#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, vector<long long>>> querys;

void init_query() {
	string s;

	while (!cin.eof()) {
		getline(cin, s);

		istringstream iss(s);

		long long x;
		char colon;
		iss >> x >> colon;
		pair<long long, vector<long long>> temp;
		temp.first = x;
		while (iss >> x) {
			temp.second.push_back(x);
		}
		querys.push_back(temp);
	}
}

bool is_right(pair<long long, vector<long long>> &query) {
	long long target = query.first;
	long long result = 0;
	vector<long long> &srcs = query.second;
	vector<int> oper(srcs.size(), 0);

	while (oper[0] == 0) {
		result = 0;
		for (int i = 0; i < srcs.size(); i++) {
			if (oper[i] == 0) {
				result += srcs[i];
			} else {
				result *= srcs[i];
			}
		}

		if (result == target) {
			return true;
		}

		oper[oper.size() - 1]++;
		for (int i = oper.size() - 1; i > 0; i--) {
			if (oper[i] == 2) {
				oper[i] = 0;
				oper[i - 1]++;
			}
		}
	}
	cout << '\n';
	return false;
}

int main() {
	long long res = 0;
	init_query();
	for (int i = 0; i < querys.size(); i++) {
		if (is_right(querys[i])) {
			res += querys[i].first;
		}
	}
	cout << res;
	return 0;
}