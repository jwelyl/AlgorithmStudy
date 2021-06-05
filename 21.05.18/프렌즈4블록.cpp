#include <bits/stdc++.h>


// 문제 입력을 받고
// 지울 수 있는지 확인하는 체크 
// 지우는 함수
// 출력을 하자.

using namespace std;
bool check[31][31];
int answer;



void removed(int m, int n, vector<string> &board){
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++){
            if(check[i][j] == true) {
                board[i][j]=' ';
            }
        }
    }
}

void fall(int m, int n, vector<string> &board) {
    for(int i = 0; i < n; i++) {
        while(1) {
            bool isOk = false;
            for(int j = m - 1; j >= 1; j--) {
                if(board[j][i] == ' ' && board[j - 1][i] != ' ') {
                    board[j][i] = board[j - 1][i];
                    board[j - 1][i] = ' ';
                    isOk = true;
                }
            }
            if(!isOk) break;
        }
    }
}

void isOk(int m, int n, vector<string> &board) {
    
    while(true) { // 지울수 없을 때 까지 반복하여 체크
        bool flag = false;
        memset(check, false, sizeof(check));
        
        for(int i=0; i<m-1; i++) {
            for(int j=0; j<n-1; j++){
                if(board[i][j]==' ') continue;
                if(board[i][j]!=board[i][j+1]) continue; //현재확인하는거랑 오른쪽이랑 다르면 넘어가고
                if(board[i][j]!=board[i+1][j]) continue; //현재확인하는거랑 아래랑 다를 때
                if(board[i][j]!=board[i+1][j+1]) continue; //대각선이 다를때
                
                flag = true;
                // 부실 때
                if(!check[i][j]) {
                    check[i][j] = true;
                    answer++;
                }
                if(!check[i][j+1]) {
                    check[i][j+1] = true;
                    answer++;
                }
                if(!check[i+1][j]) {
                    check[i+1][j] = true;
                    answer++;
                }
                if(!check[i+1][j+1]) {
                    check[i+1][j+1] = true;
                    answer++;
                }
                
            }
        }
        
        if(!flag) break; //부술게 없으면 무한루프 나가기
        
        removed(m, n, board);
        fall(m, n, board);
    }   
}

int solution(int m, int n, vector<string> board) {
    
    isOk(m, n, board);
    return answer;
}