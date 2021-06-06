#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> p;
const int INF=1000000000;
int N,M;
int Dx[4]={1,-1,0,0}, Dy[4]={0,0,1,-1};
int map[25][25];
vector<pair<p,p>> guest;
int ans=-1;
int check[404];
int getDist(int sy, int sx, int dy, int dx){
  queue<p> q;
  bool visit[N+1][N+1];
  int cost[N+1][N+1];
  memset(visit,false,sizeof(visit));
  for(int i=0; i<N;i++)for(int j=0; j<N;j++)cost[i][j]=INF;
  q.push({sy,sx});
  visit[sy][sx]=true;
  cost[sy][sx]=0;
  while(!q.empty()){
    int y=q.front().first;
    int x=q.front().second;
    q.pop();
    if(y==dy&&x==dx)break;
    for(int i=0; i<4; i++){
      int xx=x+Dx[i], yy=y+Dy[i];
      if(xx<0||yy<0||xx>=N||yy>=N||visit[yy][xx]||map[yy][xx]==1)continue;
      visit[yy][xx]=true;
      cost[yy][xx]=cost[y][x]+1;
      q.push({yy,xx});
    }
  }
  return cost[dy][dx];
}

void permu(int cy, int cx, int fuel, int num){
  if(num==M){
    ans=max(ans,fuel);
    return;
  }
  priority_queue<pair<p,p>,vector<pair<p,p>>,greater<pair<p,p>>> pq;
  int destDist[M];
  for(int i=0; i<M; i++)if(!check[i]){
    int sy=guest[i].first.first, sx=guest[i].first.second;
    int dy=guest[i].second.first, dx=guest[i].second.second;
    int dist=getDist(cy,cx,sy,sx);
    pq.push({{dist,sy},{sx,i}});
    destDist[i]=getDist(sy,sx,dy,dx);
  }
  int n=pq.top().second.second;
  int dist1=pq.top().first.first;
  int dist2=destDist[n];
  if(dist1==INF||dist2==INF)return;
  int dy=guest[n].second.first, dx=guest[n].second.second;
  if(fuel-dist1-dist2>=0){
    check[n]=true;
    fuel=fuel-dist1-dist2+dist2*2;
    permu(dy,dx,fuel,num+1);
  }
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int S;cin>>N>>M>>S;
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)cin>>map[i][j];
  int sy,sx;cin>>sy>>sx;
  sy--,sx--;
  for(int i=0; i<M; i++){
    int sy,sx,dy,dx; cin>>sy>>sx>>dy>>dx;
    sy--,sx--,dy--,dx--;
    guest.push_back({{sy,sx},{dy,dx}});
  }
  permu(sy,sx,S,0);
  cout<<ans;
}


