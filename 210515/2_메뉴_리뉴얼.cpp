#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,pair<int,string>> pis;
unordered_map<string,int> hstr;
set<string> s;

void getcombi(string& str, string next, int pos){
    for(int i=pos; i<str.size(); i++){
        string temp=next+str.substr(i,1);
        sort(temp.begin(),temp.end());
        hstr[temp]++;
        s.insert(temp);
        getcombi(str,temp,i+1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto s : orders)
        getcombi(s,"",0);
    priority_queue<pis,vector<pis>> pq;
    for(auto it : s)
        pq.push({it.size(),{hstr[it],it}});
    for(int i=course.size()-1; i>=0; i--){
        while(course[i]<pq.top().first)pq.pop();
        int n=pq.top().second.first;
        if(n<2)continue;
        while(pq.top().second.first==n){
            answer.push_back(pq.top().second.second);
            pq.pop();
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
