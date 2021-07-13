#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int price[501], indegree[501];
int ans[501];
vector<int> adj[501];
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N; cin>>N;
  priority_queue<int, vector<int>, greater<int>>pq;
  for(int i=0; i<N; i++){
    int a,b; cin>>a;
    price[i]=a;
    while(cin>>b){
      if(b==-1)break;
      adj[b-1].push_back(i);
      indegree[i]++;
    }
  }
  for(int i=0; i<N; i++)if(indegree[i]==0){pq.push(i);ans[i]=price[i];}
  while(!pq.empty()){
    int curr= pq.top(); pq.pop();
    for(auto next : adj[curr]){
      ans[next]=max(ans[next],ans[curr]+price[next]);
      indegree[next]--;
      if(indegree[next]==0)pq.push(next);
    }
  }
  for(int i=0; i<N; i++)cout<<ans[i]<<'\n';
}

