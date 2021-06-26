#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 시계 방향
int n, m;
int board1[10][10]; // 처음 상태
int board2[10][10]; // 사각지대의 갯수를 세기 위해 사용할 변수
vector <pair<int,int>> cctv;

bool bound_check(int a, int b){ // 범위 벗어났는지 판단하는 함수
    return a < 0 || a >= n || b < 0 || b >= m;
}

void upd(int x, int y, int dir){ // dir 방향으로 진행하면서 사각지대를 제외한 곳을 7로 바꿈
    dir %= 4;
    while(1){
        x += dx[dir];
        y += dy[dir];
        if (bound_check(x,y) || board2[x][y] == 6) return; // 범위를 벗어났거나 벽을 만날때, 함수를 탈출
        if (board2[x][y] != 0) continue;
        board2[x][y] = 7; // 빈칸을 7로 바꿈
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int area = 0; // 사각지대 최소 넓이
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board1[i][j];
            if (board1[i][j] != 0 && board1[i][j] != 6)
                cctv.push_back({i,j});
            if (board1[i][j] == 0) area++;
        }
    }

    for(int tmp = 0; tmp < (1 << (2*cctv.size())); tmp++){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                board2[i][j] = board1[i][j];
        int brute = tmp;
        for(int i = 0; i < cctv.size(); i++){
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].X;
            int y = cctv[i].Y;
            if(board1[x][y] == 1){
                upd(x,y,dir);
            }
            else if(board1[x][y] == 2){
                upd(x,y,dir);
                upd(x,y,dir+2);
            }
                else if(board1[x][y] == 3){
                upd(x,y,dir);
                upd(x,y,dir+1);
            }
            else if(board1[x][y] == 4){
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
            }
            else{ // board1[x][y] == 5
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
                upd(x,y,dir+3);
            }
        }

        int val = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                val += (board2[i][j] == 0);
            }
        }
        area = min(area, val);
    }
    cout << area;

     
                        
}