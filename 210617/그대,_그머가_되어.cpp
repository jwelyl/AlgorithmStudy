#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int>adj[1001];
int cnt[1001],visit[1001];
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int a,b;cin>>a>>b;a--;b--;
  if(a==b){cout<<0;return 0;}
  int N,M;cin>>N>>M;
  for(int i=0; i<M; i++){
    int s,e;cin>>s>>e;
    s--;e--;
    adj[s].push_back(e);
    adj[e].push_back(s);
  }
  bool flag =false;
  queue<int> q;
  q.push(a);visit[a]=true;
  while(!q.empty()){
    int curr=q.front();
    q.pop();
    if(curr==b){flag=true;break;}
    for(auto next:adj[curr])if(!visit[next]){
      visit[next]=true;
      cnt[next]=cnt[curr]+1;
      q.push(next);
    }
  }
  if(!flag)cnt[b]=-1;
  cout<<cnt[b];
}


