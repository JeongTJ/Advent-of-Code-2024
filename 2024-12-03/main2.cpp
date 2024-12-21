#include <bits/stdc++.h>
using namespace std;

priority_queue<int> lPQ, rPQ;

bool is_digit(const vector<char> &v) {
	bool res = true;
	for (char c: v) {
		res &= ('0' <= c && c <= '9');
	}
	return res;
}

long long get_res(string &s) {
	// mul(x,y)
	if (is_digit({s[4], s[6]}) && s[5] == ',' && s[7] == ')') {
		return stoi(s.substr(4, 1)) * stoi(s.substr(6, 1));
	}
	// mul(x,yy)
	if (is_digit({s[4], s[6], s[7]}) && s[5] == ',' && s[8] == ')') {
		return stoi(s.substr(4, 1)) * stoi(s.substr(6, 2));
	}
	// mul(x,yyy)
	if (is_digit({s[4], s[6], s[7], s[8]}) && s[5] == ',' && s[9] == ')') {
		return stoi(s.substr(4, 1)) * stoi(s.substr(6, 3));
	}
	// mul(xx,y)
	if (is_digit({s[4], s[5], s[7]}) && s[6] == ',' && s[8] == ')') {
		return stoi(s.substr(4, 2)) * stoi(s.substr(7, 1));
	}
	// mul(xx,yy)
	if (is_digit({s[4], s[5], s[7], s[8]}) && s[6] == ',' && s[9] == ')') {
		return stoi(s.substr(4, 2)) * stoi(s.substr(7, 2));
	}
	// mul(xx,yyy)
	if (is_digit({s[4], s[5], s[7], s[8], s[9]}) && s[6] == ',' && s[10] == ')') {
		return stoi(s.substr(4, 2)) * stoi(s.substr(7, 3));
	}
	// mul(xxx,y)
	if (is_digit({s[4], s[5], s[6], s[8]}) && s[7] == ',' && s[9] == ')') {
		return stoi(s.substr(4, 3)) * stoi(s.substr(8, 1));
	}
	// mul(xxx,yy)
	if (is_digit({s[4], s[5], s[6], s[8], s[9]}) && s[7] == ',' && s[10] == ')') {
		return stoi(s.substr(4, 3)) * stoi(s.substr(8, 2));
	}
	// mul(xxx,yyy)
	if (is_digit({s[4], s[5], s[6], s[8], s[9], s[10]}) && s[7] == ',' && s[11] == ')') {
		return stoi(s.substr(4, 3)) * stoi(s.substr(8, 3));
	}
	return 0;
}

long long sol() {
	string s;
	long long res = 0;
	size_t pos;
	size_t do_pos;
	size_t dont_pos;
	vector<string> do_set;
	bool is_do = true;

	while (!cin.eof()) {
		getline(cin, s);
		
		do_set.clear();
		while (!s.empty()) {
			// find "don't()"
			if (is_do) {
				pos = s.find("don't()");
				if (pos == string::npos) {
					do_set.push_back(s);
					s = "";
				} else {
					do_set.push_back(s.substr(0, pos));
					s = s.substr(pos + string("don't()").size());
					is_do = false;
				}
			// find "do()"
			} else {
				pos = s.find("do()");
				if (pos == string::npos) {
					s = "";
				} else {
					s = s.substr(pos + string("do()").size());
					is_do = true;
				}
			}
		}

		for (string s1: do_set) {
			cout << s1;
			while (!s1.empty()) {

				pos = s1.find("mul(");
				if (pos == string::npos) {
					break;
				}
				s1 = s1.substr(pos);
				res += get_res(s1);
				s1 = s1.substr(4);
			}
		}
		cout << '\n';
	}
	return res;
}

int main() {
	cout << sol();
	return 0;
}