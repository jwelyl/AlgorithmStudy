#include <iostream>
using namespace std;

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int ddx[4][9]={
	{-2,-1,-1,0,0,0,0,1,1},
	{0,1,-1,-1,1,-2,2,-1,1},
	{2,1,1,0,0,0,0,-1,-1},
	{0,1,-1,-1,1,-2,2,-1,1}
	
},
ddy[4][9]{
	{0,1,-1,1,-1,2,-2,1,-1},
	{2,1,1,0,0,0,0,-1,-1},
	{0,1,-1,1,-1,2,-2,1,-1},
	{-2,-1,-1,0,0,0,0,1,1}
};
int rate[9]={5,10,10,7,7,2,2,1,1};
int map[500][500];

int main(void){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N; cin>>N;
  for(int i=0; i<N; i++)for(int j=0; j<N; j++)cin>>map[i][j];
  int y=N/2,x=N/2,dir=0, cnt=1;
  long long ans=0;
  while(y!=0||x!=0){
    int n=2,tx,ty,px,py,cost;
    while(n--&&(y!=0||x!=0)){
      	for(int i=cnt; i>0; i--){
			if(x==0&&y==0)break;
			tx=x+dx[dir], ty=y+dy[dir];
		
			int sand=map[ty][tx];
			for(int j=0; j<9; j++){
				px=tx+ddx[dir][j], py=ty+ddy[dir][j];
				cost=(sand*rate[j])/100;
				map[ty][tx]-=cost;
				if(px<0||py<0||px>=N||py>=N){ans+=cost;}
				else {map[py][px]+=cost;}
			}
			py=ty+dy[dir],px=tx+dx[dir];
			if(px<0||py<0||px>=N||py>=N){ans+=map[ty][tx];}
			else {map[py][px]+=map[ty][tx];}
			map[ty][tx]=0;
			x=tx;y=ty;
		}
    	dir=(dir+1)%4;
    }
    cnt++;
  }
	
  cout<<ans<<'\n';
}

