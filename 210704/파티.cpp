#include <iostream>
#include <vector>
using namespace std;
const int INF=987654;
const int MAX=1001;
typedef pair<int,int> p;
int adj[MAX][MAX];
int dist[MAX][MAX];

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N,M,X; cin>>N>>M>>X;
  for(int i=0; i<N; i++)for(int j=0; j<N; j++){
    if(i==j)dist[i][j]=0;
    else dist[i][j]=INF;
  }
  for(int i=0; i<M; i++){
    int s,e,c;
    cin>>s>>e>>c; s--,e--;
    dist[s][e]=c;
  }
  for(int k=0; k<N; k++)
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
  
  int ans=0;
  for(int i=0; i<N; i++)ans=max(ans,dist[i][X-1]+dist[X-1][i]);
  cout<<ans;
}
