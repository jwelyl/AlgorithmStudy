#include <bits/stdc++.h>
using namespace std;
int graph[101][101];
int minValue;

void rotate(int x1, int y1, int x2, int y2) {
	int temp = graph[x1][y1];
    minValue = temp;
    for(int i = x1; i < x2; i++) {
        graph[i][y1] = graph[i + 1][y1];
        minValue = min(minValue, graph[i][y1]);
    }
    for(int i = y1; i < y2; i++) {
        graph[x2][i] = graph[x2][i + 1];
        minValue = min(minValue, graph[x2][i]);
    }
    for(int i = x2; i > x1; i--) {
        graph[i][y2] = graph[i - 1][y2];
        minValue = min(minValue, graph[i][y2]);
    }
    for(int i = y2; i > y1 + 1; i--) {
        graph[x1][i] = graph[x1][i - 1];
        minValue = min(minValue, graph[x1][i]);
    }
    graph[x1][y1 + 1] = temp;
    minValue = min(minValue, graph[x1][y1 + 1]);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    for(int i = 1; i <= rows; i++)
        for(int j = 1; j <= columns; j++)
            graph[i][j] = (i - 1) * columns + j;
    
	for(auto query : queries) {
        int x1, x2, y1, y2;
        x1 = query[0]; y1 = query[1];
        x2 = query[2]; y2 = query[3];
        rotate(x1, y1, x2, y2);
        answer.push_back(minValue);
    }
    return answer;
}
