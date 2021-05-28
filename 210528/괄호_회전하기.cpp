#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(const string& str){
    stack<char> s;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            s.push(str[i]);
            continue;
        }
        else if(s.empty())return false;
        if(str[i]==')'&&s.top()=='(')s.pop();
        else if(str[i]=='}'&&s.top()=='{')s.pop();
        else if(str[i]==']'&&s.top()=='[')s.pop();
        else return false;
    }
    if(s.size()==0)
        return true;
    else return false;
}

int solution(string s) {
    int answer = 0;
    int size=s.size();
    for(int i=0; i<size; i++){
        string temp=s.substr(i)+s.substr(0,i);
        if(check(temp))answer++;
    }
    return answer;
}