#include <iostream>
#include <queue>
#define RAN (ty<0||tx<0||ty>=N||tx>=M)
using namespace std;
const int INF=987654321;
const int MAX=1001;
typedef pair<pair<int,int>,int> pp;
bool map[MAX][MAX];
int N,M,K,dist[MAX][MAX][11];
int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};

void bfs(){
  queue<pp> q;
  q.push({{0,0},0});
  dist[0][0][0]=1;
  while(!q.empty()){
    int y=q.front().first.first, x=q.front().first.second;
    int cnt=q.front().second; q.pop();
    for(int i=0; i<4; i++){
      int ty=y+dy[i], tx=x+dx[i];
      if(RAN)continue;
      if(map[ty][tx]){
        if(cnt<K&&dist[ty][tx][cnt+1]>dist[y][x][cnt]+1){
          dist[ty][tx][cnt+1]=dist[y][x][cnt]+1;
          q.push({{ty,tx},cnt+1});
        }
      }
      else{
        if(dist[ty][tx][cnt]>dist[y][x][cnt]+1){
          dist[ty][tx][cnt]=dist[y][x][cnt]+1;
          q.push({{ty,tx},cnt});
        }
      }
    }
  }
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N>>M>>K;
  for(int i=0; i<=K; i++)for(int j=0; j<N; j++)for(int k=0; k<M; k++)
    dist[j][k][i]=INF;
  for(int i=0; i<N; i++){
    string str; cin>>str;
    for(int j=0; j<M; j++)map[i][j]=str[j]-'0';
  }
  bfs();
  int ans=INF;
  for(int i=0; i<=K; i++)
    ans=min(ans,dist[N-1][M-1][i]);
  if(ans==INF)cout<<-1;
  else cout<<ans;
}
