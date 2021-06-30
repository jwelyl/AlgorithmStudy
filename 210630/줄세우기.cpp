#include<iostream>

#define MAX 200 + 1
using namespace std;

int N, Max;
int Arr[MAX];
int DP[MAX];

void Solution()
{
	for (int i = 1; i <= N; i++)
	{
		DP[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (Arr[j] < Arr[i] && DP[i] < DP[j] + 1)
			{
				DP[i] = DP[j] + 1;
			}
		}
		if (Max < DP[i]) Max = DP[i];
	}
	cout << N - Max << "\n";
}
int main(void)
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Arr[i];
	}
	Solution();
	return 0;
}