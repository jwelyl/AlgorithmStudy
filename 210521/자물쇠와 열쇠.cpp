#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	//열쇠는 회전과 이동이 가능하며 열쇠의 돌기 부분을 자물쇠의 홈
	int n = key.size();
	int m = lock.size();
	vector<vector<int>> board((n - 1) * 2 + m, vector<int>((n - 1) * 2 + m, 0));

	for (int i = 0; i < lock.size(); i++) {
		for (int j = 0; j < lock[i].size(); j++) {
			if (lock[i][j] == 1) {
				board[i + n - 1][j + n - 1] = 1;
			}
		}
	}

	for (int cw = 0; cw < 4; cw++) { //0 90 180 270
		for (int i = 0; i < n - 1 + m; i++) {
			for (int j = 0; j < n - 1 + m; j++) {

				vector<vector<int>> temp = board;
				for (int row = 0; row < key.size(); row++) {
					for (int col = 0; col < key[row].size(); col++) {
						board[i + row][j + col] ^= key[row][col];
					}
				}

				bool chk = true;
				for (int row = 0; row < lock.size(); row++) {
					for (int col = 0; col < lock[row].size(); col++) {
						if (board[n - 1 + row][n - 1 + col] != 1) {
							chk = false;
							break;
						}
					}
					if (chk == false) break;
				}
				if (chk) return true;

				board = temp;
			}
		}
		//key rotation
		vector<vector<int>> key2(key.size(), vector<int>(key.size(), 0));
		for (int i = 0; i < key.size(); i++) {
			int col = key.size() - 1;
			for (int j = 0; j < key[i].size(); j++) {
				key2[i][j] = key[col - j][i];
			}
		}

		key = key2;
	}
	return answer;
}