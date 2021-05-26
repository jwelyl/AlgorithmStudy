#include <cctype>
#include <cstring>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define INF 987654321

using namespace std;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

struct Pos {
    int r, c, dir;
};

int M, N;
vector<string> Board;
map<char, Pos> blocks;  // 알파벳 앞자리 먼저

Pos bfs(char ch, Pos sPos) {
    queue<Pos> q;
    vector<vector<int>> curve(M, vector<int>(N, INF));

    sPos.dir = -1;
    q.push(sPos);
    curve[sPos.r][sPos.c] = 0;

    bool noStart = false;
    while (!q.empty()) {
        Pos now = q.front();
        q.pop();

        if (noStart && Board[now.r][now.c] == ch) return {now.r, now.c};

        noStart = true;
        for (int i = 0; i < 4; ++i) {
            int nr = now.r + dr[i];
            int nc = now.c + dc[i];
            int nDir = i;  // 0,1,2,3
            int nCurve = curve[now.r][now.c];

            if (now.dir != -1 && now.dir != nDir) nCurve++;  // 시작지점 아니고, 방향이 다르면 꺾임 1추가
            if (0 > nr || 0 > nc || nr >= M || nc >= N) continue;
            if (nCurve >= 2) continue;                                  // 2번 이상 꺾이면 안됨
            if (Board[nr][nc] != '.' && Board[nr][nc] != ch) continue;  // 같은 캐릭터 아니면 안됨
            if (curve[nr][nc] >= nCurve) {                              // 더 적은 꺾임으로 도달하면 대체
                q.push({nr, nc, nDir});
                curve[nr][nc] = nCurve;
            }
        }
    }

    return {-1, -1};
}

string solution(int m, int n, vector<string> board) {
    string ans = "";
    M = m;
    N = n;
    Board = board;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isalpha(board[i][j]))  // 알파벳이면 제거 후보에 넣는다
                blocks[board[i][j]] = {i, j};
        }
    }

    while (1) {
        bool removeFlag = false;  // 블록 페어 제거여부
        for (auto& b : blocks) {  // 맵 처음부터 세면서 블록 제거해나간다
            const auto& [ch, sPos] = b;
            Pos dPos = bfs(ch, sPos);
            if (dPos.r != -1 && dPos.c != -1) {
                removeFlag = true;
                Board[sPos.r][sPos.c] = '.';
                Board[dPos.r][dPos.c] = '.';
                ans += ch;
                blocks.erase(ch);
                break;
            }
        }

        if (removeFlag) continue;

        if (blocks.empty())
            return ans;
        else
            return "IMPOSSIBLE";
    }
}