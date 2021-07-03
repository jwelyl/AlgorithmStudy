#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> p;
typedef pair<long long,pair<int,int>> pp;
const int MAX=10001;
const long long INF=1LL<<61;
vector<p> adj[MAX];
bool visit[MAX][21];
long long dist[MAX][21];

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N,M,K; cin>>N>>M>>K;
  for(int i=0; i<M; i++){
    int s, e, c; cin>>s>>e>>c;
    s--;e--;
    adj[s].push_back({e,c});
    adj[e].push_back({s,c});
  }
  for(int i=0; i<N; i++)for(int j=0; j<21; j++){
    dist[i][j]=INF;
  }
  priority_queue<pp,vector<pp>,greater<pp>> pq;
  pq.push({0,{0,0}});
  for(int i=0; i<21; i++)dist[0][i]=0;
  while(!pq.empty()){
    int curr, k;
    do{
      curr=pq.top().second.first; k=pq.top().second.second;
      pq.pop();
    }while(!pq.empty()&&visit[curr][k]);
    if(visit[curr][k])break;
    visit[curr][k]=true;
    for(auto n : adj[curr]){
      int next=n.first;long long cost=n.second;
      if(dist[next][k]>dist[curr][k]+cost){
        dist[next][k]=dist[curr][k]+cost;
        pq.push({dist[next][k],{next,k}});
      }
      if(k<K && dist[next][k+1]>dist[curr][k]){
        dist[next][k+1]=dist[curr][k];
        pq.push({dist[next][k+1],{next,k+1}});
      }
    }
  }
  long long ans=INF;
  for(int i=0; i<=K; i++)ans=min(ans,dist[N-1][i]);
  cout<<ans;
}
