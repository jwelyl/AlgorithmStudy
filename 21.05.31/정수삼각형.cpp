#include <bits/stdc++.h>

using namespace std;

int dp[500][500]; // 가로 세로
vector<vector<int>> triangles;
int go(int x, int y) {
    if(x == 0) return triangles[0][0];
    
    int ret = dp[x][y];
    if(ret != -1) return ret;
    
    if(y == 0) ret = go(x - 1, y) + triangles[x][y];
    else if(y == x) ret = go(x - 1, y - 1) + triangles[x][y];
    else {
        ret = max(go(x - 1, y), go(x - 1, y - 1)) + triangles[x][y];
    }
    return dp[x][y] = ret;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    triangles = triangle;
    int size = triangle.size();
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0; i < triangle[size - 1].size(); i++) 
        answer = max(go(size - 1, i), answer);
    
    return answer;
}