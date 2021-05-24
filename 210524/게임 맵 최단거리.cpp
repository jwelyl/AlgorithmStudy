#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0,n=maps.size(),m=maps[0].size();
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    int dist[101][101];
    for(int i=0; i<101; i++)for(int j=0; j<101; j++)dist[i][j]=-1;
    dist[0][0]=1;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int y=q.front().first, x= q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int xx=x+dx[i], yy=y+dy[i];
            if(xx<0||yy<0||xx>=m||yy>=n||maps[yy][xx]==0)continue;
            if(dist[yy][xx]==-1){
                dist[yy][xx]=dist[y][x]+1;
                q.push({yy,xx});
            }
        }
    }
    answer=dist[n-1][m-1];
    return answer;
}