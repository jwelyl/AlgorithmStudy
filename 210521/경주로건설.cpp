#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int INF=1000000000;
typedef pair<pair<int,int>,int> p;
int dmap[26][26][4];
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};

int solution(vector<vector<int>> board) {
    int answer = INF;
    int size=board.size();
    for(int k=0; k<4; k++)for(int i=0; i<size; i++)for(int j=0; j<size; j++)
        dmap[i][j][k]=INF;
    queue<p> q;
    
    for(int i=0; i<4; i++)
        dmap[0][0][i]=0;
    q.push({{0,0},-1});
    while(!q.empty()){
        int x=q.front().first.second, y=q.front().first.first;
        int idx=q.front().second;
        q.pop();
        int c;
        for(int i=0; i<4; i++){
            if(idx!=-1&&(idx+2)%4==i)continue;
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<0||yy<0||xx>=size||yy>=size||board[yy][xx]==1)continue;
            if(idx==i||idx==-1){
                c=100;
                if(dmap[y][x][i]+c<dmap[yy][xx][i]){
                    dmap[yy][xx][i]=c+dmap[y][x][i];
                    q.push({{yy,xx},i});
                }
            }
            else{
                c=600;
                 if(dmap[y][x][idx]+c<dmap[yy][xx][i]){
                    dmap[yy][xx][i]=c+dmap[y][x][idx];
                    q.push({{yy,xx},i});
                }
            }
        }
    }
    for(int i=0; i<4; i++)answer=min(answer,dmap[size-1][size-1][i]);
    
    return answer;
}