#include <bits/stdc++.h>
using namespace std;

map<string, long long> m;
map<string, vector<string>> key_pad_code;

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

void make_pattern() {
	map<string, long long> tmp;
	
	for (map<string, long long>::iterator it = m.begin(); it != m.end(); it++) {
		string s = it->first;
		if (s == "^^") { tmp["AA"] += m[s]; } // AA

		if (s == "^A") { tmp["A>"] += m[s]; tmp[">A"] += m[s];} // A>A

		if (s == "^<") { tmp["Av"] += m[s]; tmp["v<"] += m[s]; tmp["<A"] += m[s];} // Av<A

		if (s == "^v") { tmp["Av"] += m[s]; tmp["vA"] += m[s];} // AvA

		if (s == "^>") { tmp["Av"] += m[s]; tmp["v>"] += m[s]; tmp[">A"] += m[s];} // Av>A
		// if (s == "^>") { tmp["A>"] += m[s]; tmp[">v"] += m[s]; tmp["vA"] += m[s];} // A>vA


		if (s == "A^") { tmp["A<"] += m[s]; tmp["<A"] += m[s]; } // A<A

		if (s == "AA") { tmp["AA"] += m[s]; } // AA

		if (s == "A<") { tmp["Av"] += m[s]; tmp["v<"] += m[s]; tmp["<<"] += m[s]; tmp["<A"] += m[s]; } // Av<<A
		// if (s == "A<") { tmp["A<"] += m[s]; tmp["<v"] += m[s]; tmp["v<"] += m[s]; tmp["<A"] += m[s]; } // A<v<A

		// if (s == "Av") { tmp["Av"] += m[s]; tmp["v<"] += m[s]; tmp["<A"] += m[s];} // Av<A
		if (s == "Av") { tmp["A<"] += m[s]; tmp["<v"] += m[s]; tmp["vA"] += m[s];} // A<vA

		if (s == "A>") { tmp["Av"] += m[s]; tmp["vA"] += m[s]; } // AvA


		if (s == "<^") { tmp["A>"] += m[s]; tmp[">^"] += m[s]; tmp["^A"] += m[s]; } // A>^A

		if (s == "<A") { tmp["A>"] += m[s]; tmp[">>"] += m[s]; tmp[">^"] += m[s]; tmp["^A"] += m[s]; } // A>>^A
		// if (s == "<A") { tmp["A>"] += m[s]; tmp[">^"] += m[s]; tmp["^>"] += m[s]; tmp[">A"] += m[s]; } // A>^>A
		
		if (s == "<<") { tmp["AA"] += m[s]; } // AA
		
		if (s == "<v") { tmp["A>"] += m[s]; tmp[">A"] += m[s]; } // A>A
		
		if (s == "<>") { tmp["A>"] += m[s]; tmp[">>"] += m[s]; tmp[">A"] += m[s]; } // A>>A


		if (s == "v^") { tmp["A^"] += m[s]; tmp["^A"] += m[s]; } // A^A
		
		if (s == "vA") { tmp["A^"] += m[s]; tmp["^>"] += m[s]; tmp[">A"] += m[s]; } // A^>A
		// if (s == "vA") { tmp["A>"] += m[s]; tmp[">^"] += m[s]; tmp["^A"] += m[s]; } // A>^A 
		
		if (s == "v<") { tmp["A<"] += m[s]; tmp["<A"] += m[s]; } // A<A
		
		if (s == "vv") { tmp["AA"] += m[s]; } // AA
		
		if (s == "v>") { tmp["A>"] += m[s]; tmp[">A"] += m[s]; } // A>A


		if (s == ">^") { tmp["A<"] += m[s]; tmp["<^"] += m[s]; tmp["^A"] += m[s]; } // A<^A
		// if (s == ">^") { tmp["A^"] += m[s]; tmp["^<"] += m[s]; tmp["<A"] += m[s]; } // A^<A
		
		if (s == ">A") { tmp["A^"] += m[s]; tmp["^A"] += m[s]; } // A^A
		
		if (s == "><") { tmp["A<"] += m[s]; tmp["<<"] += m[s]; tmp["<A"] += m[s]; } // A<<A
		
		if (s == ">v") { tmp["A<"] += m[s]; tmp["<A"] += m[s]; } // A<A
		
		if (s == ">>") { tmp["AA"] += m[s]; } // AA
	}
	m = tmp;
}

void init_m(string s) {
	for (int i = 0; i + 1 < s.size(); i++) {
		string tmp = s.substr(i, 2);
		m[tmp]++;
	}
}

int main(int argc, char *argv[]) {
	init_key_pad_code();
	long long ans = 0;
	for (int i = 1; i < argc; i++) {
		vector<string> kv = key_pad_code[argv[i]];
		long long res = (1LL << 62);
		for (int j = 0; j < kv.size(); j++) {
			long long tmp_res = 0;

			m.clear();
			init_m("A" + kv[j]);
			for (int k = 0; k < 25; k++) {
				make_pattern();
			}

			for (map<string, long long>::iterator it = m.begin(); it != m.end(); it++) {
				tmp_res += it->second;
			}
			res = min(tmp_res, res);
		}
		cout << "res: " << res << '\n';
		string args = argv[i];

		args.substr(0, 3);
		ans += res * stoi(args);
	}
	cout << ans << '\n';
	// cout << tmp;
	// cout << btk("^^");
	return 0;
}