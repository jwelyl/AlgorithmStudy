#include <iostream>
#include <queue>
#define RAN (ty>=R||tx>=C||ty<0||tx<0)
using namespace std;
int R,C;
int MX,LX,MY,LY;
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
char map[11][11];
bool visit[11][11];
queue<pair<int,int>> under;

void bfs(int r,int c){
  queue<pair<int,int>> q;
  q.push({r,c});
  while(!q.empty()){
    int cy=q.front().first, cx=q.front().second;
    q.pop();
    int n=0;
    for(int i=0; i<4; i++){
      int tx=cx+dx[i], ty=cy+dy[i];
      if(RAN){n++;continue;}
      if(map[ty][tx]=='.')n++;
    }
    if(n>2)under.push({cy,cx});
    for(int i=0; i<4; i++){
      int tx=cx+dx[i], ty=cy+dy[i];
      if(RAN||visit[ty][tx]) continue;
      visit[ty][tx]=true;
      if(map[ty][tx]=='X')q.push({ty,tx});
    }
  }
}
int main(void){
  LX=LY=987654321;
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>R>>C;
  for(int i=0; i<R; i++)for(int j=0; j<C; j++)
    cin>>map[i][j];
  for(int i=0; i<R; i++)for(int j=0; j<C; j++){
    if(map[i][j]=='X')bfs(i,j);
  }
  while(!under.empty()){
    int y=under.front().first, x=under.front().second;
    under.pop();
    map[y][x]='.';
  }
  for(int i=0; i<R; i++)for(int j=0; j<C; j++)if(map[i][j]=='X'){
    MX=max(MX,j);LX=min(LX,j);MY=max(MY,i);LY=min(LY,i);
  }
  for(int i=LY; i<=MY; i++){for(int j=LX; j<=MX; j++)cout<<map[i][j];
  cout<<'\n';
  }
}
