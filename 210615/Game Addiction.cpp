#include <iostream>
using namespace std;
#define MAX_SIZE 31
int H, N;
long long dp[MAX_SIZE][MAX_SIZE];
int main()
{
	cin >> H >> N;
	if (H == N) { cout << 1; return 0; }
	//작은 좌표 -> 큰 좌표로 통일하기 위함
	if (H > N) swap(H, N);
	//왼쪽 -> 오른쪽만으로 가는 경우의 수는 1가지
	//bottom up을 위함
	for (int i = H; i <= N; i++) {
		dp[H][i] = 1;
	}
	for (int i = H + 1; i <= N; i++) {
		for (int j = H + 1; j <= N; j++) {
			//왼쪽, 위쪽에서 오는 경우의 수 계산
			if (i <= j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	cout << dp[N][N];
	return 0;
}