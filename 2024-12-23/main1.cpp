#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> g;
set<set<string>> sets;

void init() {
	string s;
	
	while (!cin.eof()) {
		getline(cin, s);
		// cout << s.substr(0, 2) << ' ' << s.substr(3, 2) << '\n';
		g[s.substr(0, 2)].push_back(s.substr(3, 2));
		g[s.substr(3, 2)].push_back(s.substr(0, 2));
	}
}

bool is_conn(string s1, string s2) {
	for (int i = 0; i < g[s1].size(); i++) {
		if (g[s1][i] == s2)
			return true;
	}
	return false;
}

void find_inter() {
	// for (map<string, vector<string>>::iterator it1 = g.begin(); it1 != g.end(); it1++) {
	// 	for (map<string, vector<string>>::iterator it2 = g.begin(); it2 != g.end(); it2++) {
	// 		for (map<string, vector<string>>::iterator it3 = g.begin(); it3 != g.end(); it3++) {
	// 			if (is_conn(it1->first, it2->first) && is_conn(it2->first, it3->first) &&  is_conn(it3->first, it1->first)) {
	// 				set<string> temp;
	// 				temp.insert(it1->first);
	// 				temp.insert(it2->first);
	// 				temp.insert(it3->first);
	// 				sets.insert(temp);
	// 				// cout << it1->first << ',' << it2->first << ',' << it3->first << '\n';
	// 			}
	// 		}
	// 	}
	// }
	for (map<string, vector<string>>::iterator it1 = g.begin(); it1 != g.end(); it1++) {
		for (map<string, vector<string>>::iterator it2 = it1; it2 != g.end(); it2++) {
			for (map<string, vector<string>>::iterator it3 = it2; it3 != g.end(); it3++) {
				if (is_conn(it1->first, it2->first) && is_conn(it2->first, it3->first) &&  is_conn(it3->first, it1->first)) {
					set<string> temp;
					temp.insert(it1->first);
					temp.insert(it2->first);
					temp.insert(it3->first);
					sets.insert(temp);
					// cout << it1->first << ',' << it2->first << ',' << it3->first << '\n';
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {

	init();
	find_inter();
	int res = 0;
	for (set<set<string>>::iterator it = sets.begin(); it != sets.end(); it++) {
		for (set<string>::iterator iitt = it->begin(); iitt != it->end(); iitt++) {
			if ((*iitt)[0] == 't') {
				res++;
				break;
			}
			// cout << *iitt << ' ';
		}
		// cout << "\n";
	}
	cout << res;
	return 0;
}