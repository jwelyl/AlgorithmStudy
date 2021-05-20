#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

string solution(int k, int t, int m, int p) {
    string answer = "";
    unordered_map<int,string> hm;
    stack<string> s;
    int n=0;
    char a='0';
    for(int i=0;i<10; i++)hm[i]=a++;
    a='A';
    for(int i=10; i<16; i++)hm[i]=a++;
    string str="0";
    while(str.size()<=100000){
        int nn=++n;
        while(nn){
            int mod=nn%k;
            nn/=k;
            s.push(hm[mod]);
        }
        while(!s.empty()){
            str+=s.top();s.pop();
        }
    }
    for(int i=p-1,n=0;n<t; i+=m,n++)
        answer+=str[i];
    return answer;
}