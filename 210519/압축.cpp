#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
string chartostr(const char &c){
    char ret[2]={c,'\0'};

    return (string)ret;
}
vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string,int> idx;
    int num=1;
    for(char c= 'A'; c<='Z'; c++)idx[chartostr(c)]=num++;
    for(int i=0; i<msg.size();){
        string temp = msg.substr(i,1);

        while(idx[temp]>0&&++i<msg.size()){
            temp+=msg.substr(i,1);
        }
        int n=temp.size()-1;
        if(i==msg.size())n++;
        answer.push_back(idx[temp.substr(0,n)]);
        idx[temp]=num++;
    }
    return answer;
}