#include <iostream>
#include <vector>
using namespace std;
const int MAX=201;
const int INF=100000000;

vector<int> adj[MAX];
int ori[MAX][MAX], dist[MAX][MAX], ans[MAX][MAX];
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N,M; cin>>N>>M;
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)dist[i][j]=INF;
  for(int i=0; i<M; i++){
    int s,e,c; cin>>s>>e>>c;
    s--;e--;
    adj[s].push_back(e);
    adj[e].push_back(s);
    dist[s][e]=ori[s][e]=c;
    dist[e][s]=ori[e][s]=c;
  }
  for(int i=0; i<N; i++)dist[i][i]=0;
  for(int k=0; k<N; k++)
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
          dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      for(int k : adj[i])
        if(dist[i][j]==ori[i][k]+dist[k][j])ans[i][j]=k+1;
  
  for(int i=0; i<N; i++){for(int j=0; j<N; j++){
    if(i==j)cout<<"- ";
    else cout<<ans[i][j]<<" ";
  }
    cout<<'\n';
  }
}
