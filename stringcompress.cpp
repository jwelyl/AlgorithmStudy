#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
int num(int n){
    int res=0;
    while(n){
        res++;
        n/=10;
    }
    return res;
}
bool compare(string s, string e){
    if(s.size()!=e.size())return false;
    for(int i=0; i<s.size(); i++)
        if(s[i]!=e[i])return false;
    return true;
}
int solution(string s) {
    int answer=s.size(),n=1;
    while(n<=s.size()/2){
        vector<string> v;
        int i=0;
        while(i+n<=s.size()){
            string temp=s.substr(i,n);
            v.push_back(temp);
            i+=n;
        }
        if(i<s.size())v.push_back(s.substr(i));


        n++;
        int tans=0;
        
        for(int i=0,j=0; i<v.size);){
            int nn=0;
            while(j<v.size()&&compare(v[i],v[j])){
                nn++;
                j++;
            }
            if(nn==1){
                tans+=v[i].size();
            }
            else{
                tans+=v[i].size()+num(nn);
            }
            i=j;
        }
        answer=tans<answer?tans:answer;
    }
    return answer;
}
