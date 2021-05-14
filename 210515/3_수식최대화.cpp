#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <iostream>
using namespace std;
int strtoint(string str){
    int res=0;
    for(int i=0; i<str.size(); i++){
        res*=10;
        res+=str[i]-'0';
    }
    return res;
}

long long cal(long long n1, long long n2, char op){
    long long res=0;
    if(op=='+')res=n1+n2;
    else if(op=='-')res=n1-n2;
    else res=n1*n2;
    return res;
}
vector<string> str;
char arr[3];
void makeCombi(int check, int step){
    if(step==3){
        str.push_back((string)arr);
        return;
    }
    for(int i=0; i<3; i++)if(!(check&(1<<i))){
        arr[step]=i+1+'0';
        makeCombi(check|(1<<i),step+1);
    }
}

long long solution(string expression) {
    long long answer= 0;
    stack<long long> s;
    stack<char> o;
    unordered_map<char,int>op;
    vector<long long> num;
    vector<char> oper;
    for(int i=0; i<9; i++)op[i+'0']=0;
    op['+']=1;
    op['-']=1;
    op['*']=1;
    makeCombi(0,0);
    for(int i=0, j=0; i<expression.size(); i++){
        while(j<expression.size()&&op[expression[j]]==0)j++;
        num.push_back(strtoint(expression.substr(i,j-i))*1LL);
        i=j;
        if(j<expression.size()){
            oper.push_back(expression[j]);
            j++;
        }
    }
    for(int a=0; a<str.size(); a++){
        op['+']=str[a][0]-'0';
        op['-']=str[a][1]-'0';
        op['*']=str[a][2]-'0';
        for(int i=0,j=0; i<num.size(); i++){
            s.push(num[i]);
            while(!o.empty()&&s.size()>1&&j<oper.size()&&op[o.top()]>op[oper[j]]){
                char p=o.top();o.pop();
                long long n2=s.top();s.pop();
                long long n1=s.top();s.pop();
                if(!o.empty()&&p=='-'&&o.top()=='-')p='+';
                s.push(cal(n1,n2,p));
            }
            if(j<oper.size())o.push(oper[j]);
            j++;
        }

        while(!o.empty()&&s.size()>1){
            char p = o.top(); o.pop();
            long long n2= s.top(); s.pop();
            long long n1= s.top(); s.pop();
            if(!o.empty()&&p=='-'&&o.top()=='-')p='+';
            s.push(cal(n1,n2,p));
        }
        
        answer=abs(s.top())>answer?abs(s.top()):answer;
        s.pop();
    }
    
    return answer;
}
