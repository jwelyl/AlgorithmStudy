#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_SIZE 12
int Height, Width;
char arr[MAX_SIZE][MAX_SIZE];
int minRow = 987564321, minCol = 987654321;
int maxRow = 0, maxCol = 0;
queue<pair<int, int>> q;
bool checkIsland(int row, int col)
{
	int cnt = 0;
	if (arr[row][col] == 'X') {
		if (row >= 1 && arr[row - 1][col] == '.')
			cnt++;
		if (col >= 1 && arr[row][col - 1] == '.')
			cnt++;
		if (row <= Height && arr[row + 1][col] == '.')
			cnt++;
		if (col <= Width && arr[row][col + 1] == '.')
			cnt++;
	}
	if (cnt >= 3) {
		q.push({ row, col });
		return true;
	}
	else {
		return false;
	}
}
int main()
{
	cin >> Height >> Width;
	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			arr[i][j] = '.';
	for (int i = 1; i <= Height; i++) {
		char ch;
		for (int j = 1; j <= Width; j++) {
			scanf("%c", &ch);
			if (ch == '\n') {
				j--;
				continue;
			}
			arr[i][j] = ch;
		}
	}
	for (int i = 1; i <= Height; i++) {
		for (int j = 1; j <= Width; j++) {
			if (arr[i][j] == 'X' && !checkIsland(i, j)) {
				minRow = min(i, minRow);
				minCol = min(j, minCol);
				maxRow = max(i, maxRow);
				maxCol = max(j, maxCol);

			}
		}
	}
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		arr[p.first][p.second] = '.';
	}
	for (int i = minRow; i <= maxRow; i++) {
		for (int j = minCol; j <= maxCol; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}