#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
#define MISS    5
#define HIT     1
int GetIndexOfCache(deque<string>& dq, const string& str)
{
	deque<string>::iterator it = dq.begin();
	int idx = -1;
	for (; it != dq.end(); it++) {
		if (str == *it) {
			idx = it - dq.begin();
			break;
		}
	}
	return idx;
}
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	if (cacheSize == 0)
		return cities.size() * MISS;
	deque<string> dq;
	for (auto& city : cities) {
		transform(city.begin(), city.end(), city.begin(), ::tolower);
		int idx = GetIndexOfCache(dq, city);
		//HIT
		if (idx != -1) {
			dq.push_back(dq[idx]);
			dq.erase(dq.begin() + idx);
			answer += HIT;
		}
		//MISS
		else {
			if (dq.size() == cacheSize)
				dq.pop_front();
			dq.push_back(city);
			answer += MISS;
		}
	}
	return answer;
}