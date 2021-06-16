#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX=10001;
vector<int> adj[MAX];
int cost[MAX];
int dp[MAX][2];
int recur(int cur, int isSuper, int prev=-1){
  int &res=dp[cur][isSuper];
  if(res!=-1)return res;
  res=0;
  if(isSuper)res=cost[cur];
  for(int next : adj[cur])if(next!=prev){
    if(isSuper){
      res+=recur(next,0,cur);
    }
    else{
      res+=max(recur(next,0,cur),recur(next,1,cur));
    }
  }
  return res;
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N;cin>>N;
  memset(dp,-1,sizeof(dp));
  for(int i=0; i<N; i++){
    int c; cin>>c;
    cost[i]=c;
  }
  for(int i=0; i<N-1; i++){
    int s, e; cin>>s>>e;
    s--,e--;
    adj[s].push_back(e);
    adj[e].push_back(s);
  }
  cout<<max(recur(0,1),recur(0,0));
}
