#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;
	vector<vector<int>> board(rows, vector<int>(columns));
	int num = 1;
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= columns; j++) {
			board[i - 1][j - 1] = num++;
		}
	}
	vector<vector<int>> board2 = board;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < queries.size(); i++) {
		int x1 = queries[i][0] - 1;
		int y1 = queries[i][1] - 1;
		int x2 = queries[i][2] - 1;
		int y2 = queries[i][3] - 1;
		for (int j = y1; j < y2; j++) {
			board2[x1][j + 1] = board[x1][j];
			pq.push({ board[x1][j] });
		}
		for (int j = x1; j < x2; j++) {
			board2[j + 1][y2] = board[j][y2];
			pq.push({ board[j][y2] });
		}

		for (int j = y2; j > y1; j--) {
			board2[x2][j - 1] = board[x2][j];
			pq.push({ board[x2][j] });
		}

		for (int j = x2; j > x1; j--) {
			board2[j - 1][y1] = board[j][y1];
			pq.push({ board[j][y1] });
		}
		answer.push_back(pq.top());

		while (!pq.empty()) {
			pq.pop();
		}

		board = board2;
	}
	return answer;
}