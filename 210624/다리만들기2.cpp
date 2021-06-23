#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define RAN (ty<0||tx<0||ty>=N||tx>=M)
using namespace std;
const int INF=987654;
typedef pair<int,int> p;
typedef pair<int,pair<int,int>> pp;
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int N,M,cnt=2;
int map[11][11], bridge[8][8], par[8];
int getpar(int a){
  if(par[a]==-1)return a;
  return par[a]=getpar(par[a]);
}
bool setUnion(int s, int e){
  s=getpar(s);
  e=getpar(e);
  if(s==e)return false;
  par[s]=e;return true;
}
void mapping(int r, int c){
  queue<p> q;
  q.push({r,c});
  map[r][c]=cnt;
  while(!q.empty()){
    p c = q.front(); q.pop();
    int y=c.first, x=c.second;

    for(int i=0; i<4; i++){
      int ty=y+dy[i], tx=x+dx[i];
      if(RAN||map[ty][tx]!=1)continue;
      map[ty][tx]=cnt;
      q.push({ty,tx});
    }
  }
}

void makeBridge(int r, int c){
  int st=map[r][c];
  
  for(int i=0; i<4; i++){
    int ty=r+dy[i], tx=c+dx[i];
    if(RAN||map[ty][tx]==st)continue;
    int count=0,en=0;
    while(!(RAN)){
      if(map[ty][tx]>0){
        en=map[ty][tx];
        break;
      }
      ty+=dy[i], tx+=dx[i]; count++;
    }
    if(count<=1||en<2)continue;
    bridge[st][en]=min(count,bridge[st][en]);
    bridge[en][st]=bridge[st][en];
  }
}
int main(void){
  cin.tie(0);ios_base::sync_with_stdio(0);
  cin>>N>>M;
  fill(par,par+8,-1);
  for(int i=0; i<8; i++)for(int j=0; j<8; j++)bridge[i][j]=INF;
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)cin>>map[i][j];
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)if(map[i][j]==1){mapping(i,j);cnt++;}
  for(int i=0; i<N; i++)for(int j=0; j<M; j++)if(map[i][j]>0)makeBridge(i,j);
  priority_queue<pp,vector<pp>,greater<pp>>pq;
  for(int i=0; i<8; i++)for(int j=0; j<8; j++)if(bridge[i][j]!=INF)
    pq.push({bridge[i][j],{i,j}});
  int ans=0;
  while(!pq.empty()){
    int s=pq.top().second.first, e=pq.top().second.second;
    int cost=pq.top().first;
    pq.pop();
    if(setUnion(s,e))ans+=cost;
  }
  bool flag=true;int s=getpar(2);
  for(int i=3; i<cnt; i++)if(getpar(i)!=s){
    flag=false;break;
  }
  if(!flag)cout<<-1;
  else cout<<ans;
}
