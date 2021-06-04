#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    unordered_map<char,int> dir;
    bool visit[121][121];
    memset(visit,false,sizeof(visit));
    int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
    dir['U']=0;dir['R']=1;dir['D']=2;dir['L']=3;
    int node=5*11+5;
    
    for(int i=0; i<dirs.size(); i++){
        int d=dir[dirs[i]];
        int cy=node/11, cx=node%11;
        int ny=cy+dy[d],nx=cx+dx[d];
        if(ny<0||nx<0||nx>10||ny>10)continue;
        int nnode=ny*11+nx;
        if(!visit[node][nnode]){
            visit[node][nnode]=true;
            visit[nnode][node]=true;
            answer++;
        }
        node=nnode;
    }
    
    return answer;
}