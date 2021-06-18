#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
int arr[14];
bool dp[14][2600001];
void bf(int i, int w)
{
	if (i > N || dp[i][w])
		return;
	dp[i][w] = true; //지금까지 만들 수 있었던 조합을 메모이제이션
	bf(i + 1, w + arr[i]); //오른쪽 그릇에 i번째 무게추를 놓는다.
	bf(i + 1, abs(w - arr[i])); //왼쪽 그릇에 i번째 무게추를 놓는다.
	bf(i + 1, w); //무게추를 놓지 않는다.
}
int main()
{
	cin >> N;
	int sum = 0, answer = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	bf(0, 0);
	for (int i = 1; i <= sum; i++) {
		if (dp[N][i] == false) {
			answer++;
		}
	}
	printf("%d\n", answer);
	return 0;
}