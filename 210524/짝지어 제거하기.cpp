#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
	stack<char> st;
	int answer = 0;
	for (const auto& c : s) {
		if (!st.empty() && st.top() == c)
			st.pop();
		else
			st.push(c);
	}
	if (st.empty())
		answer = 1;
	return answer;
}