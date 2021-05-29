//0-1 bfs로 하면 시간 초과..
#include <iostream>
using namespace std;
int solution(int n)
{
	int ans = 0;
	while (n != 0) {
		//2로 나눌 수 있으면 먼저 나누는게 가장 빠름
		if (n % 2 == 0)
			n /= 2;
		else {
			n--;
			ans++;
		}
	}
	return ans;
}