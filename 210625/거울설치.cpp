#include <iostream>
#include <queue>
#define RAN (x<0||y<0||x>=N||y>=N)
using namespace std;
const int INF=987654321;
typedef pair<pair<int,int>,pair<int,int>> pp;
int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};
char map[51][51];
int visit[51][51][4];
int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  queue<pp>q;
  int N,ey,ex; cin>>N;
  bool flag=false;
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)for(int k=0; k<4; k++)visit[i][j][k]=INF;
  for(int i=0; i<N; i++)for(int j=0; j<N; j++){
    cin>>map[i][j];
    if(map[i][j]=='#'){
      if(!flag){
        flag=true;
        for(int k=0; k<4; k++)
          q.push({{i,j},{k,0}});
      }
      else{
        ey=i;ex=j;
      }
    }
  }
  int ans=INF;
  while(!q.empty()){
    int y=q.front().first.first, x=q.front().first.second;
    int dir=q.front().second.first, num=q.front().second.second;
    q.pop();
    y+=dy[dir];x+=dx[dir];
    while(!(RAN)){
      if(map[y][x]=='!'&&visit[y][x][dir]>num+1){
        visit[y][x][dir]=num+1;
        q.push({{y,x},{(dir+1)%4,num+1}});
        q.push({{y,x},{(dir+3)%4,num+1}});
      }
      else if(y==ey&&x==ex){
        visit[y][x][dir]=min(visit[y][x][dir],num);break;
      }
      else if(map[y][x]=='*')break;
      y+=dy[dir];x+=dx[dir];
    }
  }
  for(int i=0; i<4; i++){
    ans=min(ans,visit[ey][ex][i]);
  }
  cout<<ans;
}
