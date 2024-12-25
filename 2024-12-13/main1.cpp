#include <bits/stdc++.h>
using namespace std;

struct Button {
	int x;
	int y;
};

struct vec_data {
	Button button1;
	Button button2;
	Button target;
};

vector<vec_data> v;

void init_v() {
	string s;
	vec_data vd;
	while (!cin.eof()) {
		getline(cin, s);
		istringstream iss(s);

		while (!iss.eof()) {
			string button, name, x, y;
			iss >> button >> name >> x >> y;
			if (button == "Button") {
				x = x.substr(0, x.size() - 1);
				if (name == "A:") {
					vd.button1.x = stoi(x.substr(2));
					vd.button1.y = stoi(y.substr(2));
				} else if (name == "B:") {
					vd.button2.x = stoi(x.substr(2));
					vd.button2.y = stoi(y.substr(2));
				}
			} else if (button == "Prize:") {
				y = x;
				x = name;
				x = x.substr(0, x.size() - 1);
				vd.target.x = stoi(x.substr(2));
				vd.target.y = stoi(y.substr(2));

				v.push_back(vd);
			}
		}
	}
}


int main() {
	init_v();
	int total = 0;
	for (int i = 0; i < v.size(); i++) {
		int res = 100000000;
		for (int a = 0; a <= 100; a++) {
			for (int b = 0; b <= 100; b++) {
				if (v[i].button1.x * a + v[i].button2.x * b == v[i].target.x && v[i].button1.y * a + v[i].button2.y * b == v[i].target.y) {
					if (a * 3 + b < res) {
						res = a * 3 + b;
					}
				}
			}
		}
		if (res != 100000000) {
			total += res;
		}
	}
	cout << total << '\n';
	return 0;
}