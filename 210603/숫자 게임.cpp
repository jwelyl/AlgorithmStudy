#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), greater<int>());
	int idx = 0;
	int last = B.size() - 1;
	int cnt = 0;
	for (int i = 0; i < A.size(); i++) {
		if (B[idx] > A[i]) {
			idx++;
			answer++;
		}
	}
	return answer;
}