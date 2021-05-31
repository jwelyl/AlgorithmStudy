#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct info{
    int x, y, dir, cnt;
    info(){info(0,0,0,0);}
    info(int a, int b, int c, int d){
        x=a,y=b,dir=c, cnt=d;
    }
};
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int mm[4][4];
vector<pair<int,int>> vc[7];


int getDist(pair<int,int> s, pair<int,int> e, int map[][4]){
    int sx=s.second,sy=s.first,ex=e.second,ey=e.first;
    info visit[4][4];

    for(int i=0; i<4; i++)for(int j=0; j<4; j++)visit[i][j]=info(0,0,0,10000);
    
    queue<info>q;
    info start=info(sx,sy,-1,0);
    q.push(start);
    visit[sy][sx]=start;
    while(!q.empty()){
        info c = q.front();
        q.pop();
        int x=c.x,y=c.y,dir=c.dir,cnt=c.cnt;

        for(int i=0; i<4; i++){
            int xx=x+dx[i],yy=y+dy[i], dd=i;

            if(xx>=4||yy>=4||xx<0||yy<0)continue;
            info n=info(xx,yy,dd,cnt+1);
            
            if(visit[yy][xx].cnt>n.cnt){
                q.push(n);
                visit[yy][xx]=n;
            }
        }
        
        for(int i=0; i<4; i++){
            int xx= x+dx[i], yy=y+dy[i];
            if(xx<0||yy<0||xx>3||yy>3)continue;
            while(map[yy][xx]==0||xx<3||yy<3||xx>0||yy>0){
                xx+=dx[i];yy+=dy[i];
            }
            info n=info(xx,yy,i,cnt+1);
            if(visit[yy][xx].cnt>n.cnt){
                q.push(n);
                visit[yy][xx]=n;
            }
        }
    }
    return visit[ey][ex].cnt;
}
int card(int c,pair<int,int> curr){
    if(c==0)return 0;
    int res=10000000;
    int tmap[4][4]={0,};

    for(int i=0; i<4; i++)for(int j=0; j<4; j++){
        if(c&(1<<mm[i][j]))tmap[i][j]=mm[i][j];
        else tmap[i][j]=0;
    }
    
    for(int i=1; i<=6; i++){
        if((1<<i)&c){
            int temp,temp2,tt;

            temp=getDist(curr,vc[i][0],tmap)+getDist(vc[i][0],vc[i][1],tmap);
            temp2=getDist(curr,vc[i][1],tmap)+getDist(vc[i][1],vc[i][0],tmap);
            
            cout<<i<<" "<<curr.first<<" "<<curr.second<<" "<<min(temp,temp2)<<'\n';
            
            int tres=temp+card(c&(~(1<<i)),vc[i][1]);
            int tres2=temp2+card(c&(~(1<<i)),vc[i][0]);
            tres=min(tres,tres2);
            
            res=min(res,tres);
        }
    }
    return res;
}

int solution(vector<vector<int>> board, int r, int cc) {
    pair<int,int> start={r,cc};
    int answer = 0,c=0,cnt=0;
    for(int i=0; i<4; i++)for(int j=0; j<4; j++){
        mm[i][j]=board[i][j];
        if(mm[i][j]>0){
            cnt++;
            if(!((1<<mm[i][j])&c))
                c|=(1<<mm[i][j]);
            vc[mm[i][j]].push_back({i,j});
        }
    }
    
    answer=card(c,start);

    return answer+cnt;
}