#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int dp[501][501][4];
int MOD = 20170805;
int dx[2]={0,1},dy[2]={1,0};
int recur(int r, int c, int dir, const vector<vector<int>>& map){
    if(r==map.size()-1&&c==map[0].size()-1)return 1;
    int &ret= dp[r][c][dir];
    if(ret!=-1)return ret;
    ret=0;
    
    for(int i=0; i<2; i++){
        int x=c+dx[i], y=r+dy[i];
        if(x<0||y<0||x>=map[0].size()||y>=map.size()||map[y][x]==1)continue;
        if(map[r][c]==2){
            if(dir==i)ret=(ret%MOD+recur(y,x,i,map)%MOD)%MOD;
        }
        else
            ret=(ret%MOD+recur(y,x,i,map)%MOD)%MOD;
    }
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    memset(dp,-1,sizeof(dp));
    answer=recur(0,0,0,city_map);
    return answer;
}