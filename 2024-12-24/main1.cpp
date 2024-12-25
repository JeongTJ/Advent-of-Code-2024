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

int main(int argc, char *argv[]) {
	init_map();
	while (!calc()) {
		
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
	return 0;
}