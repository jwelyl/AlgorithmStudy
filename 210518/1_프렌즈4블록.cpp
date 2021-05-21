#include <cstring>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag = true;  // 다음라운드 진행여부
    bool check[m][n];

    while (flag) {
        memset(check, false, sizeof(check));
        flag = false;
        for (int i = 0; i < m - 1; ++i) {  // 깨지는 블록 체크
            for (int j = 0; j < n - 1; ++j) {
                if (board[i][j] == ' ') continue;
                char block = board[i][j];
                if (block == board[i + 1][j] && block == board[i][j + 1] && block == board[i + 1][j + 1]) {
                    check[i][j] = check[i + 1][j] = check[i][j + 1] = check[i + 1][j + 1] = true;
                    flag = true;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (check[i][j]) {
                    answer++;
                    for (int k = i - 1; k >= 0; --k) {
                        board[k + 1][j] = board[k][j];
                        board[k][j] = ' ';
                    }
                }
            }
        }
    }

    return answer;
}
