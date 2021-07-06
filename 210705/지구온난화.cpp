// 지도의 크기를 줄이는 방법에서 많이 해멨다. X일때 기준으로 최소,최대값을 잘 생각하자.
#include <iostream>
using namespace std;
int r, c;
char board[12][12];
char board2[12][12];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool isValid(int x, int y){
    return x < 0 || x >= r || y < 0 || y >= c;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            board2[i][j] = board[i][j];
        }
    }
    int ly = r, lx = c, ry = -1, rx = -1;
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if (board[i][j] == 'X'){
                int sea = 0; // 바다 갯수
                for(int dir = 0; dir < 4; dir++){ // 동서남북 돌면서 바다의 갯수를 count 해줌 
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (isValid(nx,ny) || board[nx][ny] == '.') 
                        sea++;
                }
                if (sea >= 3){ // 3개 이상일때 잠긴다.
                    board2[i][j] = '.';
                }
                else{
                    ly = min(ly,i);
                    lx = min(lx,j);
                    ry = max(ry,i);
                    rx = max(rx,j);
                }
            }
        }
    }

    for(int i = ly; i <= ry; i++){
        for(int j = lx; j <= rx; j++){
            cout << board2[i][j];
        }
        cout << '\n';
    }
    return 0;
}