#include <bits/stdc++.h>
using namespace std;
bool visited[11][11][11][11];

int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5;
    
    for(char dir : dirs) {
        int nx = x; int ny = y;
        if(dir == 'U') nx--;
        else if(dir == 'D') nx++;
        else if(dir == 'L') ny--;
        else if(dir == 'R') ny++;
        
        if(nx < 0 || nx > 10 || ny < 0 || ny > 10) continue;
        if(!visited[x][y][nx][ny]) {
            visited[x][y][nx][ny] = true;
            visited[nx][ny][x][y] = true;
            answer++;
        }
        x = nx;
        y = ny;
    }
    
    return answer;
}
