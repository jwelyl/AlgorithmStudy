#include <string>
#include <vector>

using namespace std;
vector<int>adj[300001];
long long val[300001];
long long answer=0;
long long recur(int curr, int prev=-1){
    long long num=val[curr];
    for(auto next : adj[curr])if(prev!=next){
         num+=recur(next,curr);
    }
    val[curr]=num;
    answer+=1LL*abs(num);
    return val[curr];
}

long long solution(vector<int> a, vector<vector<int>> edges) {

    for(int i=0; i<a.size(); i++)val[i]=(long long)a[i];
    for(auto edge : edges){
        int s=edge[0], e=edge[1];
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    long long n=0;
    for(int i=0; i<a.size(); i++)n+=(long long)a[i];
    if(n!=0)return -1;
    recur(0);
    return answer;
}