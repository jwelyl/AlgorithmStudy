#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
int visit[26][26] = {1};
int dp[26][26];
int n, ans = INF;

int is_valid(int r,int c){
    return 0<=r&&r<n&&0<=c&&c<n;
}
void dfs(vector<vector<int>> board,int dir, int cost, int r,int c) {
    if(cost>=ans || dp[r][c]<cost)
        return;
    if(r==(n-1)&&c==(n-1)){
       ans = min(cost,ans);
       return;
    }
    dp[r][c] = min(cost,dp[r][c]);
    int nxtr,nxtc;
    for(int i=0;i<4;i++) {
        nxtr = r+dr[i];
        nxtc = c+dc[i];
        if(!is_valid(nxtr,nxtc)||visit[nxtr][nxtc]) continue;
        if(board[nxtr][nxtc]) continue;
        visit[nxtr][nxtc] = 1;
        if(dir == i || dir==-1) 
            dfs(board,i,cost+100,nxtr,nxtc);
        else 
            dfs(board,i,cost+600,nxtr,nxtc);
        visit[nxtr][nxtc] = 0;
    }
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    n = board.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j] = INF;
    dfs(board,-1,0,0,0);
    answer = ans;
    return answer;
}