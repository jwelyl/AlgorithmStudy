#include <iostream>
using namespace std;

int n, m, k;
int notebook[42][42]; 
int sticker[12][12];
int row, col; // 스티커 행, 열

bool place(int x, int y){ // notebook (x,y)에 모눈종이의 (0,0)이 올라가게 스티커를 붙일 수 있는지 판별
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if (notebook[x+i][y+j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if (sticker[i][j] == 1)
                notebook[x+i][y+j] = 1;
        }
    }
    return true;
}

void rotate(){ // 90도 회전 하는 함수
    int tmp[12][12];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            tmp[i][j] = sticker[i][j];
        
    swap(row, col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            sticker[i][j] = tmp[row-1-j][i];
}

int main(){
    cin >> n >> m >> k;
    while(k--){
        cin >> row >> col;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                cin >> sticker[i][j];

        for(int rot = 0; rot < 4; rot++){
            bool is_paste = false;
            for(int x = 0; x <= n - row; x++){
                if (is_paste) break;
                for(int y = 0; y <= m - col; y++){
                    if (place(x,y)){
                        is_paste = true;
                        break;
                    }
                }
            }
            if(is_paste) break;
            rotate();
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cnt += notebook[i][j];
        }
    }
    cout << cnt;
}