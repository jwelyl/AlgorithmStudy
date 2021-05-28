#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
bool IsRight(string& s)
{
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			st.push(s[i]);
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
			if (!st.empty()) {
				if (st.top() == '(' && s[i] == ')')
					st.pop();
				else if (st.top() == '[' && s[i] == ']')
					st.pop();
				else if (st.top() == '{' && s[i] == '}')
					st.pop();
			}
			else {
				st.push(s[i]);
			}
		}
	}
	if (st.size())
		return false;
	return true;
}
int solution(string s) {
	int answer = 0;
	int size = s.length();

	for (int i = 0; i < size - 1; i++) {
		if (IsRight(s))
			answer++;
		char ch = s[0];
		s.push_back(ch);
		s.erase(s.begin());
	}
	return answer;
}