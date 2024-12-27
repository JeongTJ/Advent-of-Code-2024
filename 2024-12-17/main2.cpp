#include <bits/stdc++.h>
using namespace std;


struct map_data {
	unsigned long long A;
	unsigned long long B;
	unsigned long long C;
};

unsigned long long registers[7] = {0, 1, 2, 3, 0, 0, 0};
vector<int> instruction;
vector<int> outputs;
map<int, vector<map_data>> m;
int pointer = 0;

void init_instruction() {
	string s;
	char c;
	unsigned long long num;

	cin >> s >> s >> num;
	registers[4] = num;
	cin >> s >> s >> num;
	registers[5] = num;
	cin >> s >> s >> num;
	registers[6] = num;

	cin >> s;
	while (1) {
		cin >> num;
		instruction.push_back(num);
		cin >> c;
		if (cin.eof()) break;
	}
}

void adv(int opcode, int operand) {
	if (opcode != 0) return ;
	unsigned long long &A = registers[4];

	A = A >> registers[operand];
	pointer += 2;
}

void bxl(int opcode, int operand) {
	if (opcode != 1) return ;
	unsigned long long &B = registers[5];

	B ^= operand;
	pointer += 2;
}

void bst(int opcode, int operand) {
	if (opcode != 2) return ;
	unsigned long long &B = registers[5];

	B = registers[operand] % 8;
	pointer += 2;
}

void jnz(int opcode, int operand) {
	if (opcode != 3) return ;
	unsigned long long &A = registers[4];

	if (A == 0) {
		pointer += 2;
		return ;
	}
	pointer = operand;
}

void bxc(int opcode, int operand) {
	if (opcode != 4) return ;
	unsigned long long &B = registers[5];
	unsigned long long &C = registers[6];

	B = B ^ C;
	pointer += 2;
}

void out(int opcode, int operand) {
	if (opcode != 5) return ;
	// cout << setw(16) << registers[4] << ' ';
	// cout << setw(16) << registers[5] << ' ';
	// cout << setw(16) << registers[6] << ' ';
	// cout << '\n';
	// cout << registers[operand] % 8 << ',';
	outputs.push_back(registers[operand] % 8);
	pointer += 2;
}

void bdv(int opcode, int operand) {
	if (opcode != 6) return ;
	unsigned long long &A = registers[4];
	unsigned long long &B = registers[5];

	B = A >> registers[operand];
	pointer += 2;
}

void cdv(int opcode, int operand) {
	if (opcode != 7) return ;
	unsigned long long &A = registers[4];
	unsigned long long &C = registers[6];

	C = A >> registers[operand];
	pointer += 2;
}

void run_instruction(int opcode, int operand) {
	switch (opcode) {
	case 0:
		adv(opcode, operand);
		break;
	case 1:
		bxl(opcode, operand);
		break;
	case 2:
		bst(opcode, operand);
		break;
	case 3:
		jnz(opcode, operand);
		break;
	case 4:
		bxc(opcode, operand);
		break;
	case 5:
		out(opcode, operand);
		break;
	case 6:
		bdv(opcode, operand);
		break;
	case 7:
		cdv(opcode, operand);
		break;
	}
}

void find_A(int instruction_pointer, unsigned long long A) {
	// cout << "ip: " << instruction_pointer << '\n';
	if (instruction_pointer == -1) {
		registers[4] = A &= ((1LL << 49) - 1);
		registers[5] = 0;
		registers[6] = 0;
		outputs.clear();
		pointer = 0;
		// cout << "test " << A << '\n';
		while (pointer < instruction.size()) {
			run_instruction(instruction[pointer], instruction[pointer + 1]);
		}
		// cout << "test " << outputs.size() << '\n';
		bool flag = true;
		if (outputs.size() != instruction.size()) return ;
		for (int i = 0; i < instruction.size(); i++) {
			cout << outputs[i] << ' ';
			if (outputs[i] != instruction[i]) {
				flag = false;
			}
		}
		cout << '\n';
		if (flag) {
			cout << A << '\n';
		}
		return ;
	}
	unsigned long long local_A = A << 3;
	vector<map_data> &m_data = m[instruction[instruction_pointer]];
	for (map_data data: m_data) {
		local_A = local_A << 8;
		local_A |= data.B;
		local_A |= (data.C << (data.B ^ 5));
		find_A(instruction_pointer - 1, local_A);
	}
}

/*


*/

int main(int argc, char *argv[]) {
	init_instruction();
	/*
	
	*/
	unsigned long long a = stol(string(argv[1]));
	unsigned long long origin_a = a;
	for (unsigned long long b = 0; b < 8; b++) {
			a = origin_a | b;
			registers[4] = a;
			registers[5] = 0;
			registers[6] = 0;
			pointer = 0;
			outputs.clear();
			while (pointer < instruction.size()) {
				run_instruction(instruction[pointer], instruction[pointer + 1]);
			}
			cout << "a: " << (a << 3) << ' ';
			for (int i = 0; i < outputs.size(); i++) {
				cout << outputs[i] << ",";
			}
			cout << '\n';
			// m[outputs[0]].push_back({a, b, c});
		// }
	}

	// find_A(15, 0);
	// for (map<int, vector<map_data>>::iterator it = m.begin(); it != m.end(); it++) {
	// 	cout << '[' << it->first << "]: ";
	// 	for (map_data data: it->second) {
	// 		cout << '[';
	// 		// cout << setw(4) << data.A << ", ";
	// 		cout << data.B << ", ";
	// 		cout << data.C << "] ";
	// 	}
	// 	cout << '\n';
	// }
	return 0;
}