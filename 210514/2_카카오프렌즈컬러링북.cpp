#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#define pii pair<int, int>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool visited[100][100];

int bfs(int x, int y, int m, int n, vector<vector<int>>& picture) {
    int colored = 0;
    int target_color = picture[x][y];

    queue<pii> q;
    q.push({x, y});

    while (!q.empty()) {
        const auto& [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (visited[nx][ny] || picture[nx][ny] != target_color) continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
            colored++;
        }
    }

    return colored;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(visited, false, sizeof(visited));
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!picture[i][j] || visited[i][j]) continue;

            int colored = bfs(i, j, m, n, picture);
            number_of_area++;
            if (colored > max_size_of_one_area) max_size_of_one_area = colored;
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
