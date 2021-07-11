#include <iostream>
#include <queue>
using namespace std;

const int MAX=1<<6;

int map[MAX][MAX], dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int temp[MAX][MAX];
int N,Q,q[1000],ans=0;
bool isdel[MAX][MAX],visit[MAX][MAX];

void divrot(int x, int y, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      temp[y+j][x+n-1-i]=map[y+i][x+j];
  }
  for(int i=0; i<n; i++)for(int j=0; j<n; j++)
    map[y+i][x+j]=temp[y+i][x+j];
}

void setdiv(int n){
  for(int i=0; i<N; i+=n)
    for(int j=0; j<N; j+=n)
      divrot(j,i,n);
}

void delice(void){
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
	  int cnt=0;
      for(int k=0; k<4; k++){
        int x=j+dx[k], y=i+dy[k];
        if((x<0||y<0||x>=N||y>=N))cnt++;
        else if(map[y][x]==0)cnt++;
      }
      if(cnt>1)isdel[i][j]=true;
      else isdel[i][j]=false;
    }
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)if(isdel[i][j]&&(map[i][j]>0))map[i][j]--;
}

int bfs(int y, int x){
  visit[y][x]=true;
  queue<pair<int,int>> q;
  q.push({y,x});
  int res=1;
  ans=map[y][x];
  while(!q.empty()){
    int y_=q.front().first;
    int x_=q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
      int xx=x_+dx[i],yy=y_+dy[i];
      if(xx<0||yy<0||xx>=N||yy>=N)continue;
      if(map[yy][xx]>0&&!visit[yy][xx]){
        visit[yy][xx]=true;
        res++;
		ans+=map[yy][xx];
        q.push({yy,xx});
      }
    }
  }
  return res;
}

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin>>N>>Q;
  N=1<<N;
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)cin>>map[i][j];
  for(int i=0; i<Q; i++)cin>>q[i];
  
  for(int i=0; i<Q; i++){
    setdiv(1<<q[i]);
    delice();
  }
  int res=0,res2=0,ice=0;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++){
		ice+=map[i][j];
      if(!visit[i][j]&&map[i][j]>0){
		  int temp=bfs(i,j);
		  if(res<temp){
			  res=temp;
			  res2=ans;
		  }
      }
	}
  cout<<ice<<'\n'<<res;
}

