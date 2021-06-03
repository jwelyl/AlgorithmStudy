#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int s = 0;
	int pos = 1;
	int len = stations.size();
	while (pos <= n) {
		if (s < len && pos >= stations[s] - w) {
			pos = stations[s] + w + 1;
			s++;
		}
		else {
			answer++;
			pos += (2 * w) + 1;
		}
	}
	return answer;
}