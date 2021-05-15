#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
//숫자와 문자열로 압축된 문자열 생성
string make_string(const string& str, int num)
{
	if (num == 1)
		return str;
	string temp;
	temp = to_string(num) + str;
	return temp;
}
int solution(string s) {
	int answer = 987654321;
	int ParsingSize = s.size() / 2;
	queue<string> q;
	string str, result = "";
	if (s.length() == 1)
		return 1;
	for (int c = 1; c <= ParsingSize; c++) {
		int idx = 0;
		while (1) {
			//마지막 문자열이라면, 큐에 마저 추가
			if (idx + c > s.size()) {
				str = s.substr(idx);
				if (str.length() != 0)
					q.push(str);
				break;
			}
			//문자열을 특정 길이만큼 잘라서 큐에 추가
			str = s.substr(idx, c);
			q.push(str);
			idx += c;
		}

		string prev = q.front();
		q.pop();
		int num = 1;
		while (1) {
			//이전과 같은 문자열이라면 +1
			if (q.front() == prev)	
				num++;
			//이전과 다르다면, 문자열 생성하고 1로 초기화
			else {
				result += (make_string(prev, num)); 
				prev = q.front();
				num = 1;
			}
			q.pop();
			//큐가 비었다면, 답에 추가하고 종료
			if (q.empty()) {
				result += (make_string(prev, num));
				break;
			}
		}
		//최솟값 갱신
		answer = min((int)result.length(), answer);
		result.clear();
	}
	return answer;
}