#include <bits/stdc++.h>

using namespace std;
map<char, char> bracket;
bool isOk(string s) {
    stack<char> stack;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] =='{' || s[i] == '[') {
            stack.push(s[i]);
        }
        if(s[i] == ')' || s[i] == '}' || s[i] ==']') {
            if(stack.empty()) return false;
            else {
                if(bracket[s[i]] != stack.top()) return false;
                else stack.pop();
            }
        }
    }
    if(stack.empty()) return true;
    else return false;
}

int solution(string s) {
    int answer = 0;
    bracket = {{')', '('}, {'}', '{'}, {']', '['}};
    for(int i = 0; i < s.size(); i++) {
        if(isOk(s)) answer++;
        rotate(s.begin(), s.begin() + 1, s.end());
    }
    return answer;
}