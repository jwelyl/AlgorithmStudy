#include <iostream>
#include <queue>
using namespace std;
const int MAX=1000;
const int INF=98765432;
int N,M;
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int map[MAX][MAX], dist[MAX][MAX][2];
void bfs(int r, int c , int val=1, int cnt=0){
  queue<pair<int,int>> q;
  q.push({r,c});

  dist[r][c][cnt]=val;
  while(!q.empty()){
    int y=q.front().first;
    int x=q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
      int ty=y+dy[i], tx=x+dx[i];
      if(tx<0||ty<0||tx>=M||ty>=N)continue;
      if(map[ty][tx]==1&&cnt==0){
        if(dist[ty][tx][1]>dist[y][x][0]+1)
          bfs(ty,tx,dist[y][x][0]+1,1);
      }
      else if(map[ty][tx]==0){
        if(dist[ty][tx][cnt]>dist[y][x][cnt]+1){
          dist[ty][tx][cnt]=dist[y][x][cnt]+1;
          q.push({ty,tx});
        }
      }
    }
  }
}

int main(void){
  cin.tie(0);ios_base::sync_with_stdio(0);
  cin>>N>>M;
  for(int i=0; i<N; i++){
    string str; cin>>str;
    for(int j=0; j<M; j++)map[i][j]=str[j]-'0';
  }
  for(int k=0; k<2; k++)
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)dist[i][j][k]=INF;
  bfs(0,0);
  if(dist[N-1][M-1][0]==INF&&dist[N-1][M-1][1]==INF)cout<<-1;
  else cout<<min(dist[N-1][M-1][0],dist[N-1][M-1][1]);
}
