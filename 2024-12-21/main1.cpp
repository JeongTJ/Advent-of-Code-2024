#include <bits/stdc++.h>
using namespace std;

char key_pad[4][3] = 
{
	{'7', '8', '9'},
	{'4', '5', '6'},
	{'1', '2', '3'},
	{'-', '0', 'A'}
};

char arrow_pad[2][3] = 
{
	{'-', '^', 'A'},
	{'<', 'v', '>'}
};

map<char, pair<int, int>> rkey_pad;
map<string, vector<string>> key_pad_code;
map<pair<char, char>, vector<string>> arrow_pad_code;
int cur_row = 3, cur_col = 2;

void init_rkey_pad() {
	rkey_pad['0'] = {3, 1};
	rkey_pad['1'] = {2, 0};
	rkey_pad['2'] = {2, 1};
	rkey_pad['3'] = {2, 2};
	rkey_pad['4'] = {1, 0};
	rkey_pad['5'] = {1, 1};
	rkey_pad['6'] = {1, 2};
	rkey_pad['7'] = {0, 0};
	rkey_pad['8'] = {0, 1};
	rkey_pad['9'] = {0, 2};
	rkey_pad['A'] = {3, 2};
}

void init_key_pad_code() {
	/*
	964A
	246A
	973A
	682A
	180A
	*/
	key_pad_code["029A"].push_back("<A^A^^>AvvvA");

	key_pad_code["964A"].push_back("^^^AvA<<A>>vvA");

	key_pad_code["246A"].push_back("^<A^<A>>AvvA");
	key_pad_code["246A"].push_back("<^A^<A>>AvvA");
	key_pad_code["246A"].push_back("^<A<^A>>AvvA");
	key_pad_code["246A"].push_back("<^A<^A>>AvvA");

	key_pad_code["973A"].push_back("^^^A<<A>>vvAvA");
	key_pad_code["973A"].push_back("^^^A<<A>v>vAvA");
	key_pad_code["973A"].push_back("^^^A<<Av>>vAvA");
	key_pad_code["973A"].push_back("^^^A<<A>vv>AvA");
	key_pad_code["973A"].push_back("^^^A<<Av>v>AvA");
	key_pad_code["973A"].push_back("^^^A<<Avv>>AvA");

	key_pad_code["682A"].push_back("^^A^<AvvAv>A");
	key_pad_code["682A"].push_back("^^A<^AvvAv>A");
	key_pad_code["682A"].push_back("^^A^<AvvA>vA");
	key_pad_code["682A"].push_back("^^A<^AvvA>vA");

	key_pad_code["180A"].push_back("^<<A^^>AvvvA>A");
	key_pad_code["180A"].push_back("<^<A^^>AvvvA>A");
	// key_pad_code["180A"].push_back("<<^A^^>AvvvA>A");
	key_pad_code["180A"].push_back("^<<A^>^AvvvA>A");
	key_pad_code["180A"].push_back("<^<A^>^AvvvA>A");
	// key_pad_code["180A"].push_back("<<^A^>^AvvvA>A");
	key_pad_code["180A"].push_back("^<<A>^^AvvvA>A");
	key_pad_code["180A"].push_back("<^<A>^^AvvvA>A");
	// key_pad_code["180A"].push_back("<<^A>^^AvvvA>A");
}

/*
##- ^ A < v >
--#----------
^ | 1 2 3 2 3
A | 2 1 4 3 2
< | 3 4 1 2 3
v | 2 3 2 1 3
> | 3 2 3 2 1
*/
void init_arrow_pad_code() {
	arrow_pad_code[{'A', '^'}].push_back("<A");
	arrow_pad_code[{'A', 'A'}].push_back("A");
	arrow_pad_code[{'A', '<'}].push_back("v<<A");
	// arrow_pad_code[{'A', '<'}].push_back("<v<A");
	arrow_pad_code[{'A', 'v'}].push_back("<vA");
	// arrow_pad_code[{'A', 'v'}].push_back("v<A");
	arrow_pad_code[{'A', '>'}].push_back("vA");

	
	arrow_pad_code[{'^', '^'}].push_back("A");
	arrow_pad_code[{'^', 'A'}].push_back(">A");
	arrow_pad_code[{'^', '<'}].push_back("v<A");
	arrow_pad_code[{'^', 'v'}].push_back("vA");
	arrow_pad_code[{'^', '>'}].push_back("v>A");
	// arrow_pad_code[{'^', '>'}].push_back(">vA");


	arrow_pad_code[{'<', '^'}].push_back(">^A");
	arrow_pad_code[{'<', 'A'}].push_back(">>^A");
	// arrow_pad_code[{'<', 'A'}].push_back(">^>A");
	arrow_pad_code[{'<', '<'}].push_back("A");
	arrow_pad_code[{'<', 'v'}].push_back(">A");
	arrow_pad_code[{'<', '>'}].push_back(">>A");


	arrow_pad_code[{'v', '^'}].push_back("^A");
	arrow_pad_code[{'v', 'A'}].push_back(">^A");
	// arrow_pad_code[{'v', 'A'}].push_back("^>A");
	arrow_pad_code[{'v', '<'}].push_back("<A");
	arrow_pad_code[{'v', 'v'}].push_back("A");
	arrow_pad_code[{'v', '>'}].push_back(">A");


	arrow_pad_code[{'>', '^'}].push_back("<^A");
	// arrow_pad_code[{'>', '^'}].push_back("^<A");
	arrow_pad_code[{'>', 'A'}].push_back("^A");
	arrow_pad_code[{'>', '<'}].push_back("<<A");
	arrow_pad_code[{'>', 'v'}].push_back("<A");
	arrow_pad_code[{'>', '>'}].push_back("A");
}

vector<string> arrow_to_arrow(vector<string> s) {
	char prev = 'A';
	vector<string> answer;

	for (string curr: s) {
		string temp = "";
		for (int i = 0; i < curr.size(); i++) {
			temp += arrow_pad_code[{prev, curr[i]}][0];
			prev = curr[i];
		}
		answer.push_back(temp);
	}
	return answer;
}

int main(int argc, char *argv[]) {
	init_key_pad_code();
	init_arrow_pad_code();

	int res = 0;
	for (int i = 1; i < argc; i++) {
		vector<string> ans;
		ans = arrow_to_arrow(key_pad_code[argv[i]]);
		for (int i = 1; i < 2; i++) {
			ans = arrow_to_arrow(ans);
		}

		string s(argv[i]);
		s.substr(0, 3);

		string few_string = ans[0];

		for (int i = 0; i < ans.size(); i++) {
			if (few_string.size() > ans[i].size()) {
				few_string = ans[i];
			}
		}
		cout << few_string.size() << '\n';
		res += stoi(s) * few_string.size();
	}
	cout << res << '\n';
	return 0;
}