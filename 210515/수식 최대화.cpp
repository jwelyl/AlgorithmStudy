#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

vector<char> calculate;
vector<char> sign;
vector<long long> num;
char t_sign[3] = { '*', '+', '-' };

bool visit[3] = { false };
long long max2 = 0;
void permutation(int idx) {
	if (idx == 3) {

		vector<long long> t_num = num;
		vector<char> t_calculate = calculate;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < t_calculate.size(); j++) {

				if (sign[i] == t_calculate[j]) {
					//t_num[i] = 
					if (sign[i] == '*') {
						t_num[j] = t_num[j] * t_num[j + 1];
					}
					else if (sign[i] == '+') {
						t_num[j] = t_num[j] + t_num[j + 1];
					}
					else if (sign[i] == '-') {
						t_num[j] = t_num[j] - t_num[j + 1];
					}

					t_num.erase(t_num.begin() + j + 1);
					t_calculate.erase(t_calculate.begin() + j);
					j--;
				}

			}
		}
		if (max2 < abs(t_num[0])) {
			max2 = abs(t_num[0]);
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (!visit[i]) {
			visit[i] = true;
			sign.push_back(t_sign[i]);
			permutation(idx + 1);
			sign.pop_back();
			visit[i] = false;
		}
	}
}

long long solution(string expression) {

	long long answer = 0;
	string temp = "";

	for (int i = 0; i <= expression.size(); i++) {
		if (i == expression.size()) {
			num.push_back(stoi(temp));
		}

		else if (expression[i] >= '0' && expression[i] <= '9') {
			temp += expression[i];
		}
		else {
			num.push_back(stoi(temp));
			temp = "";
			calculate.push_back(expression[i]);
		}

	}
	permutation(0);
	answer = max2;
	return answer;
}
