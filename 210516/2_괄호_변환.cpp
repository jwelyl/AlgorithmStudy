#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
char tch[1001];
bool isRight(string str){
    if(str.size()==0)return true;
    stack<char> s;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='(')s.push(str[i]);
        else if(str[i]==')'){
            if(s.empty())return false;
            s.pop();
        }
    }
    if(!s.empty())return false;
    return true;
}
string reverse(string str){
    string res=str.substr(1,str.size()-2);
    for(int i=0,j=0; i<res.size(); i++){
        if(res[i]==')')tch[j++]='(';
        else tch[j++]=')';
    }
    tch[res.size()]='\0';
    res=(string)tch;
    
    return res;
}
string recursive(string str){
    if(str.size()==0)return str;
    int l =0, r =0, idx =0;
    for(; idx<str.size(); idx++){
        if(l!=0&&l==r)break;
        if(str[idx]=='(')l++;
        else if(str[idx]==')')r++;
    }
    string u=str.substr(0,idx);
    string v=str.substr(idx);
    
    string res;
    if(isRight(u)){
        res=u+recursive(v);
    }
    else{
        res="("+recursive(v)+")"+reverse(u);
    }
    return res;
}
string solution(string p) {
    string answer = recursive(p);
    
    return answer;
}
