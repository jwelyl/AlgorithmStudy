#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int graph[1001][1001];
    int x = 0, y = 0;
    int state = 0;
    int num = 1;

    for(int i = 0; i < n; i++) {
        if(state == 0) {
            for(int j = i; j < n; j++) graph[x++][y] = num++;
            x--; y++;
            state = 1;
            continue;
        }

        if(state == 1) {
            for(int j = i; j < n; j++) graph[x][y++] = num++;
            x--; y -= 2;
            state = 2;
            continue;
        }

        if(state == 2) {
            for(int j = i; j < n; j++) graph[x--][y--] = num++;
            x += 2; y++;
            state = 0;
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(graph[i][j]) answer.push_back(graph[i][j]);

    return answer;
}