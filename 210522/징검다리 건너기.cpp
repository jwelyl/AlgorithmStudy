#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 0;
	int max = 0;
	for (int i = 0; i < stones.size(); i++) {
		if (max < stones[i]) {
			max = stones[i];
		}
	}
	int start = 0;
	int end = max;
	while (start <= end) {
		int mid = (start + end) / 2;
		vector<int> temp = stones;

		max = 0;
		int cnt = 0;
		for (int i = 0; i < stones.size(); i++) {
			temp[i] = stones[i] - mid;
			if (temp[i] <= 0) {
				cnt++;
			}
			else {
				cnt = 0;
			}
			if (max < cnt) {
				max = cnt;
			}
		}

		if (max < k) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return answer = start;
}