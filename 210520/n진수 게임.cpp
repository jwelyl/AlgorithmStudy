#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
char digit_arr[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
string GetNdigit(int n, int num)
{
	string str = "";
	if (num == 0)
		return "0";
	while (num != 0) {
		if (num % n == 0)
			str += '0';
		else {
			if (num % n >= 10) {
				str.push_back(digit_arr[num % n - 10]);
			}
			else {
				str += to_string(num % n);
			}
		}
		num /= n;
	}
	reverse(str.begin(), str.end());
	return str;
}
string solution(int n, int t, int m, int p) {
	string answer = "";
	string str_digit = "";
	for (int i = 0; i <= t * m; i++) {
		str_digit += GetNdigit(n, i);
	}
	int idx = p - 1;
	for (int i = 0; i < t; i++) {
		answer += str_digit[idx];
		idx += m;
	}

	return answer;
}