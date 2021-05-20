#include <string>
#include <vector>

using namespace std;

bool visit[1<<8];

bool compare(const string& src, const string& dest){
    if(src.size()!=dest.size())return false;
    for(int i=0; i<src.size(); i++){
        if(src[i]=='*')continue;
        if(src[i]!=dest[i])return false;
    }
    return true;
}

void recur(const vector<string>& u, const vector<string>& b, int idx, int check){
    if(idx==b.size()){
        visit[check]=true;
        return;
    }
    for(int i=0; i<u.size(); i++)if(compare(b[idx],u[i])&&!(check&1<<i)){
        recur(u,b,idx+1,check|1<<i);
    }
}

int solution(vector<string> u, vector<string> b) {
    int answer = 0;
    recur(u,b,0,0);
    for(int i=0; i<(1<<8); i++)if(visit[i])answer++;
    return answer;
}