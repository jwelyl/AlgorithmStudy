#include <iostream>
#include <string>
#include <stack>

using namespace std;
int solution(string s) {
    int answer = 0;
    stack<char> stk;
    
    for(int i = 0; i < s.size(); i++) {
        if(stk.empty() || stk.top() != s[i]) stk.push(s[i]);
        else stk.pop();
    }
    if(stk.empty()) return 1;
    else return 0;
    
}