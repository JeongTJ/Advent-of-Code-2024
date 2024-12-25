#include <bits/stdc++.h>
using namespace std;

struct map_data {
	string target;
	string operand1;
	string operand2;
	string oper;
	int result;
};

map<string, map_data> m;
set<pair<string, int>> target_set;

void init_map() {
	string s;

	while (!cin.eof()) {
		getline(cin, s);

		if (s.find(':') != string::npos) {
			m[s.substr(0, s.find(':'))] = {s.substr(0, s.find(':')), "", "", "EQ", stoi(s.substr(s.find(':') + 1))};
		} else if (!s.empty()){
			istringstream iss(s);
			string operand1, operand2, oper, arrow, target;
			iss >> operand1 >> oper >> operand2 >> arrow >> target;
			m[target] = {target, operand1, operand2, oper, -1};
		}
	}
}

bool calc() {
	bool flag = true;

	for (map<string, map_data>::iterator it = m.begin(); it != m.end(); it++) {
		string &operand1 = it->second.operand1;
		string &operand2 = it->second.operand2;
		string &oper = it->second.oper;
		int &result = it->second.result;

		if (result != -1) continue;
		if (!(m[operand1].result != -1 && m[operand2].result != -1)) {
			flag = false;
			continue;
		}
		if (oper == "AND") {
			result = (m[operand1].result & m[operand2].result);
		} else if (oper == "OR") {
			result = (m[operand1].result | m[operand2].result);
		} else if (oper == "XOR") {
			result = (m[operand1].result ^ m[operand2].result);
		}
	}
	return flag;
}

void find_sources(string s) {
	queue<string> q, q2;

	q.push(s);
	// cout << "test" << '\n';
	while (!q.empty() || !q2.empty()) {
		// cout << "test" << '\n';
		while (!q.empty()) {
			string curr = q.front();
			q.pop();

			if (curr == "") continue;
			// cout << curr << ' ';
			// if (curr[0] == 'x' || curr[0] == 'y') {
			// 	// v.push_back(curr);
			// 	continue;
			// }
			if (m[curr].oper != "EQ") {
				if (m[curr].oper == "OR") {
					cout << '[' << curr << " = " << m[curr].operand1 << ' ' << m[curr].oper << "  " << m[curr].operand2 << ']' << ' ';
				} else {
					cout << '[' << curr << " = " << m[curr].operand1 << ' ' << m[curr].oper << ' ' << m[curr].operand2 << ']' << ' ';
				}
			}
			q2.push(m[curr].operand1);
			q2.push(m[curr].operand2);
		}
		cout << '\n';
		while (!q2.empty()) {
			q.push(q2.front());
			q2.pop();
		}
	}
}

long long get_x_plus_y() {
	long long res_x = 0;
	long long res_y = 0;
	long long factor_x = 1;
	long long factor_y = 1;
	set<pair<string, int>> set_x, set_y;
	for (map<string, map_data>::iterator it = m.begin(); it != m.end(); it++) {

		if (it->second.oper == "EQ" && it->second.target[0] == 'x') {
			set_x.insert({it->second.target, it->second.result});
			// target_set.insert({it->second.target, it->second.result});
		}
		if (it->second.oper == "EQ" && it->second.target[0] == 'y') {
			set_y.insert({it->second.target, it->second.result});
			// target_set.insert({it->second.target, it->second.result});
		}
	}


	for (set<pair<string, int>>::iterator it = set_x.begin(); it != set_x.end(); it++) {
		if (it->first[0] == 'x') {
			res_x += it->second * factor_x;
			factor_x *= 2;
			cout << it->first << ": " << it->second << '\n';
		}
	}
	for (set<pair<string, int>>::iterator it = set_y.begin(); it != set_y.end(); it++) {
		if (it->first[0] == 'y') {
			res_y += it->second * factor_y;
			factor_y *= 2;
			cout << it->first << ": " << it->second << '\n';
		}
	}
	return res_x + res_y;
}

int main(int argc, char *argv[]) {
	int calc_cnt = 0;

	init_map();

	// find_sources(argv[1]);

	while (1) {
		calc_cnt++;
		if (calc()) {
			break;
		}
	}
	
	for (map<string, map_data>::iterator it = m.begin(); it != m.end(); it++) {
		if (it->second.oper != "=") {
			target_set.insert({it->second.target, it->second.result});
		}
	}
	long long res = 0;
	long long factor = 1;
	for (set<pair<string, int>>::iterator it = target_set.begin(); it != target_set.end(); it++) {

		if (it->first[0] == 'z') {
			res += it->second * factor;
			factor *= 2;
			cout << it->first << ": " << it->second << '\n';
		}
	}
	cout << res << '\n';
	cout << get_x_plus_y() << '\n';
	return 0;
}
/*

     x1 x0
+    y1 y0
----------
  z2 z1 z0

z0 = x0 ^ y0

k0 = x1 ^ y1
k1 = x0 & y0

z1 = k0 ^ k1

k2 = x1 & y1
p0 = k0 & k1

z2 = k2 | p0

// 하위 단계 &, 같은 단계 ^ 둘을 ^


*/