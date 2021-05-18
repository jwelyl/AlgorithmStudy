#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;
#define BLANK 'p'
void move(vector<string>& board)
{
	stack<char> s;
	bool IsCompact = false;
	for (int c = 0; c < board[0].size(); c++) {
		for (int r = 0; r < board.size(); r++) {
			if (board[r][c] != BLANK)
				s.push(board[r][c]);
		}
		for (int r = board.size() - 1; r >= 0; r--) {
			if (!s.empty()) {
				board[r][c] = s.top();
				s.pop();
			}
			else {
				board[r][c] = BLANK;
			}
		}
	}
}
bool check(vector<string>& board, int row, int col)
{
	char ch = board[row][col];
	if (board[row + 1][col] == ch &&
		board[row][col + 1] == ch &&
		board[row + 1][col + 1] == ch)
		return true;
	else
		return false;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	int r, c;
	queue<pair<int, int>> rmq;
	do {
		while (!rmq.empty()) {
			r = rmq.front().first;
			c = rmq.front().second;
			rmq.pop();
			board[r][c] = BLANK;
		}
		move(board);
		for (int i = 0; i<board.size() - 1; i++) {
			for (int j = 0; j<board[0].size() - 1; j++) {
				if (board[i][j] != BLANK && check(board, i, j)) {
					rmq.push({ i, j });
					rmq.push({ i + 1, j });
					rmq.push({ i, j + 1 });
					rmq.push({ i + 1, j + 1 });
				}
			}
		}
	} while (!rmq.empty());
	for (int i = 0; i<board.size(); i++) {
		for (int j = 0; j<board[0].size(); j++) {
			if (board[i][j] == BLANK)
				answer++;
		}
	}
	return answer;
}