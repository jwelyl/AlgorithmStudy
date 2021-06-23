#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX=800, INF=987654321;
typedef pair<int,int> p;
int cost[3][MAX];
vector<p> adj[MAX];
bool visit[3][MAX];
int main(void){
  cin.tie(0);ios_base::sync_with_stdio(0);
  int N,E;cin>>N>>E;
  for(int i=0; i<3; i++)for(int j=0; j<MAX; j++)cost[i][j]=INF;
  for(int i=0; i<E; i++){
    int s, e, c; cin>>s>>e>>c;
    s--;e--;
    adj[s].emplace_back(e,c);
    adj[e].emplace_back(s,c);
  }
  int a,b; cin>>a>>b; a--;b--;
  vector<int> v; v.push_back(0); v.push_back(a); v.push_back(b);
  for(int i=0; i<3; i++){
    priority_queue<p,vector<p>,greater<p>> pq;
    pq.push({0,v[i]});
    cost[i][v[i]]=0;
    while(!pq.empty()){
      int curr;
      do{
        curr=pq.top().second;
        pq.pop();
      }while(!pq.empty()&&visit[i][curr]);
      if(visit[i][curr])break;
      visit[i][curr]=true;
      for(auto n : adj[curr]){
        int next=n.first, c=n.second;
        if(cost[i][next]>cost[i][curr]+c){
          cost[i][next]=cost[i][curr]+c;
          pq.push({cost[i][next],next});
        }
      }
    }
  }
  if(cost[0][a]==INF||cost[0][b]==INF||cost[0][N-1]==INF){
    cout<<-1;
    return 0;
  }
  
  cout<<min(cost[0][a]+cost[1][b]+cost[2][N-1],
      cost[0][b]+cost[2][a]+cost[1][N-1]);
}
