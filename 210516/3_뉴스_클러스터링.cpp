#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int MUL=65536;
char tch[1001];
string lowerCase(string str){
    for(int i=0; i<str.size(); i++){
        tch[i]=str[i];
        if(tch[i]>='A'&&tch[i]<='Z')tch[i]+=32;
    }
    tch[str.size()]='\0';

    return (string)tch;
}
vector<string> makeSet(string str){
    vector<string> res;
    for(int i=0,j=1; j<str.size(); i++,j++){
        if(str[i]>='a'&&str[i]<='z'&&str[j]>='a'&&str[j]<='z'){
            res.push_back(str.substr(i,2));
        }
    }
    return res;
}
bool compare(string s, string d){
    if(s.size()!=d.size())return false;
    for(int i=0; i<s.size(); i++)
        if(s[i]!=d[i])return false;
    return true;
}
vector<string> makeInter(vector<string> s1, vector<string> s2){
    vector<string> res;
    for(string str : s1){
        bool isIn=false;
        for(auto it = s2.begin(); it!=s2.end(); it++ ){
            isIn=compare(str,*it);
            if(isIn){
                s2.erase(it);
                break;
            }
        }
        if(isIn)res.push_back(str);
    }
    return res;
}
int solution(string str1, string str2) {
    int answer = 0;
    vector<string> set1,set2;
    set1=makeSet(lowerCase(str1));
    set2=makeSet(lowerCase(str2));
    
    vector<string> interset=makeInter(set1,set2);
    
    int n1=interset.size(), n2=set1.size()+set2.size()-interset.size();

    if(n2==0){
        answer=MUL;
    }
    else answer=(((double)n1)/n2*MUL);
    return answer;
}