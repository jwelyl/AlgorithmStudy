#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> p;
const int INF=1000000;
struct Info{
    int y,x,cnt;
    Info(int y, int x, int cnt){
        this->y=y;
        this->x=x;
        this->cnt=cnt;
    }
    Info(){Info(0,0,0);}
};
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
vector<p> card[6];
int limit;

int get(int& y1,int& x1,int& y2,int& x2,const vector<vector<int>>& v, const int& check){
    int ret=INF;
    queue<Info> q;
    bool visit[4][4]={false};

    q.push(Info(y1,x1,0));
    visit[y1][x1]=true;
    
    while(!q.empty()){
        Info curr=q.front();
        q.pop();
        if(curr.y==y2&&curr.x==x2)
            ret=min(ret,curr.cnt);
        for(int i=0; i<4; i++){
            int x=dx[i]+curr.x, y=dy[i]+curr.y;
            if(x<0||y<0||x>3||y>3)continue;
            Info next = Info(y,x,curr.cnt+1);
            if(!visit[y][x]){
                q.push(next);
                visit[y][x]=true;
            }
            while(x<=3&&y<=3&&x>=0&&y>=0){
                if(v[y][x]>0&&!(check&1<<(v[y][x]-1)))break;
                x+=dx[i],y+=dy[i];
                if(x<0||y<0||x>3||y>3){
                    x-=dx[i],y-=dy[i];break;
                }
            }
            next.y=y;next.x=x;
            if(!visit[y][x]){
                q.push(next);
                visit[y][x]=true;
            }
        }   
    }
    return ret;
}

int recur(int r, int c,int visit, const vector<vector<int>> v){
    if(visit==limit){
        return 0;
    }
    int ret=INF*10;
    for(int i=0; i<6; i++)if(limit&(1<<i))if(!(visit&(1<<i))){
        int y1=card[i][0].first,y2=card[i][1].first
            ,x1=card[i][0].second,x2=card[i][1].second;
        
        int tt1=get(r,c,y1,x1,v,visit)+get(y1,x1,y2,x2,v,visit);
        int tt2=get(r,c,y2,x2,v,visit)+get(y2,x2,y1,x1,v,visit);
        tt1+=recur(y2,x2,visit|(1<<i),v)+2;
        tt2+=recur(y1,x1,visit|(1<<i),v)+2;
        int temp=min(tt1,tt2);
        ret=min(temp,ret);
    }
    return ret;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    for(int i=0; i<board.size();i++)for(int j=0; j<board[i].size(); j++){
        if(board[i][j]>0){
            card[board[i][j]-1].emplace_back(i,j);
            limit|=(1<<(board[i][j]-1));
        }
    }
    answer=recur(r,c,0,board);
    return answer;
}