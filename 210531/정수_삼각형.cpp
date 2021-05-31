#include <string>
#include <vector>
#include <cstring>
using namespace std;
int dp[501][501];
int MAX=0;
int recur(int n, int m,const vector<vector<int>>& t){
    if(n==MAX){
        return 0;
    }
    int &ret=dp[n][m];
    if(ret!=-1)return ret;
    
    ret=max(recur(n+1,m,t),recur(n+1,m+1,t))+t[n][m];
    return ret;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    MAX=triangle.size();
    memset(dp,-1,sizeof(dp));
    answer=recur(0,0,triangle);
    
    return answer;
}