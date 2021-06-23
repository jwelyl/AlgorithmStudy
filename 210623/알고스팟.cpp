#include <iostream>
#include <queue>
using namespace std;
const int INF=98765;
bool map[101][101], inq[101][101];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int dist[101][101];
int main(void){
  cin.tie(0);ios_base::sync_with_stdio(0);
  int N,M; cin>>M>>N;
  for(int i=0; i<N; i++)for(int j=0; j<M; j++){dist[i][j]=INF;inq[i][j]=false;}
  for(int i=0; i<N; i++){
    string str; cin>>str;
    for(int j=0; j<M; j++)map[i][j]=str[j]-'0';
  }
  dist[0][0]=0;
  queue<pair<int,int>>q;
  q.push({0,0});
  inq[0][0]=true;

  while(!q.empty()){
    int y=q.front().first, x=q.front().second;
    q.pop();
    inq[y][x]=false;
    for(int i=0; i<4; i++){
      int ty=y+dy[i], tx=x+dx[i];
      if(ty<0||tx<0||ty>=N||tx>=M)continue;
      int tcost=map[ty][tx]?1:0;
      if(dist[ty][tx]>dist[y][x]+tcost){
        dist[ty][tx]=dist[y][x]+tcost;
        if(!inq[ty][tx]){
          q.push({ty,tx});
          inq[ty][tx]=true;
        }
      }
    }
  }
  cout<<dist[N-1][M-1];
}
