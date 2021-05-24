#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<char> stack;
	stack.push(s[0]);
	for (int i = 1; i < s.size(); i++) {
		if (stack.empty()) {
			stack.push(s[i]);
		}
		else if (stack.top() == s[i]) {
			stack.pop();
		}
		else {
			stack.push(s[i]);
		}
	}
	if (stack.size() == 0) answer = 1;
	return answer;
}