#include <iostream>
#include <queue>
#define RAN (ty<0||tx<0||ty>=N||tx>=M)
using namespace std;
typedef pair<int,int> p;
const int MAX=1001;
struct Sand{
  int n,s;
};

int dx[8]={0,1,1,1,0,-1,-1,-1}, dy[8]={-1,-1,0,1,1,1,0,-1};
int cost[MAX][MAX];
Sand map[MAX][MAX];
int N,M,ans;
bool visit[MAX][MAX];
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N>>M;
  for(int i=0; i<N; i++)for(int j=0; j<M; j++){
    char a; cin>>a; 
    if(a=='.')map[i][j].n=0;
    else map[i][j].n=a-'0';
    cost[i][j]=987654321;
  }
  queue<p> q;
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)if(map[i][j].n>0){
    int cnt=0;
    for(int k=0; k<8; k++){
      int ty=i+dy[k], tx=j+dx[k];
      if(RAN||map[ty][tx].n==0)continue;
      cnt++;
    }
    map[i][j].s=8-cnt;
    if(map[i][j].s>=map[i][j].n){
      cost[i][j]=1;
      visit[i][j]=true;
      q.push({i,j});
    }
  }
  while(!q.empty()){
    int y=q.front().first, x=q.front().second;
    q.pop();
    ans=max(ans,cost[y][x]);
    for(int i=0; i<8; i++){
      int ty=y+dy[i], tx=x+dx[i];
      if(RAN||map[ty][tx].n==0)continue;
      map[ty][tx].s++;
      if(map[ty][tx].s>=map[ty][tx].n&&!visit[ty][tx]){
        cost[ty][tx]=min(cost[ty][tx],cost[y][x]+1);
        map[ty][tx].n=0;
        q.push({ty,tx});
      }
    }
  }
  cout<<ans;  
}
