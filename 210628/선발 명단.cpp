#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 11
int ability[MAX_SIZE][MAX_SIZE];
int answer = 0;
void backtracking(int idx, int sum, bool position[])
{
	if (idx == MAX_SIZE) {
		answer = max(answer, sum);
		return;
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		if (ability[idx][i] == 0)
			continue;
		if (position[i] == false) {
			position[i] = true;
			backtracking(idx + 1, sum + ability[idx][i], position);
			position[i] = false;
		}
	}
}
int main()
{
	int tc;
	cin >> tc;
	while (tc--) {
		answer = 0;
		bool position[MAX_SIZE];
		for (int i = 0; i < MAX_SIZE; i++) {
			position[i] = false;
			for (int j = 0; j < MAX_SIZE; j++) {
				cin >> ability[i][j];
			}
		}
		backtracking(0, 0, position);
		printf("%d\n", answer);
	}
	return 0;
}