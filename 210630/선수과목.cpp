#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int indegree[1001];
vector<int> v[1001];
int ans[1001];
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N,M;
  cin>>N>>M;
  for(int i=0; i<M; i++){
    int a,b; cin>>a>>b;
    a--,b--;
    v[a].push_back(b);
    indegree[b]++;
  }
  queue<int> q;
  for(int i=0; i<N; i++)if(indegree[i]==0){
    ans[i]=1; q.push(i);
  }
  while(!q.empty()){
    int curr= q.front(); q.pop();
    for(auto next : v[curr]){
      indegree[next]--;
      if(indegree[next]==0){
        ans[next]=ans[curr]+1;
        q.push(next);
      }
    }
  }
  for(int i=0; i<N; i++)cout<<ans[i]<<" ";
}
