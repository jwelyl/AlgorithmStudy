#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int visited[100][100];
int N, M;

int dfs(int x, int y, vector<vector<int>> &picture, int target) {
    visited[x][y] = 1;
    int ret = 1;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
        if(visited[nx][ny]) continue;
        if(target != picture[nx][ny]) continue;
        ret += dfs(nx, ny, picture, target);   
    }
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    N = n, M = m;
    vector<int> answer(2);
    memset(visited, 0, sizeof(visited));
    
    
    for (int i = 0; i < picture.size(); i++) {
        for (int j = 0; j < picture[i].size(); j++) {
            if(!visited[i][j] && picture[i][j] != 0) {
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, dfs(i, j, picture, picture[i][j]));
            }
        
        }
    } 
    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}