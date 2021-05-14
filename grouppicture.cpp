#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
set<string> s;
char arr[8]={'A','C','F','J','M','N','R','T'},
temp[8]={'\0','\0','\0','\0','\0','\0','\0','\0'};

void makeCombi(int check, int step){
    if(step==8){
        s.insert(string(temp));
        return;
    }
    for(int i=0; i<8; i++)if(!(check&(1<<i))){
        temp[step]=arr[i];
        makeCombi(check|(1<<i),step+1);
    }
}

void notEqual(string str){
    char first=str[0], second=str[2];
    int n =str[4]-'0';
    set<string> ts;
    for(string t : s){
        int fn=0, sn=0;
        for(int i=0; i<t.size(); i++){
            if(t[i]==first)fn=i;
            if(t[i]==second)sn=i;
        }
        if(bs(fn-sn)-1!=n)ts.insert(t);
    }
    for(string ss : ts)s.erase(ss);
}

void notBigger(string str){
    char first=str[0], second=str[2];
    int n =str[4]-'0';
    set<string> ts;
    for(string t : s){
        int fn=0, sn=0;
        for(int i=0; i<t.size(); i++){
            if(t[i]==first)fn=i;
            if(t[i]==second)sn=i;
        }
        if(abs(fn-sn)-1<=n)ts.insert(t);
    }
    for(string ss : ts)s.erase(ss);
}
void notSmaller(string str){
    char first=str[0], second=str[2];
    int n =str[4]-'0';
    set<string> ts;
    for(string t : s){
        int fn=0, sn=0;
        for(int i=0; i<t.size(); i++){
            if(t[i]==first)fn=i;
            if(t[i]==second)sn=i;
        }
        if(abs(fn-sn)-1>=n)ts.insert(t);
    }
    for(string ss : ts)s.erase(ss);
}

int solution(int n, vector<string> data) {
    int answer = 0;
    makeCombi(0,0);
    for(string str : data){

        if(str[3]=='='){
            notEqual(str);
        }
        else if(str[3]=='>'){
            notBigger(str);
        }
        else{
            notSmaller(str);
        }
    }
    answer=s.size();
    
    return answer;
}
