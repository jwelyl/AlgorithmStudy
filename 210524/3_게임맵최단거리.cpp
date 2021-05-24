#include <queue>
#include <vector>

using namespace std;

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};
int dist[101][101];

int solution(vector<vector<int>> maps) {
    int n = maps.size() - 1;
    int m = maps[0].size() - 1;
    dist[0][0] = 1;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        const auto& [r, c] = q.front();
        if (r == n && c == m) return dist[r][c];
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (0 > nr || 0 > nc || nr > n || nc > m) continue;
            if (!maps[nr][nc] || dist[nr][nc]) continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    return -1;
}