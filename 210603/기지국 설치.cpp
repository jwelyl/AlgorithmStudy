#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include<cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int idx = 0;
	int cnt = 0;
	bool chk = true;

	for (int i = 1; i <= n; i++) {

		if (chk && stations[idx] - w <= i && i <= stations[idx] + w) {

			i = stations[idx] + w;
			idx++;
			if (cnt > 0)
				answer++;

			cnt = 0;
			if (idx >= stations.size()) chk = false;
			continue;
		}


		i += w * 2;
		answer++;

	}
	if (cnt > 0) answer++;
	return answer;
}