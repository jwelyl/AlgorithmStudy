#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string comb = "*+-";
long long calc(char op, long long num1, long long num2)
{
	long long result = 0;
	switch (op) {
	case '*':
		result = num1 * num2;
		return result;
	case '+':
		result = num1 + num2;
		return result;
	case '-':
		result = num1 - num2;
		return result;
	}
}
long long solution(string expression) {
	long long answer = 0;
	vector<long long> num;
	vector<char> op;
	string str;
	for (int i = 0; i < expression.length(); i++) {
		char c = expression[i];
		if (c == '-' || c == '+' || c == '*') {
			op.push_back(c);
			num.push_back(stoi(str));
			str.clear();
		}
		else if ('0' <= c && c <= '9') {
			str += c;
		}
		if (i == expression.length() - 1)
			num.push_back(stoi(str));
	}

	do {
		vector<long long> num_temp = num;
		vector<char> op_temp = op;
		for (int i = 0; i < comb.length(); i++) {
			for (int j = 0; j < op_temp.size(); j++) {
				if (comb[i] == op_temp[j]) {
					long long result = calc(comb[i], num_temp[j], num_temp[j + 1]);
					num_temp[j] = result;
					num_temp.erase(num_temp.begin() + j + 1);
					op_temp.erase(op_temp.begin() + j);
					j--;
				}
			}
		}
		answer = max(abs(num_temp[0]), answer);
	} while (next_permutation(comb.begin(), comb.end()));
	return answer;
}