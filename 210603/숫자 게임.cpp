#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//그리디한 방식
//가장 큰 값으로 가장 큰 값을 이겨야 최적해
//그렇지 않으면 버림
int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	int size = A.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int Aidx = A.size() - 1;
	int Bidx = B.size() - 1;
	while (size != 0) {
		if (B[Bidx] > A[Aidx]) {
			answer++;
			Bidx--;
			Aidx--;
		}
		else {
			Aidx--;
		}
		size--;
	}
	return answer;
}