#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

vector<vector<int>> Board;

struct Pos {
    int r, c, cnt;
};

int bfs(Pos src, Pos dst) {
    bool visited[4][4] = {false};
    queue<Pos> q;
    q.push(src);

    while (!q.empty()) {
        Pos curr = q.front();
        q.pop();
        if (curr.r == dst.r && curr.c == dst.c)
            return curr.cnt;

        for (int i = 0; i < 4; ++i) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            if (0 > nr || nr > 3 || 0 > nc || nc > 3) continue;
            if (!visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc, curr.cnt + 1});
            }

            for (int j = 0; j < 2; ++j) {  // ctrl로 갈 수 있는 만큼 이동
                if (Board[nr][nc]) break;
                if (nr + dr[i] < 0 || nc + dc[i] < 0 || nr + dr[i] > 3 || nc + dc[i] > 3) break;

                nr += dr[i];
                nc += dc[i];
            }

            if (!visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc, curr.cnt + 1});
            }
        }
    }

    return -1;
}

int calc(Pos src) {
    int ret = INF;
    for (int i = 1; i <= 6; ++i) {
        vector<Pos> card;  // 같은색카드 위치
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (Board[j][k] == i) card.push_back({j, k, 0});
            }
        }

        if (card.empty()) continue;

        int forward = bfs(src, card[0]) + bfs(card[0], card[1]) + 2;
        int backward = bfs(src, card[1]) + bfs(card[1], card[0]) + 2;

        for (int j = 0; j < 2; ++j) {  // 카드 페어 제거
            Board[card[j].r][card[j].c] = 0;
        }

        ret = min(ret, forward + calc(card[1]));
        ret = min(ret, backward + calc(card[0]));

        for (int j = 0; j < 2; ++j) {
            Board[card[j].r][card[j].c] = i;
        }
    }

    if (ret == INF) return 0;
    return ret;
}

// 1,2,3,4,5,6 카드 선택 -> 다른 1,2,3,4,5,6 카드, 반대 케이스도 카운트
int solution(vector<vector<int>> board, int r, int c) {
    Board = board;
    return calc({r, c, 0});
}

// 완전탐색