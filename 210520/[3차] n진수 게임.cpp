#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
char hex(int num) {
	if (num == 10) return 'A';
	else if (num == 11) return 'B';
	else if (num == 12) return 'C';
	else if (num == 13) return 'D';
	else if (num == 14) return 'E';
	else if (num == 15)	return 'F';
}
string result = "";
string trans(int n, int num) {
	if (num < n) {
		if (num >= 10) {
			return result += hex(num);
		}
		else {
			return result += to_string(num);
		}
	}
	else {
		trans(n, num / n);
		if (num % n >= 10) {
			return result += hex(num % n);
		}
		else {
			return result += to_string(num % n);
		}

	}
}
string solution(int n, int t, int m, int p) {
	string answer = "";
	//진법 n, 미리 구할 숫자의 갯수 t, 게임에 참가하는 인원 m, 튜브의 순서 p

	int num = 0;
	while (1) {

		trans(n, num);

		if (result.size() >= t * m) {
			while (1) {
				answer += result[p - 1];
				p += m;
				if (answer.size() == t) break;
			}
		}
		if (answer.size() == t) break;
		num++;

	}
	return answer;
}