#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string str)
{
    int answer = -1;

    stack<char> s;
    for(auto c:str){
        if(!s.empty()&&s.top()==c)s.pop();
        else s.push(c);
    }
    answer=s.empty()?1:0;
    return answer;
}