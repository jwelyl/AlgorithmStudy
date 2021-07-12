#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int indegree[32001];
vector<int> adj[32001];
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N,M; cin>>N>>M;
  
  for(int i=0; i<M; i++){
    int a, b; cin>>a>>b;
    indegree[b]++;
    adj[a].push_back(b);
  }
  queue<int> q;
  for(int i=1; i<=N; i++)if(indegree[i]==0)q.push(i);
  while(!q.empty()){
    int curr= q.front();
    q.pop();
    cout<<curr<<' ';
    for(auto next : adj[curr]){
      indegree[next]--;
      if(indegree[next]==0)
        q.push(next);
    }
  }
}

