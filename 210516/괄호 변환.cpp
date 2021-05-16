#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
bool IsBalance(const string& s)
{
	int l = 0, r = 0;
	for (const auto& c : s) {
		if (c == '(')
			l++;
		else if (c == ')')
			r++;
	}
	if (l == r)
		return true;
	else
		return false;
}
bool IsRight(const string& s)
{
	stack<char> st;
	for (const auto& c : s) {
		if (c == '(')
			st.push(c);
		else if (!st.empty() && st.top() == '(' && c == ')')
			st.pop();
		else
			st.push(c);
	}
	if (st.size() != 0)
		return false;
	else
		return true;
}
string reform(const string& str)
{
	string temp = "(";
	int len = str.length();
	for (int i = 1; i < len - 1; i++) {
		if (str[i] == '(')
			temp += ')';
		else
			temp += '(';
	}
	temp += ")";
	return temp;
}
string solution(string p) {
	string answer = "";
	string u, v;
	if (p.length() == 0)
		return "";
	for (int i = 2; i <= p.length(); i += 2) {
		u = p.substr(0, i);
		if (IsBalance(u)) {
			v = p.substr(i);
			break;
		}
	}
	while (IsRight(u))
		u = reform(u);
	while (IsRight(v))
		v = reform(u);
	answer = u + v;
	return answer;
}